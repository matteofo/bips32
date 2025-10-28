#ifndef BIPS32_INSTRUCTION_H
#define BIPS32_INSTRUCTION_H

#include "registers.h"
#include "types.h"
#include "cpu.h"

#define STEP(x) x->pc += 4

#define GET_INSTRUCTION(p, i)  ((p[i] << 24) & 0xff000000) | ((p[i + 1] << 16) & 0xff0000) | ((p[i + 2] << 8) & 0xff00) | (p[i + 3] & 0xff)
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

DEFINE_HANDLER(instr_handler_j);

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
        .type = R_TYPE
    },
    (InstructionInfo) {
        .code = 0b000100,
        .mnemonic = "sllv",
        .type = R_TYPE
    },
    (InstructionInfo) {
        .code = 0b000011,
        .mnemonic = "sra",
        .type = R_TYPE
    },
    (InstructionInfo) {
        .code = 0b000111,
        .mnemonic = "srav",
        .type = R_TYPE
    },
    (InstructionInfo) {
        .code = 0b000010,
        .mnemonic = "srl",
        .type = R_TYPE
    },
    (InstructionInfo) {
        .code = 0b000110,
        .mnemonic = "srlv",
        .type = R_TYPE
    },
    (InstructionInfo) {
        .code = 0b100010,
        .mnemonic = "sub",
        .type = R_TYPE
    },
    (InstructionInfo) {
        .code = 0b100011,
        .mnemonic = "subu",
        .type = R_TYPE
    },
    (InstructionInfo) {
        .code = 0b100110,
        .mnemonic = "xor",
        .type = R_TYPE
    },
    (InstructionInfo) {
        .code = 0b001110,
        .mnemonic = "xori",
        .type = I_TYPE
    },
    (InstructionInfo) {
        .code = 0b011001,
        .mnemonic = "lhi",
        .type = I_TYPE
    },
    (InstructionInfo) {
        .code = 0b011000,
        .mnemonic = "llo",
        .type = I_TYPE
    },
    (InstructionInfo) {
        .code = 0b101010,
        .mnemonic = "slt",
        .type = R_TYPE
    },
    (InstructionInfo) {
        .code = 0b101001,
        .mnemonic = "sltu",
        .type = R_TYPE
    },
    (InstructionInfo) {
        .code = 0b001010,
        .mnemonic = "slti",
        .type = I_TYPE
    },
    (InstructionInfo) {
        .code = 0b001011,
        .mnemonic = "sltiu",
        .type = I_TYPE
    },
    (InstructionInfo) {
        .code = 0b000100,
        .mnemonic = "beq",
        .type = J_TYPE
    },
    (InstructionInfo) {
        .code = 0b000111,
        .mnemonic = "bgtz",
        .type = J_TYPE
    },
    (InstructionInfo) {
        .code = 0b000110,
        .mnemonic = "blez",
        .type = J_TYPE
    },
    (InstructionInfo) {
        .code = 0b000101,
        .mnemonic = "bne",
        .type = J_TYPE
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
        .type = J_TYPE
    },
    (InstructionInfo) {
        .code = 0b001001,
        .mnemonic = "jalr",
        .type = R_TYPE
    },
    (InstructionInfo) {
        .code = 0b001000,
        .mnemonic = "jr",
        .type = R_TYPE
    },
    (InstructionInfo) {
        .code = 0b100000,
        .mnemonic = "lb",
        .type = I_TYPE
    },
    (InstructionInfo) {
        .code = 0b100100,
        .mnemonic = "lbu",
        .type = I_TYPE
    },
    (InstructionInfo) {
        .code = 0b100001,
        .mnemonic = "lh",
        .type = I_TYPE
    },
    (InstructionInfo) {
        .code = 0b100101,
        .mnemonic = "lhu",
        .type = I_TYPE
    },
    (InstructionInfo) {
        .code = 0b100011,
        .mnemonic = "lw",
        .type = I_TYPE
    },
    (InstructionInfo) {
        .code = 0b101000,
        .mnemonic = "sb",
        .type = I_TYPE
    },
    (InstructionInfo) {
        .code = 0b101001,
        .mnemonic = "sh",
        .type = I_TYPE
    },
    (InstructionInfo) {
        .code = 0b101011,
        .mnemonic = "sw",
        .type = I_TYPE
    },
    (InstructionInfo) {
        .code = 0b010000,
        .mnemonic = "mfhi",
        .type = R_TYPE
    },
    (InstructionInfo) {
        .code = 0b010010,
        .mnemonic = "mflo",
        .type = R_TYPE
    },
    (InstructionInfo) {
        .code = 0b010001,
        .mnemonic = "mthi",
        .type = R_TYPE
    },
    (InstructionInfo) {
        .code = 0b010011,
        .mnemonic = "mtlo",
        .type = R_TYPE
    }
};

#endif