
cc = gcc
LIB = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

#all
all : client

client : client.o Implement.o 

	$(cc) client.o Implement.o -o client $(LIB)

client.o : Interface.h
	$(cc) -c client.c -o client.o $(LIB)

Implement : Implement.c Interface.h
	$(cc) -c Implement.c -o Implement.o $(LIB)
clean:
	 rm *.o *~ main client


my_exec:
	./client


debug: cc += -g
debug: client
