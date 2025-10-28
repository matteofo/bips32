clang -nostdlib -target mips -march=mips32 -c $1.s
llvm-objcopy -O binary $1.o $1.bin
rm -rf $1.o