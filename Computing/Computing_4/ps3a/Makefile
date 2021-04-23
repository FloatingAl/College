cc = g++


all : NBody_main

NBody_main : NBody_main.o NBody.o
	$(cc) -Wall -Werror -ansi -pedantic NBody_main.cpp NBody.cpp -o NBody -lsfml-graphics -lsfml-window -lsfml-system

NBody_main.o : NBody.hpp
	$(cc) -c NBody_main.cpp -o NBody_main.o

NBody : NBody.cpp NBody.hpp
	$(cc) -c NBody.cpp -o NBody.o

clean:
	rm *.o NBody
