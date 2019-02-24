
#include <stdio.h>
#include <string.h>
#include <stdlib.h>





/*Question 2*/
/*
 *	La fonction prend en argument s1 et s2 (deux chaines de caractères), permet de comparer ces deux chaines
 *	pour retourner un entier qui indiquera si la première chaine est plus garnde, plus petite ou égale à la deuxieme.
 */
int compare(char *s1, char *s2){
	/*on compare les deux chaines*/
	int res = *s1 - *s2;
	/*on retourne un entier en fonction du résultat obtenue*/
	return res;
}




/*Question 4*/
/*
 *	La fonction prend en paramètre une chaine de caractère s et d'un entier c.
 *	Cette fonction permet de rechercher la première occurence de l'entier c que l'on appel en paramètre.
 *	On retourne un pointeur sur le caractère qui correspond à notre entier
 *	La fonction retourne la chaine de caractère à partir du pointeur correspondant.
 */
char* recherche(char *s, int c){
	/*Boucle qui parcours chaque lettre de la chaine de caractère*/
	for(; *s != '\0'; s++){
		/*Si la lettre correspond au code ASCII donné en paramètre*/
		if(*s ==  c)
			/*On retourne la chaine de caractère à partir de la lettre que l'on cherchais*/
			return s; 
	}
	/*Retourne rien si la lettre n'existe pas dans la chaine*/
	return NULL;
}



/*Question 6*/
/*
 *	Prend en paramètre une chaine de caractère. Celle-ci est parcourue pour trouver des caractères 
 *	qui correspondent à des chiffres, pour ensuite, les convertir en type entier. La conversion marchera que 
 *	si les caractères sont situés en début de chaine, on retourne donc l'entier.
 *	Si les bons caractères ne se trouvent pas en début de chaine, la fonction renvoie 0.
 */ 

int convert(char *s){
	/*On initialise i qui nous servira de compteur et res qui sera la valeur retourner*/
	int i, res = 0;
	/*On parcours la chaine de caractère tant que l'on est pas sur la valeur '\0'*/
	for(i = 0; s[i] != '\0'; i++){
		/*On vérifie si le caractère a une valeur en code ASCII comprise entre [48,57] (correspond à un chiffre)*/
		if(s[i] >= 48 && s[i] <= 57)
        	res = res*10 + s[i] - '0';
		/*Si la valeur suivante correspond à un caractère autre qu'un chiffre on sort de la boucle*/
		if(s[i+1] <= 48 || s[i+1] >= 57) 
			break;
	}
    return res; 
}


int main(int argc, char const *argv[]){
	/*QUESTION 2
	/*on affiche le resultat de la comparaison des deux chaines de cractères.
	quand s1 > s2*/
	printf("compare world/hello : %d\n", compare("world","hello"));
	printf("strcoll world/hello : %d\n", strcoll("world", "hello"));
 
	/*quand s1 < s2*/
	printf("compare hello/world : %d\n", compare("hello","world"));
	printf("strcoll hello/world : %d\n", strcoll("hello", "world"));

	/*quand s1 = s2*/
	printf("compare hello/hello : %d\n", compare("hello","hello"));
	printf("strcoll hello/hello : %d\n", strcoll("hello", "hello"));

	/*QUESTION 4
	/*on affiche la chaine de caractère à partir de la première occurence de b*/
	printf("recherche du premier l dans hello : %s\n", recherche("hello", 'l'));
	printf("strchr du premier l dans hello : %s\n", strchr("hello", 'l'));

	/*cas de quand le caractère n'est pas dans la chaine (cas de return NULL)*/
	if(recherche("hello", 'd') == NULL)
		printf("recherche : Le caractère n'est pas dans la chaine\n");

	if(strchr("hello", 'd') == NULL)
		printf("strchr : Le caractère n'est pas dans la chaine\n");

	/*QUESTION 6*/
	printf("atoi dezf1158 : %d\n", atoi("dezf1158"));
	printf("convert dezf1158 : %d\n", convert("dezf1158"));
	/*Valeur de retour : 0*/

	printf("atoi 145deiaj : %d\n", atoi("145deiaj"));
	printf("convert 145deiaj : %d\n", convert("145deiaj"));
	/*Valeur de retour : 145*/

	printf("atoi aef58fdd : %d\n", atoi("aef58fdd"));
	printf("convert aef58fdd : %d\n", convert("aef58fdd"));
	/*Valeur de retour : 0*/







	return 0;
}