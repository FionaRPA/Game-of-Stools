#include "../includes/menu.h"


void recupereDimensionBouton(char nom[], int taille, int *largeur, int *hauteur){

	MLV_Font* font = MLV_load_font("../doc/font//KeepCalm-Medium.ttf", taille);

	assert(nom != NULL);
	assert(taille >= 0);
	assert(largeur != NULL);
	assert(hauteur != NULL);

	MLV_get_size_of_adapted_text_box_with_font(nom, font, 0, largeur, hauteur);
}


void placeBouton(char nom[], int x, int y, float taille, MLV_Color couleur, Bouton *zone){

	int largeur, hauteur;
	MLV_Font* font = MLV_load_font("../doc/font/KeepCalm-Medium.ttf", taille);

    assert(nom != NULL);
    assert(taille >= 0);
    assert(x >= 0);
    assert(y >= 0);
    assert(couleur >= 0);
    assert(zone != NULL);

	MLV_get_size_of_adapted_text_box_with_font(nom, font, 0, &largeur, &hauteur);

	MLV_draw_text_with_font(x, y, nom, font, couleur);
	MLV_draw_rectangle(x - taille / 10, y - taille / 10, largeur + 2 * taille / 10, hauteur + taille / 10, couleur);

	MLV_free_font(font);
	MLV_actualise_window();

	zone->x1 = x - taille / 10;
	zone->y1 = y - taille / 10;
	zone->x2 =  x + largeur + taille / 10;
	zone->y2 = y + hauteur;
}


int menu(){
	int x, y;
	int largeur, hauteur, taille, largeur_txt, hauteur_txt;
	Bouton jouer, score, quitter;
	MLV_Font* font;

	MLV_clear_window(MLV_COLOR_BLACK);

	font = MLV_load_font("../doc/font//A Box For.ttf", FENETRE_X * 0.2);

	MLV_get_size_of_text_with_font("Snake", &largeur_txt, &hauteur_txt, font);
	MLV_draw_text_with_font((FENETRE_X - largeur_txt) / 2, FENETRE_Y * 0.01, "Snake", font, COULEUR_TEXTE);
	MLV_free_font(font);

	taille = FENETRE_X * 0.07;
	recupereDimensionBouton("Jouer", taille, &largeur, &hauteur);
	placeBouton("Jouer", FENETRE_X / 2 - largeur / 2, FENETRE_Y * 0.5, taille, COULEUR_TEXTE, &jouer);

	recupereDimensionBouton("Meilleur Score", taille, &largeur, &hauteur);
	placeBouton("Meilleur Score", FENETRE_X / 2 - largeur/2, jouer.y2 + 2 * taille/10, taille, COULEUR_TEXTE, &score);

	recupereDimensionBouton("Quitter", taille, &largeur, &hauteur);
	placeBouton("Quitter", FENETRE_X/2 - largeur / 2, score.y2 + 2 * taille/10, taille, COULEUR_TEXTE, &quitter);

	MLV_actualise_window();

	while (1){
		MLV_wait_mouse(&x, &y);
		/*Renvoie 0 pour Jouer. */
		if (x > jouer.x1 && x < jouer.x2 && y > jouer.y1 && y < jouer.y2)
			return 0;

		/*Renvoie 1 pour afficher la liste des Score enregistré. */
		if (x > score.x1 && x < score.x2 && y > score.y1 && y < score.y2){
			return 1;
		}
		/*Renvoie 2 pour quitter le jeu. */
		if (x > quitter.x1 && x < quitter.x2 && y > quitter.y1 && y < quitter.y2 )
			return 2;
	}
	return 0;
}
