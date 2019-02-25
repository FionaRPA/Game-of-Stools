#ifndef __MONDE__
#define __MONDE__

#include "quadrillage.h"
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <MLV/MLV_all.h>


typedef enum{
	NORD,
	SUD,
	EST,
	OUEST
}Direction;


typedef struct{
	Case *coordS;
	int taille;
	Direction dir;
}Serpent;


typedef struct{
	Case coordP;
	int point;
}Pomme;


typedef struct{
	Serpent snake;
	Pomme *pommes;
	int pommes_presentes;
	int pommes_mangees;
	int lignes;
	int colonnes;
}Monde;



/* Renvoie une pomme générée aléatoirement de sorte qu'elle tienne
 * dans un quadrillage n*m. */
Pomme pomme_gen_alea(int n, int m);


/* 	La fonction renvoie 1 si la case est vide ou 0 dans le cas contraire. */
int est_vide(Monde *mon, Case cases);


/* Ajoute une pomme dans le monde, en vérifiant d'abord que la case est vide. */
void ajouter_pomme_monde(Monde *mon, int max_pommes);


/* Renvoie un serpent dont la tête est située au centre et sa seule partie du corps est située
 * à gauche de sa tête, la direction du serpent est l'Est. */
Serpent init_serpent(int taille, int nb_lignes, int nb_colonnes);



/* De la même façon que ajouter_pomme_monde(), cette fonction ajoute une pomme empoisonnée. */
void ajouter_pomme_empoisonnee(Monde *mon, int nb_empoisonnee);


/* Renvoie un monde avec `nb_pommes` pommes présentes, le serpent se trouve à sa
 * position initiale. */
Monde init_monde(int nb_pommes, int taille_serpent, int nb_lignes, int nb_colonnes);


/* Renvoie la case situé à une case du serpent selon sa direction. */
Case case_suivante(Monde mon);


/* Ajoute la case `nouveau` en tête de liste `lst` et supprime le dernier élément. */
void ajout(Case lst[], int taille, Case nouv);


/* Modifie `mon` pour que le serpent se déplace d'une case suivant sa direction.
 * Renvoie 1 si le serpent s'est déplacé sur une case vide et 0 si la case dans laquelle
 * le serpent souhaite se déplacer est non vide, le serpent ne se déplace pas dans ce cas. */
int deplacer_serpent(Monde *mon);


/* Supprime une pomme dans la liste des pommes à l'indice `indice` en décalant la pomme à
 * supprimer vers la fin de la liste. */
void supprime_pomme(Monde *mon, int indice);


/* Si la prochaine case du serpent est une pomme, on la supprime et on fait avancer le serpent,
 * il grandit ainsi et la fonction renvoie 1. Sinon on ne fait rien et la fonction renvoie 0. */
int manger_pomme_serpent(Monde *mon);


/* Renvoie 1 si le serpent est mort et 0 si il est encore en vie */
int mort_serpent(Monde *mon);


/* Change la direction du serpent en fonction de la touche donnée en paramètre.
 * Ne change rien si la touche n'est pas une flèche directionnelle, ou si le serpent fait demi-tours. */
void changer_direction(Serpent *snake, MLV_Keyboard_button direction);



#endif
