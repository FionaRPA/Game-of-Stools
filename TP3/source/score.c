#include "../includes/score.h"



void afficheScore(int joueurScore, char *nom, int time){

	FILE* fichier = NULL;
	FILE* newfile = NULL;
	MLV_Font *font;

	int y = FENETRE_X * 0.1, cmpt = 1;
	int ret, highScore, temps, larg_texte, haut_texte;
	char chaine[100] = "";

	MLV_clear_window(COULEUR_FOND);
	MLV_actualise_window();
	font = MLV_load_font("../doc/font/KeepCalm-Medium.ttf", y/2);
	MLV_get_size_of_text_with_font( "Meilleur Scores", &larg_texte, NULL, font);
	MLV_draw_text_with_font((FENETRE_X - larg_texte) / 2, FENETRE_Y * 0.01, "Meilleur Scores", font, COULEUR_TEXTE);
	MLV_actualise_window();

	fichier = fopen("../doc/fichier/score.txt", "r");
	rename("../doc/fichier/score.txt", "../doc/fichier/score_remove.txt");
	newfile = fopen("../doc/fichier/score.txt", "w");

	if (fichier != NULL){
		ret = fscanf(fichier, "%d", &highScore);
		ret = fscanf(fichier, "%d", &temps);

		while(fgets(chaine, 100, fichier) != NULL && ret != 0){
			if (joueurScore >= highScore){
				MLV_get_size_of_text_with_font( "%d. %s: %d pts en %d s", &larg_texte, &haut_texte, font, cmpt, nom, joueurScore, time);
				MLV_draw_text_with_font((FENETRE_X - larg_texte) / 2, FENETRE_Y * 0.1 + y, "%d. %s: %d pts en %d s", font, COULEUR_TEXTE, cmpt, nom, joueurScore, time);
				fprintf(newfile, "%d %d %s\n", joueurScore, time, nom);
				joueurScore = 0;
			}
			else{
				MLV_get_size_of_text_with_font( "%d.%s: %d pts en %d s", &larg_texte, &haut_texte, font, cmpt, chaine, highScore, temps);
				MLV_draw_text_with_font((FENETRE_X - larg_texte) / 2, FENETRE_Y * 0.1 + y, "%d. %s: %d pts en %d s", font, COULEUR_TEXTE, cmpt, chaine, highScore, temps);
				fprintf(newfile, "%d %d%s", highScore, temps, chaine);
			}
			y = y + FENETRE_X * 0.1;

			cmpt += 1;
			ret = fscanf(fichier, "%d", &highScore);
			ret = fscanf(fichier, "%d", &temps);

			MLV_actualise_window();
		}
		MLV_wait_mouse(NULL, NULL);
	}
	MLV_free_font(font);
	remove("../doc/fichier/score_remove.txt");
	fclose(fichier);
	fclose(newfile);
}
