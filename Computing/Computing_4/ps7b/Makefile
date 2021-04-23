CC = g++
CFLAGS = -Wall -Werror -ansi -pedantic -std=c++0x
BOOST = -lboost_regex

all: ps7b

ps7b: ps7b.o
	$(CC) ps7b.o -o ps7b $(BOOST)

ps7b.o:
	$(CC) -c ps7b.cpp $(CFLAGS)

clean:
	rm -f *.o *~ ps7b