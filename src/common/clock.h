#ifndef CLOCK_H
#define CLOCK_H

#include <omnetpp.h>
#include <omnetpp/csimplemodule.h>
#include "clock_signal_m.h"

class ClockGenerator : public omnetpp::cSimpleModule {
  private:
    omnetpp::simtime_t clockWidth, offset;
    ClockSignal* clk;
    omnetpp::cMessage* switchLevel;
    bool level;
  public:
    ClockGenerator();
    ~ClockGenerator();
    void initialize() override;
    void handleMessage(omnetpp::cMessage*) override;
};

#endif
