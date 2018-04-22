#ifndef COMBINATIONAL_MODULE_H
#define COMBINATIONAL_MODULE_H

#include <omnetpp.h>
#include <omnetpp/csimplemodule.h>

#include "../common/word_m.h"

class CombinationalModule : public omnetpp::cSimpleModule, public omnetpp::cListener {
  protected:
    /** @brief This is a self-message whose reception produces the emition of the output value
    */
    omnetpp::cMessage* delay;
    /** @brief Simulation time requiere to produce an output */
    omnetpp::simtime_t module_delay;
  public:
    /** @brief default constructor initializing the object attributes */
    CombinationalModule();
    /** @brief Initializes the object attributes*/
    virtual void initialize() override;
    /** @brief Receives a self-message producing the module outputs */
    virtual void handleMessage(omnetpp::cMessage*) override = 0;
    /** @brief Receives input values */
    virtual void receiveSignal(
      cComponent*, 
      omnetpp::simsignal_t, 
      cObject*, 
      cObject*) override = 0;
};

#endif