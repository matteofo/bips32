#ifndef BIPS32_UTIL_H
#define BIPS32_UTIL_H

#include <stdlib.h>
#include <stdbool.h>

#define NEW(type) (type*) malloc(sizeof(type))
#define ARRAY(type, size) (type*) malloc(sizeof(type) * size)

#endif