#include "arbre.h"

#include <stdio.h>
#include <stdlib.h>

Noeud* cNd(Objet* objet, Noeud* gauche, Noeud* droite) {
  Noeud* noeud = (Noeud*)malloc(sizeof(Noeud));
  noeud->reference = objet;
  noeud->gauche = gauche;
  noeud->droite = droite;
  return noeud;
}

Noeud* cF(Objet* objet) { return cNd(objet, NULL, NULL); }

void init_arbre(Arbre* arbre, Noeud* racine, char* (*afficher)(Objet*),
                int (*comparer)(Objet*, Objet*)) {
  arbre->racine = racine;
  arbre->comparer = comparer;
  arbre->afficher = afficher;
}

Arbre* creer_arbre(Noeud* racine, char* (*afficher)(Objet*),
                   int (*comparer)(Objet*, Objet*)) {
  Arbre* arbre = (Arbre*)malloc(sizeof(Arbre));
  init_arbre(arbre, racine, afficher, comparer);
  return arbre;
}

void prefixe(Noeud* racine, char* (*afficher)(Objet*)) {
  if (racine != NULL) {
    printf("%s->", afficher(racine->reference));
    prefixe(racine->gauche, afficher);
    prefixe(racine->droite, afficher);
  }
}

void infixe(Noeud* racine, char* (*afficher)(Objet*)) {
  if (racine != NULL) {
    infixe(racine->gauche, afficher);
    printf("%s->", afficher(racine->reference));
    infixe(racine->droite, afficher);
  }
}

void postfixe(Noeud* racine, char* (*afficher)(Objet*)) {
  if (racine != NULL) {
    postfixe(racine->gauche, afficher);
    postfixe(racine->droite, afficher);
    printf("%s->", afficher(racine->reference));
  }
}

Noeud* trouverNoeud(Noeud* racine, Objet* obj,
                    int (*comparer)(Objet*, Objet*)) {
  Noeud* pNom;
  if (racine == NULL) {
    pNom = NULL;
  } else if (comparer(racine->reference, obj) == 0)
    pNom = racine;
  else {
    pNom = trouverNoeud(racine->gauche, obj, comparer);
    if (pNom == NULL) pNom = trouverNoeud(racine->droite, obj, comparer);
  }
  return pNom;
}