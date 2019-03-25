#ifndef __OPTION__
#define __OPTION__

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "liste.h"


/* Retourne 1 si une des options (a,n,s,p,e) est présente et 0 sinon.
 * Renvoie 0 si au moins 2 options entre (s,p,e) ou aucune sont présentes,
 * ou si a et n sont présent, ou encore si un caractère inconnu est présent.
 */
int options(char *argv[], int argc, char* mot, int* nb, int* option_a, int* option_n, int* option_s, int* option_p, int* option_e);


#endif