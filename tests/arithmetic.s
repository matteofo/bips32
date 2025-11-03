    .text
li $t0, 10
li $t1, -2
addu $t0, $t0, $t1

move $a0, $t0
li $v0, 1
syscall

li $t0, 10
li $t1, 8
subu $t0, $t0, $t1

move $a0, $t0
syscall

li $v0, 10
syscall