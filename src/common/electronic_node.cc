#include "electronic_node.h"

Define_Module(ElectronicNode);

void ElectronicNode::initialize() {
  outGateNumber = par("outGateNumber");
}

void ElectronicNode::handleMessage(omnetpp::cMessage* msg){
  Word* word;
  CtrlSignal* ctrl;
  ClockSignal* clk;
  int outGateBaseId = gateBaseId("out");
  for (uint8_t i = 0; i < outGateNumber; i++) {
    switch (msg->getKind()) {
      case 0:
        word = reinterpret_cast<Word*>(msg->dup());
        send(word, "out", i);
        break;
      case 1:
        ctrl = reinterpret_cast<CtrlSignal*>(msg->dup());
        send(ctrl, "out", i);
        break;
      case 2:
        clk = reinterpret_cast<ClockSignal*>(msg->dup());
        send(clk, "out", i);
        break;
    }
  }
  delete msg;
}