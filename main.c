// Ici on appelera juste les fonctions des autres fichiers pour faire les parties
// ce qui est ecrit la c'est juste pour faire des tests

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cartes.h"
#include "affichage.h"
#include "joueurs.h"

int main() {
    srand(time(NULL)); // Pour que le melange aleatoire soit different a chaque fois

    printf("---TEST CREATION D'UN JOUEUR---\n");
    int nombre_de_joueur = 0;

    Joueur* liste_joueur; //on cree un tableau de joueurs
    liste_joueur = initialiser_joueurs (&nombre_de_joueur); //on met & pour que la fonction puisse modifier
    
    //on verifie en affichant la liste
    printf("Liste des joueurs :\n");
    for (int i = 0; i < nombre_de_joueur; i++) {
        printf("Joueur %d : %s -> Score de depart : %d\n", i+1, liste_joueur[i].pseudo, liste_joueur[i].score);
    }
    printf("\n\n");
    
    // On prepare un tableau vide de 85 places et un compteur du nombre de carte dans la pioche
    Carte ma_pioche[85];
    int carte_jeu = 85;

    // On remplit le tableau avec les cartes
    creer_pioche(ma_pioche);

    // On verifie que ca a marche en affichant les 5 premieres cartes
    printf("--- TEST DE LA PIOCHE ---\n");
    for (int i = 0; i < 5; i++) {
        printf("Dans la case numero %d : ", i);
        afficher_carte(ma_pioche[i]);
    }
    printf("\n\n");

    // On melange la pioche
    melanger_pioche(ma_pioche);

    // On verifie que ca a marche en affichant les 5 premieres cartes melangees
    printf("--- TEST DE LA PIOCHE MELANGEE ---\n");
    for (int i = 0; i < 5; i++) {
        printf("Dans la case numero %d : ", i);
        afficher_carte(ma_pioche[i]);
    }
    printf("\n\n");

    // On test de piocher
    printf("---TEST DE PIOCHER UNE CARTE---\n");
    printf("Cartes en jeu avant de piocher = %d\n", carte_jeu);
    
    Carte test_piocher = piocher_carte(ma_pioche, &carte_jeu);
    
    printf("J'ai pioche la carte suivante : ");
    afficher_carte(test_piocher);
    
    printf("Il reste %d cartes dans la pioche\n\n", carte_jeu);

    return 0;
}