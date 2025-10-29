    .text
    .globl main
main:
    li $t0, 19
    li $t1, 0xff
    sb $t0, 0($t1)
    lb $t2, 0($t1)