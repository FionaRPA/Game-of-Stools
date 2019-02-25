#include "../includes/graphique.h"

void afficher_quadrillage(Monde *mon){
    int i, j, larg, haut;
    int x, y;

    assert(mon != NULL);

    larg = ((FENETRE_X - 10) / mon->colonnes);
    haut = ((FENETRE_Y - 80) / mon->lignes);

    y = 5;
    x = 5;
    /* Affichage du fond. */
    MLV_clear_window(COULEUR_FOND);
    /* Affichage des cases. */
    for (i = 0; i < mon->lignes; i++){
        for (j = 0; j < mon->colonnes; j++){
            MLV_draw_rectangle(x, y, larg, haut, COULEUR_QUADRILLAGE);
            x += larg;
        }
        x = 5;
        y += haut;
    }
}


void load_image(char* file, int larg, int haut, int pos_x, int pos_y){
    MLV_Image *image;
    image = MLV_load_image(file);
    MLV_resize_image_with_proportions(image, larg + 5, haut + 5);
    MLV_draw_image(MLV_copy_image(image), pos_x, pos_y);
    MLV_free_image(image);
}


void afficher_pomme(Pomme *pom, int nb_lignes, int nb_colonnes, char* file){
		int pos_x, pos_y/*, rayon*/;
		int larg, haut;

		assert(NULL != pom);

		larg = ((FENETRE_Y - 80) / nb_lignes);
		haut = ((FENETRE_X - 10) / nb_colonnes);
		pos_x = pom->coordP.y * haut + 5;
		pos_y = pom->coordP.x * larg;

		/*rayon = ((FENETRE_X / nb_colonnes) / 2) * 0.8;

		MLV_draw_filled_circle(pos_x + rayon, pos_y + rayon, rayon, COULEUR_POMME_CONTOUR);
		MLV_draw_filled_circle(pos_x + rayon, pos_y + rayon, rayon - 2, MLV_COLOR_GOLD);

    */load_image(file, larg, haut, pos_x, pos_y);
}


void afficher_serpent(Serpent *ser, int nb_lignes, int nb_colonnes){
    int pos_x, pos_y/*, rayon*/;
    int i, larg, haut;

    assert(NULL != ser);

    /* On affiche la tête du serpent. */
    larg = ((FENETRE_Y - 80) / nb_lignes);
    haut = ((FENETRE_X - 10) / nb_colonnes);

    pos_x = ser->coordS[0].y * haut + 5;
    pos_y = ser->coordS[0].x * larg + 5;

/*    rayon = ((FENETRE_X / nb_colonnes) / 2) * 0.8;
    MLV_draw_filled_circle(pos_x + rayon, pos_y + rayon, rayon, COULEUR_TETE_CONTOUR);
    MLV_draw_filled_circle(pos_x + rayon, pos_y + rayon, rayon - 2, COULEUR_TETE);

*/	load_image("../doc/image/serpent.png", larg, haut, pos_x, pos_y);

    /* On affiche le corps. */
    for (i = 1; i < ser->taille; i++){
        pos_x = ser->coordS[i].y * haut + 5;
        pos_y = ser->coordS[i].x * larg + 5;

        MLV_draw_filled_rectangle(pos_x, pos_y, haut, larg, COULEUR_CORPS);
        MLV_draw_rectangle(pos_x, pos_y, haut, larg, COULEUR_CORPS_CONTOUR);
    }
}


