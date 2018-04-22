#ifndef INPUT_PORT_H
#define INPUT_PORT_H

#include <omnetpp.h>
#include <omnetpp/csimplemodule.h>
#include <string>

#include "addr_m.h"
#include "clock_signal_m.h"
#include "ctrl_signal_m.h"
#include "imm16_m.h"
#include "word_m.h"

class InputPort : public omnetpp::cSimpleModule {
  protected:
    /** @brief This signal conveys the value of a mips msg */
    omnetpp::simsignal_t genericSignal;
    std::string signalName;
    /** @brief The message kind is a number identifying a message 
     *  data value = 0; ctrl_signal = 1; clock_signal = 2; rs = 3;
     *  rt = 4; rd = 5; imm16 = 6
    */
    uint8_t msgKind;
  public:
    void initialize() override;
    void handleMessage(omnetpp::cMessage*) override;
};


#endif