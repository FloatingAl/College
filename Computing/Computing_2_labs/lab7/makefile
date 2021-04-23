cc = gcc

#all
all : main

main : main.o linkedListSt.o
	$(cc) main.o linkedListSt.o -o main

main.o : linkedListSt.h
	$(cc) -c main.c -o main.o

linkedListSt : linkedListSt.c linkedListSt.h
	$(cc) -c linkedListSt.c -o linedListSt.o


clean:
	 rm *.o main



exec:
	./main


debug: cc += -g
debug: main
