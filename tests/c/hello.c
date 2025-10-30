const char* msg = "hello, world!\n";

extern void print_string(const char* string);
extern void exit2(int code);

int main() {
    for (int i = 0; i < 10; i++) {
        print_string(msg);
    }
    return 1;
}