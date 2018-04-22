#ifndef REGISTER_H
#define REGISTER_H

#include <string>

#include "../base/SequentialModule.h"
#include "../common/ctrl_signal_m.h"

class Register : public SequentialModule {
  private:
    /** @brief d-input value */
    int32_t d;
    /** @brief Memory value */
    int32_t state;
    /** @brief Control signal enabling the overwritting of the state */
    bool enable;
    /** @brief Names of the signals that this module receives */
    std::string d_port, q_port, clk_port, enable_port;
    /** @brief Signal carrying the q value */
    omnetpp::simsignal_t q_value;
  public:
    /** @brief Initializes object attributes*/
    Register();
    /** @brief Unsubscribes this module of all input signals */
    ~Register();
    virtual void initialize() override;
    virtual void handleMessage(omnetpp::cMessage*) override;
    virtual void receiveSignal(
      cComponent*, 
      omnetpp::simsignal_t, 
      cObject*, 
      cObject*) override;
};

#endif