cc = g++
#all

all : invoice_client

invoice_client : invoice_client.o Invoice.o
	$(cc) invoice_client.o Invoice.o -o main

invoice_client.o : Invoice.h
	$(cc) -c invoice_client.cpp -o invoice_client.o

Invoice : Invoice.cpp Invoice.h
	$(cc) -c Invoice.cpp -o Invoice.o


clean:
	 rm *.o invoice_client



run:
	./main


debug: cc += -g
debug: main
