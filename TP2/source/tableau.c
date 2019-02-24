#include "../headers/tableau.h"

void afficher_tab(Tablette t, Dimension dim){
    int i, j;

    assert(dim.largeur >= 0);
    assert(dim.hauteur >= 0);
    assert(t.tab != NULL);

    for(i = 0; i < dim.largeur; i++){
        for(j = 0; j < dim.hauteur; j++)
            printf("%d ",t.tab[i][j]);
        printf("\n");
    }
    printf("\n fin\n");
}


Tablette creer_tablette(Dimension dim){
    int i, j;
    Tablette tab_choco;

    assert(dim.largeur >= 0);
    assert(dim.hauteur >= 0);

    tab_choco.tab = malloc(sizeof(*tab_choco.tab) * dim.largeur);
 
    for (i = 0; i < dim.largeur; i++)
        tab_choco.tab[i] = malloc(sizeof(**tab_choco.tab) * dim.hauteur);

    for(i = 0; i < dim.largeur; i++)
        for(j = 0; j < dim.hauteur; j++)
            tab_choco.tab[i][j] = 1;

    return tab_choco;
}

