#ifndef LISTE_H
#define LISTE_H

#include <stdbool.h>

typedef void Objet;

typedef struct element {
  Objet* reference;
  struct element* suivant;
} Element;

typedef struct {
  Element* premier;
  Element* dernier;
  Element* courant;
  int nbElt;
  int type;
  char* (*afficher)(Objet*);
  int (*comparer)(Objet*, Objet*);
} Liste;

Element* cree_element();
void ouvrir_liste(Liste* li);
bool fin_liste(Liste* li);
bool liste_vide(Liste* li);

Element* deplacer_courant(Liste* li);
Objet* objet_courant(Liste* li);

void init_liste(Liste* li, int type, char* (*afficher)(Objet*),
                int (*comparer)(Objet*, Objet*));
Liste* creer_liste(int type, char* (*afficher)(Objet*),
                   int (*comparer)(Objet*, Objet*));

#endif