#ifndef __LISTE__
#define __LISTE__

#define MAX_LETTRE 200

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


typedef struct expression {
	char mot[MAX_LETTRE];
	int occurence;
	struct expression* suivant;
} Mot, *Liste;


/* Alloue l'espace necessaire pour créer une cellule de mot "nom" et 
 * on incrémente son occurence de 1 et renvoie son adresse. 
 */
Liste allouer_mot(char* nom);


/* Ajoute un mot dans le dictionnaire. S'il existe déjà, on incrémente 
 * son occurence. Renvoie 1 si l'allocation s'est bien passée sinon 0. 
 */
int ajouter_mot(Liste* lst, char* nom);


/* Retire un mot dans la liste s'il existe, et renvoie son adresse.
 * Renvoie NULL sinon. 
 */
Liste extraire_mot(Liste* lst, char* mot);


/* Renvoie 1 si "mot" existe dans "lst" et 0 sinon. */
int recherche(Liste lst, char* mot);


/* Affiche chaque mot de la liste avec son occurence du mot. */
void afficher_liste(Liste lst);


/* Renvoie la taille de la liste qui correspond au nombre de mot différents . */
int taille(Liste lst);


/* Libère la mémoire non utilisé par la liste. */
void detruire_liste(Liste *lst);


/* Copie la liste "origine" dans "dest". */
void copie_liste(Liste *origine, Liste *dest);


#endif