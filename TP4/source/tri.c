#include "../includes/tri.h"


Liste max_occurence(Liste lst){
	int max;
	Liste mot;

	if (lst == NULL)
		return NULL;
	else{
		max = lst->occurence;
		mot = lst;
	}

	for (; lst != NULL; lst = lst->suivant){
		if (lst->occurence > max){
			max = lst->occurence;
			mot = lst;
		}
	}
	return mot;
}

Liste min_lexico(Liste lst, int debut, int fin){
	char min[MAX_LETTRE];
	Liste mot;
	int i;

	assert(debut >= 0);
	assert(fin >= debut);

	if (fin < 0)
		fin = taille(lst);

	if (fin == 0)
		return NULL;

	/* On se déplace juqu'au début de l'intervalle. */
	for (i = 0; i < debut; i++, lst = lst->suivant);

	if (lst == NULL)
		return NULL;

	strcpy(min, lst->mot);
	mot = lst;

	for (i = debut; lst != NULL && i < fin; lst = lst->suivant, i++){
		if (strcmp(lst->mot, min) < 0){
			strcpy(min, lst->mot);
			mot = lst;
		}
	}

	return mot;
}

void trier_occurence_aux(Liste *lst, Liste* lst_trie){
	Liste max;

	assert(lst != NULL);
	assert(lst_trie != NULL);

	/* On récupère l'occurence maximale de `lst`. */
	max = max_occurence(*lst);
	if (NULL == max)
		return;

	/* On ajoute ce max en tête du dictionnaire trié, et on le supprime de `lst`. */
	*lst_trie = max;
	extraire_mot(lst, max->mot);

	trier_occurence_aux(lst, &((*lst_trie)->suivant));
}

 void trier_lexico_occurence(Liste *lst){
	Liste tmp;
	int i, debut, compteur, occurence_precedente;

	assert(lst != NULL);

	if (*lst == NULL)
		return;
	else{
		occurence_precedente = (*lst)->occurence;
		debut = 0;
		compteur = 0;
	}

	tmp = *lst;
	for (i = 0; tmp != NULL; i++, tmp = tmp->suivant){
		if (tmp->occurence == occurence_precedente)
			compteur++;
		else{
			if (compteur > 1)
				trier_lexico(lst, debut, debut + compteur);
			occurence_precedente = tmp->occurence;
			debut = i;
			compteur = 1;
		}
	}
	/* On oublie pas les derniers. */
	if (compteur > 1)
		trier_lexico(lst, debut, -1);
}

void trier_occurence(Liste *lst){
	Liste lst_trie;

	assert(lst != NULL);

	lst_trie = NULL;
	trier_occurence_aux(lst, &lst_trie);
	trier_lexico_occurence(&lst_trie);

	*lst = lst_trie;
}

void trier_lexico_aux(Liste *lst, Liste *lst_trie, int debut, int fin, int compteur){
	Liste min;

	assert(lst != NULL);
	assert(lst_trie != NULL);
	assert(fin >= 0);

	if (fin - compteur <= debut)
		return;

	/* On récupère le plus petit mot de `lst`. */
	min = min_lexico(*lst, debut, fin - compteur);
	if (min == NULL)
		return;

	/* On ajoute le min en tête du dictionnaire trié, et on le supprime de `lst`. */
	*lst_trie = min;
	extraire_mot(lst, min->mot);

	trier_lexico_aux(lst, &((*lst_trie)->suivant), debut, fin, compteur + 1);
}

void trier_lexico(Liste *lst, int debut, int fin){
	Liste lst_trie, tmp;
	int i;

	assert(lst != NULL);
	assert(debut >= 0);

	if (fin < 0)
		fin = taille(*lst);

	if (fin == 0)
		return;

	for (lst_trie = *lst, i = 0; i < debut; lst_trie = lst_trie->suivant, i++);

	trier_lexico_aux(lst, &lst_trie, debut, fin, 0);

	if (debut == 0)
		*lst = lst_trie;
	else{
		for (tmp = *lst, i = 0; i < debut - 1; tmp = tmp->suivant, i++);
		tmp->suivant = lst_trie;
	}
}
