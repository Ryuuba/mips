#ifndef INSTRUCTION_FORMAT_H
#define INSTRUCTION_FORMAT_H

#include <cstdint>

struct Rformat {
  uint8_t opcode, rs, rt, rd, shamnt, function;
  void decode(uint32_t);
};

struct Iformat {
  uint8_t opcode, rs, rt;
  uint16_t imm16;
  void decode(uint32_t);
};

struct Jformat {
  uint8_t opcode;
  uint32_t pseudoAddress;
  void decode(uint32_t);
};

void Rformat::decode(uint32_t word) {
  opcode = (word & 0xFC000000) >> 26;
  rs = (word & 0x03E00000) >> 21;
  rt = (word & 0x001F0000) >> 16;
  rd = (word & 0x0000F800) >> 11;
  shamnt = (word & 0x000007C0) >> 6;
  function = (word & 0x0000003F);
}

void Iformat::decode(uint32_t word) {
  opcode = (word & 0xFC000000) >> 26;
  rs = (word & 0x03E00000) >> 21;
  rt = (word & 0x001F0000) >> 16;
  imm16 = word & 0x0000FFFF;
}

void Jformat::decode(uint32_t word){
  opcode = (word & 0xFC000000) >> 26;
  pseudoAddress = word & 0x03FFFFFF;
}

#endif