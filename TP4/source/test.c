#include "../includes/test.h"



int test_creer_liste(){
	FILE* f;
	Liste lst;
	char* fichier, *nom_f = fichier = (char*)malloc(sizeof(char) *20);

	chemin_fichier(fichier, "test1.txt");

	f = fopen(fichier, "r");
	if (f == NULL)
		return 0;

	lst = NULL;
	creer_liste(f, &lst);


	if (lst == NULL)
		return 0;
	if (strcmp(lst->mot, "oui"))
		return 0;
	if (lst->occurence !=  2)
		return 0;
	lst = lst->suivant;

	if (lst == NULL)
		return 0;
	if (strcmp(lst->mot, "lu"))
		return 0;
	if (lst->occurence !=  2)
		return 0;
	lst = lst->suivant;

	if (lst == NULL)
		return 0;
	if (strcmp(lst->mot, "au"))
		return 0;
	if (lst->occurence !=  1)
		return 0;
	lst = lst->suivant;

	if (lst == NULL)
		return 0;
	if (strcmp(lst->mot, "test"))
		return 0;
	if (lst->occurence !=  2)
		return 0;
	lst = lst->suivant;

	if (lst == NULL)
		return 0;
	if (strcmp(lst->mot, "salut"))
		return 0;
	if (lst->occurence !=  2)
		return 0;
	lst = lst->suivant;

	if (lst == NULL)
		return 0;
	if (strcmp(lst->mot, "undeux"))
		return 0;
	if (lst->occurence !=  2)
		return 0;
	lst = lst->suivant;

	if (lst == NULL)
		return 0;
	if (strcmp(lst->mot, "bonjour"))
		return 0;
	if (lst->occurence !=  1)
		return 0;
	lst = lst->suivant;

	if (lst != NULL)
		return 0;

	if (fclose(f))
		return 0;


	chemin_fichier(nom_f, "test2.txt");
	f = fopen(nom_f, "r");
	if (f == NULL)
		return 0;

	detruire_liste(&lst);
	lst = NULL;
	creer_liste(f, &lst);

	
	if (lst != NULL)
		return 0;


	if (fclose(f))
		return 0;

	detruire_liste(&lst);
	return 1;
}

int test_creer_liste_a(){
	Liste lst;

	lst = NULL;
	ajouter_mot(&lst, "linux");
	ajouter_mot(&lst, "meuble");
	ajouter_mot(&lst, "lampe");
	ajouter_mot(&lst, "ananas");
	ajouter_mot(&lst, "mangue");
	ajouter_mot(&lst, "windows");
	ajouter_mot(&lst, "text");
	ajouter_mot(&lst, "meuble");
	ajouter_mot(&lst, "lampe");
	trier_lexico(&lst, 0, -1);


	if (lst == NULL || strcmp(lst->mot, "ananas"))
		return 0;
	lst = lst->suivant;

	if (lst == NULL || strcmp(lst->mot, "lampe"))
		return 0;
	lst = lst->suivant;

	if (lst == NULL || strcmp(lst->mot, "linux"))
		return 0;
	lst = lst->suivant;

	if (lst == NULL || strcmp(lst->mot, "mangue"))
		return 0;
	lst = lst->suivant;

	if (lst == NULL || strcmp(lst->mot, "meuble"))
		return 0;
	lst = lst->suivant;

	if (lst == NULL || strcmp(lst->mot, "text"))
		return 0;
	lst = lst->suivant;

	if (lst == NULL || strcmp(lst->mot, "windows"))
		return 0;
	lst = lst->suivant;

	if (lst != NULL)
		return 0;


	detruire_liste(&lst);
	return 1;
}

