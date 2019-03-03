#ifndef __GRAPHIQUE__
#define __GRAPHIQUE__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <MLV/MLV_all.h>
#include "monde.h"

#define FENETRE_X 1280
#define FENETRE_Y 720

#define COULEUR_QUADRILLAGE MLV_COLOR_DODGERBLUE4
#define COULEUR_FOND MLV_COLOR_BLACK
#define COULEUR_CORPS MLV_COLOR_CHARTREUSE3
#define COULEUR_CORPS_CONTOUR MLV_COLOR_CHARTREUSE4
#define COULEUR_TEXTE MLV_COLOR_SANDY_BROWN

#define COULEUR_POMME MLV_COLOR_FIREBRICK3
#define COULEUR_POMME_EMPOISONNEE MLV_COLOR_CHOCOLATE4
#define COULEUR_POMME_CONTOUR MLV_COLOR_FIREBRICK4
#define COULEUR_TETE MLV_COLOR_DARKGREEN
#define COULEUR_TETE_CONTOUR MLV_rgba(0, 70, 0, 255)


void afficher_quadrillage(Monde *mon);

void load_image(char* file, int larg, int haut, int pos_x, int pos_y);

void afficher_pomme(Pomme *pom, int nb_lignes, int nb_colonnes, char* file);

void afficher_serpent(Serpent *ser, int nb_lignes, int nb_colonnes);

void afficher_monde(Monde *mon, int temps);

void affiche_fin(int score, int bool);

void afficher_pause();

#endif
