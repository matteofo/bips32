#ifndef BIPS32_INSTRUCTION_H
#define BIPS32_INSTRUCTION_H

#include "types.h"
#include "cpu.h"

#define GET_OPCODE(x) (x >> (sizeof(bword) * 8 - 6))

typedef enum {
    R_TYPE = (bword) 0,
    I_TYPE,
    J_TYPE
} InstructionType;

typedef void (*InstructionHandler)(BCPU* cpu);

typedef struct {
    InstructionType type;
    bword raw;
    InstructionHandler handler;
} InstructionInfo;

#endif