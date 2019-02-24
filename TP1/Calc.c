#include <stdlib.h>
#include <stdio.h>
#include <string.h>




int main(int argc, char const *argv[]){
	
	int calc, nb1, nb2;
	/*On utilise la fonction atoi() pour rendre notre chaine de caractère des arguments 2 et 3 en entier */
	nb1 = atoi(argv[2]);
	nb2 = atoi(argv[3]);
	
	/*On compare si l'argument 1 fais partie de l'un des opérateurs ci-dessous*/
	if(strcmp(argv[1], "+") == 0){
		calc = nb1 + nb2;
		printf("Le résultat du calcul: %d + %d = %d\n", nb1, nb2, calc);
	}
	else if(strcmp(argv[1], "-") == 0){
		calc = nb1 - nb2;
		printf("Le résultat du calcul: %d - %d = %d\n", nb1, nb2, calc);
	}
	else if(strcmp(argv[1], "x") == 0){
		calc = nb1 * nb2;
		printf("Le résultat du calcul: %d x %d = %d\n", nb1, nb2, calc);
	}
	else if(strcmp(argv[1], "/") == 0){
		calc = nb1 / nb2;
		printf("Le résultat du calcul: %d / %d = %d\n", nb1, nb2, calc);
	}
	/*Si le premier argument n'est pas un opérateur alors on envoie un message d'erreur*/
	else{
		printf("Veuillez choisir 3 argument dont le premier est un opérateur\n");
		printf("Et un entier pour les deux autres arguments\n");
	}
	/*Renvoie 0 à la fin du main*/
	return 0;
}

