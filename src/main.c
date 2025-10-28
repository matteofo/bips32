#include <stdio.h>
#include <stdbool.h>
#include "cpu.h"

#define MB_64 67108864

int main() {
    BCPU* cpu = cpu_new(MB_64);
    cpu_decode(cpu);

    while (true) {
        cpu_step(cpu);
    }

    return 0;
}