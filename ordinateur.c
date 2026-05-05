#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordinateur.h"

void ajouterOrdinateur(Ordinateur ***parc, int *nb) {
    if (*nb >= MAX_ORDINATEURS) {
        printf("Parc plein.\n");
        return;
    }

    *parc = realloc(*parc, (*nb + 1) * sizeof(Ordinateur *));
    if (!*parc) {
        printf("Erreur allocation.\n");
        return;
    }

    (*parc)[*nb] = malloc(sizeof(Ordinateur));
    if (!(*parc)[*nb]) {
        printf("Erreur allocation.\n");
        return;
    }

    (*parc)[*nb]->numCarte = malloc(sizeof(int));
    (*parc)[*nb]->cpu = malloc(sizeof(float));
    (*parc)[*nb]->ram = malloc(sizeof(int));
    (*parc)[*nb]->disque = malloc(sizeof(int));
    (*parc)[*nb]->prix = malloc(sizeof(int));
    (*parc)[*nb]->specialite = malloc(50);
    (*parc)[*nb]->numSerie = malloc(50);
    (*parc)[*nb]->marque = malloc(50);

    printf("Numéro de carte: "); scanf("%d", (*parc)[*nb]->numCarte);
    printf("Spécialité: "); scanf("%49s", (*parc)[*nb]->specialite);
    printf("Numéro de série: "); scanf("%49s", (*parc)[*nb]->numSerie);
    printf("Marque: "); scanf("%49s", (*parc)[*nb]->marque);
    printf("CPU (GHz): "); scanf("%f", (*parc)[*nb]->cpu);
    printf("RAM (Go): "); scanf("%d", (*parc)[*nb]->ram);
    printf("Disque (Go): "); scanf("%d", (*parc)[*nb]->disque);
    printf("Prix (F CFA): "); scanf("%d", (*parc)[*nb]->prix);

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

void supprimerOrdinateur(Ordinateur **parc, int *nb) {
    if (*nb == 0) {
        printf("Le parc est vide. Rien à supprimer.\n");
        return;
    }
    int num, trouve = 0;
    printf("Entrer num carte à supprimer: ");
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
            trouve = 1;
            break;
        }
    }
    if (!trouve) printf("Ordinateur non trouvé.\n");
}

void repartirParSpecialite(Ordinateur **parc, int nb) {
    if (nb == 0) { printf("Le parc est vide.\n"); return; }
    printf("Liste par spécialité:\n");
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
    printf("Tri par CPU effectué.\n");
}

void valeurTotale(Ordinateur **parc, int nb) {
    if (nb == 0) { printf("Le parc est vide.\n"); return; }
    int total = 0;
    for (int i = 0; i < nb; i++) total += *parc[i]->prix;
    printf("Valeur totale du parc: %d F CFA\n", total);
}

void libererParc(Ordinateur ***parc, int nb) {
    for (int i = 0; i < nb; i++) {
        free((*parc)[i]->numCarte);
        free((*parc)[i]->cpu);
        free((*parc)[i]->ram);
        free((*parc)[i]->disque);
        free((*parc)[i]->prix);
        free((*parc)[i]->specialite);
        free((*parc)[i]->numSerie);
        free((*parc)[i]->marque);
        free((*parc)[i]);
    }
    free(*parc);
    *parc = NULL;
}
