
cc = gcc

#all
all : main

main : main.o my_add.o my_mult.o
	$(cc) main.o my_add.o my_mult.o -o main
main.o : my_add.h my_mult.h
	$(cc) -c main.c -o main.o           
my_add : my_add.c my_add.h
	$(cc) -c my_add.c -o my_add.o
my_mult : my_mult.h my_mult.c
	$(cc) -c my_mult.c -o my_mult.o


clean:
	 rm *.o main



my_exec:
	./main


debug: cc += -g
debug: main
