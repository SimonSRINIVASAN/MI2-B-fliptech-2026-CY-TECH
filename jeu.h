#ifndef JEU_H
#define JEU_H

#include "joueurs.h"
#include "cartes.h"

void lancer_partie (Joueur* liste_joueurs, int nb_joueurs);

int jouer_tour (Joueur* joueur_actuel, Carte pioche[], int* cartes_restantes);

void calcule_score_manche(Joueur* joueur);




















#endif