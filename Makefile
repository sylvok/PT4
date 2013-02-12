CC=gcc -Wall

OBJECTS= a.out

essai : $(OBJECTS)
	$(CC) $(OBJECTS) -o essai


a.out : copie2.c copie2.h 
	$(CC) -c copie2.c


clean :
	rm -f *~ *.o essai
