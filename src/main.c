#include <stdio.h>
#include <stdbool.h>
#include "cpu.h"
#include "io.h"

/* reads a program from file
 * @param path file path to an assembled mips32 program
 * @param size pointer to store the read file size in bytes
*/
word* read_program_from_file(char* path, word* size) {
    FILE* f = fopen(path, "rb");

    if (!f) {
        return NULL;
    }

    // get file size
    fseek(f, 0, SEEK_END);

    *size = ftell(f);
    long word_size = *size / 4;

    rewind(f);

    // read program word by word (32 bits)
    word* program = ARRAY(word, word_size);
    fread(program, 4, word_size, f);

    fclose(f);

    // most cpu architectures are little endian, but mips32 is big endian
    // we need to flip the endianness
    for (word i = 0; i < word_size; i++) {
        program[i] = bswap32(program[i]);
    }
    
    return program;
}

// prints the status of the cpu registers
void print_regs(CPU* cpu) {
    printf("\n");
    printf("===REGISTER DUMP===\n\n");

    for (byte i = 0; i < NUM_REGISTERS; i++) {
        printf("$%u: %u; ", i, cpu->registers[i]);
        if (i % 8 == 0 && i != 0) {
            printf("\n");
        }
    }

    printf("\n\n");
    printf("===END REGISTER DUMP===");
    printf("\n");
}

void print_mem(CPU* cpu) {
    word start = 0;
    word end = 0;

    printf("start address? ");
    scanf("%x", &start);

    printf("end address? ");
    scanf("%x", &end);

    printf("\n");
    printf("===MEMORY DUMP===\n\n");

    for (word i = start; i < end; i+=8) {
        printf("$%08x ", i);

        for (word j = i; j < i + 8; j++) {
            printf("%02x ", cpu->memory[j]);
        }

        printf("\n");
    }

    printf("\n");
    printf("===END MEMORY DUMP===");
    printf("\n");
}

int main(int argc, char** argv) {
    CPU* cpu = cpu_new();

    if (argc != 2) {
        printf("need a file!\n");
        return 1;
    }

    char* prog_path = argv[1];
    
    word program_size = 0;
    word* program = read_program_from_file(prog_path, &program_size);
    io_load_program(cpu, program, program_size);

    // run program until out of words
    word counter = 0;
    do {
        counter = cpu_step(cpu);
        read:
        char c = getchar();
        if (c == 'r') {
            print_regs(cpu);
            getchar();
            goto read;
        } else if (c == 'm') {
            print_mem(cpu);
            getchar();
            goto read;
        }
    } while(counter < (RESET_VECTOR) + program_size * 4);

    printf("reached end of program.\n");

    return 0;
}