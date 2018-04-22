#include "clock.h"

Define_Module(ClockGenerator);

ClockGenerator::ClockGenerator() {
  clockWidth = 0.0;
  offset = 0.0;
  level = 1;
  clk = nullptr;
}

ClockGenerator::~ClockGenerator() {
  if (switchLevel) {
    cancelAndDelete(switchLevel);
    switchLevel = nullptr;
  }
}

void ClockGenerator::initialize() {
  omnetpp::simtime_t period = par("period");
  offset = par("offset");
  clockWidth = period * 0.5;
  switchLevel = new omnetpp::cMessage("switch level");
  scheduleAt(omnetpp::simTime() + offset, switchLevel);
  WATCH(level);
}

void ClockGenerator::handleMessage(omnetpp::cMessage* msg) {
  level = !level;
  if (msg->isSelfMessage()) {
    if (!level) 
      bubble("Falling edge");
    else
      bubble("Rising edge");
    scheduleAt(omnetpp::simTime() + clockWidth, switchLevel);
    clk = new ClockSignal();
    clk->setLevel(level);
    clk->setKind(2);
    send(clk, "out");
  }
}