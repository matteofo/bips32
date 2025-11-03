# Scrivere un programma assembly che, utilizzando un ciclo,
# scriva i numeri interi (come word) da 20 a 30m
# negli indirizzi di memoria da 0x10010000 a 0x10010028
# (e poi termini l’esecuzione). 
    .data
acapo: .asciiz "\n"
ciao: .asciiz "ciao"
    .text
    .globl main
main:
    li $t0, 20
    li $t1, 0x10010000

loop:
    sw $t0, 0($t1) # 0x10010000: 20

    move $a0, $t0
    li $v0, 1
    syscall

    la $a0, acapo
    li $v0, 4
    syscall
    
    addi $t0, $t0, 1
    addi $t1, $t1, 4

    blt $t0, 31, loop

    li $v0, 10 # exit
    syscall