int test_creer_liste_n(){
	Liste lst;

	lst = NULL;
	ajouter_mot(&lst, "voir");
	ajouter_mot(&lst, "pomme");
	ajouter_mot(&lst, "test");
	ajouter_mot(&lst, "un");
	ajouter_mot(&lst, "test");
	ajouter_mot(&lst, "fait");
	ajouter_mot(&lst, "un");
	ajouter_mot(&lst, "fait");
	ajouter_mot(&lst, "lion");
	ajouter_mot(&lst, "test");
	ajouter_mot(&lst, "un");
	ajouter_mot(&lst, "lion");
	ajouter_mot(&lst, "test");
	ajouter_mot(&lst, "un");
	ajouter_mot(&lst, "ananas");
	ajouter_mot(&lst, "ananas");
	trier_occurence(&lst);

	if (lst == NULL || !(lst->occurence == 4) || strcmp(lst->mot, "test"))
		return 0;
	lst = lst->suivant;

	if (lst == NULL || !(lst->occurence == 4) || strcmp(lst->mot, "un"))
		return 0;
	lst = lst->suivant;

	if (lst == NULL || !(lst->occurence == 2) || strcmp(lst->mot, "ananas"))
		return 0;
	lst = lst->suivant;

	if (lst == NULL || !(lst->occurence == 2) || strcmp(lst->mot, "fait"))
		return 0;
	lst = lst->suivant;

	if (lst == NULL || !(lst->occurence == 2) || strcmp(lst->mot, "lion"))
		return 0;
	lst = lst->suivant;

	if (lst == NULL || !(lst->occurence == 1) || strcmp(lst->mot, "pomme"))
		return 0;
	lst = lst->suivant;

	if (lst == NULL || !(lst->occurence == 1) || strcmp(lst->mot, "voir"))
		return 0;
	lst = lst->suivant;

	if (lst != NULL)
		return 0;
	

	detruire_liste(&lst);
	return 1;
}

int test_creer_liste_s(){
	FILE* f;
	Liste lst;
	char mot[] = "voir";
	char* fichier, *nom_f = fichier = (char*)malloc(sizeof(char) *20);

	chemin_fichier(fichier, "test3.txt");

	f = fopen(fichier, "r");
	if (f == NULL)
		return 0;

	lst = NULL;
	creer_liste_s(f, &lst, mot);

	if (lst == NULL || lst->occurence != 2 || strcmp(lst->mot, "etre"))
		return 0;
	lst = lst->suivant;

	if (lst == NULL || lst->occurence != 1 || strcmp(lst->mot, "test"))
		return 0;
	lst = lst->suivant;

	if (lst == NULL || lst->occurence != 1 || strcmp(lst->mot, "fait"))
		return 0;
	lst = lst->suivant;

	if (lst != NULL)
		return 0;

	if (fclose(f))
		return 0;

	chemin_fichier(fichier, "test2.txt");

	f = fopen(nom_f, "r");
	if (f == NULL)
		return 0;

	detruire_liste(&lst);
	lst = NULL;
	creer_liste_s(f, &lst, mot);

	if (lst != NULL)
		return 0;


	if (fclose(f))
		return 0;

	detruire_liste(&lst);
	return 1;
}

int test_creer_liste_p(){
	FILE* f;
	Liste lst;
	char mot[] = "un";
	char* fichier, *nom_f = fichier = (char*)malloc(sizeof(char) *20);

	chemin_fichier(fichier, "test3.txt");

	f = fopen(fichier, "r");
	if (f == NULL)
		return 0;

	lst = NULL;
	creer_liste_p(f, &lst, mot);

	if (lst == NULL || lst->occurence != 1 || strcmp(lst->mot, "pomme"))
		return 0;
	lst = lst->suivant;

	if (lst == NULL || lst->occurence != 1 || strcmp(lst->mot, "etre"))
		return 0;
	lst = lst->suivant;

	if (lst == NULL || lst->occurence != 1 || strcmp(lst->mot, "un"))
		return 0;
	lst = lst->suivant;


	if (lst != NULL)
		return 0;

	if (fclose(f))
		return 0;

	chemin_fichier(fichier, "test2.txt");

	f = fopen(nom_f, "r");
	if (f == NULL)
		return 0;

	detruire_liste(&lst);
	lst = NULL;
	creer_liste_p(f, &lst, mot);

	if (lst != NULL)
		return 0;


	if (fclose(f))
		return 0;

	detruire_liste(&lst);
	return 1;
}

