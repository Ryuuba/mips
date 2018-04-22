#ifndef ELECTRONIC_NODE_H
#define ELECTRONIC_NODE_H

#include <omnetpp.h>
#include <omnetpp/csimplemodule.h>

#include "clock_signal_m.h"
#include "ctrl_signal_m.h"
#include "word_m.h"

class ElectronicNode : public omnetpp::cSimpleModule {
  protected:
    uint8_t outGateNumber;
  public:
    void initialize() override;
    void handleMessage(omnetpp::cMessage*) override;
};

#endif