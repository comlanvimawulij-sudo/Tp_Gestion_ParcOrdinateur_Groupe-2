#include <stdio.h>
#include <stdlib.h>
#include "ordinateur.h"
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    Ordinateur **parc = NULL;  // tableau dynamique
    int nb = 0;
    int choix = -1;

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

    while (choix != 0) {
        printf("\n--- MENU ---\n");
        printf("1. Ajouter un ordinateur\n");
        printf("2. Lister les ordinateurs\n");
        printf("3. Afficher les détails d'un ordinateur\n");
        printf("4. Supprimer un ordinateur\n");
        printf("5. Répartir par spécialité\n");
        printf("6. Répartir par marque\n");
        printf("7. Trier par vitesse CPU\n");
        printf("8. Valeur totale du parc\n");
        printf("0. Quitter\n");
        printf("Choix: ");

        if (scanf("%d", &choix) != 1) {
    printf("Entrée invalide. Veuillez entrer un nombre.\n");
    choix = -1; // réinitialiser

    // vider le buffer d'entrée (supprimer la chaîne ou caractère saisi)
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    continue; // revenir au menu
}

switch (choix) {
         case 1:
               ajouterOrdinateur(&parc, &nb);
               break;
        case 2:
               listerOrdinateurs(parc, nb);
               break;
        case 3:
               listerOrdinateurs(parc, nb);
               break;
        case 4:
              supprimerOrdinateur(parc, &nb);
               break;
        case 5:
              repartirParSpecialite(parc, nb);
              break;
        case 6:
              repartirParMarque(parc, nb);
              break;
         case 7:
                trierParCpu(parc, nb);
                 break;
         case 8:
                valeurTotale(parc, nb);
                 break;
         case 0:
                libererParc(&parc, nb);
                printf("Fin programme.\n");
                break;
         default:
                   printf("Choix invalide.\n");
       }
   }
return 0;
}
