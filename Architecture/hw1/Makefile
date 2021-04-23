cc = g++
#all


all : main

main : main.o
	$(cc) -Wall -Werror -ansi -pedantic arch_hw1.cpp -o main

main.o :
	$(cc) -c arch_hw1.cpp -o main.o


clean:
	rm *.o main

run:
	./main

debug: cc += -g
debug: main
