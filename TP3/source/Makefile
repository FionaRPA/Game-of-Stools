CC = gcc
ICLD = ../includes/
LDFLAGS = -lm -lMLV
CFLAGS = -ansi -pedantic -Wall -Wfatal-errors
OBJ = menu.o score.o jeu.o monde.o graphique.o main.o

snake: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS) $(CFLAGS)

menu.o: $(ICLD)menu.h menu.c $(ICLD)graphique.h

jeu.o: $(ICLD)jeu.h jeu.c $(ICLD)graphique.h $(ICLD)monde.h $(ICLD)menu.h

monde.o: $(ICLD)monde.h monde.c

graphique.o: $(ICLD)graphique.h graphique.c

score.o: $(ICLD)score.h score.c

main.o: main.c $(ICLD)jeu.h $(ICLD)graphique.h

%.o: %.c
		$(CC) -c $< $(CFLAGS)

clear:
	rm $(OBJ)
	rm snake
