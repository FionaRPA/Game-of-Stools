#include <MLV/MLV_all.h>
#include <stdlib.h>

#include "includes/graphique.h"


void afficher_quadrillage(Monde *mon){
	int i, j, larg, haut;
    int x, y;

	assert(mon != NULL);

    larg = ((FENETRE_X - 10) / mon->colonnes);
    haut = ((FENETRE_Y - 100) / mon->lignes);

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
    MLV_actualise_window();
}


void afficher_pomme(Pomme *pom, int nb_lignes, int nb_colonnes, char* file){
    int pos_x, pos_y;
    int larg, haut;
    MLV_Image *image;

	assert(NULL != pom);

    larg = ((FENETRE_Y - 100) / nb_lignes);
    haut = ((FENETRE_X - 10) / nb_colonnes);

	pos_x = pom->coordP.y * haut + 5;
	pos_y = pom->coordP.x * larg + 5;

	image = MLV_load_image(file);
    MLV_resize_image_with_proportions( image, larg + 5, haut + 5);
	MLV_draw_image( image, pos_x, pos_y);
}


void afficher_serpent(Serpent *ser, int nb_lignes, int nb_colonnes) {
	int pos_x, pos_y;
	int i, larg, haut;
    MLV_Image *image;

	assert(NULL != ser);

	/* On affiche la tête du serpent. */
    larg = ((FENETRE_Y - 100) / nb_lignes);
    haut = ((FENETRE_X - 10) / nb_colonnes);

    pos_x = ser->coordS[0].y * haut + 5;
    pos_y = ser->coordS[0].x * larg + 5;

    image = MLV_load_image("image/serp.png");
    MLV_resize_image_with_proportions( image, larg + 5, haut + 5);
	MLV_draw_image( image, pos_x, pos_y);

	/* On affiche le corps. */
	for (i = 1; i < ser->taille; i++) {
		pos_x = ser->coordS[i].y * haut + 5;
		pos_y = ser->coordS[i].x * larg + 5;

		MLV_draw_rectangle(pos_x, pos_y, haut, larg, COULEUR_CORPS_CONTOUR);
		MLV_draw_filled_rectangle(pos_x + 1, pos_y + 1, haut, larg, COULEUR_CORPS);
	}
}

void afficher_monde(Monde *mon) {
	int i;
	int pos_x, pos_y;
	int largeur_nombre;
	MLV_Font *police;

	assert(NULL != mon);

	afficher_quadrillage(mon);

	for (i = 0; i < mon->pommes_presentes; i++)
		if (mon->pommes[i].point == 2)
			afficher_pomme(&(mon->pommes[i]), mon->lignes, mon->colonnes, "image/pomme-or.png");
		else
			afficher_pomme(&(mon->pommes[i]), mon->lignes, mon->colonnes, "image/pomme-rouge.png");
		
	afficher_pomme(&(mon->pomme_empoisonnee), mon->lignes, mon->colonnes, "image/pomme-empoisonnee.png");

	afficher_serpent(&(mon->snake), mon->lignes, mon->colonnes);

	/* On affiche le nombre de pommes mangées sur la tête du serpent. */
    police = MLV_load_font("coolvetica_rg.ttf", ((FENETRE_X) / mon->colonnes) * 0.5 );
    MLV_get_size_of_text_with_font( "%d", &largeur_nombre, NULL, police, mon->pommes_mangees );
    pos_x = mon->snake.coordS[0].y * (FENETRE_X / mon->colonnes) + (FENETRE_X / mon->colonnes) / 2 - largeur_nombre / 2;
    pos_y = mon->snake.coordS[0].x * (FENETRE_Y / mon->lignes) + (FENETRE_Y/ mon->lignes) * 0.25;
    MLV_draw_text_with_font(pos_x, pos_y, "%d", police, COULEUR_NOMBRE, mon->pommes_mangees);
    MLV_free_font(police);

	MLV_actualise_window();
}