int test_creer_liste_e(){
	FILE* f;
	Liste lst;
	int n = 2;
	char* fichier, *nom_f = fichier = (char*)malloc(sizeof(char) *20);

	chemin_fichier(fichier, "test3.txt");

	f = fopen(fichier, "r");
	if (f == NULL)
		return 0;

	lst = NULL;
	creer_liste_e(f, &lst, n);

	if (lst == NULL || lst->occurence != 2 || strcmp(lst->mot, "voir etre"))
		return 0;
	lst = lst->suivant;

	if (lst == NULL || lst->occurence != 1 || strcmp(lst->mot, "etre montre"))
		return 0;
	lst = lst->suivant;

	if (lst == NULL || lst->occurence != 1 || strcmp(lst->mot, "montre voir"))
		return 0;
	lst = lst->suivant;

	if (lst == NULL || lst->occurence != 1 || strcmp(lst->mot, "voir test"))
		return 0;
	lst = lst->suivant;

	if (lst == NULL || lst->occurence != 1 || strcmp(lst->mot, "test test"))
		return 0;
	lst = lst->suivant;

	if (lst == NULL || lst->occurence != 1 || strcmp(lst->mot, "test mont"))
		return 0;
	lst = lst->suivant;

	if (lst == NULL || lst->occurence != 1 || strcmp(lst->mot, "mont pomme"))
		return 0;
	lst = lst->suivant;

	if (lst == NULL || lst->occurence != 1 || strcmp(lst->mot, "pomme un"))
		return 0;
	lst = lst->suivant;

	if (lst == NULL || lst->occurence != 1 || strcmp(lst->mot, "un montre"))
		return 0;
	lst = lst->suivant;

	if (lst == NULL || lst->occurence != 2 || strcmp(lst->mot, "montre lion"))
		return 0;
	lst = lst->suivant;

	if (lst == NULL || lst->occurence != 1 || strcmp(lst->mot, "lion montre"))
		return 0;
	lst = lst->suivant;

	if (lst == NULL || lst->occurence != 1 || strcmp(lst->mot, "lion voir"))
		return 0;
	lst = lst->suivant;

	if (lst == NULL || lst->occurence != 1 || strcmp(lst->mot, "voir fait"))
		return 0;
	lst = lst->suivant;

	if (lst == NULL || lst->occurence != 1 || strcmp(lst->mot, "fait voir"))
		return 0;
	lst = lst->suivant;

	if (lst == NULL || lst->occurence != 1 || strcmp(lst->mot, "etre un"))
		return 0;
	lst = lst->suivant;

	if (lst == NULL || lst->occurence != 1 || strcmp(lst->mot, "un un"))
		return 0;
	lst = lst->suivant;

	if (lst != NULL)
		return 0;


	if (fclose(f))
		return 0;

	chemin_fichier(nom_f, "test2.txt");

	f = fopen(nom_f, "r");
	if (f == NULL)
		return 0;

	detruire_liste(&lst);
	lst = NULL;
	creer_liste_e(f, &lst, n);

	if (lst != NULL)
		return 0;

	if (fclose(f))
		return 0;

	detruire_liste(&lst);
	return 1;
}

int test(){
	int err;

	err = test_creer_liste();
	printf("creer_liste :\t%d\n", err);
	if (!err)
		return 0;

	err = test_creer_liste_a();
	printf("creer_liste_a :\t%d\n", err);
	if (!err)
		return 0;

	err = test_creer_liste_n();
	printf("creer_liste_n :\t%d\n", err);
	if (!err)
		return 0;

	err = test_creer_liste_s();
	printf("creer_liste_s :\t%d\n", err);
	if (!err)
		return 0;

	err = test_creer_liste_p();
	printf("creer_liste_p :\t%d\n", err);
	if (!err)
		return 0;

	err = test_creer_liste_e();
	printf("creer_liste_e :\t%d\n", err);
	if (!err)
		return 0;

	return 1;
}