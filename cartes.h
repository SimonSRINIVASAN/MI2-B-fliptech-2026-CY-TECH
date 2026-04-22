#ifndef CARTES_H
#define CARTES_H

//On liste les types de cartes
typedef enum {
    NUMERO,
    BONUS,
} TypeCarte;

//On liste les bonus
typedef enum {
    SANS_BONUS,
    PLUS_2,
    PLUS_4,
    PLUS_6,
    PLUS_8,
    PLUS_10,
    FOIS_2,
} TypeBonus;

//La structure d'une carte
typedef struct {
    TypeCarte type;
    int valeur; //le numero de la carte de 0 à 12
    TypeBonus bonus;
} Carte;

void creer_pioche (Carte pioche[]);

void melanger_pioche (Carte pioche[]);

#endif
