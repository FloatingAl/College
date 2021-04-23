.data 

	text: .asciiz "Please pick a integer:\n"
	text2: .asciiz "The product of the two numbers combined is:\n"
.text
	#print string from "text"
	li $v0,4	#loaded and executed 
	la $a0 , text
	syscall
	#ask user for integer
	li $v0, 5
	syscall
	
	#store value in $t0 temporarly
	move $t0, $v0
	
	li $v0,4	#loaded and executed 
	la $a0 , text
	syscall

	#ask user for another integer
	li $v0, 5
	syscall
	
	#store vale in $t1 temporarly
	move $t1, $v0
	
	#Display Product
	li $v0, 4
	la $a0, text2
	syscall
	
	#Multply two integers and then prints out the number
	mul $a0, $t0, $t1
	li $v0, 1
	syscall
	


