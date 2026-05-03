#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"
#include "affichage.h" 

// Fonction qui gère le tour d'un seul joueur
int jouer_tour(Joueur* joueur_actuel, Carte pioche[], int* cartes_restantes) {
    
    printf("\n\n");
    printf("           C'est au tour de %s !\n", joueur_actuel->pseudo);
    printf("\n");

    int choix = 0;

    //La boucle tourne tant que le joueur est en jeu
    while (joueur_actuel->etat == EN_JEU) {
        
        printf("\nIl reste %d cartes dans la pioche\n\n", *cartes_restantes);
        printf("%s que voulez-vous faire ?\n",joueur_actuel->pseudo);
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

            //On augmente le nombre de carte dans sa main
            joueur_actuel->nombre_cartes = joueur_actuel->nombre_cartes + 1;

            //on verifie si il a piocher une carte qu'il avait deja 
            if (carte_piochee.type == NUMERO) {
                
                int est_elimine = 0; //On crée un petit drapeau
                
                //On vérifie d'abord l'élimination
                for (int i = 0; i < place_nouvelle_carte; i++) {

                    if (joueur_actuel->main[i].type == NUMERO && joueur_actuel->main[i].valeur == carte_piochee.valeur) {

                        printf("\n  MINCE ! Tu as deja le numero %d ! %s est elimine ! \n", carte_piochee.valeur, joueur_actuel->pseudo);
                        joueur_actuel->etat = ELIMINE; 
                        est_elimine = 1; //On lève le drapeau

                        break;
                    }
                }

                //S'il n'est pas éliminé, on compte ses numéros pour voir si il fait un Flip 7 
                if (est_elimine == 0) {
                    int compte_numeros = 0;
                    for (int i = 0; i < joueur_actuel->nombre_cartes; i++) {
                        //ON verifie combien de numero il a dans sa main
                        if (joueur_actuel->main[i].type == NUMERO) {
                            compte_numeros++;
                        }
                    }

                    //Si c'est son 7ème numéro différent
                    if (compte_numeros == 7) {
                        printf("\n⭐ INCROYABLE ! %s a 7 numeros differents ! FLIP 7 ! ⭐\n", joueur_actuel->pseudo);
                        joueur_actuel->etat = STOP; 
                        return 1; //On coupe la fonction direct 
                    }
                }
            }

        } 
        else if (choix == 2) {
            //Le joueur s'arrete
            printf("\n%s decide de s'arreter. Fin de son tour.\n", joueur_actuel->pseudo);
            //On change son etat
            joueur_actuel->etat = STOP;
        } 
        else {
            printf("\nChoix invalide, veuillez taper 1 ou 2.\n");
        }
    }
    
    return 0;
}


void lancer_partie(Joueur* liste_joueurs, int nb_joueurs) {
    //On prépare la pioche pour la partie
    Carte pioche[TOTAL_CARTES_JEU]; //Ya le #define dans joueur.h
    int cartes_restantes = TOTAL_CARTES_JEU;
    
    creer_pioche(pioche);
    melanger_pioche(pioche);

    printf("\n\n========================================\n");
    printf("           DEBUT DE LA MANCHE !\n");
    printf("========================================\n");

    //On fait jouer chaque joueur à tour de rôle
    for (int i = 0; i < nb_joueurs; i++) {

        //On stocke la réponse de jouer_tour 1 si Flip 7, 0 sinon
        int flip7 = jouer_tour(&liste_joueurs[i], pioche, &cartes_restantes);
        
        //Si le joueur vient de faire un Flip 7
        if (flip7 == 1) {
            printf("\n🚨 %s A FAIT UN FLIP 7 ! LA MANCHE S'ARRETE IMMEDIATEMENT ! 🚨\n", liste_joueurs[i].pseudo);
            
            // Le mot break détruit la boucle "for"
            // les joueurs suivants n'auront pas le droit de jouer 
            break;
        }
    }

    printf("\n========================================\n");
    printf("            FIN DE LA MANCHE !\n");
    printf("========================================\n");
    printf("\n--- RESULTATS DE LA MANCHE ---\n\n");

    //On calcule et affiche le score de chaque joueur 
    for (int i = 0; i < nb_joueurs; i++) {
        calcule_score_manche(&liste_joueurs[i]);
    }
    printf("\n");
}


void calcule_score_manche(Joueur* joueur) {
    // Si le joueur est éliminé ducoup il marque 0 point pour cette manche
    if (joueur->etat == ELIMINE) {
        printf("%s a ete elimine et ne marque aucun point -> Score total : %d\n", joueur->pseudo, joueur->score);
        return; 
    }

    int somme_numero = 0;
    int somme_bonus = 0;
    int multiplicateur = 1;
    int compte_numeros = 0;

    //On analyse toutes les cartes dans la main du joueur pour savoir ce que c'est 
    for (int i = 0; i < joueur->nombre_cartes; i++) {
        Carte c = joueur->main[i];
        
        if (c.type == NUMERO) {
            somme_numero = somme_numero + c.valeur;
            compte_numeros++;
        } 
        else if (c.type == BONUS) {
            // On trie les bonus
            switch (c.bonus) {
                case PLUS_2:  somme_bonus += 2; 
                break;
                case PLUS_4:  somme_bonus += 4; 
                break;
                case PLUS_6:  somme_bonus += 6; 
                break;
                case PLUS_8:  somme_bonus += 8; 
                break;
                case PLUS_10: somme_bonus += 10; 
                break;
                case FOIS_2:  multiplicateur = 2; 
                break;
                case SANS_BONUS: 
                break;
            }
        }
    }

    //On applique la formule pour faire le score d'un coup
    int score_manche = (somme_numero * multiplicateur) + somme_bonus;

    //On ajoute le bonus du flip7 si y'en a un
    if (compte_numeros >= 7) {
        printf("   ⭐ BONUS FLIP 7 ! +15 points pour %s ! ⭐\n", joueur->pseudo);
        score_manche = score_manche + 15;
    }
    
    //On ajoute ça au score total du joueur
    joueur->score = joueur->score + score_manche;
    
    printf("%s s'est arrete a temps et marque %d points ! -> Score total : %d\n", 
           joueur->pseudo, score_manche, joueur->score);
}