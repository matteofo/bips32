    .data
hi: 
.asciiz "hi\n"
    .text
li $t0, '\n'
li $t1, 0xff
sb $t0, 0($t1)

li $a0, -10
li $v0, 1
syscall # print_int

move $a0, $t1
li $v0, 4
syscall # print_string

la $a0, hi
li $v0, 4
syscall

li $v0, 10 # exit
syscall