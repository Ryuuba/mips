#ifndef INDICATOR_H
#define INDICATOR_H

#include <omnetpp.h>
#include <omnetpp/csimplemodule.h>
#include <string>

#include "word_m.h"
#include "instruction_format.h"

class Indicator : public omnetpp::cSimpleModule {
private:
  int32_t value;
  Word* word;
public:
  void initialize() override;
  void handleMessage(omnetpp::cMessage*) override;
};

#endif
