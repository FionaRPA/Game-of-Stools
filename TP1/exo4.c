
#include <stdio.h>
#include <string.h>
#include <stdlib.h>




/*Question 2*/
/*
 *	Cette fonction prend en paramètre deux entier a et b et elle renvoie 0 si l'un des
 *	deux entiers est négatif ou elle renvoie le résultat du calcul qui effectue le modulo
 *	de deux nombre a et b s'ils sont positifs.
 */
int bon_modulo(int a, int b){
	if (a > 0 && b > 0)
		return a % b;
	return 0;
}

/*Question 3*/
/*
 *	Cette fonction prend en paramètre la clé de cryptage et le mot que l'on veut modifier.
 *	Elle renvoie le nouveu mot crypter.
 *	On crypt le mot que l'on donne en paramètre en fonction de la clé de cryptage donnée.
 */
char* crypt(int cle, char *mot){
	
	int i ;
	/*Un nouveau mot alloué est crée pour pouvoir insérer les lettres modifier*/
	char *neew = (char*)malloc(1024);

	/*On parcours chaque lettre du mot jusqu'a atteindre la taille de celui-ci*/
	for (i = 0; i < strlen(mot); i++){
		/*Si la lettre est en minuscule on entre dans cette condition*/
		if (mot[i] >= 'a' && mot[i]<= 'z')
			/*La lettre a donc changé avec la clé cryptage, on effectue alors ce calcul*/
			neew[i] = (((mot[i]-'a')+cle)%26)+'a';
       /*On fait de même avec les lettres majuscule*/
		else if(mot[i] >= 'A' && mot[i]<= 'Z')
			neew[i] = (((mot[i]-'A')+cle)%26)+'A';
		/*Si le caractère n'est pas une lettre de l'alphabet, alors il n'est pas crypter*/
		else
			neew[i] = mot[i];
	}
	/*Renvoie le mot crypter*/
	return neew;
}


/*Question 4*/
/*
 *	Cette fonction est pratiquement la même que la fonction crypt(), mais elle fait 
 *	l'inverse de celle-ci.
 *	Elle prend les même paramètre que cette fonction et renvoie aussi un le nouveau mot.
 *	On desincrémente par la clé de cryptage, pour retrouver le mot de départ.
 */
char* decrypt(int cle, char *mot){

	int i;
	char *neew = (char*)malloc(1024);

	for (i = 0; i < strlen(mot); i++){
		if (mot[i] >= 'a' && mot[i]<= 'z')
			neew[i] = (((mot[i]-'a')-cle)%26)+'a';
       
		else if(mot[i] >= 'A' && mot[i]<= 'Z')
			neew[i] = (((mot[i]-'A')-cle)%26)+'A';
		else
			neew[i] = mot[i];
	}
	return neew;
}


int main(int argc, char const *argv[]){
	/*Test pour 9%5 qui renvoie 4*/
	printf("%d\n",bon_modulo(9,5));
	/*Test pour (-9)%5 qui renvoie 1*/
	printf("%d\n",bon_modulo(-9,5));

	/*Question 5*/
	/*Crée un mot que l'on veut crypter et décrypter*/
	char *mot = "Les !";
	
	mot = crypt(3, mot);
	printf("mot crypté: %s\n", mot);

	mot = decrypt(3, mot);
	printf("mot décrypté: %s\n", mot);
	
	return 0;
}
