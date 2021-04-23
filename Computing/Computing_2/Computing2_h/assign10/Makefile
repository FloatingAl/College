cc = gcc


main : main.o pq.o heap.o item.o
	$(cc) main.o pq.o heap.o item.o -o main

main.o : pq.h heap.h item.h
	$(cc) -c main.c 

pq : pq.c pq.h
	$(cc) -c pq.c

heap: heap.c heap.h
	$(cc) -c heap.c

item: item.c item.h 
	$(cc) -c item.c 


clean:
	 rm -r *.o main *.gch *~



run:
	./main


debug: cc += -g
debug: main
