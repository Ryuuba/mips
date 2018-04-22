#include "RegisterFile.h"

Define_Module(RegisterFile);

RegisterFile::RegisterFile() {
  for (auto& data : reg)
    data = 0;
  data_input = 0;
  rs = 0;
  rt = 0;
  rs_addr = 0;
  rt_addr = 0;
  dest_addr = 0;
  regWrite = false;
}

void RegisterFile::initialize() {
  SequentialModule::initialize();
  for (int i = 0; i < 32; i++)
    WATCH(reg[i]);
  WATCH(rs);
  WATCH(rt);
  WATCH(rs_addr);
  WATCH(rt_addr);
  WATCH(dest_addr);
  WATCH(regWrite);
  scheduleAt(omnetpp::simTime(), delay);
}

void RegisterFile::handleMessage(omnetpp::cMessage* msg) {
  std::string text;
  if (msg->isSelfMessage()) {
    Word* rs_value = new Word;
    Word* rt_value = new Word;
    rs_value->setData(reg[rs_addr]);
    rs_value->setInstructionFlag(0);
    rs_value->setKind(0);
    send(rs_value, "rs");
    rt_value->setData(reg[rt_addr]);
    rt_value->setInstructionFlag(0);
    rt_value->setKind(0);
    send(rt_value, "rt");
    if (dest_addr != 0)
      reg[dest_addr] = regWrite ? data_input : reg[dest_addr];
    text = "rs = " + std::to_string(reg[rs_addr]) + '\n' +
           "rt = " + std::to_string(reg[rt_addr]);
    bubble(text.c_str());
  }
  else
    error("RegisterFile: This module only receives self-messages");
}

void RegisterFile::receiveSignal(cComponent* src, omnetpp::simsignal_t id, 
  cObject* obj, cObject* details) {
  omnetpp::cMessage* msg = reinterpret_cast<omnetpp::cMessage*>(obj);
  switch(msg->getKind()) {
    case 0:
      data_input = (reinterpret_cast<Word*>(msg))->getData();
      break;
    case 1:
      regWrite = (reinterpret_cast<CtrlSignal*>(msg))->getSignal(0);
      break;
    case 2:
    {
      bool currentClockLevel = (reinterpret_cast<ClockSignal*>(msg))->getLevel();
      if (risingEdge(currentClockLevel))
        scheduleAt(omnetpp::simTime() + module_delay, delay);
      clockLevel = currentClockLevel;
      break;
    }
    case 3:
      rs_addr = (reinterpret_cast<Address*>(msg))->getAddress();
      break;
    case 4:
      rt_addr = (reinterpret_cast<Address*>(msg))->getAddress();
      break;
    case 5:
      dest_addr = (reinterpret_cast<Address*>(msg))->getAddress();
      break;
    default:
      error("RegisterFile: signal %d couldn't be processed", msg->getKind());
  }
  delete msg;
}