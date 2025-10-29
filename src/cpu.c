#include "cpu.h"

CPU* cpu_new() {
    CPU* cpu = NEW(CPU);

    // init registers in memory
    for (byte i = 0; i < NUM_REGISTERS; i++) {
        cpu->registers[i] = 0;
    }
    
    cpu->memory = ARRAY(byte, CPU_MEM_SIZE);

    cpu->pc = RESET_VECTOR;
    cpu->epc = 0;
    cpu->cause = 0;
    cpu->badvaddr = 0;
    cpu->status = RESET_STATUS;
    cpu->hi = 0;
    cpu->lo = 0;

    return cpu;
}

void _instr_run(CPU* cpu, InstructionInfo info) {
    if (!info.handler) {
        printf("(%s unimplemented) ", info.mnemonic);
        STEP(cpu);
        return;
    }

    info.handler(cpu);
    printf("(%s) ", info.mnemonic);
}

// decodes a cpu instruction and runs it
void cpu_decode(CPU* cpu) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);
    byte opcode = GET_OPCODE(instruction);

    //printf("[pc %x]: " WORD_TO_BINARY_PATTERN ", " BYTE_TO_BINARY_PATTERN " ",
    //    cpu->pc, 
    //    WORD_TO_BINARY(instruction),
    //    BYTE_TO_BINARY(opcode)
    //);

    printf("[pc %x]: %x ", cpu->pc, instruction);

    // R-types all have zero opcodes
    // all other instructions are either I-types or J-types
    if (opcode == 0) {
        byte funct = GET_FUNCT(instruction);

        // ts is slow asf but i don't really know how else to index them
        for EACH(i, INSTRUCTION_TABLE) {
            const InstructionInfo info = INSTRUCTION_TABLE[i];
            if (info.type == R_TYPE && funct == info.code) {
                // run instruction
                _instr_run(cpu, info);
                return;
            }
        }
    } else {
        for EACH(i, INSTRUCTION_TABLE) {
            const InstructionInfo info = INSTRUCTION_TABLE[i];
            if (info.type != R_TYPE && opcode == info.code) {
                _instr_run(cpu, info);
                return;
            }
        }
    }

    STEP(cpu);
}

word cpu_step(CPU* cpu) {
    cpu_decode(cpu);
    
    return cpu->pc;
}