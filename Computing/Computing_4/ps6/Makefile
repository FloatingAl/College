cc = g++

all : MarkovModel 

MarkovModel : MarkovModel.o mmtest.o
	$(cc) -Wall -ansi -pedantic -Werror mmtest.cpp MarkovModel.cpp -o TextGenerator -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -l boost_unit_test_framework

MarkovModel.o : MarkovModel.hpp  
	$(cc) -c MarkovModel.cpp -o MarkovModel.o

mmtest.o : MarkovModel.hpp
	$(cc) -c mmtest.cpp -o mmtest.o

clean :  
	rm  *.o TextGenerator debug

debug :
	g++ -g -Wall -ansi -pedantic -Werror mmtest.cpp MarkovModel.cpp -o Markov -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -l boost_unit_test_framework