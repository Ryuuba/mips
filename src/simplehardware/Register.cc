#include "Register.h"

Define_Module(Register);

Register::Register() {
  state = 0;
  enable = 0;
  d = 0;
}

Register::~Register() {
  unsubscribe(d_port.c_str(), this);
  unsubscribe(enable_port.c_str(), this);
  unsubscribe(clk_port.c_str(), this);
}

void Register::initialize() {
  SequentialModule::initialize();
  d_port = par("dPort").stringValue();
  enable_port = par("enablePort").stringValue();
  clk_port = par("clkPort").stringValue();
  getParentModule()->subscribe(d_port.c_str(), this);
  getParentModule()->subscribe(enable_port.c_str(), this);
  getParentModule()->subscribe(clk_port.c_str(), this);
  q_port = par("qPort").stringValue();
  
  WATCH(state);
  WATCH(d);
  WATCH(enable);
  WATCH(clockLevel);
  scheduleAt(omnetpp::simTime(), delay);
}

void Register::handleMessage(omnetpp::cMessage* msg) {
  std::string bubbleText;
  if (msg->isSelfMessage()) {
    state = enable ? d : state;
    if (enable) {
      Word* word = new Word;
      word->setData(state);
      word->setInstructionFlag(0);
      word->setKind(0);
      //emit();
    }
    bubbleText = "state = " + std::to_string(state);
    bubble(bubbleText.c_str());
  }
  else 
    error("Register: This module only receives self-messages");
}

void Register::receiveSignal(cComponent* src, 
      omnetpp::simsignal_t id, 
      cObject* obj, 
      cObject* details) {
  omnetpp::cMessage* msg = reinterpret_cast<omnetpp::cMessage*>(obj);
  switch(msg->getKind()) {
    case 0:
      d = (reinterpret_cast<Word*>(msg))->getData();
      break;
    case 1:
      enable = (reinterpret_cast<CtrlSignal*>(msg))->getSignal(0);
      break;
    case 2:
      {
      bool currentClockLevel = (reinterpret_cast<ClockSignal*>(msg))->getLevel();
      if (risingEdge(currentClockLevel))
        scheduleAt(omnetpp::simTime() + module_delay, delay);
      clockLevel = currentClockLevel;
      break;
      }
    default:
      delete msg;
      error("Register: message kind %d couldn't be processed", msg->getKind());
  }
  delete msg;
}