cc = g++

all : main

main : main.o ED.o
	$(cc) -Wall -Werror -ansi -pedantic main.cpp ED.cpp -o ED -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

main.o : ED.hpp
	$(cc) -c main.cpp -o main.o

ED : ED.cpp ED.hpp
	$(cc) -c ED.cpp -o ED.o

clean:
	rm *.o ED 