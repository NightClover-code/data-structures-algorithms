#ifndef LISTE_H
#define LISTE_H

#include <stdbool.h>

typedef void *Objet;  // pointer to empty data (void)

typedef struct element {
  Objet *reference;
  struct element *suivant;
} Element;

typedef struct {
  Element *premier;
  Element *dernier;
  Element *courant;
  int nbElt;
  int type;  // 0: simple, 1:croissant, 2:décroissant
  char *(*afficher)(Objet *);
  int (*comparer)(Objet *, Objet *);
} Liste;

void init_liste(Liste *li, int type, char *(*afficher)(Objet *),
                int (*comparer)(Objet *, Objet *));
Liste *cree_liste(int type, char *(*afficher)(Objet *),
                  int (*comparer)(Objet *, Objet *));
void inserer_en_tete(Liste *li, Objet *objet);

bool liste_vide(Liste *li);
static Element *cree_element();
int nbElement(Liste *li);

#endif
