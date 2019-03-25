#ifndef __TRI__
#define __TRI__

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "liste.h"


/* Renvoie l'adresse du mot ayant la plus grande occurence dans "lst",
 * NULL si la liste est vide.
 */
Liste max_occurence(Liste lst);


/* Renvoie l'adresse du plus petit mot (ordre lexicographique) dans 
 * "lst" sur l'intervalle [debut, fin[, et NULL si la liste est vide.
 * Si fin est négatif, on regarde jusqu'à la fin de la liste. 
 */
Liste min_lexico(Liste lst, int debut, int fin);


/* Fait un tri par insertion dans la liste en fonction de son nombre 
 * d'occurence. */
void trier_occurence(Liste *lst);


/* Tri par insertion des mots de la liste en fonction des noms des mots.*/
void trier_lexico(Liste *lst, int debut, int fin);

#endif