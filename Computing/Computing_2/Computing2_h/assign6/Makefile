cc = gcc

#all
all : main

main : main.o Implement.o
	$(cc) main.o Implement.o -o main

main.o : Interface.h
	$(cc) -c main.c -o main.o

Implement : Implement.c Interface.h
	$(cc) -c Implement.c -o Implement.o


clean:
	 rm *.o main



my_exec:
	./main


debug: cc += -g
debug: main
