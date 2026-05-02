#ifndef JEU_H
#define JEU_H

#include "joueurs.h"
#include "cartes.h"

void lancer_partie (Joueur* liste_joueurs, int nb_joueurs);

void jouer_tour (Joueur* joueur_actuel, Carte pioche[], int* cartes_restantes);


//ici on doit definir les regles et l'etat de la partie etc

















#endif