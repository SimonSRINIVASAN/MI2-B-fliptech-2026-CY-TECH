#include <stdio.h>
#include "affichage.h"

void afficher_carte (Carte a) {
    if (a.type == 0) {
        printf("Carte numero : %d\n", a.valeur);
    }
    else if (a.type == 1) {
        printf("Carte BONUS ! (code du bonus %d)\n", a.bonus);
    }
}