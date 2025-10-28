#include "cpu.h"

BCPU* cpu_new(bword memsize) {
    BCPU* cpu = NEW(BCPU);

    cpu->memory_size = memsize;
    cpu->memory = ARRAY(bword, memsize);

    cpu->pc = RESET_VECTOR;
    cpu->epc = 0;
    cpu->cause = 0;
    cpu->badvaddr = 0;
    cpu->status = RESET_STATUS;
    cpu->hi = 0;
    cpu->lo = 0;

    return cpu;
}

InstructionInfo cpu_decode(BCPU* cpu) {
    bword instruction = cpu->memory[cpu->pc];
    bbyte opcode = GET_OPCODE(instruction);

    printf("decode (pc %x) %x, opcode %x\n", cpu->pc, instruction, opcode);

    return (InstructionInfo) {};
}

void cpu_step(BCPU* cpu) {

}