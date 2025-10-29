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

DEFINE_HANDLER(instr_handler_sll) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);
    
    byte rd = GET_RD(instruction);
    byte rt = GET_RT(instruction);
    byte shamt = GET_SHAMT(instruction);

    cpu->registers[rd] = cpu->registers[rt] << shamt;
    STEP(cpu);
}

DEFINE_HANDLER(instr_handler_sllv) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);
    
    byte rs = GET_RT(instruction);
    byte rt = GET_RT(instruction);
    byte rd = GET_RD(instruction);

    cpu->registers[rd] = cpu->registers[rt] << cpu->registers[rs];

    STEP(cpu);
}

DEFINE_HANDLER(instr_handler_sra) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);
    
    byte rt = GET_RT(instruction);
    byte rd = GET_RD(instruction);
    byte shamt = GET_SHAMT(instruction);

    cpu->registers[rd] = (s_word) cpu->registers[rt] >> shamt;

    STEP(cpu);
}

DEFINE_HANDLER(instr_handler_srav) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);
    
    byte rt = GET_RT(instruction);
    byte rd = GET_RD(instruction);
    byte rs = GET_RS(instruction);
    byte shamt = GET_SHAMT(instruction);

    cpu->registers[rd] = (s_word) cpu->registers[rt] >> cpu->registers[rs];

    STEP(cpu);
}

DEFINE_HANDLER(instr_handler_srl) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);
    
    byte rt = GET_RT(instruction);
    byte rd = GET_RD(instruction);
    byte shamt = GET_SHAMT(instruction);

    cpu->registers[rd] = cpu->registers[rt] >> shamt;

    STEP(cpu);
}

DEFINE_HANDLER(instr_handler_srlv) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);
    
    byte rt = GET_RT(instruction);
    byte rd = GET_RD(instruction);
    byte rs = GET_RS(instruction);

    cpu->registers[rd] = cpu->registers[rt] >> cpu->registers[rs];

    STEP(cpu);
}

DEFINE_HANDLER(instr_handler_sub) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);
    
    byte rt = GET_RT(instruction);
    byte rd = GET_RD(instruction);
    byte rs = GET_RS(instruction);

    cpu->registers[rd] = (s_word) cpu->registers[rs] - (s_word) cpu->registers[rt];

    STEP(cpu);
}

DEFINE_HANDLER(instr_handler_subu) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);
    
    byte rt = GET_RT(instruction);
    byte rd = GET_RD(instruction);
    byte rs = GET_RS(instruction);

    cpu->registers[rd] = cpu->registers[rs] - cpu->registers[rt];

    STEP(cpu);
}

DEFINE_HANDLER(instr_handler_xor) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);
    
    byte rt = GET_RT(instruction);
    byte rd = GET_RD(instruction);
    byte rs = GET_RS(instruction);

    cpu->registers[rd] = cpu->registers[rs] ^ cpu->registers[rt];

    STEP(cpu);
}


DEFINE_HANDLER(instr_handler_xor) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);
    
    byte rd = GET_RD(instruction);
    byte rs = GET_RS(instruction);
    hword immediate = GET_IMMEDIATE(instruction);

    cpu->registers[rd] = cpu->registers[rs] ^ immediate;

    STEP(cpu);
}

DEFINE_HANDLER(instr_handler_lhi) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);
    
    byte rt = GET_RT(instruction);
    hword immediate = GET_IMMEDIATE(instruction);

    cpu->registers[rt] = (immediate << 16) | (cpu->registers[rt] & 0xffff);

    STEP(cpu);
}

DEFINE_HANDLER(instr_handler_llo) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);
    
    byte rt = GET_RT(instruction);
    hword immediate = GET_IMMEDIATE(instruction);

    cpu->registers[rt] = (cpu->registers[rt] & 0xffff0000) | (immediate);

    STEP(cpu);
}

DEFINE_HANDLER(instr_handler_slt) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);

    word rd = GET_RD(instruction);
    word rs = GET_RS(instruction);
    word rt = GET_RT(instruction);

    cpu->registers[rd] = (s_word) cpu->registers[rs] < (s_word) cpu->registers[rt];

    STEP(cpu);
}

DEFINE_HANDLER(instr_handler_sltu) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);

    word rd = GET_RD(instruction);
    word rs = GET_RS(instruction);
    word rt = GET_RT(instruction);

    cpu->registers[rd] = cpu->registers[rs] < cpu->registers[rt];

    STEP(cpu);
}

DEFINE_HANDLER(instr_handler_slti) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);

    word rs = GET_RS(instruction);
    word rt = GET_RT(instruction);
    hword immediate = GET_IMMEDIATE(instruction);

    cpu->registers[rt] = (s_word) cpu->registers[rs] < (s_word) immediate;

    STEP(cpu);
}

DEFINE_HANDLER(instr_handler_sltiu) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);

    word rs = GET_RS(instruction);
    word rt = GET_RT(instruction);
    s_hword immediate = GET_IMMEDIATE(instruction);

    cpu->registers[rt] = cpu->registers[rs] < immediate;

    STEP(cpu);
}

DEFINE_HANDLER(instr_handler_beq) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);

    word rs = GET_RS(instruction);
    word rt = GET_RT(instruction);
    s_hword immediate = GET_IMMEDIATE(instruction);

    if (cpu->registers[rs] == cpu->registers[rt]) {
        cpu->pc += immediate << 2;
    } else {
        STEP(cpu);
    }
}

DEFINE_HANDLER(instr_handler_bgtz) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);

    word rs = GET_RS(instruction);
    s_hword immediate = GET_IMMEDIATE(instruction);

    if ((s_word) cpu->registers[rs] > 0) {
        cpu->pc += immediate << 2;
    } else {
        STEP(cpu);
    }
}