void afficher_monde(Monde *mon, int temps){
    int i;
    MLV_Font *police;

    assert(mon != NULL);

    afficher_quadrillage(mon);

    for (i = 0; i < mon->pommes_presentes; i++){
        if (mon->pommes[i].point == 2)
            afficher_pomme(&(mon->pommes[i]), mon->lignes, mon->colonnes, "../doc/image/pomme-or.png");
        else if(mon->pommes[i].point == 1)
            afficher_pomme(&(mon->pommes[i]), mon->lignes, mon->colonnes, "../doc/image/pomme-rouge.png");
        else
          afficher_pomme(&(mon->pommes[i]), mon->lignes, mon->colonnes, "../doc/image/pomme-empoisonnee.png");
    }
    afficher_serpent(&(mon->snake), mon->lignes, mon->colonnes);

    /* On affiche le nombre de pommes mangées sur la tête du serpent. */
    police = MLV_load_font("../doc/font/coolvetica_rg.ttf", 50);
    MLV_draw_text_with_font(10, FENETRE_Y - 60, "Score: %d", police, COULEUR_TEXTE, mon->pommes_mangees);
		MLV_draw_text_with_font(FENETRE_X - 250, FENETRE_Y - 60, "Chrono: %d", police,  COULEUR_TEXTE, temps);

    MLV_free_font(police);

    MLV_actualise_window();
}


void affiche_fin(int score, int bool){
    int largeur_texte, hauteur_texte;
    MLV_Font *police;

    assert(score >= 0);

    MLV_clear_window(COULEUR_FOND);

    police = MLV_load_font("../doc/font/coolvetica_rg.ttf", FENETRE_X * 0.1 );
		if (bool){
			MLV_get_size_of_text_with_font( "Fin du temps imparti", &largeur_texte, &hauteur_texte, police);
			MLV_draw_text_with_font((FENETRE_X - largeur_texte) / 2, (FENETRE_Y - hauteur_texte) / 2, "Fin du temps imparti", police, COULEUR_TEXTE);
			MLV_actualise_window();
			MLV_wait_mouse(NULL, NULL);
			MLV_clear_window(COULEUR_FOND);
		}

    MLV_get_size_of_text_with_font("GAME OVER", &largeur_texte, &hauteur_texte, police);
    MLV_draw_text_with_font((FENETRE_X - largeur_texte) / 2, FENETRE_Y * 0.1, "GAME OVER", police, COULEUR_TEXTE);

    MLV_draw_line(FENETRE_X * 0.2, FENETRE_Y * 0.1 + hauteur_texte, FENETRE_X * 0.8, FENETRE_Y * 0.1 + hauteur_texte, COULEUR_TEXTE);

    MLV_get_size_of_text_with_font( "Score : %d", &largeur_texte, &hauteur_texte, police, score );
    MLV_draw_text_with_font((FENETRE_X - largeur_texte) / 2, (FENETRE_Y - hauteur_texte) / 2, "Score : %d", police, COULEUR_TEXTE, score);

		MLV_free_font(police);
    MLV_actualise_window();

    MLV_wait_mouse(NULL, NULL);
}


void afficher_pause(){
    int largeur_texte, hauteur_texte;
    MLV_Keyboard_button touche;
    MLV_Font *police;

    MLV_save_screen();
    /* On assombris l'écran. */
    MLV_clear_window(MLV_rgba(0, 0, 0, 120));

    /* On affiche le cadre. */
    MLV_draw_filled_rectangle(FENETRE_X*0.3, FENETRE_Y*0.3, FENETRE_X*0.4, FENETRE_Y*0.4, MLV_COLOR_BLACK);
    MLV_draw_filled_rectangle(FENETRE_X*0.3 + 2, FENETRE_Y*0.3 + 2, FENETRE_X*0.4 - 4, FENETRE_Y*0.4 - 4, COULEUR_FOND);

    /* Affichage du mot "PAUSE". */
    police = MLV_load_font("../doc/font/coolvetica_rg.ttf", FENETRE_X * 0.043 );
    MLV_get_size_of_text_with_font("PAUSE", &largeur_texte, &hauteur_texte, police);
    MLV_draw_text_with_font((FENETRE_X - largeur_texte)/2, FENETRE_Y*0.35, "PAUSE", police, COULEUR_TEXTE);
    MLV_free_font(police);

    MLV_actualise_window();

    do{
        MLV_wait_keyboard(&touche, NULL, NULL);
    } while (touche != MLV_KEYBOARD_SPACE);

    MLV_load_screen();
}
