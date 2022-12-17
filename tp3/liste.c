#include "liste.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// user functions
bool fin_liste(Liste *li) { return li->courant == NULL; };
void ouvrir_liste(Liste *li) { li->courant = li->premier; };

// helper functions
static Element *cree_element() { return (Element *)malloc(sizeof(Element)); }
bool liste_vide(Liste *li) { return li->nbElt == 0; }
int nb_element(Liste *li) { return li->nbElt; }

// current functions
static Element *element_courant(Liste *li) {
  Element *ptc = li->courant;
  if (li->courant != NULL) {
    li->courant = li->courant->suivant;
  }
  return ptc;
}

Objet *objet_courant(Liste *li) {
  Element *ptc = element_courant(li);
  return ptc == NULL ? NULL : ptc->reference;
}

// main functions
void init_liste(Liste *li, int type, char *(*afficher)(Objet *),
                int (*comparer)(Objet *, Objet *)) {
  li->premier = NULL;
  li->dernier = NULL;
  li->courant = NULL;
  li->nbElt = 0;
  li->type = type;
  li->afficher = afficher;
  li->comparer = comparer;
}

Liste *creer_liste(int type, char *(*afficher)(Objet *),
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

void inserer_apres(Liste *li, Element *precedent, Objet *objet) {
  if (precedent == NULL) {
    inserer_en_tete(li, objet);
  } else {
    Element *nouveau = cree_element();
    nouveau->reference = objet;
    nouveau->suivant = precedent->suivant;
    precedent->suivant = nouveau;
    if (precedent == li->dernier) li->dernier = nouveau;
    li->nbElt++;
  }
}

void inserer_en_fin(Liste *li, Objet *objet) {
  inserer_apres(li, li->dernier, objet);
}

void lister_liste(Liste *li) {
  ouvrir_liste(li);
  while (!fin_liste(li)) {
    Objet *objet = objet_courant(li);
    printf("%s\n", li->afficher(objet));
  }
}

Objet *chercher_objet(Liste *li, Objet *objet_cherche) {
  bool trouve = false;
  ouvrir_liste(li);
  Objet *objet;
  while (!fin_liste(li)) {
    objet = objet_courant(li);
    trouve = li->comparer(objet_cherche, objet) == 0;
  }

  return trouve ? objet_cherche : NULL;
}

Objet *extraire_en_tete(Liste *li) {
  Element *extrait = li->premier;
  if (!liste_vide(li)) {
    li->premier = li->premier->suivant;
    if (li->premier == NULL) li->dernier = NULL;  //???
    li->nbElt--;
  }

  return extrait != NULL ? extrait->reference : NULL;
}

Objet *extraire_apres(Liste *li, Element *precedent) {
  if (precedent == NULL) {
    return extraire_en_tete(li);
  } else {
    Element *extrait = precedent->suivant;
    if (extrait->suivant) {
      precedent->suivant = extrait->suivant;
      if (extrait == li->dernier) li->dernier = precedent;
      li->nbElt--;
    }
  }
}

Objet *extraire_fin(Liste *li) {
  Objet *extrait;
  if (liste_vide(li)) {
    extrait = NULL;
  } else if (li->premier == li->dernier) {
    extrait = extraire_en_tete(li);
  } else {
    Element *ptc = li->premier;
    while (ptc->suivant != li->dernier) ptc = ptc->suivant;
    extrait = extraire_apres(li, ptc);
  }

  return extrait;
}

bool extraire_objet(Liste *li, Objet *objet) {
  Element *precedent = NULL;
  Element *ptc = NULL;
  bool trouve = false;
  ouvrir_liste(li);
  while (!fin_liste(li) && !trouve) {
    precedent = ptc;
    ptc = element_courant(li);
    trouve = (ptc->reference == objet) ? true : false;
  }
  if (!trouve) return false;
  Objet *extrait = extraire_apres(li, precedent);
  return true;
}

void detruire_liste(Liste *li) {
  ouvrir_liste(li);
  while (!fin_liste(li)) {
    Element *ptc = element_courant(li);
    // free(ptc->reference) destruction objets
    free(ptc);
  }
  init_liste(li, 0, NULL, NULL);
}
