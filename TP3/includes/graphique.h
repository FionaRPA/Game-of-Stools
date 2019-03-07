#ifndef __GRAPHIQUE__
#define __GRAPHIQUE__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <MLV/MLV_all.h>
#include "monde.h"

#define FENETRE_X 1280
#define FENETRE_Y 720

#define COULEUR_QUADRILLAGE MLV_rgba(169,169,169,255)
#define COULEUR_FOND MLV_COLOR_BLACK
#define COULEUR_CORPS MLV_COLOR_CHARTREUSE3
#define COULEUR_CORPS_CONTOUR MLV_COLOR_CHARTREUSE4
#define COULEUR_TEXTE MLV_COLOR_SANDY_BROWN


/* Prend en paramètre le monde de type Monde*.
 * Affiche le plateau de jeu en fonction du nombre de lignes et colonnes indiqués dans la variable mon.
 * Aucune valeur n'est renvoyée.
 */
void afficher_quadrillage(Monde *mon);

/* A pour argument : le nom du fichier de type char*, les entiers larg et haut de type int qui correspondent
 * à la largeur et la hauteur de l'image et (pos_x, pos_y) de type int qui correspondent à la position où l'on
 * désir l'afficher.
 * Aucune valeur n'est renvoyée.
 */
void load_image(char* file, int larg, int haut, int pos_x, int pos_y);

/* Prend en paramètre une pomme (pom de type Pomme*), deux entiers nb_ligne et nb_colonnes qui correspondent à la
 * taille de la grille et un fichier de type char* qui contient l'image d'une pomme.
 * Grâce à la fonction load_image on recharge l'image en fonction des arguments donnés.
 * Aucune valeur n'est renvoyée.
 */
void afficher_pomme(Pomme *pom, int nb_lignes, int nb_colonnes, char* file);

/* Prend en paramètre un serpent (ser) de type Serpent* et de deux entier nb_lignes et nb_colonnes
 * qui correspondent à la taille de la grille.
 * On affiche une image, recharger, grâce à la fonction load_image pour la tête du serpent suivi de rectangle
 * vert qui correspondent au corps de celui-ci. Tout est affiché en fonction de la hauteur, la largeur et des postions
 * x et y désiré.
 * Aucune valeur n'est renvoyée.
 */
void afficher_serpent(Serpent *ser, int nb_lignes, int nb_colonnes);

/* A pour paramètre le monde (mon) de type Monde* et le temps (temps) de type int.
 * On affiche tout ce qui appartient au monde actuel : le serpent, la grille, le temps, le score et les pommes
 * (empoisonnées, bonus, normale).
 * Aucune valeur n'est renvoyée.
 */
void afficher_monde(Monde *mon, int temps);

/* Prend en paramètre un score et d'un booléen de type entier.
 * Affiche différentes fins de parties : si la fin du jeu est provoqué par un temps dépassé on affiche un message à
 * l'utilisateur que le jeu prend fin pour cause de temps imparti sinon le jeu se termine car l'utilisateur à perdu
 * Aucune valeur n'est renvoyée.
 */
void affiche_fin(int score, int bool);

/* Affiche un écran assombri qui indique que le jeu est en pause.
 * L'utilisateur doit appuyer sur la touche espace pour provoquer la mise en pause du jeu.
 * Il suffit de rappuyer sur espace pour reprendre le jeu.
 * Aucune valeur n'est renvoyée.
 */
void afficher_pause();

#endif
