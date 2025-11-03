#include "syscalls.h"

int main() {
    print_string("counting to 10:\n");

    for (int i = 1; i < 11; i++) {
        print_int(i);
        print_string("\n");
    }

    float a = 0.12f;
    print_float(a + 1);

    return 0;
}