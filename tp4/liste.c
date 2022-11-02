#include "liste.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static Element* cree_element() { return (Element*)malloc(sizeof(Element)); }
static void ouvrir_liste(Liste* li) { li->courant = li->premier; }
static bool fin_liste(Liste* li) { li->courant == NULL; }
static bool liste_vide(Liste* li) { return li->nbElt == 0; }

static Element* element_courant(Liste* li) {  // liste ouverte !!
  Element* ptc = li->courant;
  if (li->courant != NULL) {
    li->courant = li->courant->suivant;
  }
  return ptc;
}

static Objet* objet_courant(Liste* li) {
  Element* ptc = li->courant;  //!!
  if (li->courant != NULL) {
    li->courant = li->courant->suivant;
  }
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

void inserer_en_tete(Liste* li, Objet* objet) {
  Element* ptc = cree_element();
  ptc->reference = objet;
  ptc->suivant = li->premier;
  li->premier = ptc;
  if (li->dernier == NULL) li->dernier = ptc;
  li->nbElt++;
}

static void inserer_apres(Liste* li, Element* precedent, Objet* objet) {
  if (precedent == NULL) {
    inserer_en_tete(li, objet);
  } else {
    Element* ptc = cree_element();
    ptc->reference = objet;
    ptc->suivant = precedent->suivant;
    precedent->suivant = ptc;
    if (precedent == li->dernier) li->dernier = ptc;
    li->nbElt++;
  }
}

void inserer_en_fin(Liste* li, Objet* objet) {
  inserer_apres(li, li->dernier, objet);
}

Objet* extraire_en_tete(Liste* li) {
  Element* extrait = li->premier;
  if (extrait != NULL) {
    li->premier = li->premier->suivant;
    if (li->premier == NULL) li->dernier = NULL;
    li->nbElt--;
  }
  return extrait != NULL ? extrait->reference : NULL;
}

static Objet* extraire_apres(Liste* li, Element* precedent) {
  if (precedent == NULL) {
    extraire_en_tete(li);
  } else {
    Element* extrait = precedent->suivant;
    if (extrait != NULL) {
      precedent->suivant = extrait->suivant;
      if (extrait == li->dernier) li->dernier = precedent;
      li->nbElt--;
    }
    return extrait != NULL ? extrait->reference : NULL;
  }
}

Objet* extraire_fin(Liste* li) {
  Objet* objet_extrait;
  if (liste_vide(li)) {
    objet_extrait = NULL;
  } else if (li->dernier == li->dernier) {
    objet_extrait = extraire_en_tete(li);
  } else {
    Element* ptc = li->premier;
    while (ptc->suivant != li->dernier) ptc = ptc->suivant;
    objet_extrait = extraire_apres(li, ptc);
  }
  return objet_extrait;
}

bool extraire_objet(Liste* li, Objet* objet) {
  Element* precedent = NULL;
  Element* courant = NULL;
  bool trouve = false;

  ouvrir_liste(li);
  while (!fin_liste(li) && !trouve) {
    precedent = courant;
    courant = element_courant(li);
    trouve = (courant->reference == objet) ? true : false;
  }
  if (!trouve) return false;

  extraire_apres(li, precedent);
  return true;
}

bool chercher_objet(Liste* li, Objet* objet_cherche) {
  Objet* courant_objet;
  bool trouve = false;

  ouvrir_liste(li);
  while (!fin_liste(li) && !trouve) {
    courant_objet = objet_courant(li);
    trouve = li->comparer(objet_cherche, courant_objet) == 0;
  }
  return trouve ? courant_objet : NULL;
}

void lister_liste(Liste* li) {
  ouvrir_liste(li);
  while (!fin_liste(li)) {
    Objet* objet = objet_courant(li);
    printf("%s\n", li->afficher(objet));
  }
}

void detruire_liste(Liste* li) {
  ouvrir_liste(li);
  while (!fin_liste(li)) {
    Element* ptc = element_courant(li);
    // free(ptc->reference) destruction objets
    free(ptc);
  }
  init_liste(li, 0, NULL, NULL);
}
