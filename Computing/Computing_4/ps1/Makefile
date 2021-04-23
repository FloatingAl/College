cc = g++
#all


all : main original

main : main.o sierpinski.o
	$(cc) -Wall -Werror -ansi -pedantic main.cpp sierpinski.cpp -o sierpinski -lsfml-graphics -lsfml-window -lsfml-system

main.o : sierpinski.hpp
	$(cc) -c main.cpp -o main.o

sierpinski : sierpinski.cpp sierpinski.hpp
	$(cc) -c sierpinski.cpp -o sierpinski.o


original : original.o original_imp.o
	$(cc) -Wall -Werror -ansi -pedantic original.cpp original_imp.cpp -o original -lsfml-graphics -lsfml-window -lsfml-system

original.o : original.hpp
	$(cc) -c original.cpp -o original.o 

original_imp : original_imp.cpp original.hpp
	$(cc) -c original_imp.cpp -o original_imp.o 

clean:
	rm *.o main original

run:
		./sierpinski 5 800
		./original 8 400

debug: cc += -g
debug: main original
