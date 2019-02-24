CFLAGS = -ansi -pedantic -Wall -Wfatal-errors

snake: jeu.o monde.o graphique.o quadrillage.o main.o
	gcc -o snake jeu.o monde.o graphique.o quadrillage.o main.o -lMLV $(CFLAGS)
	rm includes/graphique.h.gch graphique.o includes/jeu.h.gch jeu.o main.o includes/monde.h.gch monde.o includes/quadrillage.h.gch quadrillage.o

jeu.o: includes/jeu.h jeu.c includes/graphique.h includes/monde.h
	gcc -c includes/jeu.h jeu.c includes/graphique.h includes/monde.h $(CFLAGS)

monde.o: includes/monde.h monde.c includes/quadrillage.h 
	gcc -c includes/monde.h monde.c includes/quadrillage.h quadrillage.c $(CFLAGS)

graphique.o: includes/graphique.h graphique.c
	gcc -c includes/graphique.h graphique.c $(CFLAGS)

quadrillage.o: includes/quadrillage.h quadrillage.c
	gcc -c includes/quadrillage.h quadrillage.c $(CFLAGS)

main.o: main.c includes/jeu.h includes/graphique.h
	gcc -c main.c includes/jeu.h includes/graphique.h $(CFLAGS)

clear:
	rm snake
