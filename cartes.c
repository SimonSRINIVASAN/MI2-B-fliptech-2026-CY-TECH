#include "cartes.h"

void creer_pioche (Carte pioche[]) {
    int i = 0;

    //On fabrique la carte 0
    pioche[0].bonus = SANS_BONUS;
    pioche[0].type = NUMERO;
    pioche[0].valeur = 0;

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