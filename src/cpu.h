#ifndef BIPS32_CPU_H
#define BIPS32_CPU_H

#include <stdio.h>
#include <stdbool.h>
#include "types.h"
#include "registers.h"
#include "util.h"

#define RESET_VECTOR (word) 0x00008000
#define RESET_STATUS (word) 0x00000000

#define CPU_MEM_SIZE (word) 0xffffffff

typedef struct {
    word registers[NUM_REGISTERS];
    byte* memory;

    word pc;
    word epc;
    word cause;
    word badvaddr;
    word status;
    word hi;
    word lo;
} CPU;

#include "instruction.h"

CPU* cpu_new();

void cpu_decode(CPU* cpu, bool silent);
word cpu_step(CPU* cpu, bool silent);

#endif