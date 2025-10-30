	.globl _start
	.globl print_string
	.globl exit2
	j _start
print_string:
	li $v0, 4
	syscall
	jr $ra
exit:
	li $v0, 10
	syscall
exit2:
	li $v0, 17
	syscall
_start:
	la $ra, exit2 # where to go after main()
	j main