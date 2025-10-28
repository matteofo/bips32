#ifndef BIPS32_UTIL_H
#define BIPS32_UTIL_H

#include <stdlib.h>
#include <stdbool.h>

#define BYTES(x) x * 8
#define NEW(type) (type*) malloc(sizeof(type))
#define ARRAY(type, size) (type*) malloc(sizeof(type) * size)

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  ((byte) & 0x80 ? '1' : '0'), \
  ((byte) & 0x40 ? '1' : '0'), \
  ((byte) & 0x20 ? '1' : '0'), \
  ((byte) & 0x10 ? '1' : '0'), \
  ((byte) & 0x08 ? '1' : '0'), \
  ((byte) & 0x04 ? '1' : '0'), \
  ((byte) & 0x02 ? '1' : '0'), \
  ((byte) & 0x01 ? '1' : '0') 

#define WORD_TO_BINARY_PATTERN BYTE_TO_BINARY_PATTERN BYTE_TO_BINARY_PATTERN BYTE_TO_BINARY_PATTERN BYTE_TO_BINARY_PATTERN
#define WORD_TO_BINARY(word) \
  BYTE_TO_BINARY(word >> 24), \
  BYTE_TO_BINARY(word >> 16), \
  BYTE_TO_BINARY(word >> 8), \
  BYTE_TO_BINARY(word)

#define EACH(iter, array) (bword iter = 0; iter < sizeof(array) / sizeof(array[0]); iter++)

#endif