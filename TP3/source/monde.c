#include "../includes/monde.h"

void afficher_case(Case casee) {
	printf("(%d, %d)\n", casee.x, casee.y);
}

Pomme pomme_gen_alea(int n, int m){
	Pomme pomme;
	int ligne, colonne, random;

	assert(n > 0);
	assert(m > 0);

	ligne = rand() % n;
	colonne = rand() % m;

	pomme.coordP.x = ligne;
	pomme.coordP.y = colonne;

	random = rand()%100;

	if (random <= 20 && random > 6)
		pomme.point = 2;
	else if (random <= 6)
		pomme.point = 0;
	else
		pomme.point = 1;

	return pomme;
}


int est_vide(Monde *mon, Case cases){
	int i;

  assert(mon != NULL);

	/* On vérifie si une pomme n'est pas déjà présente à cet emplacement. */
	for (i = 0; i < mon->pommes_presentes; i++){
		if ((cases.x == mon->pommes[i].coordP.x) && (cases.y == mon->pommes[i].coordP.y))
      return 0;
	}
	/* On vérifie si un morceau du serpent ne se situe pas à cet emplacement. */
	for (i = 0; i < mon->snake.taille; i++){
		if ((cases.x == mon->snake.coordS[i].x) && (cases.y == mon->snake.coordS[i].y))
			return 0;
	}

	return 1;
}

void ajouter_pomme_monde(Monde *mon, int max_pommes){
	Pomme pomme;

	assert(mon != NULL);

	if (mon->pommes_presentes == max_pommes)
		return;
	/* Tant que la nouvelle pomme ne se situe pas sur une case vide. */
	do{ /* On définis l'emplacement de la pomme à placer. */
		pomme = pomme_gen_alea(mon->lignes, mon->colonnes);

	}while (!est_vide(mon, pomme.coordP));

	/* L'emplacement où on souhaite ajouter la pomme est vide, on peut donc l'ajouter. */
	mon->pommes[mon->pommes_presentes] = pomme;
	mon->pommes_presentes += 1;
}


Serpent init_serpent(int taille, int nb_lignes, int nb_colonnes){
	Serpent snake;
	int i;

	snake.coordS = (Case *)malloc(sizeof(Case) * nb_lignes * nb_colonnes);
	if (NULL == snake.coordS)
		exit(EXIT_FAILURE);

	/* On positionne la tête au centre. */
	snake.coordS[0].x = nb_lignes / 2;
	snake.coordS[0].y = nb_colonnes / 2 + taille / 2;

	/* On positionne le reste de son corps à gauche de sa tête. */
	for (i = 1; i < taille; i++){
		snake.coordS[i].x = snake.coordS[i-1].x;
		snake.coordS[i].y = snake.coordS[i-1].y - 1;
	}
	/* Le serpent à sa tête et une partie de son corps, sa taille est donc de 2. */
	snake.taille = taille;
	snake.dir = EST;

	return snake;
}


Monde init_monde(int nb_pommes, int taille_serpent, int nb_lignes, int nb_colonnes){
	Monde mon;
	int i;

	assert(taille_serpent > 0);
	assert(nb_lignes >= 0);
	assert(nb_colonnes >= 0);

	mon.snake = init_serpent(taille_serpent, nb_lignes, nb_colonnes);
	mon.lignes = nb_lignes;
	mon.colonnes = nb_colonnes;

	/* Ajout des pommes. */
	mon.pommes = (Pomme *)malloc(sizeof(Pomme) * nb_pommes);
	if (NULL == mon.pommes)
		exit(EXIT_FAILURE);
	mon.pommes_presentes = 0;

	for (i = 0; i < nb_pommes; i++)
		ajouter_pomme_monde(&mon, nb_pommes);

	mon.pommes_presentes = nb_pommes;
	mon.pommes_mangees = 0;

	return mon;
}


Case case_suivante(Monde mon) {
	Case suivante;

	switch( mon.snake.dir ){
		case NORD:	suivante.x = mon.snake.coordS[0].x - 1;
					suivante.y = mon.snake.coordS[0].y;
					break;
		case EST:	suivante.x = mon.snake.coordS[0].x;
					suivante.y = mon.snake.coordS[0].y + 1;
					break;
		case SUD:	suivante.x = mon.snake.coordS[0].x + 1;
					suivante.y = mon.snake.coordS[0].y;
					break;
		case OUEST:	suivante.x = mon.snake.coordS[0].x;
					suivante.y = mon.snake.coordS[0].y - 1;
					break;
	}
	return suivante;
}


