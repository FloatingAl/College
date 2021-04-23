.data
inArr:		.word		0:60
symTab:		.word		0:80
inBuf:		.word		0:8
wordPrint:	.word		0:4
saveReg: 	.word 		0:3
prompt:		.asciiz		"Enter new token:"
typeprompt:	.asciiz		"Enter the token type: "
LOC:		.word		0 #location of counter
tablestatus: 	.asciiz 	"TOKEN    type    status  \n"
skipline:	.asciiz		"\n"
space:		.asciiz		"    "
errorPrint: 	.asciiz 	"Error, token has already been defined"


		.text
main:
		li		$t0,0x0400	# Initialize the Location Counter to x400
		sw		$t0, LOC
		li		$s3,0		#symtable index
		
inLoop:		
		
		la		$a0, inArr	
		jal		getTokens
		
		lb		$t8, inArr
		beq		$t8, 35, exit
		
		li		$t9, 0		# DEFN
		li		$t0, 0		# index to inArr
		li 		$t1, 0 		# The systab index   
		
		# if the NEXT Token is a ':' then the current Token is a label
		# Since the current Token takes 12 bytes, look ahead 12 bytes and see if it's a ':'
		lb		$s0, inArr+12($t0)
		bne		$s0, ':', operator 
		
		move		$a0, $t0	# moves the offeset to the $a0 and $a1 register
		move		$a1, $t1
		
		jal		getLabel
		
operator:	# Loads the next token then branch to chkVar if a value is found
		li		$s0, 44
		lb		$s1, inArr+20($t0)
		
chkVar:		
		bne		$s1, 50, noVar	#compare to type 2
	
		jal		getVar #save the var and LOC in to SymTable if their is a value
			
		
noVar:		addi		$t0, $t0, 12		# go to next token
		lb		$s0, inArr+20($t0)
		
		beq 		$s0, 35,  done
		beq		$t0, 60,  done
		bne		$s0, 44, noVar		# keep going until we get a ',' - variable might come next
		
		
		lb		$s1, inArr+20($t0)
		b		chkVar
	
		
		
done:		
		la 		$a0,skipline #Skip a line and print
		li 		$v0,4
		syscall
		
		
		jal		printSymTab	#PrintoutsymTab
		

		la 		$a0,skipline	# Skip a new line
		li 		$v0,4
		syscall
		
		jal		clearInArr #Clear the array
		
	
		lw		$t0, LOC	#increments address the location by 4	
		addi		$t0,$t0,4
		sw		$t0, LOC
		
		#branch back to inLOOP
		b		inLoop
	
		
			
#
# Save from keyboard to inArr table
# Get all the tokens and their types for a given line of assembly language
#	
getTokens:
	li 	$t0, 0		# t0 is not set to zero
	
tokenloop:

	la 	$a0, prompt	#  Asks user to add tokens
	li 	$v0, 4 		# Set to 4 print 
	syscall
	
	#takes 8 chars into inBuf
	la	$a0, inBuf
	li 	$a1, 8
	li	$v0, 8
	syscall
	
	lw 	$t3, inBuf	#loads from inBuf
	sw 	$t3, inArr($t0) #save it into inArr
	lw 	$t3, inBuf+4
	sw 	$t3, inArr+4($t0)
	
	la 	$a0, typeprompt # Prints out the type 
	li 	$v0, 4
	syscall
	
	la 	$a0, inBuf #load into buffer then
	li 	$a1, 4
	li 	$v0, 8
	syscall

	lb 	$t3,inBuf	#loads in the first word in inBuffer
	sb 	$t3, inArr+8($t0)


	
	lb 	$t4, inArr($t0)	# Load array into the register $t1
	beq	$t4, 35, tokenfinish
	
	
	beq 	$t0, 60, tokenfinish	#if($t1 == #) go to token finish
	
	addi 	$t0, $t0, 12		#if not increment $t0 by 12
	j 	tokenloop		#branch to token finish
tokenfinish:
	jr 	$ra	#returns the value of the register	
	


