#include <stdlib.h>
#include <time.h>
#include <MLV/MLV_all.h>
#include "includes/graphique.h"
#include "includes/jeu.h"


int main(int argc, char const *argv[]){

    Monde world;
    world = init_monde(10, 2, 100, 100);
	MLV_create_window("Snake", "Snake", FENETRE_X, FENETRE_Y);
    
    afficher_monde(&world);

    MLV_wait_mouse(NULL, NULL);
	MLV_free_window();

    return 0;
}