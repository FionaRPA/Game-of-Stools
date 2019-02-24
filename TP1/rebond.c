
#include <MLV/MLV_all.h>
#include <stdlib.h>
#include <stdio.h>
#define TAILLE_FX 700
#define TAILLE_FY 700

/*	
 *	Fonction qui prend en argument les positions du rectangle ainsi que sa destination voulue.
 *	Permet de déplacer de rectangle du nord-est au sud-ouest de manière rebondi jusqu'à que l'utilisateur 
 *	appuie sur la touche entrée (qui se trouve près des touches numériques) pour mettre fin au programme.
 */
void move_Rectangle(int dest_x, int dest_y, int *x_rec, int *y_rec){
	MLV_Button_state entree;
	/*Tant que la positions du rectangle en x et y n'est pas identique à la destination donnée en paramètre*/
	while ( *x_rec != dest_x && *y_rec != dest_y ) {
		/*Prend le statut du bouton ENTRÉE qui se trouve à droite avec les chiffre*/
		entree = MLV_get_keyboard_state( MLV_KEYBOARD_KP_ENTER );
		/*Si il est pressé alors */
		if( entree == MLV_PRESSED)
			/*On provoque la fin de l'éxécution du programme*/
			exit(EXIT_FAILURE);
		else{
			/*Dessine le rectangle*/
			MLV_draw_filled_rectangle(*x_rec, *y_rec, 30, 30, MLV_COLOR_BLUE);
			MLV_actualise_window();
			MLV_wait_milliseconds(15);
			MLV_clear_window(MLV_COLOR_WHITE);
			/*Si la destination y vaut 0 alors on incrémente x_rec de 1 et désincremente y de 1*/
			if(dest_y == 0){
				*x_rec += 1;
				*y_rec -= 1;
			}
			/*Sinon le contraire*/
			else{
				*x_rec -= 1;
				*y_rec += 1;	
			}
		}
	}
}

int main(int argc, char const *argv[]){
	MLV_Keyboard_button touche;
	int dest_x, dest_y;
	
	int x_rec = TAILLE_FX/2-30, y_rec = TAILLE_FY/2;
	MLV_create_window("", "", TAILLE_FX, TAILLE_FY);
	MLV_clear_window(MLV_COLOR_WHITE);

	MLV_draw_filled_rectangle(x_rec, y_rec, 30, 30, MLV_COLOR_BLUE);
	MLV_actualise_window();
	/*On attend que l'utilisateur appuie sur la touche entrée*/
	MLV_wait_keyboard(&touche, NULL, NULL);
	/*Tant que touche n'est plus appuyer on lance la fonction move_Rectangle avec 
	pour premiere destination la direction Nord-Est*/
	while(touche != MLV_KEYBOARD_KP_ENTER){
		
			dest_x = TAILLE_FX;
			dest_y = 0;
			move_Rectangle(dest_x, dest_y, &x_rec, &y_rec);

			dest_x = 0;
			dest_y = TAILLE_FY;
			move_Rectangle(dest_x, dest_y, &x_rec, &y_rec);
		

	}

	MLV_free_window();
	return 0;
}

