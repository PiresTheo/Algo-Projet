#ifndef PROJETALGO_POKER_H
#define PROJETALGO_POKER_H

#include "Grille.h"
#include "Poker.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct {
    int argent;
    int mise;
    Case jeu[2];
    bool coucher;
}joueurPoker;

typedef struct {
    Case river[5];
    joueurPoker tableDeJeu[5];
    int pot;
}Parti;



joueurPoker initJoueur(joueurPoker j);
void initTirage(int n, Case t[5+2*n]);
Parti initParti(int n,Parti p);
int nbAlea(int n);
bool appartient(int v, int c ,int n ,Case t[5+2*n]);
void remplirTirage(int n ,Case t[5+2*n]);
Parti distribution(int n, Case t[5+2*n], Parti p);
int maxMise(Parti p,int n);
Parti Suivre(Parti p,int joueur,int n);
Parti tapis(Parti p , int joueur);
Parti seCoucher(Parti p, int joueur);
Parti relancer(Parti p ,int joueur, int somme,int n);
int quitterLaTable(Parti* p, int numeroJoueur);
Parti repartitionArgent (Parti p, int joueurGagnant, int n);
Parti repartitionEgaliter(Parti p, int n);
Parti miseDepart(Parti p, int n, int tour);
int potTotale(Parti p,int n);
int nombreAbbandon(Parti p, int n);
int nombreCoucher(Parti p, int n);
Parti tourJoueur(Parti p,int numerojoueur, int n);
int tour(Parti* p, int n, int premier);
Parti tourPartie (Parti p , int n,  Case t[5+2*n]);
void partie();
#endif //PROJETALGO_POKER_H
