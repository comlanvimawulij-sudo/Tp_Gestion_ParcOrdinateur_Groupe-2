
#ifndef ORDINATEUR_H
#define ORDINATEUR_H

#define MAX_ORDINATEURS 300

typedef struct {
    int *numCarte;
    char *specialite;
    char *numSerie;
    char *marque;
    float *cpu;
    int *ram;
    int *disque;
    int *prix;
} Ordinateur;

void ajouterOrdinateur(Ordinateur **parc, int *nb);
void listerOrdinateurs(Ordinateur **parc, int nb);
void afficherDetails(Ordinateur **parc, int nb);
void supprimerOrdinateur(Ordinateur **parc, int *nb);
void repartirParSpecialite(Ordinateur **parc, int nb);
void repartirParMarque(Ordinateur **parc, int nb);
void trierParCpu(Ordinateur **parc, int nb);
void valeurTotale(Ordinateur **parc, int nb);
void libererParc(Ordinateur **parc, int nb);

#endif
