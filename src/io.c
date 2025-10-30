#include "io.h"

void io_load_program(CPU* cpu, word* program, word size) {
    assert(cpu != NULL);
    assert(program != NULL);
    
    // write to memory, word-aligned
    word* mem = (word*) cpu->memory;
    for (word i = 0; i < size; i++) {
        mem[i] = bswap32(program[i]);
    }
}