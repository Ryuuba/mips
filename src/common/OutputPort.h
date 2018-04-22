#ifndef OUTPUT_PORT_H
#define OUTPUT_PORT_H

#include <omnetpp.h>
#include <omnetpp/csimplemodule.h>
#include <string>
#include <functional>

#include "addr_m.h"
#include "clock_signal_m.h"
#include "ctrl_signal_m.h"
#include "imm16_m.h"
#include "word_m.h"

class OutputPort : public omnetpp::cSimpleModule, public omnetpp::cListener {
  protected:
    omnetpp::simsignal_t genericSignal;
    std::string signalName;
    /** @brief The message kind is a number identifying a message 
     *  data value = 0; ctrl_signal = 1; clock_signal = 2; rs = 3;
     *  rt = 4; rd = 5; imm16 = 6
    */
    uint8_t msgKind;
    std::function<void(OutputPort&, cObject*)> sendMessage[5];
  protected:
    void sendAddress(cObject*);
    void sendClockSignal(cObject*);
    void sendCtrlSignal(cObject*);
    void sendImm16(cObject*);
    void sendWord(cObject*);
  public:
    OutputPort();
    ~OutputPort();
    void initialize() override;
    void handleMessage(omnetpp::cMessage*) override;
    void receiveSignal(
      cComponent*, 
      omnetpp::simsignal_t, 
      cObject*, 
      cObject*) override;
};

#endif