#
# getLabel: Label is found, save it in symTab
#
getLabel:
	lw 	$a0,inArr($t0)
	lw	$a1, inArr+4($t0)
	li	$a2,1
	move 	$s4, $ra	
	jal 	checkToken
	move 	$ra, $s4	
	beq 	$v0,-1,return
		
	sw 	$v0,symTab+12($s3)
			
				
	lw 	$t5, inArr($t0) #Loads in the first char into the array 
	sw 	$t5, symTab($s3)#then into the symTab
	
	lw 	$t5, inArr+4($t0)#Loads second char into array
	sw 	$t5, symTab+4($s3)#then into symtab
	
	lw 	$a0, LOC#loads LOC in a0 for to be sent to hex2char
	
	move 	$s2, $ra
	jal 	hex2char
	move 	$ra, $s2
	
	sw 	$v0, symTab+8($s3)  #this stores into +8
	
	li	$t5, '1'  	#Stores 1 into the symtab
	sw 	$a3, symTab+12($s3)
	addi	$s3, $s3, 16
	
	jr 	$ra

#
# getVar: Retrieves cariable
#
getVar:

	lw 	$a0,inArr+12($t0)
	lw	$a1,inArr+16($t0)
	li	$a2,0
	move	$s4, $ra
	jal	checkToken
	move	$ra, $s4
	beq	$v0, -1, return
	
	sw	$v0,symTab+12($s3)
	
	lw 	$t5, inArr+12($t0)	#loads first word in the array
	sw	$t5,  symTab($s3)
	
	lw 	$t5, inArr+16($t0)	#loads second word in the array
	sw 	$t5, symTab+4($s3)
	
	lw 	$a0, LOC
	
	move	$s2, $ra	#calles function within a function
	jal 	hex2char
	move	$ra, $s2
	
	sw	$v0, symTab+8($s3)
	
	li	$t5, '0'		#loads 0 in t5
	sb	$a3, symTab+12($s3)
	
	addi	$s3, $s3, 16		#add 16 into s7
	
	jr	$ra


#
# printSymTab
#
printSymTab:
	#prints out the names for the lable
	la	$a0, tablestatus
	li	$v0, 4
	syscall
	
	
	li	$t0,0	#counters for t0 and t1
	li	$t1,0
	
printloop:
	bge	$t0, $s3, return #returns the values when the function prints them out
	
	li	$t2, 0		#initizalize $t2 to 0

printstringloop:
	
	lb	$a0, symTab($t0) 
	beq	$a0, 10,printspaceloop # goes and prints if it the line has a space
	beq	$t2, 7, printspaceloop #same for this
	
	li	$v0,11	#set the reigister v0 to 11 to print the characters
	syscall
	
	
	addi	$t0, $t0, 1 #increment by 1 for t0 and t1
	addi	$t2, $t2, 1
	
	j	printstringloop
printspaceloop:
	beq 		$t2,16,printvalueloop #prints until $t2 == 16
	addi 		$t2,$t2,1
		
	li 		$a0,32	#print the space
	li 		$v0,11
	syscall
	
	#loops back until it branches 
	j 		printspaceloop
	
printvalueloop:

	lw 		$t2,symTab+8($t1) #loads one word from symtable(8) into a 4 byte location
	sw 		$t2,wordPrint	#prints
	la 		$a0,wordPrint
	li 		$v0, 4 # print the text
	syscall

	la 		$a0,space # print string with 8 spaces 
	li 		$v0,4
	syscall


	lb 		$a0,symTab+12($t1) # loads word then prints out as a integer
	li 		$v0, 11 #This checks the status
	syscall
	
	la		$s0,symACTS
	sll		$a1,$a0,2
	add		$s0,$s0,$a1
	move		$s3,$ra
	jalr		$s0
	move		$ra,$s3
		
	li 		$v0, 1
	syscall
	
	la 		$a0,skipline # goes to the next line
	li 		$v0,4
	syscall


	addi 		$t1,$t1,16  #increment t1 by 16 to be able to go to the next values
	move 		$t0,$t1
		
	
	j 		printloop



#
# clearInArr
#
clearInArr:
	li 	$t0, 0
	la	$t2, inArr
	
