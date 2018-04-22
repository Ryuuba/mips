#include "../simplehardware/Adder.h"
#include <iostream>

Define_Module(Adder);

Adder::Adder(){
  a = 0;
  b = 0;
  port_a = nullptr;
  port_b = nullptr;
  result = nullptr;
}

Adder::~Adder(){
  if (delay) {
    std::cout << "Adder: delete delay\n";
    cancelAndDelete(delay);
    delay = nullptr;
  }
}

void Adder::initialize(){
  module_delay = par("module_delay");
  port_a = gate("portA");
  port_b = gate("portB");
  delay = new omnetpp::cMessage("module_delay");
}

void Adder::handleMessage(omnetpp::cMessage* msg) {
  static Word* operand;
  std::string text;
  // module delay has gone by
  if (msg->isSelfMessage()) {
    //Updates result
    result = new Word();
    result->setData(a + b);
    result->setInstructionFlag(false);
    result->setKind(0);
    send(result, "result");
    text = std::to_string(a) + " + " + std::to_string(b);
    bubble(text.c_str());
  }
  //A new operand arrives in port A or port B
  else { 
    //Gets values from msg
    operand = reinterpret_cast<Word*>(msg);
    if (msg->getArrivalGateId() == port_a->getId()) {
      a = operand->getData();
      EV << "new data arrives from port a\n";
    }
    else {
      b = operand->getData();
      EV << "new data arrives from port b\n";
    }
    //Only one delay msg is scheduled despite that both operands have changed
    if (!delay->isScheduled())
      scheduleAt(omnetpp::simTime() + module_delay, delay);
    delete msg;
  }
}
