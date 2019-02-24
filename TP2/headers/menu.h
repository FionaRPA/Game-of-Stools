#ifndef MENU_H
#define MENU_H


/*
 * La fonction récupère les dimensions nécessaire pour faire un rectangle en fonction
 * du nom, de la taile, de la largeur et de la hauteur donné en paramètre.
 * 
 * Aucune valeur n'est renvoyée.
 */
void recupereDimensionBouton(char nom[], int taille, int *largeur, int *hauteur);


/*
 * Cette fonction place les différents boutons sur la fenêtre en fonction de la dimension
 * recupéré.
 * 
 * Aucune valeur n'est renvoyée.
 */
void placeBouton(char nom[], int x, int y, float taille, MLV_Color couleur, Bouton *zone);


/*
 * Affiche le menu complet avec le nom principale et le début de partie qui peut se faire
 * avec une partie sauvegardé ou une nouvelle partie.
 * 
 * Aucune valeur n'est renvoyée.
 */
int menu();


#endif
