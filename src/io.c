#include "io.h"

void io_load_program(BCPU* cpu, bword* program, bword size) {
    for (bword i = 0; i < size; i++) {
        cpu->memory[RESET_VECTOR + i] = program[i];
    }
}