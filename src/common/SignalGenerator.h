#ifndef SIGNAL_GENERATOR_H
#define SIGNAL_GENERATOR_H

#include <fstream>
#include <string>

#include "../base/Generator.h"

class SignalGenerator : public Generator {
  private:
    CtrlSignal* signal;
    std::ifstream *ifs;
    std::string filename, signalName;
    unsigned size;
  public:
    SignalGenerator();
    ~SignalGenerator();
    void initialize() override;
    void handleMessage(omnetpp::cMessage*) override;
};

#endif