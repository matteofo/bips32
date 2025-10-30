#!/usr/bin/env zsh

for file in *.c;
do
./compile.sh "${file%.c}"
done