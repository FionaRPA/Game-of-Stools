#ifndef __JEU__
#define __JEU__


#include "monde.h"
#include "graphique.h"
#include <MLV/MLV_all.h>


typedef struct {
	int largeur, hauteur;
	int nb_pommes;
	int taille_serpent;
	int duree_tour;
} Partie;

/*void jouer();*/
Partie init_parametres();


#endif
