cc = g++

all : GuitarString RingBuffer GuitarHero

GuitarString : GuitarString.o RingBuffer.o GuitarHero.o
	$(cc) -Wall -ansi -pedantic -Werror GuitarString.cpp RingBuffer.cpp GuitarHero.cpp -o GuitarHero -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -l boost_unit_test_framework

GuitarString.o : GuitarString.hpp RingBuffer.hpp 
	$(cc) -c GuitarString.cpp -o GuitarString.o

RingBuffer : RingBuffer.hpp
	$(cc) -c RingBuffer.cpp -o RingBuffer.o

GuitarHero : GuitarHero.cpp RingBuffer.hpp GuitarString.hpp
	$(cc) -c GuitarHero.cpp -o GuitarHero.o


clean :  
	rm  *.o GuitarHero debug

debug :
	g++ -g -Wall -ansi -pedantic -Werror GuitarString.cpp RingBuffer.cpp GStest.cpp -o debug -l boost_unit_test_framework

