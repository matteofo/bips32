#include "instruction.h"

// rd = rs + rt
DEFINE_HANDLER(instr_handler_add) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);
    
    byte rs = GET_RS(instruction);
    byte rt = GET_RT(instruction);
    byte rd = GET_RD(instruction);

    cpu->registers[rd] = (s_word) cpu->registers[rs] + (s_word) cpu->registers[rt];
    STEP(cpu);
}

// rd = rs + rt (unsigned)
DEFINE_HANDLER(instr_handler_addu) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);
    
    byte rs = GET_RS(instruction);
    byte rt = GET_RT(instruction);
    byte rd = GET_RD(instruction);

    cpu->registers[rd] = cpu->registers[rs] + cpu->registers[rt];
    STEP(cpu);
}

// rt = rs + immediate
DEFINE_HANDLER(instr_handler_addi) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);

    byte rs = GET_RS(instruction);
    byte rt = GET_RT(instruction);
    s_hword immediate = GET_IMMEDIATE(instruction);

    cpu->registers[rt] = (s_word) cpu->registers[rs] + immediate;
    STEP(cpu);
}

// rt = rs + immediate (unsigned)
DEFINE_HANDLER(instr_handler_addiu) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);

    word rs = GET_RS(instruction);
    word rt = GET_RT(instruction);
    hword immediate = GET_IMMEDIATE(instruction);

    cpu->registers[rt] = cpu->registers[rs] + immediate;
    STEP(cpu);
}

// rd = rs & rt
DEFINE_HANDLER(instr_handler_and) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);
    
    byte rs = GET_RS(instruction);
    byte rt = GET_RT(instruction);
    byte rd = GET_RD(instruction);

    cpu->registers[rd] = cpu->registers[rs] & cpu->registers[rt];
    STEP(cpu);
}

// rt = rs & immediate
DEFINE_HANDLER(instr_handler_andi) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);

    byte rs = GET_RS(instruction);
    byte rt = GET_RT(instruction);
    hword immediate = GET_IMMEDIATE(instruction);

    cpu->registers[rt] = cpu->registers[rs] & immediate;
    STEP(cpu);
}

// lo = rs / rt
// hi = rs % rt
DEFINE_HANDLER(instr_handler_div) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);
    
    byte rs = GET_RS(instruction);
    byte rt = GET_RT(instruction);
    byte rd = GET_RD(instruction);

    cpu->lo = (s_word) cpu->registers[rs] / (s_word) cpu->registers[rt];
    cpu->hi = (s_word) cpu->registers[rs] % (s_word) cpu->registers[rt];
    STEP(cpu);
}

// lo = rs / rt (unsigned)
// hi = rs % rt (unsigned)
DEFINE_HANDLER(instr_handler_divu) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);
    
    byte rs = GET_RS(instruction);
    byte rt = GET_RT(instruction);
    byte rd = GET_RD(instruction);

    cpu->lo = cpu->registers[rs] / cpu->registers[rt];
    cpu->hi = cpu->registers[rs] % cpu->registers[rt];
    STEP(cpu);
}

// hi = rs * rt (higher 32 bits)
// lo = rs * rt (lower 32 bits)
DEFINE_HANDLER(instr_handler_mult) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);
    
    byte rs = GET_RS(instruction);
    byte rt = GET_RT(instruction);
    byte rd = GET_RD(instruction);

    s_dword result = (s_dword) cpu->registers[rs] * (s_dword) cpu->registers[rt];
    cpu->hi = (result >> 32) & 0xffffffff;
    cpu->lo = result & 0xffffffff;
    STEP(cpu);
}

// hi = rs * rt (higher 32 bits, unsigned)
// lo = rs * rt (lower 32 bits, unsigned)
DEFINE_HANDLER(instr_handler_multu) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);
    
    byte rs = GET_RS(instruction);
    byte rt = GET_RT(instruction);
    byte rd = GET_RD(instruction);

    dword result = (dword) cpu->registers[rs] * (dword) cpu->registers[rt];
    cpu->hi = (result >> 32) & 0xffffffff;
    cpu->lo = result & 0xffffffff;
    STEP(cpu);
}

// rd = ~(rs | rt)
DEFINE_HANDLER(instr_handler_nor) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);
    
    byte rs = GET_RS(instruction);
    byte rt = GET_RT(instruction);
    byte rd = GET_RD(instruction);

    cpu->registers[rd] = ~(cpu->registers[rs] | cpu->registers[rt]);
    STEP(cpu);
}

// rd = rs | rt
DEFINE_HANDLER(instr_handler_or) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);

    byte rs = GET_RS(instruction);
    byte rt = GET_RT(instruction);
    byte rd = GET_RD(instruction);

    cpu->registers[rd] = cpu->registers[rs] | cpu->registers[rt];
    STEP(cpu);
}

// rt = rs | immediate
DEFINE_HANDLER(instr_handler_ori) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);

    byte rs = GET_RS(instruction);
    byte rt = GET_RT(instruction);
    hword immediate = GET_IMMEDIATE(instruction);

    cpu->registers[rt] = cpu->registers[rs] | immediate;
    STEP(cpu);
}

// pc = high 4 bits of pc | address << 2 (instructions are word-aligned)
DEFINE_HANDLER(instr_handler_j) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);
    word address = GET_ADDRESS(instruction);

    cpu->pc = (cpu->pc & 0xf0000000) | (address << 2);
}