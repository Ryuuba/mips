#include "SignalGenerator.h"

Define_Module(SignalGenerator);

SignalGenerator::SignalGenerator() {
  signal = nullptr;
  ifs = nullptr;
}

SignalGenerator::~SignalGenerator(){
  if (delay) {
    cancelAndDelete(delay);
    delay = nullptr;
  }
  if (ifs) {
    delete ifs;
    ifs = nullptr;
  }
}

void SignalGenerator::initialize(){
  filename = par("trace").stringValue();
  ifs = new std::ifstream(filename.c_str());
  if (ifs->is_open()) {
    size = unsigned(par("size"));
    signalName = par("signalName").stringValue();
    Generator::initialize();
  }
  else {
    error("Trace file not found\n");
    endSimulation();
  }
}

void SignalGenerator::handleMessage(omnetpp::cMessage* msg){
  std::string text;
  bool signal_value;
  signal = new CtrlSignal(signalName.c_str());
  signal->setSignalArraySize(size);
  for (unsigned i = 0; i < size; i++) {
    if (*ifs >> signal_value) {
      signal->setSignal(size-i-1, signal_value);
      text += std::to_string(int(signal_value));
    }
    else {
      EV << "No more values in trace " << filename << '\n';
      ifs->close();
      endSimulation();
    }
  }
  signal->setKind(1);
  send(signal, "out");
  scheduleAt(omnetpp::simTime() + module_delay, msg);
  bubble(text.c_str());
}