#ifndef GENERATOR_H
#define GENERATOR_H

#include <omnetpp.h>
#include <omnetpp/csimplemodule.h>

#include "../common/word_m.h"
#include "../common/addr_m.h"
#include "../common/ctrl_signal_m.h"


class Generator: public omnetpp::cSimpleModule {
  protected:
    omnetpp::cMessage* delay;
    omnetpp::simtime_t module_delay, offset;
  public:
    Generator();
    virtual ~Generator();
    virtual void initialize() override;
    virtual void handleMessage(omnetpp::cMessage*) override = 0;
};

#endif