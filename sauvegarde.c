//ici on met le code des options de sauvegarde qu'on a listé

#include "sauvegarde.h"
#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"
#define NOM_FICHIER_SAUVEGARDE "partie_flip7.txt"

void sauvegarder_partie(Joueur* liste_joueurs, int nb_joueurs, Carte pioche[], int cartes_restantes) {
    FILE* f = fopen(NOM_FICHIER_SAVE, "w");
    if (f == NULL) {
        printf("Erreur lors de la sauvegarde.\n");
        return;
    }

    fprintf(f, "%d %d\n", nb_joueurs, cartes_restantes);

    // 2. Sauvegarder chaque joueur
    for (int i = 0; i < nb_joueurs; i++) {
        // On sauve : Pseudo, Score, État, Nombre de cartes en main
        fprintf(f, "%s %d %d %d\n", liste_joueurs[i].pseudo, 
                                    liste_joueurs[i].score, 
                                    liste_joueurs[i].etat, 
                                    liste_joueurs[i].nombre_cartes);
        
        // On sauve les cartes qu'il a en main
        for (int j = 0; j < liste_joueurs[i].nombre_cartes; j++) {
            fprintf(f, "%d %d %d ", liste_joueurs[i].main[j].type, 
                                     liste_joueurs[i].main[j].valeur, 
                                     liste_joueurs[i].main[j].bonus);
        }
        fprintf(f, "\n");
    }

    // 3. Sauvegarder la pioche (pour ne pas que le mélange change au chargement)
    for (int i = 0; i < cartes_restantes; i++) {
        fprintf(f, "%d %d %d ", pioche[i].type, pioche[i].valeur, pioche[i].bonus);
    }

    fclose(f);
    printf("Système : Partie enregistrée dans %s\n", NOM_FICHIER_SAVE);
}






void charger_partie(Joueur* liste_joueurs, int* nb_joueurs, Carte pioche[], int* cartes_restantes) {
    FILE* f = fopen(NOM_FICHIER_SAVE, "r");
    if (f == NULL) {
        printf("Aucune sauvegarde trouvée.\n");
        return;
    }

    // 1. Lire les infos générales
    fscanf(f, "%d %d", nb_joueurs, cartes_restantes);

    // 2. Lire chaque joueur
    for (int i = 0; i < *nb_joueurs; i++) {
        fscanf(f, "%s %d %d %d", liste_joueurs[i].pseudo, 
                                 &liste_joueurs[i].score, 
                                 (int*)&liste_joueurs[i].etat, 
                                 &liste_joueurs[i].nombre_cartes);
        
        for (int j = 0; j < liste_joueurs[i].nombre_cartes; j++) {
            fscanf(f, "%d %d %d", (int*)&liste_joueurs[i].main[j].type, 
                                  &liste_joueurs[i].main[j].valeur, 
                                  (int*)&liste_joueurs[i].main[j].bonus);
        }
    }

    // 3. Lire la pioche
    for (int i = 0; i < *cartes_restantes; i++) {
        fscanf(f, "%d %d %d", (int*)&pioche[i].type, 
                              &pioche[i].valeur, 
                              (int*)&pioche[i].bonus);
    }

    fclose(f);
    printf("Système : Partie chargée avec succès !\n");
}