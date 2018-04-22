#ifndef ADDR_GENERATOR_H
#define ADDR_GENERATOR_H

#include "addr_m.h"
#include "../base/Generator.h"

class AddressGenerator : public Generator {
  private:
    Address* address;
    uint8_t address_value;
    short kind;
  public:
    AddressGenerator();
    void initialize() override;
    void handleMessage(omnetpp::cMessage*) override;
};


#endif