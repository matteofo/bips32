# Realizzare un contatore in assembly che incrementi il valore di un registro 
# (e.g. $t0 inizialmente contenente il valore 20)
# fino ad un valore predefinito (e.g. fino al valore 31) e, 
# una volta raggiunto quel valore, lo azzeri prima di ritornare ad incrementarlo
    .data
newline: .asciiz "\n"
    .text
    .globl main
main:
    li $t0, 20
    li $t1, 32

loop:
    li $v0, 1
    move $a0, $t0
    syscall

    addi $t0, $t0, 1

    la $a0, newline
    li $v0, 4
    syscall
    
    blt	$t0, $t1, loop

    j restart
restart:
    li $t0, 20
    j loop