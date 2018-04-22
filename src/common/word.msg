cplusplus {{
#include <cstdint>
}}

enum InstructionType {
  R = 0;
  I = 1;
  J = 2;
};

message Word {
  int32_t data;
  bool instructionFlag;
  uint8_t instructionType @enum(InstructionType);
};
