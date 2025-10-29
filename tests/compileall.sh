#!/usr/bin/env zsh

for file in *.s;
do
./compile.sh "${file%.s}"
done