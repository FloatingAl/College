cc = g++

all : RingBuffer test

RingBuffer : RingBuffer.o test.o
	$(cc) -Wall -ansi -pedantic -Werror RingBuffer.cpp test.cpp -o ps5a -l boost_unit_test_framework

RingBuffer.o : RingBuffer.hpp
	$(cc) -c RingBuffer.cpp -o RingBuffer.o

test : test.cpp RingBuffer.hpp
	$(cc) -c test.cpp -o test.o


clean :  
	rm  *.o ps5a