#ifndef GRAPHIQUE_H
#define GRAPHIQUE_H

/* 
 * Cette fonction dessine case par case l'état actuel de la Tablette contenu dans pos.
 * Les cases sont dessiné seulement si elles n'ont pas été mangé (égal à 1).
 * On affiche aussi le numéro de la partie en cours.
 * 
 * Aucune valeur n'est renvoyée.
 */
void afficher_position(Position *pos, int partie_actuel, int partie_total, Dimension dim, Score gagnant);

/* 
 * La fonction attend un clic de souris. Si le clique est sur une case déja mangé, ou 
 * à l'extèrieur de la grille redemande un nouveau clic de souris. Sinon donne à coup 
 * (de Type Coup) les coordonnées de la case cliqué.
 * On prend en paramètre la partie ouverte pour récupérer le nombre de partie total et le nombre de partie joué pour
 * les placer dans notre fichier sauvegarde.
 * 
 * Renvoie un coup valide de type Coup en fonction de la position donné en paramètre.
 */
Coup lire_coup(Partie *game);

/* 
 * La fonction affiche le gagnant de la partie à l'écran, en prenant le joueur en 
 * paramètre
 * 
 * Aucune valeur n'est renvoyée.
 */
void affiche_gagnant(Joueur joueur_g, Score *gagnant);

/*
 * La fonction prend en paramètre un pointeur de type entier qui représente le nombre de partie.
 * Demande à l'utilisateur grâce aux boxes le nombre de parties que désire chaque joueur, les valeurs sont ensuite converti en entier. 
 * Ensuite, on fait une moyenne des deux entiers et on indique aux joueurs le nombre final de manche.
 * 
 * Aucune valeur n'est renvoyée.
 */
void nombre_partie(int *partie_total);


/*
 * Fonction qui prend en paramètre deux pointeurs de type entier.
 * Demande à l'utilisateur grâce aux boxes la taille de la hauteur et largeur désirée de sa tablette de chocolat
 * qui seront assignées aux deux pointeurs respectifs. Les valeurs entrées sont converti en entier pour par la suite 
 * les utiliser lors de la création de la tablette.
 * 
 * Aucune valeur n'est renvoyée.
 */
void choix_taille(int *n, int *m);


/*
 * Fonction qui prend en paramètre la partie actuel.
 * Elle permet d'assigné à la largeur et hauteur de la tablette :
 * - les valeurs définies 8 et 16;
 *           ou
 * - les valeurs que le joueur a décidés.
 * 
 * Aucune valeur de retour.
 */
void choix(Partie *game);


/* 
 * Ouvre une fenêtre pour le jeu et affiche le menu du jeu, pour commencé une partie
 * sauvegardé ou non.
 * 
 * Aucune valeur n'est renvoyée.
 */
void creer_fenetre(Partie *game);


#endif