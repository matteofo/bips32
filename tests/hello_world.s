    .data
msg: .asciiz "hello world!\n"
    .text
la $a0, msg
li $v0, 4
syscall

li $v0, 10
syscall