CC=gcc



a.out: aide.o copier.o main.o
	$(CC) -o a.out aide.o copier.o main.o 

aide.o: aide.c aide.h
	$(CC) -o aide.o -c aide.c 
	
copier.o: copier.c copier.h
	$(CC) -o copier.o -c copier.c
	
main.o: main.c aide.h copier.h
	$(CC) -o main.o -c main.c 

clean:
	rm -rf *.o
