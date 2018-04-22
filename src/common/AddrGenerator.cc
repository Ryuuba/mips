#include "AddrGenerator.h"

Define_Module(AddressGenerator);

AddressGenerator::AddressGenerator() {
  address = nullptr;
  address_value = 0;
  kind = 0;
}

void AddressGenerator::initialize() {
  kind = int(par("msgKind"));
  if (kind < 2 || kind > 6) {
    error("Address Generator: msgKind out of range");
    endSimulation();
  }
  WATCH(address_value);
  Generator::initialize();
}

void AddressGenerator::handleMessage(omnetpp::cMessage* msg) {
  address_value = intuniform(0,31);
  address = new Address;
  address->setAddress(address_value);
  address->setKind(kind);
  send(address, "out");
  scheduleAt(omnetpp::simTime() + module_delay, delay);
  bubble((std::to_string(address_value).c_str()));
}

