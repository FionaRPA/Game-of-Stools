#include <stdlib.h>
#include <time.h>
#include <MLV/MLV_all.h>
#include "../includes/graphique.h"
#include "../includes/jeu.h"


int main(int argc, char const *argv[]){
  srand(time(NULL));
  MLV_create_window("Snake", "Snake", FENETRE_X, FENETRE_Y);
  jouer();
  MLV_free_window();

  return 0;
}
