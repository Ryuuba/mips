#ifndef SEQUENTIAL_MODULE_H
#define SEQUENTIAL_MODULE_H

#include <omnetpp.h>
#include <omnetpp/csimplemodule.h>
#include <omnetpp/clistener.h>
#include <string>
#include "../common/word_m.h"
#include "../common/clock_signal_m.h"

class SequentialModule : public omnetpp::cSimpleModule, public omnetpp::cListener {
  protected:
    bool clockLevel;
    omnetpp::simtime_t module_delay;
    omnetpp::cMessage* delay;
    virtual bool risingEdge(bool);
  public:
    SequentialModule();
    ~SequentialModule();
    virtual void initialize() override;
    virtual void handleMessage(omnetpp::cMessage*) override = 0;
    virtual void receiveSignal(
      cComponent*, 
      omnetpp::simsignal_t, 
      cObject*, 
      cObject*) override = 0;
};

#endif