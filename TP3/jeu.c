#include "includes/jeu.h"
/*
void jouer() {
	Partie parametres;
	Monde monde;
	MLV_Keyboard_button touche;
	MLV_Button_state mode;
	MLV_Music* music;
	MLV_Sound* end;

	 Initialisation. 
	parametres = init_parametres();
	monde = init_monde(parametres.nb_pommes, parametres.taille_serpent, parametres.hauteur, parametres.largeur);
	afficher_monde(&monde);
	MLV_init_audio();
	music = MLV_load_music("mario.mp3");
	end = MLV_load_sound("smb_mariodie.wav");

	MLV_wait_keyboard(&touche, NULL, NULL);
	changer_direction( &(monde.serpent), touche );
	MLV_play_music(music, 1.0, -1);

	 Boucle de jeu. 
	while ( 1 ) {
		if (MLV_get_event(&touche, NULL, NULL, NULL, NULL, NULL, NULL, NULL, &mode) == MLV_KEY) {
			if ( touche == MLV_KEYBOARD_ESCAPE && mode == MLV_PRESSED )
				afficher_pause();
			changer_direction( &(monde.serpent), touche );
		}

		if ( mort_serpent(&monde) ) {
			MLV_play_sound(end, 2.0);
			MLV_wait_seconds(2);
			break;
		}
		else if ( !deplacer_serpent(&monde) ) {
			manger_pomme_serpent(&monde);
			ajouter_pomme_monde(&monde, parametres.nb_pommes);
		}

		afficher_monde(&monde);

		MLV_wait_milliseconds(parametres.duree_tour);
	}

	 On arrête et libère tous les sons. 
	MLV_stop_all_sounds();
	MLV_stop_music();
	MLV_free_music(music);
	MLV_free_sound(end);
	MLV_free_audio();

	affiche_fin( monde.nb_pommes_mangees );
}
*/
/* Crée un fichier Serpent.ini dans lequel sont figurés les paramètre du jeu par défaut.
Si le fichier existe déjà, la fonction vérifie les valeurs.
Renvoie ensuite ces paramètres. */
Partie init_parametres() {
	FILE* fichier;
	Partie parametres;

	fichier = fopen("Serpent.ini", "r+");
	if (NULL == fichier)
		fichier = fopen("Serpent.ini", "w");

	if (fscanf(fichier, "largeur = %d\n", &(parametres.largeur)) != 1) {
		parametres.largeur = 16;
		fprintf(fichier, "largeur = %d\n", parametres.largeur);
	}
	if (fscanf(fichier, "hauteur = %d\n", &(parametres.hauteur)) != 1) {
		parametres.hauteur = 8;
		fprintf(fichier, "hauteur = %d\n", parametres.hauteur);
	}
	if (fscanf(fichier, "nombre_pommes = %d\n", &(parametres.nb_pommes)) != 1) {
		parametres.nb_pommes = 3;
		fprintf(fichier, "nombre_pommes = %d\n", parametres.nb_pommes);
	}
	if (fscanf(fichier, "taille_serpent = %d\n", &(parametres.taille_serpent)) != 1) {
		parametres.taille_serpent = 2;
		fprintf(fichier, "taille_serpent = %d\n", parametres.taille_serpent);
	}
	if (fscanf(fichier, "duree_tour = %d\n", &(parametres.duree_tour)) != 1) {
		parametres.duree_tour = 250;
		fprintf(fichier, "duree_tour = %d\n", parametres.duree_tour);
	}

	fclose(fichier);

	return parametres;
}