clean:
	
	sb	$zero,($t2) #sets t2 by zero
	
	addi	$t0, $t0, 1 #Increment t0 value from the address by 1
	addi	$t2, $t2, 1 #same for here
	
	beq	$t0, 80, return #goes to return when its 80
	
	j	clean

return:
	jr	$ra	#jumps to ra and returns it.

#Continue to HW6
checkToken:
	li	$t7,-16	#count the variable
	la	$t5,symTab#load address into symTab
	subi	$t5,$t5,16#sub by 16
checkTokenLoop:
	addi	$t7,$t7,16 #add 16 to address
	addi	$t5,$t5,16 #add 16 to counter
	
	lw	$t6,($t5)#loads the first character from table
	beq	$t6,$a0,firstToken#if($t6 == $a0) then branch to first token
	
	blt	$t7,$s3,checkTokenLoop #if not, contine going through the loop until the condition
	j	Avaliable
firstToken:
	#This checks the second token if it exists
	lw	$t6,4($t5)
	beq	$t6,$a1,NotAvaliable
	j	checkTokenLoop
NotAvaliable:
	lw	$t6,12($t5) # takes the previous status
	
	and	$t7,$t6,2  # goes though new status and old status into DEFN
	and	$t6,$t6,1
	sll	$t6,$t6,1
	or	$t6,$t6,$t7
	or	$t6,$t6,$a2
	
	sw	$t6,12($t5) #stores the new set of tokens in the old ones
	li	$v0, -1 # Giving -1 can tell the program that the token exists 
	
	j 	return
Avaliable:
	#stores the new status because it doesn't exist
	li	$v0,4
	or	$v0,$v0,$a2
	
	j 	return
	
symACTS:
		b	symACT0
		b	symACT1
		b	symACT2
		b	symACT3
		b	symACT4
		b	symACT5		
		
symACT0:
		j	return
	
symACT1:
		j	return

symACT2:
		j	return


symACT3:	#use statusACT3 for the error
		
		la	$a0,errorPrint
		li	$v0,4
		syscall
		
		
		li 	$v0,10	#exit
		syscall
symACT4:
		j	return
symACT5:	
		j	return
#
# hex2char:
# Convert a number in $a0 into char hex in $v0
#
# When you have '6b6a' in $a0,
# $v0 should have 'a''6''b''6'
#
# 4-bit mask slides from right to left in $a0.
# As corresponding char is collected into $v0,
# $a0 is shifted right by four bits for the next hex digit in the last four bits
#
#

hex2char:

	# save registers
	sw $t0, saveReg($0) 	# hex digit to process
	sw $t1, saveReg+4($0) 	# 4-bit mask
	sw $t9, saveReg+8($0)

	# initialize registers
	li $t1, 0x0000000f 	# $t1: mask of 4 bits
	li $t9, 3 	# $t9: counter limit

nibble2char:
	
	and $t0, $a0, $t1 	# $t0 = least significant 4 bits of $a0

	# convert 4-bit number to hex char
	bgt $t0, 9, hex_alpha # 	if ($t0 > 9) goto alpha
	# hex char '0' to '9'
	addi $t0, $t0, 0x30 	# convert to hex digit
	b collect
	
hex_alpha:

	addi $t0, $t0, -10 	# subtract hex # "A"
	addi $t0, $t0, 0x61 	# convert to hex char, a..f

	# save converted hex char to $v0

collect:

	sll $v0, $v0, 8 	# make a room for a new hex char
	or $v0, $v0, $t0 	# collect the new hex char

	# loop counter bookkeeping
	srl $a0, $a0, 4 	# right shift $a0 for the next digit
	addi $t9, $t9, -1 	# $t9--
	bgez $t9, nibble2char

	# restore registers
	lw $t0, saveReg($0)
	lw $t1, saveReg+4($0)
	lw $t9, saveReg+8($0)
	jr $ra
	
#exits the program
exit:
		
		la 		$a0,skipline
		li 		$v0,4
		syscall
		
		jal 		printSymTab
		li 		$v0,10
		syscall


