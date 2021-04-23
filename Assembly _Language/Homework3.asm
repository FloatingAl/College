.data
	st_prompt:.asciiz "Enter anything you want:\n" 
	inBuf:  .space 80
	printBuf: .space 80

.text

main:

startline:	
	jal getline	#This is the return address for getline
	li $t0,0	#The index is t0 and starts at 0
quit_check:
	lb 	$t1, inBuf
	beq	$t1, '#', quit

loop:
	bge 	$t0,80,getline  	# Condition $t0 >= 80 go to getLine
	lb  	$s0, inBuf($t0)		#loads the char from s0  into inBuf
	beq	$s0, 10, endline	#sees if the string is at the end of the line
	jal 	find			#
	addi 	$s1, $s1, 0x30		#
	sb	$s1, printBuf($t0)	#Stores the char in printBuf
	addi	$t0, $t0, 1 		#add one to the iteerator
	b 	loop 			#goes back to the condition
		

endline:	#this is to check the line
		jal printstring	#Jumps to printstring
		b   startline	#Branches back to startline


quit:	
	li	$v0, 10
	syscall

getline:
	la	$a0, st_prompt   #prompt to enter a new line
	li	$v0, 4		#set the address to 4
	syscall 
	
	la	$a0, inBuf	#read a new line
	li	$a1, 80		#loads the number 80 in the regester $a1
	li	$v0, 8		#stores string into $v0
	syscall 
	
	jr	$ra  		#goes back to the a register

printstring:
	la 	$a0, printBuf 	#Gives strings into printBuf
	la	$t3, ($a0)	#loads adddress of from printBuf
	li	$v0, 4		#prints strings
	syscall	
find:
	li 	$t1, 0		#puts 0 into the loop target

rep_string:
	sra	$t1, $t1, 3	#Sifts 3 spaces to the right of the memory
	bge 	$t1, 80, done	#if($t0 >= 80) then branch to the done objective
	sll	$t1,$t1, 3	#Shifts 3 spaces to the left of the memory
	lb	$a0, Tabchar($t1)# Loads the char into the register $t1
	bne 	$a0, $s0, else	#Branch to the else statment
	
	lw	$s1, Tabchar+4($t1)#	Adds 4 because in MIPS to go to the next address, you need to add 4
	b done	#branch to the object done
else:
	addi $t1, $t1, 8	#The register is then incremented of t0 by 8
	b    rep_string		#branches back to rep_string
done:
	jr	$ra		#jumps back to the address
	
	
.data
	
Tabchar: 
	.word ' ', 5
	.word '#', 6
	.word '(', 4
	.word ')', 4
	.word '*', 3
	.word '+', 3
	.word ',', 4
	.word '-', 3
	.word '.', 4
	.word '/', 3
	.word '0', 1
	.word '1', 1
	.word '2', 1
	.word '3', 1
	.word '4', 1
	.word '5', 1
	.word '6', 1
	.word '7', 1
	.word '8', 1
	.word '9', 1
	.word ':', 4
	.word 'A', 2
	.word 'B', 2
	.word 'C', 2 
	.word 'D', 2
	.word 'E', 2
	.word 'F', 2
	.word 'G', 2
	.word 'H', 2
	.word 'I', 2
	.word 'J', 2
	.word 'K', 2
	.word 'L', 2
	.word 'M', 2
	.word 'N', 2
	.word 'O', 2
	.word 'P', 2
	.word 'Q', 2
	.word 'R', 2
	.word 'S', 2
	.word 'T', 2
	.word 'U', 2
	.word 'V', 2
	.word 'W', 2
	.word 'X', 2
	.word 'Y', 2
	.word 'Z', 2
	.word 'a', 2
	.word 'b', 2
	.word 'c', 2
	.word 'd', 2
	.word 'e', 2	
	.word 'f', 2
	.word 'g', 2
	.word 'h', 2
	.word 'i', 2
	.word 'j', 2
	.word 'k', 2
	.word 'l', 2
	.word 'm', 2
	.word 'n', 2
	.word 'o', 2
	.word 'p', 2
	.word 'q', 2
	.word 'r', 2
	.word 's', 2
	.word 't', 2
	.word 'u', 2
	.word 'v', 2
	.word 'w', 2
	.word 'x', 2 
