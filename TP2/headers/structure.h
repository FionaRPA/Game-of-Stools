/* Inclusio principale nécessaire pour le programme. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include <assert.h>

/* Initialisation de tout les defines qui nous serviront pour la création du jeu*/
#define N 8
#define M 16
#define FENETRE_X 1000
#define FENETRE_Y 700


/* Sructure pour les boutons correspondant au menu*/
typedef struct Bouton {
    int x1;
    int y1;
    int x2;
    int y2;
    int numero_bouton;
} Bouton;


typedef struct{
    int **tab;
}Tablette;


typedef enum {
    JOUEUR_1,
    JOUEUR_2
}Joueur;


typedef struct{
    Tablette tableau;
    Joueur player;
}Position;


typedef struct{
    int x;
    int y;
}Coup;


typedef struct{
    int largeur;
    int hauteur;
}Dimension;


typedef struct{
    int player1;
    int player2;
}Score;

/* Structure Partie qui regroupe le numéro de partie total et le nombre de partie actuel.*/
typedef struct{
    int partie_actuel;
    int partie_total;
    Position pos;
    Dimension dim;
    Score gagnant;
}Partie;
