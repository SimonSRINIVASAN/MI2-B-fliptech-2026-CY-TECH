#include "cartes.h"
#include <stdlib.h>
#include <time.h>

//on cree la pioche
void creer_pioche (Carte pioche[]) {
    int i = 0;

    //On fabrique la carte 0
    pioche[0].bonus = SANS_BONUS;
    pioche[0].type = NUMERO;
    pioche[0].valeur = 0;
    i++;

    //On fabrique les cartes de 1 à 12
    for (int valeur_carte = 1; valeur_carte <= 12; valeur_carte++) {
        for (int quantité = 0; quantité < valeur_carte; quantité++) {
            pioche[i].bonus = SANS_BONUS;
            pioche[i].type = NUMERO;
            pioche[i].valeur = valeur_carte;
            i++; //On avance d'une case a chaque carte créé
        }
    }

    //On fabrique les 6 cartes bonus
    //Bonus x2
    pioche[i].bonus = FOIS_2;
    pioche[i].type = BONUS;
    pioche[i].valeur = 0;
    i++;

    //Bonus +2
    pioche[i].bonus = PLUS_2;
    pioche[i].type = BONUS;
    pioche[i].valeur = 0;
    i++;

    //Bonus +4
    pioche[i].bonus = PLUS_4;
    pioche[i].type = BONUS;
    pioche[i].valeur = 0;
    i++;

    //Bonus +6
    pioche[i].bonus = PLUS_6;
    pioche[i].type = BONUS;
    pioche[i].valeur = 0;
    i++;

    //Bonus +8
    pioche[i].bonus = PLUS_8;
    pioche[i].type = BONUS;
    pioche[i].valeur = 0;
    i++;

    //Bonus +10
    pioche[i].bonus = PLUS_10;
    pioche[i].type = BONUS;
    pioche[i].valeur = 0;
    //Pas de i++ car c'est la dernière carte 
}

//On melange la pioche 

void melanger_pioche (Carte pioche[]) {
    int i, j;
    Carte melange;

    //On parcourt le paquet a l'envers
    for (i = 84; i >= 0; i--) {
        j = rand() % (i+1);

        melange = pioche[i];
        pioche[i] = pioche[j];
        pioche[j] = melange;
    } 
}

//Fonction pour piocher une carte
Carte piocher_carte(Carte pioche[], int* cartes_restantes) {
    Carte carte_vide;

    //on test si la pioche est vide
    if (*cartes_restantes <= 0) {
        carte_vide.type = 0;
        carte_vide.valeur = 0;
        carte_vide.bonus = 0;

        return carte_vide;
    } //si ya plus de carte on renvoie une carte avec tout a 0 pour dire que la pioche est vide

    *cartes_restantes = *cartes_restantes - 1; //on diminue la pioche de 1
    //on diminue avant de donner la carte car on a 85 cartes mais le tableau s'arrete a 84

    return pioche[*cartes_restantes];
}