DEFINE_HANDLER(instr_handler_blez) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);

    word rs = GET_RS(instruction);
    s_hword immediate = GET_IMMEDIATE(instruction);

    if ((s_word) cpu->registers[rs] <= 0) {
        cpu->pc += immediate << 2;
    } else {
        STEP(cpu);
    }
}

DEFINE_HANDLER(instr_handler_bne) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);

    word rs = GET_RS(instruction);
    word rt = GET_RT(instruction);
    s_hword immediate = GET_IMMEDIATE(instruction);

    if (cpu->registers[rs] != cpu->registers[rt]) {
        cpu->pc += immediate << 2;
    } else {
        STEP(cpu);
    }
}

// pc = high 4 bits of pc | address << 2 (instructions are word-aligned)
DEFINE_HANDLER(instr_handler_j) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);
    word address = GET_ADDRESS(instruction);

    cpu->pc = (cpu->pc & 0xf0000000) | (address << 2);
}

DEFINE_HANDLER(instr_handler_jal) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);
    word address = GET_ADDRESS(instruction);

    cpu->registers[REG_RA] = cpu->pc;
    cpu->pc = (cpu->pc & 0xf0000000) | (address << 2);
}

DEFINE_HANDLER(instr_handler_jalr) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);

    word rs = GET_RS(instruction);

    cpu->registers[REG_RA] = cpu->pc;
    cpu->pc = cpu->registers[rs];
}

DEFINE_HANDLER(instr_handler_jr) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);

    word rs = GET_RS(instruction);

    cpu->pc = cpu->registers[rs];
}

DEFINE_HANDLER(instr_handler_lb) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);
    
    word rt = GET_RT(instruction);
    word rs = GET_RS(instruction);
    s_hword immediate = GET_IMMEDIATE(instruction);

    s_word address = cpu->registers[rs] + immediate;

    cpu->registers[rt] = (s_word) ((s_byte) cpu->memory[address]);

    STEP(cpu);
}

DEFINE_HANDLER(instr_handler_lbu) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);
    
    word rt = GET_RT(instruction);
    word rs = GET_RS(instruction);
    s_hword immediate = GET_IMMEDIATE(instruction);

    s_word address = cpu->registers[rs] + immediate;

    cpu->registers[rt] = (word) (cpu->memory[address]);

    STEP(cpu);
}

DEFINE_HANDLER(instr_handler_lh) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);
    
    word rt = GET_RT(instruction);
    word rs = GET_RS(instruction);
    s_hword immediate = GET_IMMEDIATE(instruction);

    s_word address = cpu->registers[rs] + immediate;
    byte part1 = cpu->memory[address];
    byte part2 = cpu->memory[address + 1];

    cpu->registers[rt] = (s_word) ((s_hword) ((part1 << 8) | part2));

    STEP(cpu);
}

DEFINE_HANDLER(instr_handler_lhu) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);
    
    word rt = GET_RT(instruction);
    word rs = GET_RS(instruction);
    s_hword immediate = GET_IMMEDIATE(instruction);

    s_word address = cpu->registers[rs] + immediate;

    cpu->registers[rt] = (word) ((hword) GET_HWORD(cpu->memory, address));

    STEP(cpu);
}

DEFINE_HANDLER(instr_handler_lw) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);
    
    word rt = GET_RT(instruction);
    word rs = GET_RS(instruction);
    s_hword immediate = GET_IMMEDIATE(instruction);
    
    s_word address = cpu->registers[rs] + immediate;

    cpu->registers[rt] = (s_word) GET_WORD(cpu->memory, address);

    STEP(cpu);
}

DEFINE_HANDLER(instr_handler_sb) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);
    
    word rt = GET_RT(instruction);
    word rs = GET_RS(instruction);
    s_hword immediate = GET_IMMEDIATE(instruction);

    s_word address = cpu->registers[rs] + immediate;

    cpu->memory[address] = (word) cpu->registers[rt] & 0xff;

    STEP(cpu);
}


DEFINE_HANDLER(instr_handler_sh) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);
    
    word rt = GET_RT(instruction);
    word rs = GET_RS(instruction);
    s_hword immediate = GET_IMMEDIATE(instruction);

    s_word address = cpu->registers[rs] + immediate;

    cpu->memory[address] = (word) GET_HWORD(cpu->memory, address);

    STEP(cpu);
}

DEFINE_HANDLER(instr_handler_sw) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);
    
    word rt = GET_RT(instruction);
    word rs = GET_RS(instruction);
    s_hword immediate = GET_IMMEDIATE(instruction);

    s_word address = cpu->registers[rs] + immediate;

    cpu->memory[address] = GET_WORD(cpu->memory, address);

    STEP(cpu);
}

DEFINE_HANDLER(instr_handler_mfhi) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);

    word rd = GET_RD(instruction);

    cpu->registers[rd] = cpu->hi;

    STEP(cpu);
}

DEFINE_HANDLER(instr_handler_mflo) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);

    word rd = GET_RD(instruction);

    cpu->registers[rd] = cpu->lo;

    STEP(cpu);
}

DEFINE_HANDLER(instr_handler_mthi) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);

    word rs = GET_RS(instruction);

    cpu->registers[rs] = cpu->hi;

    STEP(cpu);
}

DEFINE_HANDLER(instr_handler_mtlo) {
    word instruction = GET_INSTRUCTION(cpu->memory, cpu->pc);

    word rs = GET_RS(instruction);

    cpu->registers[rs] = cpu->lo;

    STEP(cpu);
}