#ifndef BIPS32_IO_H
#define BIPS32_IO_H

#include <stdio.h>
#include <sys/endian.h>
#include "cpu.h"

void io_load_program(CPU* cpu, word* program, word size);

#endif