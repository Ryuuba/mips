#include "Generator.h"

Register_Abstract_Class(Generator);

Generator::Generator(){
  delay = nullptr;
  module_delay = 0.0;
  offset = 0.0;
}

Generator::~Generator(){
  if (delay) {
    cancelAndDelete(delay);
    delay = nullptr;
  }
}

void Generator::initialize() {
  offset = par("offset");
  module_delay = par("delay");
  delay = new omnetpp::cMessage;
  scheduleAt(omnetpp::simTime() + offset, delay);
}