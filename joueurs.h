#ifndef JOUEURS_H
#define JOUEURS_H

#include "cartes.h"

#define TAILLE_MAX_PSEUDO 50
#define TOTAL_CARTES_JEU 85

//La structure de l'etat d'un joueur
typedef enum {
    EN_JEU,       //0 
    STOP,         //1
    ELIMINE,      //2
} Etat_Joueur;

//La structure d'un joueur
typedef struct {
    char pseudo[TAILLE_MAX_PSEUDO];
    int score;
    Carte main[TOTAL_CARTES_JEU];
    int nombre_cartes;
    Etat_Joueur etat;
} Joueur;


#endif