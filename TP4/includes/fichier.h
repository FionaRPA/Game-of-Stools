#ifndef __FICHIER__
#define __FICHIER__

#include <stdio.h>
#include "liste.h"

/* Ajoute le chemin du fichier dans son nom. */
void chemin_fichier(char* nouv, char* fichier);

/* Modifie l'extension de "nom" pour qu'elle devient ".extension" avec "extension" passé en paramètre,
 * le nom modifié est envoyé à "nouv".
 */
void change_ext(char* nom, char* extension, char* nouv);


/* Ecris le contenu de "lst" dans un fichier "nom".clm . */
int ecrire_liste(char* nom, Liste lst);

#endif