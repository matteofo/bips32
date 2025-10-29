#!/usr/bin/env zsh

clang -nostdlib -target mips -march=mips32 -c $1.s
ld.lld -T raw.ld $1.o -o $1.bin
rm -rf $1.o