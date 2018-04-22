#include "Indicator.h"

Define_Module(Indicator);

void Indicator::initialize() {
  EV << "Initializing . . .\n";
  WATCH(value);
}

void Indicator::handleMessage(omnetpp::cMessage* msg) {
  std::string text;
  Rformat r_instr;
  Jformat j_instr;
  Iformat i_instr;
  
  word = reinterpret_cast<Word*>(msg);
  value = word->getData();
  if (word->getInstructionFlag())
    switch (word->getInstructionType()) {
      case R:
        r_instr.decode(word->getData());
        text = '<' + std::to_string(r_instr.opcode) + ", " 
                   + std::to_string(r_instr.rs) + ", "
                   + std::to_string(r_instr.rt) + ", "
                   + std::to_string(r_instr.rd) + ", "
                   + std::to_string(r_instr.shamnt) + ", "
                   + std::to_string(r_instr.function) + ">";
        break;
      case I:
        i_instr.decode(word->getData());
        text = '<' + std::to_string(i_instr.opcode) + ", " 
                   + std::to_string(i_instr.rs) + ", "
                   + std::to_string(i_instr.rt) + ", "
                   + std::to_string(i_instr.imm16) + ">";
        break;
      default:
        j_instr.decode(word->getData());
        text = '<' + std::to_string(j_instr.opcode) + ", " 
                   + std::to_string(j_instr.pseudoAddress) + ">";
        break;
    }
  else 
    text = std::to_string(value);
  EV << "Word value: " << value << '\n';
  bubble(text.c_str());
  if (msg) {
    delete msg;
    msg = nullptr;
  }
}
