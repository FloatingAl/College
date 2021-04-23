.data

array1: .word 5,10,102,11
array2: .word 42,61,70,9,80,60
sum1:	.word  0
sum2:	.word  0

.text
	main:#The main will give the number of elements and name
		
		li, $a0, 4      #$a0 will be number of elements 
		la, $a1, array1	#$a1 will be the address of array
		jal SumArr	#call function
		sw $v0, sum1 	#storing first array sum in sum1
		
		#now for the second array
		li, $a0, 6
		la, $a1, array2
		jal SumArr
		sw $v0, sum2	#storing second array sum in sum2
	
		li $v0, 10	#Exiting cleanly 
		syscall	
		
	SumArr:# This function is a for loop
		li, $v0, 0 	#sum  
		li, $t0, 0      #i iterrator for loop
	work:	
		bge $t0, $a0, done #condition
		mulo $t4, $t0,4	   #Multiply the number of bytes
		add $t2, $t4, $a1 #adding iterrator and address to get the address of the iterator element  
		lw  $t1, ($t2)     #loads ith element and its t1
		add $v0, $t1, $v0 # sum = sum + arr[i] Adds to become sum
		add $t0, $t0,1 	  #i++
		b work		  # branching(Go back to loop condition)
	done:
		jr $ra 		  # return 
	
	
		
		
	
		
			
