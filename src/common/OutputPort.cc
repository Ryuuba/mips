#include "OutputPort.h"

Define_Module(OutputPort);

OutputPort::OutputPort() {
  sendMessage[0] = &OutputPort::sendWord;
  sendMessage[1] = &OutputPort::sendCtrlSignal;
  sendMessage[2] = &OutputPort::sendClockSignal;
  sendMessage[3] = &OutputPort::sendAddress;
  sendMessage[4] = &OutputPort::sendImm16;
}

OutputPort::~OutputPort() {
  unsubscribe(signalName.c_str(), this);
}

void OutputPort::sendAddress(cObject* obj) {
  send(reinterpret_cast<Address*>(obj), "out");
}

void OutputPort::sendClockSignal(cObject* obj) {
  send(reinterpret_cast<ClockSignal*>(obj), "out");
}

void OutputPort::sendCtrlSignal(cObject* obj) {
  send(reinterpret_cast<CtrlSignal*>(obj), "out");
}

void OutputPort::sendImm16(cObject* obj) {
  send(reinterpret_cast<Imm16*>(obj), "out");
}

void OutputPort::sendWord(cObject* obj) {
  send(reinterpret_cast<Word*>(obj), "out");
}

void OutputPort::initialize() {
  signalName = par("signalName").stringValue();
  //Signal emitted by hardware components will be listened by 
  //this module
  getParentModule()->subscribe(signalName.c_str(), this);
  msgKind = int(par("msgKind"));
}

void OutputPort::receiveSignal(cComponent *src, omnetpp::simsignal_t id, cObject *obj, cObject *details) {
  sendMessage[msgKind](*this, obj);
}

void OutputPort::handleMessage(omnetpp::cMessage* msg){
  error("Output port: this module doesn't receive any kind of messages");
}