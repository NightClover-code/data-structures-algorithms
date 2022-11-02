#ifndef LISTE_H
#define LISTE_H

#include <stdbool.h>

typedef void Objet;  // pointer to empty data (void)

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
  int (*comparer)(Objet *, Objet *);  // 0, < 0, > 0
} Liste;

void init_liste(Liste *li, int type, char *(*afficher)(Objet *),
                int (*comparer)(Objet *, Objet *));
Liste *cree_liste(int type, char *(*afficher)(Objet *),
                  int (*comparer)(Objet *, Objet *));
void inserer_en_tete(Liste *li, Objet *objet);
void inserer_en_fin(Liste *li, Objet *objet);
void inserer_apres(Liste *li, Element *precedent, Objet *objet);
void afficher_liste(Liste *li);
Objet *chercher_objet(Liste *li, Objet *objet);
Objet *extraire_en_tete(Liste *li);
Objet *extraire_apres(Liste *li, Element *precedent);
Objet *extraire_fin(Liste *li);
bool extraire_objet(Liste *li, Objet *objet);
void detruire_liste(Liste *li);

#endif
