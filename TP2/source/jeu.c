#include "../headers/jeu.h"


void manger(Tablette *t, int x, int y, Dimension dim){
    int i, j;

    assert(x >= 0);
    assert(y >= 0);
    assert(t != NULL);
    assert(dim.largeur >= 0);
    assert(dim.hauteur >= 0);
    
    for(i = x; i < dim.largeur; i++)
        for(j = y; j < dim.hauteur; j++)
            t->tab[i][j] = 0;
}


int est_legal(Position *pos, Coup *coup){
    int pos_x = coup->x;
    int pos_y = coup->y;

    assert(pos != NULL);
    assert(coup != NULL);

    if(pos->tableau.tab[pos_x][pos_y] == 1)
        return 1;
    return 0;
}


int est_jeu_termine(Position *pos, Joueur *joueur_gagnant){

    assert(pos != NULL);
    assert(joueur_gagnant != NULL);

    if(pos->tableau.tab[0][0] == 0){
        (*joueur_gagnant) = pos->player;
        return 1;
    }
    return 0;
}


int jouer_coup(Position *pos, Coup *coup, Dimension dim){
    
    assert(pos != NULL);
    assert(coup != NULL);
    assert(dim.largeur >= 0);
    assert(dim.hauteur >= 0);


    if (coup->x == -1 && coup->y == -1)
        return 2;

    if (est_legal(pos, coup)){
        manger(&(pos->tableau), coup->x, coup->y, dim);  
        if (pos->player == JOUEUR_1)
            pos->player = JOUEUR_2;
        else
            pos->player = JOUEUR_1;
        return 1;
    }
    return 0;
}


void rejouer_ou_quitter(Partie *game){
    int x, y;

    assert(game != NULL);

    MLV_draw_text_box(FENETRE_X / 2 - 150, FENETRE_Y / 2 + 120, 300, 50, "Rejouer ?", 9,  MLV_COLOR_SANDY_BROWN, MLV_COLOR_SANDY_BROWN,  MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(FENETRE_X / 2 - 150, FENETRE_Y / 2 - 220, 300, 50, "Quitter ?", 9,  MLV_COLOR_SANDY_BROWN, MLV_COLOR_SANDY_BROWN,  MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);

    
    MLV_actualise_window();

    /*Pour commencer une nouvelle partie. */
    MLV_wait_mouse(&x, &y);

    while(!(x >= FENETRE_X / 2 - 150 && x <= ((FENETRE_X / 2 - 150) + 300) && y >= FENETRE_Y / 2 + 120 && y <= (FENETRE_Y / 2 + 120) + 50)
          && !(x >= FENETRE_X / 2 - 150 && x <= ((FENETRE_X / 2 - 150) + 300) && y >= FENETRE_Y / 2 - 220 && y <= (FENETRE_Y / 2 - 220) + 50))
        MLV_wait_mouse(&x, &y);
    

    if (x >= FENETRE_X / 2 - 150 && x <= ((FENETRE_X / 2 - 150) + 300) && y >= FENETRE_Y / 2 - 120 && y <= (FENETRE_Y / 2 + 120) + 50) {
        if (game->pos.player == JOUEUR_1)
            game->pos.player = JOUEUR_2;
        else
            game->pos.player = JOUEUR_1;
        game->partie_actuel = 0;
        game->gagnant.player1 = 0;
        game->gagnant.player2 = 0;
        partie_jeu(game);

    }

    if (x >= FENETRE_X / 2 - 150 && x <= ((FENETRE_X / 2 - 150) + 300) && y >= FENETRE_Y / 2 - 120 && y <= (FENETRE_Y / 2 - 220) + 50)
        exit(EXIT_FAILURE);

    
    MLV_actualise_window();

}

void partie_jeu(Partie *game){
    Coup coup;
    Joueur joueur_g;

    assert(game != NULL);

    
    /*Le jeu continue tant que le nombre de partie obtenu n'est pas joué.*/
    for(; game->partie_actuel < game->partie_total; game->partie_actuel++){
        /* Partie continue tant qu'il n'y a aucun perdant et gagnant. */
        while(est_jeu_termine(&(game->pos), &joueur_g) != 1){
            afficher_position(&(game->pos), game->partie_actuel, game->partie_total, game->dim, game->gagnant);
            coup = lire_coup(game);
            if (jouer_coup(&(game->pos), &coup, game->dim) == 2)
                exit(EXIT_FAILURE);
        }
        affiche_gagnant(joueur_g, &(game->gagnant));
        /*Réaffiche une nouvelle tablette à chaque partie.*/
        game->pos.tableau = creer_tablette(game->dim);
    }
    rejouer_ou_quitter(game);
}
