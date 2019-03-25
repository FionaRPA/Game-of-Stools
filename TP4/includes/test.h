#ifndef __TEST__
#define __TEST__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "occurence.h"
#include "tri.h"
#include "liste.h"
#include "fichier.h"


/* On vérifie dans le fichier test1.txt si les mots obtenus dans le fichier .clm sont identiquent
 * avec le bon nombre d'occurence et le bon ordre d'apparition aux valeurs
 * indiquées dans la fonction. 
 */
int test_creer_liste();


/* Test de l'option "-a". Renvoie 1 si les mots obtenus sont identiquent au test,
 * 0 sinon. */
int test_creer_liste_a();


/* Test de l'option "-n". Renvoie 1 si les mots obtenus sont identiquent au test,
 * 0 sinon. */
int test_creer_liste_n();


/* Test de l'option "-s". Renvoie 1 si les mots obtenus sont identiquent au test,
 * fait avec les fichiers test3.txt et test2.txt 0 sinon. */
int test_creer_liste_s();


/* Test de l'option "-p". Renvoie 1 si les mots obtenus sont identiquent au test,
 * fait avec les fichiers test3.txt et test2.txt 0 sinon. */
int test_creer_liste_p();


/* Test de l'option "-e". Renvoie 1 si les mots obtenus sont identiquent au test,
 * fait avec les fichiers test3.txt et test2.txt 0 sinon. */
int test_creer_liste_e();


/* Appel de toutes les fonctions test sur les trois fichiers test[1,2,3].txt ou 
 * sur les listes crées dans les fonctions. */
int test();


#endif