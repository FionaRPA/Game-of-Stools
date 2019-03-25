#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../includes/fichier.h"



void chemin_fichier(char* nouv, char* fichier){
	strcpy(nouv, "../doc/");
	strcat(nouv , fichier);
}


void change_ext(char* nom, char* extension, char* nouv){
	int i;
	char* fichier = (char*)malloc(sizeof(char) * strlen(nom) + 4);

	assert(nom != NULL);
	assert(extension != NULL);
	assert(nouv != NULL);

	for (i = 0; nom[i] != '.' && nom[i] != '\0'; i++)
		fichier[i] = nom[i];

	fichier[i] = '.';
	
	strcat( &(fichier[i+1]), extension);

	chemin_fichier(nouv, fichier);

}

int ecrire_liste(char* nom, Liste lst){
	char* nom_f;
	FILE* f;

	assert(nom != NULL);

	nom_f = (char*)malloc(sizeof(char) * strlen(nom) + 4);
	if ( NULL == nom_f )
		exit(EXIT_FAILURE);

	change_ext(nom, "clm", nom_f);
	f = fopen(nom_f, "w");

	if (NULL == f)
		return 0;

	for (; lst != NULL; lst = lst->suivant)
		fprintf(f, "%s %d\n", lst->mot, lst->occurence);

	if (!(fclose(f) != EOF))
		return 0;

	return 1;
}

