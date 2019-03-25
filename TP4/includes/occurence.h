#ifndef __OCCURENCE__
#define __OCCURENCE__

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "liste.h"


/* Renvoie 1 si la chaine de caractère `mot` est un mot, et 0 sinon. */
int est_un_mot(char* mot);


/* Transforme toutes les majuscules de la chaine "mot" en minuscule. 
 * Renvoie 0 si un caractère est non alphabétique. 
 */
int maj_to_min(char* mot);


/* Remplis le liste donné en paramètre des mots du fichier "f" 
 * associés de leur occurence. Renvoie 1 si tout s'est bien passé 
 * et 0 sinon. 
 */
int creer_liste(FILE* f, Liste* lst);


/* Crée une liste de mots formée avec l'option -s. */
int creer_liste_s(FILE* f, Liste* lst, char* mot);


/* Crée une liste de mots formée avec l'option -p. */
int creer_liste_p(FILE* f, Liste* lst, char* reference);


/* Crée une liste de mots formée avec l'option -e. */
int creer_liste_e(FILE* f, Liste* lst, int n);

#endif