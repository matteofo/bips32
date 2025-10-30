#include "syscalls.h"

int main() {
    print_string("counting to 10:\n");

    for (int i = 1; i < 11; i++) {
        print_int(i);
        print_string("\n");
    }

    float a = 0.01f;
    print_float(a);

    return 0;
}