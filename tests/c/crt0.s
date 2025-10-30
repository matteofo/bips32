	.globl _start

	# syscalls
	.globl print_int
	.globl print_float
	.globl print_string
	.globl exit2
	
	# program entry point 
	j _start

print_int:
	li $v0, 1
	syscall
	jr $ra

print_float:
	li $v0, 2
	syscall
	jr $ra

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

_exit:
	# load value returned from main()
	move $a0, $v0
	j exit2
_start:
	la $ra, _exit # where to go after main()
	j main