#ifndef NUMBER_GENERATOR_H
#define NUMBER_GENERATOR_H

#include "../base/Generator.h"

class NumberGenerator : public Generator {
private:
  Word* number;
  int lower_limit, upper_limit;
  int32_t rnd;
public:
  NumberGenerator();
  ~NumberGenerator();
  void initialize() override;
  void handleMessage(omnetpp::cMessage*) override;
};

#endif
