#ifndef BIPS32_INSTRUCTION_H
#define BIPS32_INSTRUCTION_H

#include "registers.h"
#include "types.h"
#include "cpu.h"

#define STEP(x) x->pc += 4

#define GET_INSTRUCTION(p, i) ((p[i] << 24) & 0xff000000) | ((p[i + 1] << 16) & 0xff0000) | ((p[i + 2] << 8) & 0xff00) | (p[i + 3] & 0xff)

#define GET_HWORD(p, i)     ((p[i] << 8) & 0xff00) | (p[i + 1] & 0xff)
#define GET_WORD(p, i)      GET_INSTRUCTION(p, i)

#define SET_HWORD(p, i, v)  p[i] = (v >> 8) & 0xff; p[i + 1] = v & 0xff
#define SET_WORD(p, i, v)   p[i] = (v >> 24) & 0xff; p[i + 1] = (v >> 16) & 0xff; p[i + 2] = (v >> 8) & 0xff; p[i+3] = v & 0xff

#define GET_OPCODE(x)       (x >> (BYTES(sizeof(word)) - 6))
#define GET_FUNCT(x)        (x & 0b111111)

#define GET_RS(x)           ((x >> (BYTES(sizeof(word)) - 11)) & 0b11111)
#define GET_RT(x)           ((x >> (BYTES(sizeof(word)) - 16)) & 0b11111)
#define GET_RD(x)           ((x >> (BYTES(sizeof(word)) - 21)) & 0b11111)
#define GET_SHAMT(x)        ((x >> (BYTES(sizeof(word)) - 26)) & 0b11111)

#define GET_IMMEDIATE(x)    (x & 0xffff)

#define GET_ADDRESS(x)      (x & 0x3ffffff)

typedef enum {
    R_TYPE = (word) 0,
    I_TYPE,
    J_TYPE
} InstructionType;

typedef void (*InstructionHandler)(CPU* cpu);

typedef struct {
    InstructionType type;
    byte code;
    char* mnemonic;
    InstructionHandler handler;
} InstructionInfo;

// instruction handlers
#define DEFINE_HANDLER(name) void name (CPU* cpu)

DEFINE_HANDLER(instr_handler_add);
DEFINE_HANDLER(instr_handler_addu);
DEFINE_HANDLER(instr_handler_addi);
DEFINE_HANDLER(instr_handler_addiu);

DEFINE_HANDLER(instr_handler_and);
DEFINE_HANDLER(instr_handler_andi);

DEFINE_HANDLER(instr_handler_div);
DEFINE_HANDLER(instr_handler_divu);

DEFINE_HANDLER(instr_handler_mult);
DEFINE_HANDLER(instr_handler_multu);

DEFINE_HANDLER(instr_handler_nor);
DEFINE_HANDLER(instr_handler_or);
DEFINE_HANDLER(instr_handler_ori);

DEFINE_HANDLER(instr_handler_sll);
DEFINE_HANDLER(instr_handler_sllv);
DEFINE_HANDLER(instr_handler_sra);
DEFINE_HANDLER(instr_handler_srav);
DEFINE_HANDLER(instr_handler_srl);
DEFINE_HANDLER(instr_handler_srlv);

DEFINE_HANDLER(instr_handler_sub);
DEFINE_HANDLER(instr_handler_subu);

DEFINE_HANDLER(instr_handler_xor);
DEFINE_HANDLER(instr_handler_xori);

DEFINE_HANDLER(instr_handler_lui);
DEFINE_HANDLER(instr_handler_lhi);
DEFINE_HANDLER(instr_handler_llo);

DEFINE_HANDLER(instr_handler_slt);
DEFINE_HANDLER(instr_handler_sltu);
DEFINE_HANDLER(instr_handler_slti);
DEFINE_HANDLER(instr_handler_sltiu);

DEFINE_HANDLER(instr_handler_beq);
DEFINE_HANDLER(instr_handler_bgtz);
DEFINE_HANDLER(instr_handler_blez);
DEFINE_HANDLER(instr_handler_bne);

DEFINE_HANDLER(instr_handler_j);
DEFINE_HANDLER(instr_handler_jal);
DEFINE_HANDLER(instr_handler_jalr);
DEFINE_HANDLER(instr_handler_jr);

DEFINE_HANDLER(instr_handler_lb);
DEFINE_HANDLER(instr_handler_lbu);
DEFINE_HANDLER(instr_handler_lh);
DEFINE_HANDLER(instr_handler_lhu);
DEFINE_HANDLER(instr_handler_lw);

DEFINE_HANDLER(instr_handler_sb);
DEFINE_HANDLER(instr_handler_sh);
DEFINE_HANDLER(instr_handler_sw);

DEFINE_HANDLER(instr_handler_mfhi);
DEFINE_HANDLER(instr_handler_mflo);
DEFINE_HANDLER(instr_handler_mthi);
DEFINE_HANDLER(instr_handler_mtlo);

