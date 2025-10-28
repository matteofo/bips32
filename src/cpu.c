#include "cpu.h"

BCPU* cpu_new() {
    BCPU* cpu = NEW(BCPU);

    cpu->memory = ARRAY(bword, CPU_MEM_SIZE);

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
    InstructionInfo info;

    bword instruction = cpu->memory[cpu->pc];
    bbyte opcode = GET_OPCODE(instruction);

    printf("[pc %x]: " WORD_TO_BINARY_PATTERN ", " BYTE_TO_BINARY_PATTERN " ",
        cpu->pc, 
        WORD_TO_BINARY(instruction),
        BYTE_TO_BINARY(opcode)
    );

    // R-types all have zero opcodes
    // all other instructions are either I-types or J-types
    if (opcode == 0) {
        bbyte funct = GET_FUNCT(instruction);

        // ts is slow asf but i don't really know how else to index them
        for EACH(i, INSTRUCTION_TABLE) {
            const InstructionInfo _info = INSTRUCTION_TABLE[i];
            if (_info.type == R_TYPE && funct == _info.code) {
                bbyte rs = GET_RS(instruction);
                bbyte rt = GET_RT(instruction);
                bbyte rd = GET_RD(instruction);
                bbyte shamt = GET_SHAMT(instruction);

                printf("%s $%u, $%u, $%u", _info.mnemonic, rd, rs, rt);

                if (shamt) {
                    printf(", %u", shamt);
                }

                break;
            }
        }
    } else {

    }

    printf("\n");
    return info;
}

bword cpu_step(BCPU* cpu) {
    InstructionInfo info = cpu_decode(cpu);
    cpu->pc++;
    
    return cpu->pc;
}