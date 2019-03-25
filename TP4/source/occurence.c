#include "../includes/occurence.h"


int est_un_mot(char* mot){
	assert(mot != NULL);

	while (*mot != '\0'){
		if (!((('a' <= (*mot) && (*mot) <= 'z') || ('A' <= (*mot) && (*mot) <= 'Z'))))
			return 0;
		mot++;
	}
	return 1;
}

int maj_to_min(char* mot){
	assert(mot != NULL);

	while (*mot != '\0'){
		if (!((('a' <= (*mot) && (*mot) <= 'z') || ('A' <= (*mot) && (*mot) <= 'Z'))))
			return 0;
		if ('A' <= *mot && *mot <= 'Z')
			*mot += 'a' - 'A';
		mot++;
	}
	return 1;
}

int creer_liste(FILE* f, Liste* lst){
	char mot[MAX_LETTRE];

	assert(f != NULL);
	assert(lst != NULL);

	while (fscanf(f, "%s", mot) != EOF){
		if (est_un_mot(mot)){
			maj_to_min(mot);
			if (!ajouter_mot(lst, mot))
				return 0;
		}
	}
	return 1;
}

int creer_liste_s(FILE* f, Liste* lst, char* reference){
	char mot[MAX_LETTRE];

	assert(f != NULL);
	assert(lst != NULL);
	assert(mot != NULL);

	if (est_un_mot(reference))
		maj_to_min(reference);
	else
		return 0;
		
	while (fscanf(f, "%s", mot) != EOF){
		if (est_un_mot(mot)){
			maj_to_min(mot);
			if (strcmp(reference, mot) == 0){
				do{
					if (fscanf(f, "%s", mot) == EOF)
						return 1;
				} while (!est_un_mot(mot));
				maj_to_min(mot);
				if (!ajouter_mot(lst, mot))
					return 0;
				fseek(f, strlen(mot) * -1, SEEK_CUR);
			}
		}
	}

	return 1;
}

int creer_liste_p(FILE* f, Liste* lst, char* reference){
	char mot[MAX_LETTRE];
	char mot_precedent[MAX_LETTRE] = "";

	assert(f != NULL);
	assert(lst != NULL);
	assert(mot != NULL);

	if (est_un_mot(reference))
		maj_to_min(reference);
	else
		return 0;

	while (fscanf(f, "%s", mot) != EOF){
		if (est_un_mot(mot)){
			maj_to_min(mot);
			if (strcmp(reference, mot) == 0 && strcmp(mot_precedent, "") != 0){
				if (!ajouter_mot(lst, mot_precedent))
					return 0;
			}
			strcpy(mot_precedent, mot);
		}
	}

	return 1;
}

int creer_liste_e(FILE* f, Liste* lst, int n){
	int i;
	long pos;
	char mot[MAX_LETTRE];
	char expression[MAX_LETTRE];

	assert(f != NULL);
	assert(lst != NULL);
	assert(n > 0);

	while (fscanf(f, "%s", mot) != EOF){
		if (est_un_mot(mot)){
			maj_to_min(mot);
			pos = ftell(f);
			strcpy(expression, mot);
			for (i = 1; i < n; i++){
				if (fscanf(f, "%s", mot) == EOF)
					return 1;
				if (est_un_mot(mot)){
					maj_to_min(mot);
					strcat(expression, " ");
					strcat(expression, mot);
				} else
					i--;
			}
			if (!ajouter_mot(lst, expression))
				return 0;
			fseek(f, pos, 0);
		}
	}

	return 1;
}