#include <stdio.h>
#include "affichage.h"

void afficher_carte (Carte a) {
    if (a.type == 0) {
        printf("Carte numero : %d\n", a.valeur);
    }
    else if (a.type == 1) {
        printf("Carte BONUS !\n");

        switch (a.bonus) {
            case 0 : printf("Aucun effet\n");
            break;

            case 1 : printf("Effet : +2 points\n");
            break;

            case 2 : printf("Effet : +4 points\n");
            break;

            case 3 : printf("Effet : +6 points\n");
            break;

            case 4 : printf("Effet : +8 points\n");
            break;

            case 5 : printf("Effet : +10 points\n");
            break;

            case 6 : printf("Effet : Score x2\n");
            break;

            default : printf("Erreur Bonus inconnu\n");
            break;
        }
    }
}