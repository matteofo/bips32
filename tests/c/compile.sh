#!/usr/bin/env zsh

clang -nostdlib -target mips -march=mips32 -c crt0.s
clang -nostdlib -target mips -march=mips32 -c $1.c
ld.lld -T ../raw.ld crt0.o $1.o -o $1.bin
rm -rf $1.o