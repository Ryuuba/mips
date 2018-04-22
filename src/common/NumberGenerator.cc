#include "NumberGenerator.h"

Define_Module(NumberGenerator);

NumberGenerator::NumberGenerator(){
  number = nullptr;
  lower_limit = 0;
  upper_limit = 0;
  rnd = 0;
}

NumberGenerator::~NumberGenerator(){
}

void NumberGenerator::initialize(){
  Generator::initialize();
  lower_limit = int(par("a"));
  upper_limit = int(par("b"));
  WATCH(rnd);
}

void NumberGenerator::handleMessage(omnetpp::cMessage* msg){
  rnd = cComponent::intuniform(lower_limit, upper_limit);
  std::string text = std::to_string(rnd);
  number = new Word();
  number->setData(rnd);
  number->setInstructionFlag(false);
  send(number, "out");
  scheduleAt(omnetpp::simTime() + module_delay, msg);
  EV << "Number: " << rnd;
  bubble(text.c_str());
}
