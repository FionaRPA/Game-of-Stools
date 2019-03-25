#include <string.h>
#include <stdlib.h>
#include "../includes/liste.h"
#include "../includes/occurence.h"
#include "../includes/fichier.h"
#include "../includes/test.h"
#include "../includes/option.h"


#define N 25

int main(int argc, char *argv[]){
	int option_a, option_n, option_s, option_p, option_e;
	int nb;
	char mot[N], *fichier = (char*)malloc(sizeof(char) *20);
	FILE* f;
	Liste lst;

	if (argc < 2 || !options(argv, argc, mot, &nb, &option_a, &option_n, &option_s, &option_p, &option_e) ){
		printf("Le mode d'éxécution est :\n");
		printf("./clm -test\n");
		printf("ou\n");
		printf("./clm [fichier] [option d'occurence : -s ou -p ou -e] [paramètre] [option de tri : -a ou -n]\n");
		printf("Option de tri peut être concaténée à l'option d'occurence. Par exemple ./clm fichier -s mot\n");
		return 0;
	}

	if (strcmp(argv[1], "-test") == 0 ){
		test();
		return 1;
	}
	chemin_fichier(fichier, argv[1]);

	f = fopen(fichier, "r");

	if (NULL == f){
		printf("Le fichier d'entrée est incorrect.\n");
		return 0;
	}

	if ((option_s || option_p) && !est_un_mot(mot) ){
		printf("Le mot mis en paramètre est incorrect, il doit être alphabétique.\n");
		return 0;
	}

	if (option_e && !(0 < nb && nb < N) ){
		printf("L'entier mis en paramètre n'est pas compris entre 0 et %d.\n", N);
		return 0;
	}

	lst = NULL;
	if (option_s )
		creer_liste_s(f, &lst, mot);
	else if (option_p )
		creer_liste_p(f, &lst, mot);
	else if (option_e )
		creer_liste_e(f, &lst, nb);
	else
		creer_liste(f, &lst);

	if (option_a )
		trier_lexico(&lst, 0, -1);
	if (option_n )
		trier_occurence(&lst);

	if (!(fclose(f) != EOF))
		exit(EXIT_FAILURE);

	ecrire_liste(argv[1], lst);

	return 0;
}