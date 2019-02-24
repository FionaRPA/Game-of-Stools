#include "../headers/graphique.h"

void afficher_position(Position *pos, int partie_actuel, int partie_total, Dimension dim, Score gagnant){
    int n, m, x, y, larg, haut;

    assert( partie_total >= 0);
    assert( partie_actuel >= 0);
    assert(pos != NULL);
    assert(dim.largeur >= 0);
    assert(dim.hauteur >= 0);
    assert(gagnant.player1 >= 0);
    assert(gagnant.player2 >= 0);



    MLV_clear_window(MLV_COLOR_BLACK);

    larg = ((FENETRE_X - 20) / dim.hauteur);
    haut = ((FENETRE_Y - 300) / dim.largeur);

    x = 10;
    y = 150;

    for (n = 0; n < dim.largeur; n++){
        for (m = 0; m < dim.hauteur; m++){
            if (pos->tableau.tab[n][m] == 1){
                if (pos->player == JOUEUR_1){
                    /* Affiche le tour du Joueur 1 en marron*/
                    MLV_draw_text_box(FENETRE_X / 2 - 100, FENETRE_Y - (FENETRE_Y - 30), 150, 30, "Tour du Joueur 1", 9,  MLV_COLOR_BLACK, MLV_COLOR_BLACK,  MLV_COLOR_CHOCOLATE4, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
                    MLV_draw_filled_rectangle(x, y, larg, haut, MLV_COLOR_CHOCOLATE4);
                    MLV_draw_rectangle(x, y, larg, haut, MLV_COLOR_SANDY_BROWN);
                }
                else {
                    /* Affiche le tour du Joueur 2 en blanc*/
                    MLV_draw_text_box(FENETRE_X / 2 - 100, FENETRE_Y - (FENETRE_Y - 30), 150, 30, "Tour du Joueur 2", 9,  MLV_COLOR_BLACK, MLV_COLOR_BLACK,  MLV_COLOR_BEIGE, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
                    MLV_draw_filled_rectangle(x, y, larg, haut, MLV_COLOR_BEIGE);
                    MLV_draw_rectangle(x, y, larg, haut, MLV_COLOR_SANDY_BROWN);
                }
            }
            x = x + larg;
        }
        x = 10;
        y = y + haut;
    }
    MLV_draw_filled_circle(10 + larg/2, 150 + haut/2, 5, MLV_COLOR_SANDY_BROWN);
    MLV_draw_text_box(50, FENETRE_Y - (FENETRE_Y - 30), 150, 30, "Partie %d / %d", 9,  MLV_COLOR_SANDY_BROWN, MLV_COLOR_SANDY_BROWN,  MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER, partie_actuel + 1, partie_total);
    MLV_draw_text_box(50, FENETRE_Y - 50, 150, 30, "Sauvegarder Partie", 9,  MLV_COLOR_SANDY_BROWN, MLV_COLOR_SANDY_BROWN,  MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(FENETRE_X - 200, FENETRE_Y - 50, 150, 30, "Quitter", 9,  MLV_COLOR_SANDY_BROWN, MLV_COLOR_SANDY_BROWN,  MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text(FENETRE_X - 200, 20, "Joueur 1: %d", MLV_COLOR_CHOCOLATE4, gagnant.player1);
    MLV_draw_text(FENETRE_X - 200, 50, "Joueur 2: %d", MLV_COLOR_BEIGE, gagnant.player2);
    MLV_actualise_window();
}


Coup lire_coup(Partie *game){
    int posx, posy, i, j, larg, haut, X, Y;
    Coup coup;
    
    assert(game != NULL);

	coup.x = -1;
    coup.y = -1;

    larg = ((FENETRE_X - 20) / game->dim.hauteur);
    haut = ((FENETRE_Y - 300) / game->dim.largeur);

    X = 10;
    Y = 150;

    while (coup.x < 0 || coup.y < 0){
        
        MLV_wait_mouse(&posx, &posy);
        /* Bouton Quitter*/
        if (posx < (FENETRE_X - 50) && posx > (FENETRE_X - 200))
            if (posy < (FENETRE_Y - 20) && posy > (FENETRE_Y - 50))
				return coup;

		/* Bouton Sauvegarde*/
        if (posx < 250 && posx > 100)
            if (posy < (FENETRE_Y - 20) && posy > (FENETRE_Y - 50))
                sauvegarde_partie(*game);

        for (i = 0; i < game->dim.largeur ; i++)
            for (j = 0; j < game->dim.hauteur; j++)
                if (posx > (X + larg * j) && posx < (X + larg * (j + 1)))
                    if (posy > (Y + haut * i) && posy < (Y + haut * (i + 1)))
                        if (game->pos.tableau.tab[i][j] == 1) {
                            coup.x = i;
                            coup.y = j;
                        }
    }
    return coup;
}


void affiche_gagnant(Joueur joueur_g, Score *gagnant){

    assert(joueur_g == JOUEUR_1 || joueur_g == JOUEUR_2);
    assert( gagnant != NULL);

    if(joueur_g == JOUEUR_1){
        /* Affiche le Joueur 1 gagnant.*/
        MLV_clear_window(MLV_COLOR_BLACK);
        MLV_draw_text_box(FENETRE_X / 2 - 150, FENETRE_Y / 2 - 60, 300, 50, "Joueur 1 Gagnant", 9,  MLV_COLOR_SANDY_BROWN, MLV_COLOR_SANDY_BROWN,  MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
        gagnant->player1++;

    }
    else{
        /* Affiche le Joueur 2 gagnant.*/
        MLV_clear_window(MLV_COLOR_BLACK);
        MLV_draw_text_box(FENETRE_X / 2 - 150, FENETRE_Y / 2 - 60, 300, 50, "Joueur 2 Gagnant", 9,  MLV_COLOR_SANDY_BROWN, MLV_COLOR_SANDY_BROWN,  MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
        gagnant->player2++;
    }
    MLV_actualise_window();
    MLV_wait_mouse(NULL, NULL);
}


void nombre_partie(int *partie_total){
    char *chaine1, *chaine2;
    int nb1, nb2;

    assert( partie_total != NULL);
    
    /*Demande le nombre partie que chaque joueur veut jouer*/
	MLV_clear_window(MLV_COLOR_BLACK);
	MLV_wait_input_box_with_font(FENETRE_X/2 - 200, 100, 400, 100, MLV_COLOR_SANDY_BROWN, MLV_COLOR_SANDY_BROWN, MLV_COLOR_BLACK, "Nombre de Partie Joueur 1: ", &chaine1,  MLV_load_font( "image/KeepCalm-Medium.ttf" , 20 ));
	MLV_wait_input_box_with_font(FENETRE_X/2 - 200, 400, 400, 100, MLV_COLOR_SANDY_BROWN, MLV_COLOR_SANDY_BROWN, MLV_COLOR_BLACK, "Nombre de Partie Joueur 2: ", &chaine2,  MLV_load_font( "image/KeepCalm-Medium.ttf" , 20 ));

    nb1 = atoi(chaine1);
    nb2 = atoi(chaine2);

    free(chaine1);
    free(chaine2);

    *partie_total = (nb1 + nb2)/2;
    MLV_draw_text_box(FENETRE_X / 2 - 150, FENETRE_Y / 2 - 60, 300, 50, "Vous allez jouer %d partie", 9,  MLV_COLOR_SANDY_BROWN, MLV_COLOR_SANDY_BROWN,  MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER, *partie_total);
    MLV_actualise_window();
    MLV_wait_mouse_or_seconds(NULL, NULL, 2);
}


void choix_taille(int *n, int *m){
    char *chaine1, *chaine2;
    
    assert( n != NULL);
    assert( m != NULL);

    /*Demande la taille que le joueur désire*/
    MLV_clear_window(MLV_COLOR_BLACK);
    MLV_wait_input_box_with_font(FENETRE_X/2 - 200, 100, 400, 100, MLV_COLOR_SANDY_BROWN, MLV_COLOR_SANDY_BROWN, MLV_COLOR_BLACK, "Largeur de la Tablette: ", &chaine1,  MLV_load_font( "image/KeepCalm-Medium.ttf" , 20 ));
    MLV_wait_input_box_with_font(FENETRE_X/2 - 200, 400, 400, 100, MLV_COLOR_SANDY_BROWN, MLV_COLOR_SANDY_BROWN, MLV_COLOR_BLACK, "hauteur de la Tablette: ", &chaine2,  MLV_load_font( "image/KeepCalm-Medium.ttf" , 20 ));

    *n = atoi(chaine1);
    *m = atoi(chaine2);

    free(chaine1);
    free(chaine2);
}


void choix(Partie *game){
    int x, y;

    assert(game != NULL);

    MLV_clear_window(MLV_COLOR_BLACK);

    MLV_draw_text_box(FENETRE_X / 2 - 150, FENETRE_Y / 2 - 10, 300, 50, "Tablette fixe", 9,  MLV_COLOR_SANDY_BROWN, MLV_COLOR_SANDY_BROWN,  MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(FENETRE_X / 2 - 150, FENETRE_Y / 2 - 120, 300, 50, "Créer tablette", 9,  MLV_COLOR_SANDY_BROWN, MLV_COLOR_SANDY_BROWN,  MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_actualise_window();
    MLV_wait_mouse(&x, &y);

    /*Pour commencer une nouvelle partie avec une tablette fixe. */
    if (x >= FENETRE_X / 2 - 150 && x <= ((FENETRE_X / 2 - 150) + 300) && y >= FENETRE_Y / 2 - 10 && y <= FENETRE_Y / 2 + 60){
        game->dim.largeur = N;
        game->dim.hauteur = M;
    }
    /*Pour commencer une nouvelle partie avec une tablette de taille choisi. */
    if (x >= FENETRE_X / 2 - 150 && x <= ((FENETRE_X / 2 - 150) + 300) && y >= FENETRE_Y / 2 - 120 && y <= (FENETRE_Y / 2 - 60) - 10) {
        choix_taille(&(game->dim.largeur), &(game->dim.hauteur));
    }
    MLV_actualise_window();


}

void creer_fenetre(Partie *game){
    int res;

    assert(game != NULL);

    game->pos.player = JOUEUR_1;
    game->partie_actuel = 0;
    game->gagnant.player1 = 0;
    game->gagnant.player2 = 0;

    MLV_create_window("Chocolat", "TP2", FENETRE_X, FENETRE_Y);
    MLV_actualise_window();
    res = menu();
    
    if(res == 0){
        choix(game);
        game->pos.tableau = creer_tablette(game->dim);
        nombre_partie(&(game->partie_total));
    }
    else if (res == 1)
        partie_save(game);
}


