#ifndef SAUVEGARDE_H
#define SAUVEGARDE_H
#include "jeu.h" 

// Prototypes des fonctions
void sauvegarder_partie(Joueur* liste_joueurs, int nb_joueurs, Carte pioche[], int cartes_restantes);
void charger_partie(Joueur* liste_joueurs, int* nb_joueurs, Carte pioche[], int* cartes_restantes);

#endif