#include "../includes/liste.h"


void afficher_liste(Liste lst){
	while (lst != NULL){
		printf("%s\t", lst->mot);
		printf("%d\n", lst->occurence);
		lst = lst->suivant;
	}
}

Liste allouer_mot(char* nom){
	Liste mot;

	assert(nom != NULL);

	mot = (Liste)malloc(sizeof(Mot));

	if (mot == NULL)
		return NULL;

	strcpy(mot->mot, nom);
	mot->occurence = 1;
	return mot;
}

int ajouter_mot(Liste* lst, char* nom){
	Liste tmp;

	assert(nom != NULL);
	assert(lst != NULL);

	/* Si la liste est vide. */
	if (*lst == NULL){
		*lst = allouer_mot(nom);
	 	return (*lst != NULL);
	}

	tmp = *lst;

	/* On parcours la liste. */
	for (; tmp->suivant != NULL; tmp = tmp->suivant){
		/* Si le mot est présent dans la liste, on incrémente son occurence. */
		if (strcmp(tmp->mot, nom) == 0){
			tmp->occurence += 1;
			return 1;
		}
	}

	/* Arrivé a ce stade, on est en bout de chaine. */
	/* On regarde si le dernier mot de la liste est le meme que celui qu'on veut ajouter. */
	if (strcmp(tmp->mot, nom) == 0){
		tmp->occurence += 1;
		return 1;
	}

	/* Sinon c'est qu'il n'est pas présent dans la liste, donc on l'ajoute. */
	tmp->suivant = allouer_mot(nom);

	return (tmp->suivant != NULL);
}


Liste extraire_mot(Liste* lst, char* mot){
	Liste tmp, a_extraire;

	assert(lst != NULL);
	assert(mot != NULL);

	if (*lst == NULL)
		return NULL;

	tmp = *lst;

	/* On gère le cas où le mot à extraire se trouve en premier. */
	if (strcmp((*lst)->mot, mot) == 0){
		*lst = (*lst)->suivant;
		return tmp;
	}

	/* On parcours la liste jusqu'à trouver le mot à extraire. */
	for (; tmp != NULL && strcmp(tmp->suivant->mot, mot) != 0; tmp = tmp->suivant);

	/* Le mot n'appartient pas au dictionnaire. */
	if (NULL == tmp)
		return NULL;

	/* Sinon c'est qu'on se situe avant le mot qu'on cherche. */
	a_extraire = tmp->suivant;
	tmp->suivant = a_extraire->suivant;

	return a_extraire;
}

int recherche(Liste lst, char* mot){
	/* On parcours tout la liste. */
	for (; lst != NULL && strcmp(lst->mot, mot) != 0; lst = lst->suivant);

	return (lst != NULL);
}

void copie_liste(Liste *origine, Liste *dest){
	assert(NULL != origine);
	assert(NULL != dest);

	if (NULL != *origine){
		*dest = allouer_mot((*origine)->mot);
		(*dest)->occurence = (*origine)->occurence;
		copie_liste(&((*origine)->suivant), &((*dest)->suivant));
	}
}

void detruire_liste(Liste *lst){
	assert(lst != NULL);

	if (*lst == NULL)
		return;

	detruire_liste(&((*lst)->suivant));

	free(*lst);
}

int taille(Liste lst){
	int i;

	if (lst == NULL)
		return 0;

	i = 0;

	for (; lst != NULL; lst = lst->suivant){
		i++;
	}

	return i;
}