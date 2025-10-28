#ifndef BIPS32_IO_H
#define BIPS32_IO_H

#include <stdio.h>
#include "cpu.h"

void io_load_program(BCPU* cpu, bword* program, bword size);

#endif