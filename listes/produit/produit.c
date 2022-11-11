#include "produit.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Produit* cree_produit(int id, char* nom, float prix) {
  Produit* p = (Produit*)malloc(sizeof(Produit));
  p->id = id;
  strcpy(p->nom, nom);
  p->prix = prix;
  return p;
}
void inserer_produit(Liste* li, Produit* produit) {
  Produit* precedent = NULL;
  Produit* courant = NULL;
  bool trouve = false;

  if (li->nbElt == 0) {
    inserer_en_tete(li, produit);
  }

  ouvrir_liste(li);

  while (!fin_liste(li)) {
  }
}

char* afficher_produit(Objet* objet) {
  Produit* p = (Produit*)objet;
  char* output = (char*)malloc(sizeof(Produit));
  snprintf(output, sizeof(Produit), "%d %s %f\n", p->id, p->nom, p->prix);
  return output;
}

int comparer_produit(Objet* objet1, Objet* objet2) {
  Produit* p1 = (Produit*)objet1;
  Produit* p2 = (Produit*)objet2;
  return strcmp(p1->id, p2->id);  // 0 equal, >0 s1>s2, <0, s1<s1
}
