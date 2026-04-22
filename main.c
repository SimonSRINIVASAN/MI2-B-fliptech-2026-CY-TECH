//Ici on appelera juste les fonctions des autres fichiers pour faire les parties
//ce qui est ecrit la c'est juste pour faire des tests

#include <stdio.h>
#include <stdlib.h>
#include <time.h>     
#include "cartes.h"  

int main() {

    srand(time(NULL)); //Pour que le melange aleatoire soit different a chaque fois
    //On prépare un tableau vide de 85 places
    Carte ma_pioche[85]; 

    // On rempli le tableau avec les cartes
    creer_pioche(ma_pioche);

    //On vérifie que ça a marché en affichant les 5 premières cartes
    printf("--- TEST DE LA PIOCHE ---\n");
    for (int i = 0; i < 5; i++) {
        printf("Dans la case numero %d : Type = %d, Valeur = %d\n", i, ma_pioche[i].type, ma_pioche[i].valeur);
    }

    melanger_pioche(ma_pioche);

    //On vérifie que ça a marché en affichant les 5 premières cartes
    printf("--- TEST DE LA PIOCHE MELANGER---\n");
    for (int i = 0; i < 5; i++) {
        printf("Dans la case numero %d : Type = %d, Valeur = %d\n", i, ma_pioche[i].type, ma_pioche[i].valeur);
    }



    return 0;
}