
#include <MLV/MLV_all.h>
#include <stdlib.h>
#include <stdio.h>

/*
 *	Ce programme affiche un rectangle rouge dans une fenetre de
 *  longueur 700 et de largeur 700.
 *	Si l'utilisateur clic dans le rectangle alors il change de couleur,
 *	en passant de rouge à bleu et inversement.
 *	Si l'utilisateur clic en dehors du rectangle alors la fenetre 
 *	est fermée.
 */


int main(int argc, char const *argv[]){

	int taille_fX = 700, taille_fY = 700;
	int x, y, i=0;

	MLV_create_window("", "", taille_fX, taille_fY);
	/*Attente d'un clic de l'utilisateur*/
	MLV_wait_mouse(NULL, NULL);
	/*Dessine un rectangle Rouge*/
	MLV_draw_filled_rectangle(taille_fX-450, taille_fY-450, 150, 100, MLV_COLOR_RED);
	MLV_actualise_window();
	/*Attend de nouveau un clic de l'utilisateur*/
	MLV_wait_mouse(&x, &y);

	/*Tant que l'utilisateur n'a pas cliquer hors du rectangle dessiné alors il sera dans cette boucle*/
	while((x >= taille_fX-450 && x <= 400) && (y >= taille_fY-450 && y <= 350)){
		/*Lors du clic, on efface la fenêtre, puis on l'affiche de nouveau avec un rectangle d'une autre couleur*/
		MLV_clear_window(MLV_COLOR_BLACK);
		/*On a un compteur i pour dessiner les rectangle au fur et à mesure	*/	
		if(i % 2 == 0)
			MLV_draw_filled_rectangle(taille_fX-450, taille_fY-450, 150, 100, MLV_COLOR_BLUE);
		else
			MLV_draw_filled_rectangle(taille_fX-450, taille_fY-450, 150, 100, MLV_COLOR_RED);
		MLV_actualise_window();
		MLV_wait_mouse(&x, &y);
		/*incrémentation de i pour faire un rectangle d'une autre rectangle*/
		i++;
	}
	/*Sort de la boucle si l'utilisateur clic autour du rectangle*/
	MLV_free_window();

	return 0;
}