#ifndef PERSONNE_H
#define PERSONNE_H

typedef char ch15[16];
typedef void Objet;

typedef struct {
  ch15 nom;
  ch15 prenom;
} Personne;

Personne* cree_personne(char* nom, char* prenom);
char* afficher_personne(Objet* objet);
int comparer_personne(Objet* objet1, Objet* objet2);

#endif