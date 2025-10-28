#ifndef BIPS32_INSTRUCTION_H
#define BIPS32_INSTRUCTION_H

#include "types.h"
#include "cpu.h"

#define GET_OPCODE(x) (x >> (BYTES(sizeof(bword)) - 6))
#define GET_FUNCT(x) (x & 0b111111)

#define GET_RS(x) ((x >> (BYTES(sizeof(bword)) - 6 - 5)) & 0b11111)
#define GET_RT(x) ((x >> (BYTES(sizeof(bword)) - 6 - 5 - 5)) & 0b11111)
#define GET_RD(x) ((x >> (BYTES(sizeof(bword)) - 6 - 5 - 5 - 5)) & 0b11111)
#define GET_SHAMT(x) ((x >> (BYTES(sizeof(bword)) - 6 - 5 - 5 - 5 - 5)) & 0b11111)


typedef enum {
    R_TYPE = (bword) 0,
    I_TYPE,
    J_TYPE
} InstructionType;

typedef void (*InstructionHandler)(BCPU* cpu);

typedef struct {
    InstructionType type;
    bbyte code;
    char* mnemonic;
    InstructionHandler handler;
} InstructionInfo;

static const InstructionInfo INSTRUCTION_TABLE[] = {
    (InstructionInfo) {
        .code = 0b100000,
        .mnemonic = "add",
        .type = R_TYPE
    },
    (InstructionInfo) {
        .code = 0b100001,
        .mnemonic = "addu",
        .type = R_TYPE
    },
    (InstructionInfo) {
        .code = 0b001000,
        .mnemonic = "addi",
        .type = I_TYPE
    },
    (InstructionInfo) {
        .code = 0b001001,
        .mnemonic = "addiu",
        .type = I_TYPE
    },
    (InstructionInfo) {
        .code = 0b001001,
        .mnemonic = "addiu",
        .type = I_TYPE
    },
    (InstructionInfo) {
        .code = 0b100100,
        .mnemonic = "and",
        .type = R_TYPE
    },
    (InstructionInfo) {
        .code = 0b001100,
        .mnemonic = "andi",
        .type = I_TYPE
    },
    (InstructionInfo) {
        .code = 0b011010,
        .mnemonic = "div",
        .type = R_TYPE
    },
    (InstructionInfo) {
        .code = 0b011011,
        .mnemonic = "divu",
        .type = R_TYPE
    },
    (InstructionInfo) {
        .code = 0b011000,
        .mnemonic = "mult",
        .type = R_TYPE
    },
    (InstructionInfo) {
        .code = 0b011001,
        .mnemonic = "multu",
        .type = R_TYPE
    },
    (InstructionInfo) {
        .code = 0b100111,
        .mnemonic = "nor",
        .type = R_TYPE
    },
    (InstructionInfo) {
        .code = 0b100101,
        .mnemonic = "or",
        .type = R_TYPE
    },
    (InstructionInfo) {
        .code = 0b001101,
        .mnemonic = "ori",
        .type = I_TYPE
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
        .code = 0b001001,
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
        .type = J_TYPE
    },
    (InstructionInfo) {
        .code = 0b000011,
        .mnemonic = "jal",
        .type = J_TYPE
    },
    (InstructionInfo) {
        .code = 0b001001,
        .mnemonic = "jalr",
        .type = J_TYPE
    },
    (InstructionInfo) {
        .code = 0b001000,
        .mnemonic = "jr",
        .type = J_TYPE
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