start:  lodd on:
        stod 4095
        call xbsywt:
        loco str1:
nextw:  pshi
        addd c1:
        stod pstr1:
        pop
        jzer crnl:
        stod 4094
        push
        subd c255:
        jneg crnl:
        call sb:
        insp 1
        push
        call xbsywt:
        pop
        stod 4094
        call xbsywt:
        lodd pstr1:
        jump nextw:
crnl:   lodd cr:
        stod 4094
        call xbsywt:
        lodd nl:
        stod 4094
        call xbsywt:
        lodd on:                ; mic1 program to print string
        stod 4093               ; and scan in a 1-5 digit number
bgndig: call rbsywt:            ; using CSR memory locations
        lodd 4092
        subd numoff:
        push
nxtdig: call rbsywt:
        lodd 4092
        stod nxtchr:
        subd nl:
        jzer endnum:
        mult 10
        lodd nxtchr:
        subd numoff:
        addl 0
        stol 0
        jump nxtdig:
endnum: lodd numptr:
        popi
        addd c1:
        stod numptr:
        lodd numcnt:
        jzer addnms:
        subd c1:
        stod numcnt:
        jump start:

addnms: lodd binum1: ; Add binum 1 and 2 and store in sum
	addd binum2:
	stod sum:    

	jneg over:   ; Checks to see if its over

	call xbsywt:
	loco str2:   ; print out the string
	call xbsywt:
	call bits:   ; go to bits and convert results

	call xbsywt:
	lodd zero:
	
	halt	     ; this is where you would go to add the binums

over:	loco str3:   ; Loads in string print and loads in -1 in the accumlator and halts
	lodd neg:
	halt

bits:	lodd on:
	stod 4095
	lodd neg:     ; puts in -1 in the accumlator
	push	      ; push -1 on to stack
	lodd mask:    
	push	      ; push mask on stack

result:	lodd sum:     ; loads sum in the AC
	jzer print:   ; if not overflow go to print
	lodd mask:    ; lod the mask
	push	      ; push on the stack
	lodd sum:     ; lodd the sum onto AC
	push	      ; push on stack
	div	      ; divide the sum by mask
	pop	      ; pop from stack
	stod sum:     ; store in the sum
	pop	      ; pop from stack
	insp 2	      ; clear the stack
	addd numoff:  ; convert to a character string
	push	      ; push on the stack
	jump result:  ; recursive loop to result 

print:	pop           ; pop char
	jneg done:    ; if -1 is finish and show result
	stod 4094     ; stor ac into content register
	call xbsywt:  ; show result 
	jump print:   ; pretin next result
	
xbsywt: lodd 4095
        subd mask:
        jneg xbsywt:
        retn

rbsywt: lodd 4093
        subd mask:
        jneg rbsywt:
        retn
sb:     loco 8
loop1:  jzer finish:
        subd c1:
        stod lpcnt:
        lodl 1
        jneg add1:
        addl 1
        stol 1
        lodd lpcnt:
        jump loop1:
add1:   addl 1
        addd c1:
        stol 1
        lodd lpcnt:
        jump loop1:
	
finish: lodl 1
        retn

done:	retn
	
numoff: 48
nxtchr: 0
numptr: binum1:
binum1: 0
binum2: 0
lpcnt:  0
mask:   10
on:     8
nl:     10
cr:     13
c1:     1
c10:    10
c255:   255
sum:    0
numcnt: 1
pstr1:  0
str1:   "Please enter a 1-5 digit number followed by enter"
str2:	"The sum of the two integers is: "
str3:	"Overflow"
neg:	-1
zero:	0
