#ifndef __JEU__
#define __JEU__


#include "monde.h"
#include "score.h"
#include "graphique.h"
#include "menu.h"
#include <MLV/MLV_all.h>


typedef struct {
	int largeur, hauteur;
	int nb_pommes;
	int taille_serpent;
	int vitesse;
	int duree_tour;
} Partie;


void creer_fenetre();


void jouer(Monde *monde);


void rejouer_ou_quitter(Monde *monde);


/* Crée un fichier Serpent.ini dans lequel sont figurés les paramètre du jeu par défaut.
 * Si le fichier existe déjà, la fonction vérifie les valeurs.
 * Renvoie ensuite ces paramètres. */
Partie init_parametres();


#endif
