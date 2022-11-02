#include "liste.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

Element* cree_element() { return (Element*)malloc(sizeof(Element)); }
void ouvrir_liste(Liste* li) { li->courant = li->premier; }
bool fin_liste(Liste* li) { li->courant == NULL; }
bool liste_vide(Liste* li) { return li->nbElt == 0; }

Element* deplacer_courant(Liste* li) {  // liste ouverte !!
  Element* ptc = li->courant;
  if (li->courant != NULL) {
    li->courant = li->courant->suivant;
  }
  return ptc;
}

Objet* objet_courant(Liste* li) {
  Element* ptc = li->courant;  //!!

  return ptc != NULL ? ptc->reference : NULL;
}

void init_liste(Liste* li, int type, char* (*afficher)(Objet*),
                int (*comparer)(Objet*, Objet*)) {
  li->premier = NULL;
  li->dernier = NULL;
  li->courant = NULL;
  li->nbElt = 0;
  li->type = type;
  li->afficher = afficher;

  li->comparer = comparer;
}

Liste* creer_liste(int type, char* (*afficher)(Objet*),
                   int (*comparer)(Objet*, Objet*)) {
  Liste* li = (Liste*)malloc(sizeof(Liste));
  init_liste(li, type, afficher, comparer);
  return li;
}
