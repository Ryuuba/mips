#include "SequentialModule.h"

Register_Abstract_Class(SequentialModule);

SequentialModule::SequentialModule() {
  clockLevel = 0;
  module_delay = 0.0;
  delay = nullptr;
}

SequentialModule::~SequentialModule() {
  if (delay) {
    cancelAndDelete(delay);
    delay = nullptr;
  }
}

bool SequentialModule::risingEdge(bool currentClockLevel) {
  return (!clockLevel) & currentClockLevel;
}

void SequentialModule::initialize() {
  module_delay = par("delay");
  delay = new omnetpp::cMessage();
}

