#include "../headers/sauvegarde.h"


void sauvegarde_partie(Partie game){
    int n, m;
    FILE * fichier = NULL;

    assert(game.pos.player == JOUEUR_1 || game.pos.player == JOUEUR_2);
    assert(game.pos.tableau.tab != NULL);
    assert(game.dim.largeur >= 0);
    assert(game.dim.hauteur >= 0);
    assert(game.gagnant.player1 >= 0);
    assert(game.gagnant.player2 >= 0);

    fichier = fopen("doc/save", "w+");
    fprintf(fichier, "%d %d %d %d ", game.partie_total, game.partie_actuel, game.dim.largeur, game.dim.hauteur);
    fprintf(fichier, "%d %d ", game.gagnant.player1, game.gagnant.player2);

    for (n = 0; n < game.dim.largeur; n++)
        for (m = 0; m < game.dim.hauteur; m++)
            fprintf(fichier, "%d ", game.pos.tableau.tab[n][m]);
    
    fclose(fichier);
    MLV_draw_text(FENETRE_X/2 - 50, FENETRE_Y - 50, "Partie Sauvegardé", MLV_COLOR_RED);
    MLV_actualise_window();
}


void partie_save(Partie *game){

    int n, m, ret;
    FILE* fichier = NULL;

    assert(game != NULL);

	fichier = fopen("doc/save", "r");

    if(fichier == NULL)
        return;
    /* Récupère les numéros des partie total et de la partie en cours.*/
    ret = fscanf(fichier, "%d%d%d%d", &(game->partie_total), &(game->partie_actuel),&(game->dim.largeur), &(game->dim.hauteur));
    ret = fscanf(fichier, "%d%d", &(game->gagnant.player1), &(game->gagnant.player2));
    
    game->pos.tableau.tab = malloc(sizeof(*(game->pos.tableau.tab)) * game->dim.largeur);
 
    for (n = 0; n < game->dim.largeur; n++)
        game->pos.tableau.tab[n] = malloc(sizeof(**(game->pos.tableau.tab)) * game->dim.hauteur);

    for (n = 0; n < game->dim.largeur && ret != 0; n++)
        for (m = 0; m < game->dim.hauteur && ret != 0; m++)
            ret = fscanf(fichier, "%d", &(game->pos.tableau.tab[n][m]));

    fclose(fichier);
}