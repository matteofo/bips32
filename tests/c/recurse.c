#include "syscalls.h"

void cool(int val) {
    print_int(val);
    print_string("\n");
    if (val < 10) {
        cool(++val);
    }
}

int main() {
    print_string("testing recursive calls\n");
    cool(0);

    return 0;
}