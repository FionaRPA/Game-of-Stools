
/* Auteurs: Zineb SDAF - Preanthy RAVENDRAN
 * Date Creéation: 05-02-2019
 * Dernière Modification: 18-02-2019
 * */
#include "headers/structure.h"
#include "source/menu.c"
#include "source/tableau.c"
#include "source/sauvegarde.c"
#include "source/graphique.c"
#include "source/jeu.c"


int main(int argc, char const *argv[]){
    
	Partie game;
    
    creer_fenetre(&game);

    partie_jeu(&game);

    MLV_free_window();

    return 0;
}
