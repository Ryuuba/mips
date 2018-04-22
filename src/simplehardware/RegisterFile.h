#ifndef REGISTER_FILE_H
#define REGISTER_FILE_H

#include <omnetpp.h>
#include <omnetpp/csimplemodule.h>
#include <array>

#include "../base/SequentialModule.h"
#include "../common/ctrl_signal_m.h"
#include "../common/addr_m.h"

class RegisterFile : public SequentialModule {
  protected:
    std::array<int32_t, 32> reg;
    int32_t data_input, rs, rt;
    uint8_t rt_addr, rs_addr, dest_addr;
    bool regWrite;
  public:
    RegisterFile();
    void initialize() override;
    void handleMessage(omnetpp::cMessage*) override;
    virtual void receiveSignal(
      cComponent*, 
      omnetpp::simsignal_t, 
      cObject*, 
      cObject*) override;
};


#endif