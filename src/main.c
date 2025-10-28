#include <stdio.h>
#include <stdbool.h>
#include "cpu.h"
#include "io.h"

bword load_program_from_file(char* path, bword* program) {
    // read program from file
    FILE* f = fopen(path, "rb");

    fseek(f, 0, SEEK_END);
    long size = ftell(f);

    rewind(f);

    program = ARRAY(bword, size / 4);
    fread(program, 4, size / 4, f);

    fclose(f);

    return (bword) size / 4;
}

int main(int argc, char** argv) {
    BCPU* cpu = cpu_new();

    if (argc != 2) {
        printf("need a file!\n");
        return 1;
    }

    char* prog_path = argv[argc - 1];
    
    bword* program;
    bword program_size = load_program_from_file(prog_path, program);
    io_load_program(cpu, program, program_size);

    bword l = 0;

    do {
        l = cpu_step(cpu);
    } while(l < (RESET_VECTOR) + program_size);

    printf("reached end of program.\n");

    return 0;
}