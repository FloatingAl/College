cc = gcc

#all
all : main

main : main.o linkedListSt.o item.o
	$(cc) main.o linkedListSt.o item.o -o main

main.o : item.h linkedListSt.h 
	$(cc) -c main.c -o main.o

linkedListSt : linkedListSt.c linkedListSt.h
	$(cc) -c linkedListSt.c -o linkedListSt.o

item : item.c item.h
	$(cc) -c item.c -o item.o


clean:
	 rm *.o main



my_exec:
	./main


debug: cc += -g
debug: main
