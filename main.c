#include <stdio.h>
#include <stdlib.h>
#include "ordinateur.h"
#include <locale.h>
int main() {
    setlocale(LC_ALL, "");
    Ordinateur *parc[MAX_ORDINATEURS] = {NULL};
    int nb = 0;
    int choix = -1;
//Affichages des informations sur le menu
printf("**************************************************************\n");
printf("*                    SOYEZ LES BIENVENUS                     *\n");
printf("*              SVP VEUILLEZ CHOISIR VOTRE MENU               *\n");
printf("**************************************************************\n");
printf("si vous voulez ajouter un ordinateur au parc tapez 1\n");
printf("si vous voulez lister les ordinateurs deja enregistrer tapez 2\n");
printf("si vous voulez afficher les détails d'un ordinateur tapez 3\n");
printf("si vous voulez supprimer un ordinateur du parc tapez 4\n");
printf("si vous voulez repartir les ordinateur par spécialité tapez 5\n");
printf("si vous voulez repartir les ordinateur par marque tapez 6\n");
printf("si vous voulez repartir les ordinateur par vitesse du processeur tapez 7\n");
printf("si vous voulez calculer la valeur du parc tapez 8\n");
printf("si vous voulez quitter tapez 0");

//Affichage du menu

    while (choix != 0) {
        printf("\n--- MENU ---\n");
        printf("1. Ajouter un ordinateur\n2. Lister les ordinateurs\n3.");
        printf(" Afficher les details d'un ordinateur\n4. Supprimer un ordinateur du parc\n5.");
        printf(" Répartir par specialité\n6. Répartir  par marque\n7. Répartir par vitesse CPU\n8.");
        printf(" Valeur totale\n0. Quitter le parc\n");
        printf("Choix: ");

        // Vérification  de l'entrée
        if (scanf("%d", &choix) != 1) {
        // Si scanf échoue (entrée non numérique)
            printf("Entrée invalide. Veuillez entrer un nombre compris dans le menu.\n");
            choix = -1; // réinitialiser
        // vider le buffer d'entrée
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue; // revenir au menu
        }

        switch (choix) {
            case 1: ajouterOrdinateur(parc, &nb); break;
            case 2: listerOrdinateurs(parc, nb); break;
            case 3: afficherDetails(parc, nb); break;
            case 4: supprimerOrdinateur(parc, &nb); break;
            case 5: repartirParSpecialite(parc, nb); break;
            case 6: repartirParMarque(parc, nb); break;
            case 7: trierParCpu(parc, nb); break;
            case 8: valeurTotale(parc, nb); break;
            case 0: libererParc(parc, nb); printf("Fin programme.\n"); break;
            default: printf("Choix invalide.\n");
        }
    }
    return 0;
}
