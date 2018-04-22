#ifndef ADDER_H
#define ADDER_H

#include <omnetpp.h>
#include <omnetpp/csimplemodule.h>
#include <cstdint>
#include <string>
#include "../common/word_m.h"

class Adder : public omnetpp::cSimpleModule {
  private:
    /** @brief a + b = result */
    int32_t a, b;
    /** @brief module delay */
    omnetpp::simtime_t module_delay;
    /** @brief input ports */
    omnetpp::cGate* port_a, *port_b;
    /** @brief Time required to compute a sum */
    omnetpp::cMessage* delay;
    /** @brief Signal conveying  r = a + b */
    Word* result;
  public:
    Adder();
    ~Adder();
    virtual void initialize() override;
    /** @brief when a message is received, this function computes the addition 
     * a + b = res as well as the output carry
     * */
    virtual void handleMessage(omnetpp::cMessage*) override;
};

#endif
