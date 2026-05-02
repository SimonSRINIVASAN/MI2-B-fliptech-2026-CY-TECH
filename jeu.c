#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"
#include "affichage.h" 

// Fonction qui gère le tour d'un seul joueur
void jouer_tour(Joueur* joueur_actuel, Carte pioche[], int* cartes_restantes) {
    
    printf("\n\n");
    //Comme joueur_actuel est un pointeur (*), on utilise une flèche (->) au lieu d'un point (.)
    printf("           C'est au tour de %s !\n", joueur_actuel -> pseudo);
    printf("\n");

    int choix = 0;

    //La boucle tourne tant que le joueur est EN_JEU
    while (joueur_actuel->etat == EN_JEU) {
        
        printf("\nIl reste %d cartes dans la pioche\n\n", *cartes_restantes);
        printf("%s que voulez-vous faire ?\n",joueur_actuel -> pseudo);
        printf("1- Piocher une carte\n");
        printf("2- S'arreter\n\n");
        printf("Tu choisis : ");
        scanf("%d", &choix);

        if (choix == 1) {
            //On pioche la carte
            Carte carte_piochee = piocher_carte(pioche, cartes_restantes);
            
            //On l'affiche
            printf("\n--> Tu as pioche la ");
            afficher_carte(carte_piochee);

            //On range la carte dans la main du joueur
            int place_nouvelle_carte = joueur_actuel->nombre_cartes;
            joueur_actuel->main[place_nouvelle_carte] = carte_piochee;
            
            //On augmente le nombre de cartes qu'il possède
            joueur_actuel->nombre_cartes = joueur_actuel->nombre_cartes + 1;

            
            //on verifie si le joueur est eliminer en regatdant si il a piocher la meme carte
            //On vérifie si la carte piochée est un numéro
            if (carte_piochee.type == NUMERO) {
                
                //puis on parcourt les cartes qu'il avait deja avant de piocher
                for (int i = 0; i < place_nouvelle_carte; i++) {
                    
                    // Si on trouve une ancienne carte qui est aussi un numéro et qui a la meme valeur il est eliminer
                    if (joueur_actuel->main[i].type == NUMERO && joueur_actuel->main[i].valeur == carte_piochee.valeur) {
                        
                        printf("\n  MINCE ! Tu as deja le numero %d ! %s est elimine ! \n", carte_piochee.valeur, joueur_actuel -> pseudo);
                        
                        //On passe son état à ELIMINE pour arreter le tour
                        joueur_actuel->etat = ELIMINE; 
                        
                        break;
                    }
                }
            }

        } 
        else if (choix == 2) {
            //Le joueur s'arrete
            printf("\n%s decide de s'arreter. Fin de son tour.\n", joueur_actuel->pseudo);
            
            //On change son état
            joueur_actuel->etat = STOP;
        } 
        else {
            printf("\nChoix invalide, veuillez taper 1 ou 2.\n");
        }
    }
}

void lancer_partie(Joueur* liste_joueurs, int nb_joueurs) {
    //On prépare la pioche pour la partie
    Carte pioche[TOTAL_CARTES_JEU]; //Ya le #define dans joueur.h
    int cartes_restantes = TOTAL_CARTES_JEU;
    
    creer_pioche(pioche);
    melanger_pioche(pioche);

    printf("\n\n========================================\n");
    printf("           DEBUT DE LA PARTIE !\n");
    printf("========================================\n");

    //On fait jouer chaque joueur à tour de rôle
    for (int i = 0; i < nb_joueurs; i++) {
        //On envoie l'adresse du joueur actuel (&), la pioche, et l'adresse des cartes restantes
        jouer_tour(&liste_joueurs[i], pioche, &cartes_restantes);
    }

    printf("\n========================================\n");
    printf("            FIN DE LA PARTIE \n");
    printf("========================================\n");
}