// Ici on appelera juste les fonctions des autres fichiers pour faire les parties
// ce qui est ecrit la c'est juste pour faire des tests

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cartes.h"
#include "affichage.h"
#include "joueurs.h"
#include "jeu.h" 
#include "sauvegarde.h"

#define SCORE_VICTOIRE 200 // On définit le score pour gagner la partie

int main() {
    srand(time(NULL)); 

    printf("========================================\n");
    printf("         BIENVENUE DANS FLIP 7 !        \n");
    printf("========================================\n\n");

    int nb_joueurs = 0;
Joueur* liste = NULL;
int choix_demarrage;
int partie_terminee = 0; //C'est l'indication pour savoir si quelqu'un a gagné
int numero_manche = 1;


 Carte pioche[TOTAL_CARTES_JEU];
int cartes_restantes = TOTAL_CARTES_JEU;

printf("1. Nouvelle Partie\n");
printf("2. Charger une partie existante\n");
printf("Choix : ");
scanf("%d", &choix_demarrage);

if (choix_demarrage == 2) {
    // On alloue la mémoire pour la liste avant de charger (ex: max 10 joueurs)
    liste = malloc(sizeof(Joueur) * 10); 
    charger_partie(liste, &nb_joueurs, pioche, &cartes_restantes);
} else {
    liste = initialiser_joueurs(&nb_joueurs);
    creer_pioche(pioche);
    melanger_pioche(pioche);
}

    //Ca c'est la boucle de la partie
    while (partie_terminee == 0) {
        
        printf("\n\n>>> MANCHE %d <<<\n", numero_manche);
        
        //On lance une manche
        lancer_partie(liste, nb_joueurs, pioche, &cartes_restantes);

        //a la fin de la manche faut vérifier si quelqu'un a atteint 200 points
        int score_max = 0;
        int id_gagnant = -1;

        for (int i = 0; i < nb_joueurs; i++) {
            //Si on trouve un score plus grand que le score_max il prend sa place
            if (liste[i].score > score_max) {
                score_max = liste[i].score;
                id_gagnant = i;
            }
        }

        //on verifie que le meilleur joueur a dépassé 200 points
        if (score_max >= SCORE_VICTOIRE) {
            partie_terminee = 1; //On met l'indication a 1 pour que la boucle s'arrete
            
            printf("\n========================================\n");
            printf("      FIN DE LA PARTIE !  \n");
            printf(" Le grand gagnant est %s avec %d points !\n", liste[id_gagnant].pseudo, score_max);
            printf("========================================\n");
        } 
       else {
    numero_manche++;
    
    int veut_sauver;
    printf("\nVoulez-vous sauvegarder et quitter la partie ? (1: Oui / 0: Non) : ");
    scanf("%d", &veut_sauver);
    
    if (veut_sauver == 1) {
        // On appelle ta fonction de sauvegarde.c
        sauvegarder_partie(liste, nb_joueurs, pioche, cartes_restantes);
        
        free(liste); // Très important pour CY Tech !
        return 0;    // On ferme le programme
    }

    // Si on ne sauvegarde pas, on remet les mains à zéro pour la manche suivante
    for (int i = 0; i < nb_joueurs; i++) {
        liste[i].nombre_cartes = 0;
        liste[i].etat = EN_JEU;
    }
    
    printf("\nPreparez-vous pour la manche suivante...\n");
    system("pause");
}
    }

    //On rend la mémoire à la fin
    free(liste); 

    return 0;
}