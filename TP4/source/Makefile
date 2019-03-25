CC = gcc
ICLD = ../includes/
CFLAGS = -ansi -pedantic -Wall -Wfatal-errors


clm: main.o option.o fichier.o liste.o occurence.o tri.o test.o
	$(CC) -o $@ $^ $(CFLAGS)

main.o: main.c $(ICLD)option.h $(ICLD)fichier.h $(ICLD)occurence.h $(ICLD)tri.h

option.o: option.c $(ICLD)option.h

fichier.o: fichier.c $(ICLD)fichier.h

occurence.o: occurence.c $(ICLD)occurence.h $(ICLD)fichier.h $(ICLD)liste.h

liste.o: liste.c $(ICLD)liste.h

tri.o: tri.c $(ICLD)tri.h

test.o: test.c $(ICLD)test.h

%.o: %.c
		$(CC) -c $< $(CFLAGS)
clear:
	rm *.o
	rm clm