#ifndef ARBRE_H
#define ARBRE_H

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
Noeud* trouverNoeud(Noeud* racine, Objet* obj, int (*comparer)(Objet*, Objet*));
void enLargeur(Noeud* racine, char* (*afficher)(Objet*));

#endif