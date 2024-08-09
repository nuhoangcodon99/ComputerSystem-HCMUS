.data
	prompt: .asciiz "Enter number: "
	sum: .asciiz "\nAdd: "
	substract: .asciiz "\nSub: "
	multiply: .asciiz "\nMul: "
	divide: .asciiz "\nDiv: "
	modi: .asciiz "\nMod: "
.text
	#add
	li $v0, 4
	la $a0, prompt
	syscall
	
	li $v0, 5
	syscall
	
	move $t0, $v0
	
	li $v0, 4
	la $a0, prompt
	syscall
	
	li $v0, 5
	syscall
	
	move $t1, $v0
	add $t2, $t0, $t1
	
	li $v0, 4
	la $a0, sum
	syscall
	
	li $v0, 1
	move $a0, $t2
	syscall
	#end add
	#sub
	sub $t2, $t0, $t1
	
	li $v0, 4
	la $a0, substract
	syscall
	
	li $v0, 1
	move $a0, $t2
	syscall
	#end sub
	#mul
	mul $t2, $t0, $t1
	
	li $v0, 4
	la $a0, multiply
	syscall
	
	li $v0, 1
	move $a0, $t2
	syscall
	#end mul
	#div
	div $t2, $t0, $t1
	
	li $v0, 4
	la $a0, divide
	syscall
	
	li $v0, 1
	move $a0, $t2
	syscall
	#end div
	#mod
	move $t3, $t2
	mul $t2, $t3, $t1
	sub $t3, $t0, $t2
	
	li $v0, 4
	la $a0, modi
	syscall
	
	li $v0, 1
	move $a0, $t3
	syscall
	
	
	
	
	
	
