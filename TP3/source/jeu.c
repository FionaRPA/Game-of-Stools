#include "../includes/jeu.h"


void creer_fenetre(){
	Monde monde;
	int res, largeur, hauteur;
	int temps;
	char *nom;
	MLV_Font *font;

	MLV_create_window("Snake", "Snake", FENETRE_X, FENETRE_Y);
	res = menu();
	if (res == 2)
		return;
	else if (res == 1){
		afficheScore(0, NULL, 0);
	}
	MLV_clear_window(COULEUR_FOND);
	font = MLV_load_font("../doc/font/coolvetica_rg.ttf", FENETRE_X * 0.05 );
	MLV_get_size_of_adapted_text_box_with_font(" Votre Nom: ", font, 1, &largeur, &hauteur);
	MLV_wait_input_box_with_font(50, FENETRE_Y/2 - 100, FENETRE_X - 50, 100, MLV_COLOR_BLACK, COULEUR_TEXTE, MLV_COLOR_BLACK, " Votre Nom: ", &nom, font);
	MLV_free_font(font);
	jouer(&monde, &temps);

	afficheScore(monde.pommes_mangees, nom, temps);
	free(nom);
}

void jouer(Monde *monde, int *temps){
	Partie parametres;
	MLV_Keyboard_button touche;
	MLV_Button_state mode;
	MLV_Music* music;
	MLV_Sound* end, *pause, *times_up;
	time_t depart, fin;

	/* Initialisation */
	time(&depart);
	(*temps) = 0;
	parametres = init_parametres();
	(*monde) = init_monde(parametres.nb_pommes, parametres.taille_serpent, parametres.hauteur, parametres.largeur);
	afficher_monde(monde, *temps);
	MLV_init_audio();
	music = MLV_load_music("../doc/audio/mario.mp3");
	end = MLV_load_sound("../doc/audio/smb_mariodie.wav");
	pause = MLV_load_sound("../doc/audio/smb_pause.wav");
	times_up = MLV_load_sound("../doc/audio/times-up.wav");

	MLV_wait_keyboard(&touche, NULL, NULL);
	changer_direction( &(monde->snake), touche);
	MLV_play_music(music, 1.0, -1);

	/* Boucle principale du jeu.*/
	while (1){
		time(&fin);
		(*temps) = difftime(fin, depart);

		if((*temps) >= parametres.duree_tour){
			MLV_stop_music();
			MLV_play_sound(times_up, 1);
			affiche_fin(monde->pommes_mangees, 1);
			return;
		}
		if (MLV_get_event(&touche, NULL, NULL, NULL, NULL, NULL, NULL, NULL, &mode) == MLV_KEY){
			if (touche == MLV_KEYBOARD_SPACE && mode == MLV_PRESSED){
				MLV_play_sound(pause, 1);
				afficher_pause();
			}
			changer_direction(&(monde->snake), touche);
		}

		if (mort_serpent(monde)){
			MLV_play_sound(end, 2);
			MLV_wait_seconds(2);
			break;
		}
		else if (!deplacer_serpent(monde)){
			manger_pomme_serpent(monde);
			ajouter_pomme_monde(monde, parametres.nb_pommes);
		}
		afficher_monde(monde, *temps);

		MLV_wait_milliseconds(parametres.vitesse);
	}
	/* On arrête et libère tous les sons.*/
	MLV_stop_all_sounds();
	MLV_stop_music();
	MLV_free_music(music);
	MLV_free_sound(end);
	MLV_free_sound(pause);
	MLV_free_sound(times_up);
	MLV_free_audio();

	affiche_fin(monde->pommes_mangees, 0);
	rejouer_ou_quitter(monde, temps);
}

void rejouer_ou_quitter(Monde *mon, int *temps){
    int x, y;

	MLV_clear_window(COULEUR_FOND);

    MLV_draw_text_box(FENETRE_X / 2 - 150, FENETRE_Y / 2 + 120, 300, 50, "Rejouer", 9,  COULEUR_TEXTE, COULEUR_TEXTE,  MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(FENETRE_X / 2 - 150, FENETRE_Y / 2 - 220, 300, 50, "Quitter", 9,  COULEUR_TEXTE, COULEUR_TEXTE,  MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);

    MLV_actualise_window();

    /*Pour commencer une nouvelle partie. */
    do {
		MLV_wait_mouse(&x, &y);
    } while(!(x >= FENETRE_X / 2 - 150 && x <= ((FENETRE_X / 2 - 150) + 300) && y >= FENETRE_Y / 2 + 120 && y <= (FENETRE_Y / 2 + 120) + 50)
          && !(x >= FENETRE_X / 2 - 150 && x <= ((FENETRE_X / 2 - 150) + 300) && y >= FENETRE_Y / 2 - 220 && y <= (FENETRE_Y / 2 - 220) + 50));

    if (x >= FENETRE_X / 2 - 150 && x <= ((FENETRE_X / 2 - 150) + 300) && y >= FENETRE_Y / 2 - 120 && y <= (FENETRE_Y / 2 + 120) + 50){
        jouer(mon, temps);
    }

    if (x >= FENETRE_X / 2 - 150 && x <= ((FENETRE_X / 2 - 150) + 300) && y >= FENETRE_Y / 2 - 120 && y <= (FENETRE_Y / 2 - 220) + 50)
        return;

    MLV_actualise_window();
}


Partie init_parametres(){
	FILE* fichier;
	Partie parametres;

	fichier = fopen("../doc/fichier/Serpent.ini", "r+");
	if (NULL == fichier)
		fichier = fopen("../doc/fichier/Serpent.ini", "w");

	if (fscanf(fichier, "largeur = %d\n", &(parametres.largeur)) != 1){
		parametres.largeur = 20;
		fprintf(fichier, "largeur = %d\n", parametres.largeur);
	}
	if (fscanf(fichier, "hauteur = %d\n", &(parametres.hauteur)) != 1){
		parametres.hauteur = 10;
		fprintf(fichier, "hauteur = %d\n", parametres.hauteur);
	}
	if (fscanf(fichier, "nombre_pommes = %d\n", &(parametres.nb_pommes)) != 1){
		parametres.nb_pommes = 3;
		fprintf(fichier, "nombre_pommes = %d\n", parametres.nb_pommes);
	}
	if (fscanf(fichier, "taille_serpent = %d\n", &(parametres.taille_serpent)) != 1){
		parametres.taille_serpent = 2;
		fprintf(fichier, "taille_serpent = %d\n", parametres.taille_serpent);
	}
	if (fscanf(fichier, "vitesse = %d\n", &(parametres.vitesse)) != 1){
		parametres.vitesse = 1;
		fprintf(fichier, "vitesse = %d\n", parametres.vitesse);
	}
	if (fscanf(fichier, "duree_tour = %d\n", &(parametres.duree_tour)) != 1){
		parametres.duree_tour = 200;
		fprintf(fichier, "duree_tour = %d\n", parametres.duree_tour);
	}
	fclose(fichier);

	return parametres;
}
