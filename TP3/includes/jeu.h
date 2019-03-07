#ifndef __JEU__
#define __JEU__


#include "monde.h"
#include "score.h"
#include "graphique.h"
#include "menu.h"
#include <MLV/MLV_all.h>


typedef struct{
	int largeur, hauteur;
	int nb_pommes;
	int taille_serpent;
	int vitesse;
	int duree_tour;
} Partie;


/* Crée une fênetre MLV dans laquelle on affiche le menu et par la suite,
 * l'utilisateur peut soit jouer soit affcher la liste des meilleures scores ou
 * encore quitter le jeu. S'il choisi un des deux premiers choix on 
 * demande le pseudo qu'il desir, puis la partie commence. 
 * Aucune valeur n'est renvoyée.
 */
void creer_fenetre();

/* Fonction principale pour le bon déroulement du jeu qui prend en paramètre le monde 
 * de type Monde* et le temps de type int*. Cette fonction permet de faire toutes les
 * initialisations du jeu. Après l'initialisation, on a la boucle principale du jeu.
 * Dans cette boucle, on génére les déplacements du serpent (changement de direction), 
 * l'apppariton et disparition des pommes mais aussi la mise en pause et reprise du jeu 
 * grâce à la touche espace, le chronomètre qui tourne et le son de fond qui tourne
 * en boucle. 
 * Aucune valeur n'est renvoyée.
 */
void jouer(Monde *monde, int *temps);

/* Prend en paramètre le monde et le temps avec comme type respectif : Monde* et int*.
 * Demande à l'utilisateur s'il veut rejouer une partie ou quitter. 
 * Aucune valeur n'est renvoyée.
 */
void rejouer_ou_quitter(Monde *monde, int *temps);


/* Crée un fichier Serpent.ini dans lequel sont figurés les paramètre du jeu par défaut.
 * Si le fichier existe déjà, la fonction vérifie les valeurs.
 * Renvoie ensuite ces paramètres. 
 */
Partie init_parametres();


#endif
