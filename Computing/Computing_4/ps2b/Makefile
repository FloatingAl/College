cc = g++
#all

all : PhotoMagic

PhotoMagic : PhotoMagic.o LFSR.o
	$(cc) -Wall -Werror -ansi -pedantic PhotoMagic.cpp LFSR.cpp -o PhotoMagic -lsfml-graphics -lsfml-window -lsfml-system

PhotoMagic.o : LFSR.hpp
	$(cc) -c PhotoMagic.cpp -o PhotoMagic.o

LFSR : LFSR.cpp LFSR.hpp
	$(cc) -c LFSR.cpp -o LFSR.o

clean:
	rm *.o main

