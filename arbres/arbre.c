#include "arbre.h"

#include <stdio.h>
#include <stdlib.h>

#include "liste.h"

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

void enLargeur(Noeud* racine, char* (*afficher)(Objet*)) {
  Liste* li = cree_liste(0, afficher, NULL);
  inserer_en_fin(li, racine);
  while (!liste_vide(li)) {
    Noeud* extrait = (Noeud*)extraire_en_tete(li);
    printf("%s->", afficher(extrait->reference));
    if (extrait->gauche != NULL) inserer_en_fin(li, extrait->gauche);
    if (extrait->droite != NULL) inserer_en_fin(li, extrait->droite);
  }
}

int maximum(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}

bool estFeuille(Noeud* racine) {
  return (racine->droite == NULL) && (racine->gauche == NULL);
}

int taille(Noeud* racine) {
  if (racine == NULL)
    return 0;
  else
    return 1 + taille(racine->gauche) + taille(racine->droite);
}

int hauteur(Noeud* racine) {
  if (racine == NULL)
    return 0;
  else
    return 1 + maximum(hauteur(racine->droite), hauteur(racine->gauche));
}

int nbFeuilles(Noeud* racine) {
  if (racine == NULL)
    return 0;
  else if (estFeuille(racine))
    return 1;
  else
    return nbFeuilles(racine->droite) + nbFeuilles(racine->gauche);
}