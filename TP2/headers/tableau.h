#ifndef TABLEAU_H
#define TABLEAU_H

/* 
 * Cette fonction sert à afficher le contenu de la Tablette tab donné en parmètre qui a pour taille les valeurs
 * de la variable dim de type Dimension qui est en paramètre.
 * Son utilité est seulement sur la console voir si le contenu à bien été modifié.
 * 
 * Aucune valeur n'est renvoyée.
 */
void afficher_tab(Tablette t, Dimension dim);

/* 
 * La fonction prend en paramètre les dimension de la tablette du jeu qui va se lancer. 
 * Elle crée une nouvelle variable de type Tablette, et toutes les cases de ce Tableau 
 * seront initialisées à 1.
 * 
 * Renvoi le tableau du type Tablette obtenue.
 */
Tablette creer_tablette(Dimension dim);

#endif