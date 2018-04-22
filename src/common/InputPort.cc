#include "InputPort.h"

Define_Module(InputPort);

void InputPort::initialize() {
  signalName = par("signalName").stringValue();
  genericSignal = registerSignal(signalName.c_str());
  msgKind = int(par("msgKind"));
}

void InputPort::handleMessage(omnetpp::cMessage* msg) {
  emit(genericSignal, msg);
}