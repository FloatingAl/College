CC = g++
CFLAGS = -Wall -Werror -ansi -pedantic -std=c++0x
BOOST = -lboost_regex

all: ps7a

ps7a: ps7a.o
	$(CC) ps7a.o -o ps7a $(BOOST)

ps7a.o:
	$(CC) -c ps7a.cpp $(CFLAGS)

clean:
	rm -f *.o *~ ps7a