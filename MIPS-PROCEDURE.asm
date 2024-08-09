.data
	comma: .asciiz ", "
	sumOdd: .asciiz "\nSum odd: "
	prompt: .asciiz "\nEnter number of element: "
	myArray: .word 100
.text
	main:
	#Input number of elements
	
	jal inputArray
	jal outputArray
	
	li $v0, 4
	la $a0, sumOdd
	syscall
	
	jal sumOddNumber
	
	#End program
	li $v0, 10
	syscall
	
	#Procedure input
	inputArray:
	li $v0, 4
	la $a0, prompt
	syscall
	
	li $v0, 5
	syscall
	move $s0, $v0
	
	move $s1, $s0
	la $t0, myArray
	input:
		beq $s1, 0, inputExit
		
		li $v0, 5
		syscall
		
		sw $v0, ($t0)
		addi $s1, $s1, -1
		addi $t0, $t0, 4
		j input
	inputExit:
		jr $ra
	
	#Procedure output
	outputArray:
	la $t0, myArray
	move $s1, $s0
	output:
		#vong loop dieu kien
		beq $s1, 0, outputExit
		
		lw $t1, ($t0)
		move $a0, $t1
		li $v0, 1
		syscall
		
		#Them dau phay
		la $a0, comma
		li $v0, 4
		syscall
		
		#i=i+4
		addi $s1, $s1, -1
		add $t0, $t0, 4
		
		j output
	outputExit:
		jr $ra
	sumOddNumber:
	addi $t2, $zero, 2
	la $t0, myArray
	move $s1, $s0
	while:
		beq $s1, 0, exit
		
		lw $t1, ($t0)
		
		jal isOdd

		beq $t3, 0, not
		add $t4, $t4, $t1
		not:
		
		addi $s1, $s1, -1
		add $t0, $t0, 4
		j while
	exit:
	move $a0, $t4
	li $v0, 1
	syscall
	jr $ra
	
	isOdd:
	div $t3, $t1, $t2 #15/2=7
	mul $t3, $t2, $t3 #14
	sub $t3, $t1, $t3 #15-14=1
	jr $ra
