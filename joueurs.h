#ifndef JOUEURS_H
#define JOUEURS_H

#include "cartes.h"

//La structure de l'etat d'un joueur
typedef enum {
    EN_JEU,       //0 
    STOP,         //1
    ELIMINE,      //2
} Etat_Joueur;

//La structure d'un joueur
typedef struct {
    char pseudo[50];
    int score;
    Carte main[85];
    int nombre_cartes;
    Etat_Joueur etat;
} Joueur;


#endif