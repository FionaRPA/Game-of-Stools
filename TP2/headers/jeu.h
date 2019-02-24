#ifndef JEU_H
#define JEU_H


/* 
 * La fonction modifie les valeurs de la case (x,y), deux entier donnés en paramètre, 
 * on les modifie en 0, ainsi que toutes ses cases en bas et à droite. C'est à dire les 
 * cases ayant des coordonnées égales ou supérieures à x et y.
 * Ces modification ont lieu dans le tableau t donné grace à la variable dim donné en paramètre.
 * 
 * Aucune valeur n'est renvoyée.
 */
void manger(Tablette *t, int x, int y, Dimension dim);


/* 
 * Cette fonction prend en paramètre deux pointeurs : *pos de type Position et *coup 
 * de type Coup, elle vérifie si le coup joué est possible (si la position du coup dans 
 * la Tablette est égal à 1) ou non.
 * 
 * Elle renvoi 1 si le coup est valide et 0 sinon.
 */
int est_legal(Position *pos, Coup *coup);


/* 
 * Cette fonction vérifie si le jeu est terminé en verifiant si la case (0,0) de la 
 * Tablette est égal à 0, et evalu *joueur_gagnant par le joueur qui a gagné.
 * 
 * La Tablette est donnée en paramètre en tant que pointeur avec le type Position et 
 * de meme avec le joueur _gagnant qui donné avec le type Joueur.
 * 
 * Elle renvoie 1 si la partie est terminé et 0 sinon.
 */
int est_jeu_termine(Position *pos, Joueur *joueur_gagnant);

/* 
 * Le fonction jouer_coup vérifie si le coup joué est légal en faisant appel à la 
 * fonction est_legal(), si le coup est possible on utilise la fonction manger() pour 
 * modifier le contenue de la tablette à la localisation du coup. Ensuite on change le joueur 
 * qui vient de jouer le coup par l'autre joueur.
 * 
 * La fonction prend deux pointeurs en paramètre *pos de type Position et *coup de type Coup ainsi que la taille
 * dim de la tablette de type Dimension.
 * 
 * Elle renvoi 1 si le coup joué est valide et 0 sinon.
 */
int jouer_coup(Position *pos, Coup *coup, Dimension dim);

/*
 * La fonction prend en paramètre en tant que pointeur la partie en cours.
 * Tant que le nombre de partie donnée par les joueurs n'est pas atteint on continu le bon 
 * déroulement du jeu. A la fin du jeu on affiche le gagnant et on redemande aux joueurs s'ils
 * veulent rejouer ou quitter la partie.
 *
 * Aucune valeur de retour n'est renvoyée.
 */
void partie_jeu(Partie *game);


#endif