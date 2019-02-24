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



void jouer();


/* Crée un fichier Serpent.ini dans lequel sont figurés les paramètre du jeu par défaut.
 * Si le fichier existe déjà, la fonction vérifie les valeurs.
 * Renvoie ensuite ces paramètres. */
Partie init_parametres();


#endif
