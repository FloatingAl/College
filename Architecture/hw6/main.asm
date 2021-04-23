main:   lodd arg1:
        push
        call lcshft:
        stod rslt:
        lodd arg1:
        push
        call triple:
        stod rslt3:
        halt

lcshft: lodl 1 
        jneg add1: 
        addl 1 
        retn 

add1:   addl 1 
        addd c1:   
        retn

triple:	lodl 1
	addl 1
	addd 1
	addd 1
	insp 2
	retn
	

.LOC 200
arg1: 7
rslt: 0
rslt3: 0
c1: 1 