void ajout(Case lst[], int taille, Case nouv){
	int i;

	assert(lst != NULL);
	assert(taille >= 0);

	for (i = taille - 1; i > 0; i--)
		lst[i] = lst[i-1];
	/* Equivalent à lst[0]. */
	lst[i] = nouv;
}


int deplacer_serpent(Monde *mon){
	Case suivante;

	assert(NULL != mon);

	suivante = case_suivante(*mon);

	/* On vérifie si la case suivante ne se situe pas sur les bords. */
	if (suivante.x == mon->lignes || suivante.y == mon->colonnes || suivante.x == -1 || suivante.y == -1)
		return 0;

	if (!est_vide(mon, suivante))
		return 0;

	/* La case suivante est donc libre, on peut déplacer le serpent. */
	ajout(mon->snake.coordS, mon->snake.taille, suivante);

	return 1;
}

void supprime_pomme(Monde *mon, int indice){
	Pomme tmp;

	assert(NULL != mon);
	assert(indice >= 0);

	while ( indice < mon->pommes_presentes - 1 ){
		tmp = mon->pommes[indice];
		mon->pommes[indice] = mon->pommes[indice + 1];
		mon->pommes[indice + 1] = tmp;

		indice += 1;
	}
	mon->pommes_presentes -= 1;
}

int manger_pomme_serpent(Monde *mon){
	Case suivante;
	Case queue;
	int i, indice_pomme;
	MLV_Sound* eat;

	assert(mon != NULL);

	/* On regarde si la case suivante du serpent est une pomme et si oui, on récupère l'indice de la pomme. */
	suivante = case_suivante(*mon);
	indice_pomme = -1;
	for (i = 0; i < mon->pommes_presentes; i++){
		if (suivante.x == mon->pommes[i].coordP.x && suivante.y == mon->pommes[i].coordP.y)
			indice_pomme = i;
	}
	/* Si indice_pomme n'est pas modifiée c'est qu'on a pas trouvé de pomme. */
	if (indice_pomme == -1)
		return 0;

	mon->snake.taille += mon->pommes[indice_pomme].point;
	mon->pommes_mangees += mon->pommes[indice_pomme].point;
	/* Sinon on la supprime et on agrandis le serpent. */
	supprime_pomme(mon, indice_pomme);
	/* On retient la position de la queue du serpent (sa dernière partie), on déplace le serpent puis on lui rajoute sa queue. */
	queue = mon->snake.coordS[mon->snake.taille - 1];
	ajout( mon->snake.coordS, mon->snake.taille, suivante);
	mon->snake.coordS[mon->snake.taille] = queue;

	/* On joue le son. */
	eat = MLV_load_sound("../doc/audio/humm.wav");
	MLV_play_sound(eat, 1.0);
	MLV_wait_milliseconds(800);
	MLV_free_sound(eat);

	return 1;
}

int mort_serpent(Monde *mon){
	Case suivante;
	int i;

	assert(mon != NULL);

	suivante = case_suivante(*mon);

	/* On vérifie si la case suivante n'est pas une pomme empoisonnée. */
	for (i = 0; i < mon->pommes_presentes; i++)
		if (suivante.x == mon->pommes[i].coordP.x && suivante.y == mon->pommes[i].coordP.y && mon->pommes[i].point == 0)
			return 1;

    /* On vérifie si la case suivante ne se situe pas sur les bords. */
    if (suivante.x == mon->lignes || suivante.y == mon->colonnes || suivante.x == -1 || suivante.y == -1)
        return 1;

    /* On vérifie si un morceau du serpent se situe sur la case suivante. */
    for (i = 0; i < mon->snake.taille; i++){
        if ((suivante.x == mon->snake.coordS[i].x) && (suivante.y == mon->snake.coordS[i].y))
            return 1;
    }
    return 0;
}

void changer_direction(Serpent *snake, MLV_Keyboard_button direction){
	switch (direction){
		case MLV_KEYBOARD_UP:
			if (snake->dir != SUD) snake->dir = NORD;
				break;
		case MLV_KEYBOARD_RIGHT:
			if (snake->dir != OUEST) snake->dir = EST;
				break;
		case MLV_KEYBOARD_DOWN:
			if (snake->dir != NORD) snake->dir = SUD;
				break;
		case MLV_KEYBOARD_LEFT:
			if (snake->dir != EST) snake->dir = OUEST;
				break;
		default: break;
	}
}
