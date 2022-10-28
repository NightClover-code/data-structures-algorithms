#include "liste.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// main functions

void init_liste(Liste *li, int type, char *(*afficher)(Objet *),
                int (*comparer)(Objet *, Objet *)) {
  li->premier = NULL;
  li->dernier = NULL;
  li->courant = NULL;
  li->type = type;
  li->afficher = afficher;
  li->comparer = comparer;
}

Liste *cree_liste(int type, char *(*afficher)(Objet *),
                  int (*comparer)(Objet *, Objet *)) {
  Liste *li = (Liste *)malloc(sizeof(Liste));
  init_liste(li, type, afficher, comparer);
  return li;
}

void inserer_en_tete(Liste *li, Objet *objet) {
  Element *nouveau = cree_element();

  nouveau->reference = objet;
  nouveau->suivant = li->premier;
  li->premier = nouveau;
  if (li->dernier == NULL) li->dernier = nouveau;
  li->nbElt++;
}

// helper functions

Element *cree_element() { return (Element *)malloc(sizeof(Element)); }

bool liste_vide(Liste *li) { return li->nbElt == 0; }

int nbElement(Liste *li) { return li->nbElt; }
