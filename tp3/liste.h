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

static Element* cree_element();
static void ouvrir_liste(Liste* li);
static bool fin_liste(Liste* li);
static bool liste_vide(Liste* li);

static Element* element_courant(Liste* li);
static Objet* objet_courant(Liste* li);

void init_liste(Liste* li, int type, char* (*afficher)(Objet*),
                int (*comparer)(Objet*, Objet*));
Liste* creer_liste(int type, char* (*afficher)(Objet*),
                   int (*comparer)(Objet*, Objet*));
void inserer_en_tete(Liste* li, Objet* objet);
static void inserer_apres(Liste* li, Element* precedent, Objet* objet);
void inserer_en_fin(Liste* li, Objet* objet);
Objet* extraire_en_tete(Liste* li);
static Objet* extraire_apres(Liste* li, Element* precedent);
Objet* extraire_fin(Liste* li);
bool extraire_objet(Liste* li, Objet* objet);
Objet* chercher_objet(Liste* li, Objet* objet_cherche);
void lister_liste(Liste* li);
void detruire_liste(Liste* li);

#endif