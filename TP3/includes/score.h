#ifndef __SCORE__
#define __SCORE__

#include <MLV/MLV_all.h>
#include "graphique.h"


/*
 * La fonction afficheScore regarde si le score est dans le top 3, puis on inscrit dans le
 * fichier "score.txt" le score et le nom du joueur donnée en paramètre, s'il en fait partie.
*/
void afficheScore(int joueurScore, char *nom);



#endif
