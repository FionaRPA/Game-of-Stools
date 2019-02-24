
#include <MLV/MLV_all.h>
#include <stdlib.h>
#include <stdio.h>


/*
 *	Ce programme affiche un rectangle bleu dans une fenetre de
 *  longueur 500 et de largeur 500.
 *	On ferme la fenetre une fois que l'utilisateur clic dans la fenetre.
 */


int main(int argc, char const *argv[]){
	
	MLV_create_window("", "", 500, 500);
	MLV_draw_rectangle(200, 200, 100, 200, MLV_COLOR_BLUE);
	MLV_actualise_window();
	MLV_wait_mouse(NULL, NULL);
	MLV_free_window();

	return 0;
}