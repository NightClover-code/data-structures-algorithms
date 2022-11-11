#ifndef P_H
#define P_H
#include "liste.h"

typedef struct {
  int exposant;
  double coefficient;
} Monome;

typedef Liste Polynome;

Monome *creerMonome(double coefficiant, int exposant);
Monome *creerMonome();
char *ecrireMonome(Objet *objet);
int comparerMonome(Objet *objet1, Objet *objet2);
Polynome *creerPolynome();
void insererEnOrdre(Polynome *po, Monome *nouveau);
void afficherPolynome(Polynome *po);
static double expo(double x, int e);
double valeurPolynome(Polynome *po, double x);
void detruirePolynome(Polynome *po);

#endif