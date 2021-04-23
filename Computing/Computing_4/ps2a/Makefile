cc = g++
#all

all : LFSR test

LFSR : LFSR.o test.o
	$(cc) -Wall -ansi -pedantic -Werror LFSR.cpp test.cpp -o ps2a -l boost_unit_test_framework

LFSR.o : LFSR.hpp
	$(cc) -c LFSR.cpp -o LFSR.o

test : test.cpp LFSR.hpp
	$(cc) -c test.cpp -o test.o


clean:
		rm *.o ps2a

run:
		./ps2a

debug: cc += -g
debug: ps2a

