#include "../simplehardware/Mux2x1.h"

Define_Module(Mux2x1);

Mux2x1::Mux2x1(){
  a = 0;
  b = 0;
  selector = 0;
  module_delay = 0.0;
  port_a = nullptr;
  port_b = nullptr;
  port_f = nullptr;
  delay = nullptr;
  out_value = nullptr;
}

Mux2x1::~Mux2x1(){
  if (delay) {
    std::cout << "Mux2x1: delete delay\n";
    cancelAndDelete(delay);
    delay = nullptr;
  }
}

void Mux2x1::initialize() {
  module_delay = par("module_delay");
  port_a = gate("portA");
  port_b = gate("portB");
  port_f = gate("portF");
  delay = new omnetpp::cMessage("module_delay");
}

void Mux2x1::handleMessage(omnetpp::cMessage* msg) {
  static Word* operand;
  static CtrlSignal* sel;
  std::string text = "output = ";
  if (msg->isSelfMessage()) {
    out_value = new Word();
    if (!selector) {
      out_value->setData(a);
      text += std::to_string(a);
    }
    else {
      out_value->setData(b);
      text += std::to_string(b);
    }
    out_value->setInstructionFlag(false);
    send(out_value, "portF");
    bubble(text.c_str());
  }
  else if (msg->getKind() == 0) { //a data arrived
    operand = reinterpret_cast<Word*>(msg);
    if (msg->getArrivalGateId() == port_a->getId()) {
      a = operand->getData();
      EV << "new data arrives from port a\n";
    }
    else {
      b = operand->getData();
      EV << "new data arrives from port b\n";
    }
    delete msg;
    if (!delay->isScheduled())
      scheduleAt(omnetpp::simTime() + module_delay, delay);
  }
  else { //a control signal arrived
    sel = reinterpret_cast<CtrlSignal*>(msg);
    selector = sel->getSignal(0);
    EV << "selector value has changed\n";
    delete msg;
    if (!delay->isScheduled())
      scheduleAt(omnetpp::simTime() + module_delay, delay);
  }
}



