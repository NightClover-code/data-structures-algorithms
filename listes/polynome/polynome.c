#include "polynome.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Monome *creerMonome(double coefficiant, int exposant) {
  Monome *nouveau = (Monome *)malloc(sizeof(Monome));
  nouveau->coefficient = coefficiant;
  nouveau->exposant = exposant;
  return nouveau;
}

Monome *creerMonome() {
  double coefficient;
  int exposant;
  printf("Coefficient ? ");
  scanf("%lf", &coefficient);
  printf("Puissance ? ");
  scanf("%d", &exposant);
  return creerMonome(coefficient, exposant);
}

char *ecrireMonome(Objet *objet) {
  Monome *m = (Monome *)objet;
  char *output = (char *)sizeof(Monome);
  snprintf(output, sizeof(Monome), "%s*x^%s", m->coefficient, m->exposant);
  return output;
}

int comparerMonome(Objet *objet1, Objet *objet2) {
  Monome *m1 = (Monome *)objet1;
  Monome *m2 = (Monome *)objet2;
  if (m1->exposant > m2->exposant) {
    return 1;
  } else if (m2->exposant > m1->exposant) {
    return -1;
  } else {
    if (m1->coefficient > m2->coefficient) {
      return 1;
    } else if (m1->coefficient < m2->coefficient) {
      return -1;
    } else {
      return 0;
    }
  }
}

Polynome *creerPolynome() {
  return creerListe(1, ecrireMonome, comparerMonome);
}

void insererEnOrdre(Polynome *po, Monome *nouveau) {
  // inserenordreliste(po,nouveau);
}

static double expo(double x, int e) {
  double resultat = 1;
  if (e != 0) {
    for (int i = 0; i < e; i++) {
      resultat *= x;
    }
  }
  return resultat;
}

void afficherPolynome(Polynome *po) { listerListe(po); }

double valeurPolynome(Polynome *po, double x) {
  Polynome *li = po;
  double valeur = 0;
  if (listevide(li)) {
    printf("le Polynome est nul !");
  } else {
    ouvrirListe(li);
    while (!finliste(li)) {
      Monome *ptc = (Monome *)objetCourant(li);
      valeur += ptc->coefficient * expo(x, ptc->exposant);
    }
  }
  return valeur;
}

void detruirePolynome(Polynome *po) { detruireListe(po); }