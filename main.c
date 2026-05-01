//Ici on appelera juste les fonctions des autres fichiers pour faire les parties
//ce qui est ecrit la c'est juste pour faire des tests

#include <stdio.h>
#include <stdlib.h>
#include <time.h>     
#include "cartes.h"  
#include "affichage.h"

int main() {

    srand(time(NULL)); //Pour que le melange aleatoire soit different a chaque fois
    //On prépare un tableau vide de 85 places
    Carte ma_pioche[85]; 
    int carte_jeu = 85;

    // On rempli le tableau avec les cartes
    creer_pioche(ma_pioche);

    //On vérifie que ça a marché en affichant les 5 premières cartes
    printf("--- TEST DE LA PIOCHE ---\n");
    for (int i = 0; i < 5; i++) {
        printf("Dans la case numero %d : Type = %d, Valeur = %d\n", i, ma_pioche[i].type, ma_pioche[i].valeur);
    }
    printf("\n\n\n");

    melanger_pioche(ma_pioche);

    //On vérifie que ça a marché en affichant les 5 premières cartes
    printf("--- TEST DE LA PIOCHE MELANGER---\n");
    for (int i = 0; i < 5; i++) {
        printf("Dans la case numero %d : Type = %d, Valeur = %d\n", i, ma_pioche[i].type, ma_pioche[i].valeur);
    }
    printf("\n\n\n");

    //on test de piocher
    printf("--------TEST DE PIOCHER UNE CARTE--------\n");
    printf("carte en jeu = %d\n", carte_jeu);
    Carte test_piocher = piocher_carte(ma_pioche, &carte_jeu);
    printf("le type de la carte est %d et sa valeur est %d\n", test_piocher.type, test_piocher.valeur);
    printf("il reste %d carte dans la pioche\n", carte_jeu);
    printf("\n\n\n");

    //test affichage carte
    afficher_carte(test_piocher);
    printf("\n\n\n");
    
    return 0;
}