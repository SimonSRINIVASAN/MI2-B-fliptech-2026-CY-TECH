// Ici on appelera juste les fonctions des autres fichiers pour faire les parties
// ce qui est ecrit la c'est juste pour faire des tests

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cartes.h"
#include "affichage.h"
#include "joueurs.h"
#include "jeu.h" // N'oublie pas d'inclure le nouveau menu du jeu !

int main() {
    srand(time(NULL)); 

    printf("========================================\n");
    printf("           CREATION DES JOUEURS\n");
    printf("========================================\n\n");
    int nb_joueurs = 0;
    Joueur* liste = initialiser_joueurs(&nb_joueurs);

    //On lance la partie avec nos joueurs 
    lancer_partie(liste, nb_joueurs);

    //faut rendre la mémoire à la fin
    free(liste); 

    return 0;
}