#include "../includes/score.h"



void afficheScore(int joueurScore, char *nom){

	FILE* fichier = NULL;
	FILE* newfile = NULL;
	MLV_Font *font;

	int y = FENETRE_X * 0.1, cmpt = 1;
	int ret, highScore, larg_texte, haut_texte;
	char chaine[100] = "";

	MLV_clear_window(COULEUR_FOND);
	MLV_actualise_window();
	font = MLV_load_font("../doc/font/KeepCalm-Medium.ttf", y);
	MLV_get_size_of_text_with_font( "Meilleur Score", &larg_texte, NULL, font);
	MLV_draw_text_with_font((FENETRE_X - larg_texte) / 2, FENETRE_Y * 0.01, "Meileur Score", font, COULEUR_TEXTE);
	MLV_actualise_window();

	fichier = fopen("../doc/fichier/score.txt", "r");
	rename("../doc/fichier/score.txt", "../doc/fichier/score_remove.txt");
	newfile = fopen("../doc/fichier/score.txt", "w");

	if (fichier != NULL){
		ret = fscanf(fichier, "%d", &highScore);

		while(fgets(chaine, 100, fichier) != NULL && ret != 0){
			if (joueurScore > highScore){
				MLV_get_size_of_text_with_font( "%d. %s: %d", &larg_texte, &haut_texte, font, cmpt, nom, joueurScore);
				MLV_draw_text_with_font((FENETRE_X - larg_texte) / 2, FENETRE_Y * 0.1 + y, "%d. %s: %d", font, COULEUR_TEXTE, cmpt, nom, joueurScore);
				fprintf(newfile, "%d %s\n", joueurScore, nom);

				joueurScore = 0;
			}
			else{
				MLV_get_size_of_text_with_font( "%d. %s: %d", &larg_texte, &haut_texte, font, cmpt, chaine, highScore);
				MLV_draw_text_with_font((FENETRE_X - larg_texte) / 2, FENETRE_Y * 0.1 + y, "%d. %s: %d", font, COULEUR_TEXTE, cmpt, chaine, highScore);
				fprintf(newfile, "%d%s", highScore, chaine);
			}
			y = y + FENETRE_X * 0.1;

			cmpt += 1;
			ret = fscanf(fichier, "%d", &highScore);
			MLV_actualise_window();
		}
		MLV_wait_mouse(NULL, NULL);
	}
	MLV_free_font(font);
	remove("../doc/fichier/score_remove.txt");
	fclose(fichier);
	fclose(newfile);
}
