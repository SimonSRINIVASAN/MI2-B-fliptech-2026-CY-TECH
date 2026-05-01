#include <stdio.h>
#include <stdlib.h>
#include "joueurs.h"

Joueur* initialiser_joueurs(int *nb_joueurs){

    printf("Combien de joueurs vont participer ? ");
    scanf("%d", nb_joueurs);

    Joueur *liste_joueurs = malloc((*nb_joueurs) * sizeof(Joueur));

    if (liste_joueurs ==NULL){
        printf("Erreur : espace mémoire insuffisant.\n");
        exit(1);
    }

    for (int i=0; i < *nb_joueurs; i++){
        printf("Entrez le pseudo du joueur %d : ", i+1);
        scanf("%49s", liste_joueurs[i].pseudo);

        liste_joueurs[i].score = 0;
        liste_joueurs[i].nombre_cartes = 0;
        liste_joueurs[i].etat = EN_JEU;
    }

    return liste_joueurs;
}

