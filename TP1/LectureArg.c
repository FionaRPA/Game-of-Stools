#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]){
	
	int i;
	/*Affiche le nombre d'argument avec lequel le programme est lancé*/
	printf("Le programme est lancé avec %d arguments\n", argc);
	/*Parcours la liste argv pour ous afficher tout les arguments */
	for (i = 0; i < argc; i++){
		printf("argument %d: %s\n", i, argv[i]);
	}
	return 0;
}