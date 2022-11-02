#include "personne.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Personne* cree_personne(char* nom, char* prenom) {
  Personne* p = (Personne*)malloc(sizeof(Personne));
  strcpy(p->nom, nom);
  strcpy(p->prenom, prenom);
  return p;
}

char* afficher_personne(Objet* objet) {
  Personne* p = (Personne*)objet;
  char* output = (char*)malloc(sizeof(Personne));
  snprintf(output, sizeof(Personne), "%s %s\n", p->nom, p->prenom);
  return output;
}

int comparer_personne(Objet* objet1, Objet* objet2) {
  Personne* p1 = (Personne*)objet1;
  Personne* p2 = (Personne*)objet2;
  return strcmp(p1->nom, p2->nom);  // 0 equal, >0 s1>s2, <0, s1<s1
}
