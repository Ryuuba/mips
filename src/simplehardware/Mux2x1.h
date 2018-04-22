#ifndef MUX2X1_H
#define MUX2X1_H

#include <omnetpp.h>
#include <omnetpp/csimplemodule.h>
#include <cstdint>
#include <string>
#include "../common/word_m.h"
#include "../common/ctrl_signal_m.h"

class Mux2x1 : public omnetpp::cSimpleModule {
  private:
    /** @brief data input */
    int32_t a, b;
    /** @brief selector */
    bool selector;
    /** @brief module delay */
    omnetpp::simtime_t module_delay;
    /** @brief input ports */
    omnetpp::cGate* port_a, *port_b;
    /** @brief output ports */
    omnetpp::cGate* port_f;
    /** @brief Time requiered by the module to process signal */
    omnetpp::cMessage* delay;
    /** @brief output value */
    Word* out_value;
  public:
    Mux2x1();
    ~Mux2x1();
    void initialize() override;
    void handleMessage(omnetpp::cMessage*) override;
};

#endif