#include "io.h"

void io_load_program(CPU* cpu, word* program, word size) {
    // write to memory, word-aligned
    word* mem = (word*) cpu->memory;
    for (word i = 0; i < size; i++) {
        mem[RESET_VECTOR + i] = bswap32(program[i]);
    }
}