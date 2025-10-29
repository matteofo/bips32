#ifndef BIPS32_IO_H
#define BIPS32_IO_H

#include <stdio.h>
#ifndef __APPLE__
#include <byteswap.h>
#define bswap32 bswap_32
#else
#include <sys/endian.h>
#endif
#include "cpu.h"

void io_load_program(CPU* cpu, word* program, word size);

#endif