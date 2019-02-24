#ifndef SAUVEGARDE_H
#define SAUVEGARDE_H

/*
 * La fonction enregistre tout les données important pour sauvegarder une partie,
 * en prenant en paramètre le type Partie contenant le type Position, le numéro 
 * du nombre de partie total et le numéro de la partie acuel.
 * 
 * Aucune valeur n'est renvoyée.
 */
void sauvegarde_partie(Partie game);

/*
 * La fonction récupère le fichier sauvegardé et modifie le type Partie pour 
 * commencer avec une partie sauvegrdé.
 * 
 * Aucune valeur n'est renvoyée.
 */
void partie_save(Partie *game);


#endif