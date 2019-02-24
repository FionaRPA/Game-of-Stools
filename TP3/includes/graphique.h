#ifndef __GRAPHIQUE__
#define __GRAPHIQUE__

#include <stdio.h>
#include <assert.h>
#include <MLV/MLV_all.h>
#include "monde.h"

#define FENETRE_X 1280
#define FENETRE_Y 720

#define COULEUR_QUADRILLAGE MLV_COLOR_DODGERBLUE4
#define COULEUR_FOND MLV_COLOR_CORNFLOWER_BLUE
#define COULEUR_CORPS MLV_COLOR_CHARTREUSE3
#define COULEUR_CORPS_CONTOUR MLV_COLOR_CHARTREUSE4
#define COULEUR_NOMBRE MLV_COLOR_GREEN4
#define COULEUR_TEXTE MLV_COLOR_CHARTREUSE4


void afficher_quadrillage(Monde *mon);

void afficher_pomme(Pomme *pom, int nb_lignes, int nb_colonnes, char* file);

void afficher_serpent(Serpent *ser, int nb_lignes, int nb_colonnes);

void afficher_monde(Monde *mon);


#endif