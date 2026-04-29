#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordinateur.h"

void ajouterOrdinateur(Ordinateur **parc, int *nb) {
    if (*nb >= MAX_ORDINATEURS) {
        printf("Parc plein.\n");
        return;
    }

    parc[*nb] = malloc(sizeof(Ordinateur));
    if (!parc[*nb]) { printf("Erreur allocation.\n"); return; }

    parc[*nb]->numCarte = malloc(sizeof(int));
    parc[*nb]->cpu = malloc(sizeof(float));
    parc[*nb]->ram = malloc(sizeof(int));
    parc[*nb]->disque = malloc(sizeof(int));
    parc[*nb]->prix = malloc(sizeof(int));

    parc[*nb]->specialite = malloc(50);
    parc[*nb]->numSerie = malloc(50);
    parc[*nb]->marque = malloc(50);

    printf("Numéro de carte du détenteur: "); scanf("%d", parc[*nb]->numCarte);
    printf("Specialité du détenteur: "); scanf("%49s", parc[*nb]->specialite);
    printf("Numéro de série: "); scanf("%49s", parc[*nb]->numSerie);
    printf("Marque: "); scanf("%49s", parc[*nb]->marque);
    printf(" la vitesse du CPU (GHz): "); scanf("%f", parc[*nb]->cpu);
    printf("RAM (Go): "); scanf("%d", parc[*nb]->ram);
    printf("la taille du disque dur (Go): "); scanf("%d", parc[*nb]->disque);
    printf("Prix estimé de l'ordinateur (F CFA): "); scanf("%d", parc[*nb]->prix);

    (*nb)++;
}

void listerOrdinateurs(Ordinateur **parc, int nb) {
    if (nb == 0) {
        printf("Le parc est vide.\n");
        return;
    }
    for (int i = 0; i < nb; i++) {
        printf("%d | %s | %s | %s | %.2f GHz | %d Go RAM | %d Go DD | %d F CFA\n",
            *parc[i]->numCarte, parc[i]->specialite, parc[i]->numSerie,
            parc[i]->marque, *parc[i]->cpu, *parc[i]->ram,
            *parc[i]->disque, *parc[i]->prix);
    }
}

void afficherDetails(Ordinateur **parc, int nb) {
    if (nb == 0) {
        printf("Le parc est vide.\n");
        return;
    }
    int num;
    printf("Entrer num carte: ");
    scanf("%d", &num);
    for (int i = 0; i < nb; i++) {
        if (*parc[i]->numCarte == num) {
            printf("Carte: %d\nSpecialite: %s\nSerie: %s\nMarque: %s\nCPU: %.2f GHz\nRAM: %d Go\nDisque: %d Go\nPrix: %d F CFA\n",
                *parc[i]->numCarte, parc[i]->specialite, parc[i]->numSerie,
                parc[i]->marque, *parc[i]->cpu, *parc[i]->ram,
                *parc[i]->disque, *parc[i]->prix);
            return;
        }
    }
    printf("Ordinateur introuvable.\n");
}

void supprimerOrdinateur(Ordinateur **parc, int *nb) {
    if (*nb == 0) {
        printf("Le parc est vide. Rien à supprimer.\n");
        return;
    }
    int num;
    printf("Entrer num carte a supprimer: ");
    scanf("%d", &num);
    for (int i = 0; i < *nb; i++) {
        if (*parc[i]->numCarte == num) {
            free(parc[i]->numCarte);
            free(parc[i]->cpu);
            free(parc[i]->ram);
            free(parc[i]->disque);
            free(parc[i]->prix);
            free(parc[i]->specialite);
            free(parc[i]->numSerie);
            free(parc[i]->marque);
            free(parc[i]);
            for (int j = i; j < *nb - 1; j++) parc[j] = parc[j+1];
            (*nb)--;
            printf("Ordinateur supprimé.\n");
            return;
        }
    }
    printf("Ordinateur non trouvé.\n");
}

void repartirParSpecialite(Ordinateur **parc, int nb) {
    if (nb == 0) { printf("Le parc est vide.\n"); return; }
    printf("Liste par specialite:\n");
    for (int i = 0; i < nb; i++) {
        printf("%s -> Carte %d\n", parc[i]->specialite, *parc[i]->numCarte);
    }
}

void repartirParMarque(Ordinateur **parc, int nb) {
    if (nb == 0) { printf("Le parc est vide.\n"); return; }
    printf("Liste par marque:\n");
    for (int i = 0; i < nb; i++) {
        printf("%s -> Carte %d\n", parc[i]->marque, *parc[i]->numCarte);
    }
}

void trierParCpu(Ordinateur **parc, int nb) {
    if (nb == 0) { printf("Le parc est vide.\n"); return; }
    for (int i = 0; i < nb - 1; i++) {
        for (int j = i + 1; j < nb; j++) {
            if (*parc[i]->cpu > *parc[j]->cpu) {
                Ordinateur *tmp = parc[i];
                parc[i] = parc[j];
                parc[j] = tmp;
            }
        }
    }
    printf("Trie par CPU effectue.\n");
}

void valeurTotale(Ordinateur **parc, int nb) {
    if (nb == 0) { printf("Le parc est vide.\n"); return; }
    int total = 0;
    for (int i = 0; i < nb; i++) total += *parc[i]->prix;
    printf("Valeur totale du parc: %d F CFA\n", total);
}

void libererParc(Ordinateur **parc, int nb) {
    for (int i = 0; i < nb; i++) {
        free(parc[i]->numCarte);
        free(parc[i]->cpu);
        free(parc[i]->ram);
        free(parc[i]->disque);
        free(parc[i]->prix);
        free(parc[i]->specialite);
        free(parc[i]->numSerie);
        free(parc[i]->marque);
        free(parc[i]);
    }
}

