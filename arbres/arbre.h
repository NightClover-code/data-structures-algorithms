#ifndef ARBRE_H
#define ARBRE_H

#include <stdbool.h>

typedef void Objet;

typedef struct noeud {
  Objet* reference;
  struct noeud* gauche;
  struct noeud* droite;
} Noeud;

typedef struct {
  Noeud* racine;
  char* (*afficher)(Objet*);
  int (*comparer)(Objet*, Objet*);
} Arbre;

Noeud* cNd(Objet* objet, Noeud* gauche, Noeud* droite);
Noeud* cF(Objet* objet);

void init_arbre(Arbre* arbre, Noeud* racine, char* (*afficher)(Objet*),
                int (*comparer)(Objet*, Objet*));
Arbre* creer_arbre(Noeud* racine, char* (*afficher)(Objet*),
                   int (*comparer)(Objet*, Objet*));
void prefixe(Noeud* racine, char* (*afficher)(Objet*));
void infixe(Noeud* racine, char* (*afficher)(Objet*));
void postfixe(Noeud* racine, char* (*afficher)(Objet*));
Noeud* trouver_noeud(Noeud* racine, Objet* obj,
                     int (*comparer)(Objet*, Objet*));
void en_largeur(Noeud* racine, char* (*afficher)(Objet*));
bool egalite_arbre(Noeud* racine1, Noeud* racine2,
                   int (*comparer)(Objet*, Objet*));

#endif