DEFINE_HANDLER(instr_handler_syscall);

static const InstructionInfo INSTRUCTION_TABLE[] = {
    (InstructionInfo) {
        .code = 0b100000,
        .mnemonic = "add",
        .type = R_TYPE,
        .handler = instr_handler_add
    },
    (InstructionInfo) {
        .code = 0b100001,
        .mnemonic = "addu",
        .type = R_TYPE,
        .handler = instr_handler_addu
    },
    (InstructionInfo) {
        .code = 0b001000,
        .mnemonic = "addi",
        .type = I_TYPE,
        .handler = instr_handler_addi
    },
    (InstructionInfo) {
        .code = 0b001001,
        .mnemonic = "addiu",
        .type = I_TYPE,
        .handler = instr_handler_addiu
    },
    (InstructionInfo) {
        .code = 0b100100,
        .mnemonic = "and",
        .type = R_TYPE,
        .handler = instr_handler_and
    },
    (InstructionInfo) {
        .code = 0b001100,
        .mnemonic = "andi",
        .type = I_TYPE,
        .handler = instr_handler_andi
    },
    (InstructionInfo) {
        .code = 0b011010,
        .mnemonic = "div",
        .type = R_TYPE,
        .handler = instr_handler_div
    },
    (InstructionInfo) {
        .code = 0b011011,
        .mnemonic = "divu",
        .type = R_TYPE,
        .handler = instr_handler_divu
    },
    (InstructionInfo) {
        .code = 0b011000,
        .mnemonic = "mult",
        .type = R_TYPE,
        .handler = instr_handler_mult
    },
    (InstructionInfo) {
        .code = 0b011001,
        .mnemonic = "multu",
        .type = R_TYPE,
        .handler = instr_handler_multu
    },
    (InstructionInfo) {
        .code = 0b100111,
        .mnemonic = "nor",
        .type = R_TYPE,
        .handler = instr_handler_nor
    },
    (InstructionInfo) {
        .code = 0b100101,
        .mnemonic = "or",
        .type = R_TYPE,
        .handler = instr_handler_or
    },
    (InstructionInfo) {
        .code = 0b001101,
        .mnemonic = "ori",
        .type = I_TYPE,
        .handler = instr_handler_ori
    },
    (InstructionInfo) {
        .code = 0b000000,
        .mnemonic = "sll",
        .type = R_TYPE,
        .handler = instr_handler_sll
    },
    (InstructionInfo) {
        .code = 0b000100,
        .mnemonic = "sllv",
        .type = R_TYPE,
        .handler = instr_handler_sllv
    },
    (InstructionInfo) {
        .code = 0b000011,
        .mnemonic = "sra",
        .type = R_TYPE,
        .handler = instr_handler_sra
    },
    (InstructionInfo) {
        .code = 0b000111,
        .mnemonic = "srav",
        .type = R_TYPE,
        .handler = instr_handler_srav
    },
    (InstructionInfo) {
        .code = 0b000010,
        .mnemonic = "srl",
        .type = R_TYPE,
        .handler = instr_handler_srl
    },
    (InstructionInfo) {
        .code = 0b000110,
        .mnemonic = "srlv",
        .type = R_TYPE,
        .handler = instr_handler_srlv
    },
    (InstructionInfo) {
        .code = 0b100010,
        .mnemonic = "sub",
        .type = R_TYPE,
        .handler = instr_handler_sub
    },
    (InstructionInfo) {
        .code = 0b100011,
        .mnemonic = "subu",
        .type = R_TYPE,
        .handler = instr_handler_subu
    },
    (InstructionInfo) {
        .code = 0b100110,
        .mnemonic = "xor",
        .type = R_TYPE,
        .handler = instr_handler_xor
    },
    (InstructionInfo) {
        .code = 0b001110,
        .mnemonic = "xori",
        .type = I_TYPE,
        .handler = instr_handler_xori
    },
    (InstructionInfo) {
        .code = 0b001111,
        .mnemonic = "lui",
        .type = I_TYPE,
        .handler = instr_handler_lui
    },
    (InstructionInfo) {
        .code = 0b011001,
        .mnemonic = "lhi",
        .type = I_TYPE,
        .handler = instr_handler_lhi
    },
    (InstructionInfo) {
        .code = 0b011000,
        .mnemonic = "llo",
        .type = I_TYPE,
        .handler = instr_handler_llo
    },
    (InstructionInfo) {
        .code = 0b101010,
        .mnemonic = "slt",
        .type = R_TYPE,
        .handler = instr_handler_slt
    },
    (InstructionInfo) {
        .code = 0b101001,
        .mnemonic = "sltu",
        .type = R_TYPE,
        .handler = instr_handler_sltu
    },
    (InstructionInfo) {
        .code = 0b001010,
        .mnemonic = "slti",
        .type = I_TYPE,
        .handler = instr_handler_slti
    },
    (InstructionInfo) {
        .code = 0b001011,
        .mnemonic = "sltiu",
        .type = I_TYPE,
        .handler = instr_handler_sltiu
    },
    (InstructionInfo) {
        .code = 0b000100,
        .mnemonic = "beq",
        .type = I_TYPE,
        .handler = instr_handler_beq
    },
    (InstructionInfo) {
        .code = 0b000111,
        .mnemonic = "bgtz",
        .type = I_TYPE,
        .handler = instr_handler_bgtz
    },
    (InstructionInfo) {
        .code = 0b000110,
        .mnemonic = "blez",
        .type = I_TYPE,
        .handler = instr_handler_blez
    },
    (InstructionInfo) {
        .code = 0b000101,
        .mnemonic = "bne",
        .type = I_TYPE,
        .handler = instr_handler_bne
    },
    (InstructionInfo) {
        .code = 0b000010,
        .mnemonic = "j",
        .type = J_TYPE,
        .handler = instr_handler_j
    },
    (InstructionInfo) {
        .code = 0b000011,
        .mnemonic = "jal",
        .type = J_TYPE,
        .handler = instr_handler_jal
    },
    (InstructionInfo) {
        .code = 0b001001,
        .mnemonic = "jalr",
        .type = R_TYPE,
        .handler = instr_handler_jalr
    },
    (InstructionInfo) {
        .code = 0b001000,
        .mnemonic = "jr",
        .type = R_TYPE,
        .handler = instr_handler_jr
    },
    (InstructionInfo) {
        .code = 0b100000,
        .mnemonic = "lb",
        .type = I_TYPE,
        .handler = instr_handler_lb
    },
    (InstructionInfo) {
        .code = 0b100100,
        .mnemonic = "lbu",
        .type = I_TYPE,
        .handler = instr_handler_lbu
    },
    (InstructionInfo) {
        .code = 0b100001,
        .mnemonic = "lh",
        .type = I_TYPE,
        .handler = instr_handler_lh
    },
    (InstructionInfo) {
        .code = 0b100101,
        .mnemonic = "lhu",
        .type = I_TYPE,
        .handler = instr_handler_lhu
    },
    (InstructionInfo) {
        .code = 0b100011,
        .mnemonic = "lw",
        .type = I_TYPE,
        .handler = instr_handler_lw
    },
    (InstructionInfo) {
        .code = 0b101000,
        .mnemonic = "sb",
        .type = I_TYPE,
        .handler = instr_handler_sb
    },
    (InstructionInfo) {
        .code = 0b101001,
        .mnemonic = "sh",
        .type = I_TYPE,
        .handler = instr_handler_sh
    },
    (InstructionInfo) {
        .code = 0b101011,
        .mnemonic = "sw",
        .type = I_TYPE,
        .handler = instr_handler_sw
    },
    (InstructionInfo) {
        .code = 0b010000,
        .mnemonic = "mfhi",
        .type = R_TYPE,
        .handler = instr_handler_mfhi
    },
    (InstructionInfo) {
        .code = 0b010010,
        .mnemonic = "mflo",
        .type = R_TYPE,
        .handler = instr_handler_mflo
    },
    (InstructionInfo) {
        .code = 0b010001,
        .mnemonic = "mthi",
        .type = R_TYPE,
        .handler = instr_handler_mthi
    },
    (InstructionInfo) {
        .code = 0b010011,
        .mnemonic = "mtlo",
        .type = R_TYPE,
        .handler = instr_handler_mtlo
    },
    (InstructionInfo) {
        .code = 0b001100,
        .mnemonic = "syscall",
        .type = R_TYPE,
        .handler = instr_handler_syscall
    }
};

DEFINE_HANDLER(syscall_handler_dummy);

DEFINE_HANDLER(syscall_handler_print_int);
DEFINE_HANDLER(syscall_handler_print_float);
DEFINE_HANDLER(syscall_handler_print_string);
DEFINE_HANDLER(syscall_handler_exit);
DEFINE_HANDLER(syscall_handler_exit2);

static const InstructionHandler SYSCALL_TABLE[] = {
    syscall_handler_print_int,
    syscall_handler_print_float,
    syscall_handler_dummy,
    syscall_handler_print_string,
    syscall_handler_dummy,
    syscall_handler_dummy,
    syscall_handler_dummy,
    syscall_handler_dummy,
    syscall_handler_dummy,
    syscall_handler_exit,
    syscall_handler_dummy,
    syscall_handler_dummy,
    syscall_handler_dummy,
    syscall_handler_dummy,
    syscall_handler_dummy,
    syscall_handler_dummy,
    syscall_handler_exit2
};

#endif