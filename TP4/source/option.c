#include "../includes/option.h"



int options(char *argv[], int argc, char* mot, int* nb, int* option_a, int* option_n, int* option_s, int* option_p, int* option_e){
	int i, j, passe = 0;

	*option_a = *option_n = *option_s = *option_p = *option_e = 0;

	for (i = 2; i < argc; i++){
		if (argv[i][0] == '-'){
			for (j = 1; j < strlen(argv[i]); j++){
				switch (argv[i][j]){
					case 'a':	if (*option_n == 1) return 0;
								*option_a = 1;
								break;
					case 'n':	if (*option_a == 1) return 0;
								*option_n = 1;
								break;
					case 's':	if (*option_p == 1 || *option_e == 1) return 0;
								*option_s = 1;
								if (i == argc -1) return 0;
								strcpy(mot, argv[i+1]);
								passe = 1;
								break;
					case 'p':	if (*option_s == 1 || *option_e == 1) return 0;
								*option_p = 1;
								if (i == argc -1) return 0;
								strcpy(mot, argv[i+1]);
								passe = 1;
								break;
					case 'e':	if (*option_s == 1 || *option_p == 1) return 0;
								*option_e = 1;
								if (i == argc -1) return 0;
								*nb = atoi(argv[i+1]);
								passe = 1;
								break;
					default:	return 0;
				}
			}
		} else{
			if (passe)
				passe = 0;
			else
				return 0;
		}
	}

	return 1;
}
