loop:   lodd counter:  		; num of fibs to do in counter
	jzer done:		; no more passes, go to done
	subd c1:		; subtract 1 from the counter
	stod counter:		; - - passes remaining
	
P1:	lodd daddr:		; load a pointer to fib arg
	pshi			; push arg for fib on stack
	addd c1:		; increment ++
	stod daddr:		;  store pointer for next d[n] 
	call fib:		; call fib (arg on stack)
	insp 1			; clear stack on fib return
	
P2:	push			; put return AC (fib(n)) on stack
	lodd faddr:		; load a pointer to result f[n]
	popi			; pop result off stack into f[n]
	addd c1:		; increment ++
	stod faddr:		; inc, store pointer for next f[n]
	jump loop:		; go to top for next pass
	
fib:	lodl 1			; fib func loads arg from stack
	jzer fibzer:		; if fib(0) == 0 go to fibzer
	subd c1:		; dec arg value in AC (arg-1)
	jzer fibone:		; if fib(1) == 1 go to fibone
	push			; push (arg-1) onto the stack
	call fib:		; recrusive call the fib function
	push			; push current result onto stack
	lodl 1			; load (arg-1) onto the stack
	subd c1:		; change (arg-1) to (arg-2) by accumlation
	push			; push (arg-2) onto the 
	call fib:		; recrusive call the fib function

clrstack:
	insp 1			; (arg-2) removed from the stack
	addl 0			; add results to AC
	insp 2			; remove arguments from the stack
	retn			; return to back to caller
	
fibzer:	lodd c0:
	retn			; AC = 0 for fib(0)
	
fibone:	lodd c1:
	retn			; AC = 1 for fib(1)
	
done:	halt			; Program is halted
	
.LOC 	100			; locate data beginning at 100
d0:  	3			; array of args for fib function
     	9
     	18
     	23
     	25
f0:  	0			; array of result locs for fib returns
     	0
     	0
     	0 
     	0
daddr:  d0:			; start address of fib args 
faddr:  f0:			; start address of fib results
c0: 	0			; constants 
c1: 	1
c2:	2
counter: 5			; number of data elements to process
