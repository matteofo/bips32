#ifndef BIPS32_CPU_H
#define BIPS32_CPU_H

#include <stdio.h>
#include "types.h"
#include "registers.h"

#define RESET_VECTOR (bword) 0xbfc00000
#define RESET_STATUS (bword) 0x00000000

#define CPU_MEM_SIZE (bword) 0xffffffff

typedef struct {
    bword registers[NUM_REGISTERS];
    bword* memory;

    bword pc;
    bword epc;
    bword cause;
    bword badvaddr;
    bword status;
    bword hi;
    bword lo;
} BCPU;

#include "util.h"
#include "instruction.h"

BCPU* cpu_new();

InstructionInfo cpu_decode(BCPU* cpu);
bword cpu_step(BCPU* cpu);

#endif