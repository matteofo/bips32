    .data
msg: .asciiz "hello\n"
    .text
    j main
print_string:
    addiu $sp, $sp, -4
    sw $t0, 0($sp)
    lw $a0, 0($sp)
    li $v0, 4
    syscall

    addiu $sp, $sp, 4
    jr $ra
main:
    la $t0, msg
    jal print_string

    li $v0, 10
    syscall