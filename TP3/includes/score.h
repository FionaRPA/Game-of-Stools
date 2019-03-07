#ifndef __SCORE__
#define __SCORE__

#include <MLV/MLV_all.h>
#include "graphique.h"



/* Prend en paramètre un entier qui correspond au score du joueur (joueurScore), d'un char* nom
 * nom qui a été donné par l'utilisateur et d'un entier temps qui correspond au temps effectué
 * par le joueur.
 * La fonction afficheScore regarde si le score est dans le top 3, puis on inscrit dans le
 * fichier "score.txt" le score et le nom du joueur donnée en paramètre, s'il en fait partie.
 * Aucune valeur n'est renvoyée.
*/
void afficheScore(int joueurScore, char *nom, int temps);



#endif
