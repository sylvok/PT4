CC=gcc

a.out: aide.o main.o
	$(CC) -o a.out aide.o main.o 

aide.o: aide.c aide.h
	$(CC) -o aide.o -c aide.c 
	
main.o: main.c aide.h
	$(CC) -o main.o -c main.c 

clean:
	rm -rf *.o
