#ifndef PRODUIT_H
#define PRODUIT_H

#include "liste.h"

typedef void Objet;

typedef struct {
  int id;
  char* nom;
  float prix;
} Produit;

Produit* cree_produit(int id, char* nom, float prix);
Liste* cree_liste_produit();
void inserer_produit(Liste* li, Produit* produit);

char* afficher_produit(Objet* objet);
int comparer_produit(Objet* objet1, Objet* objet2);

#endif