CC=gcc

a.out: aide.o copier.o header.o supp.o global.o main.o 
	$(CC) -o a.out aide.o copier.o header.o supp.o global.o main.o 

aide.o: aide.c aide.h
	$(CC) -o aide.o -c aide.c 
	
copier.o: copier.c copier.h
	$(CC) -o copier.o -c copier.c

header.o: header.c header.h
	$(CC) -o header.o -c header.c 

supp.o: supp.c supp.h
	$(CC) -o supp.o -c supp.c 
	
	
global.o: global.c global.h
	$(CC) -o global.o -c global.c 
	
main.o: main.c aide.h copier.h header.h supp.h global.h
	$(CC) -o main.o -c main.c 
	
clean:
	rm -rf *.o
