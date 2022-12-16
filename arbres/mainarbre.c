#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arbre.h"

int comparerInt(void *obj1, void *obj2) {
  int *b = (int *)obj2;
  int *a = (int *)obj1;
  if (*a > *b)
    return 1;
  else if (*a == *b)
    return 0;
  else
    return -1;
}

char *afficherInt(void *objet) {
  int *p = (int *)objet;
  char *output = (char *)malloc(sizeof(int));
  snprintf(output, sizeof(int), "%d", *p);
  return output;
}

int *create_num_pointer(int num) {
  int *p = (int *)malloc(sizeof(int));
  *p = num;
  return p;
}

int main() {
  int *a = create_num_pointer(1);
  int *b = create_num_pointer(2);
  int *c = create_num_pointer(4);
  int *d = create_num_pointer(5);
  int *e = create_num_pointer(7);
  int *f = create_num_pointer(8);
  int *g = create_num_pointer(3);
  int *h = create_num_pointer(6);
  int *i = create_num_pointer(9);
  int *j = create_num_pointer(10);

  Noeud *racine1 = cNd(a, cNd(b, cF(c), cNd(d, cF(e), cF(f))),
                       cNd(g, NULL, cNd(h, cF(i), NULL)));
  Noeud *racine2 = cNd(b, cNd(c, cF(c), cNd(d, cF(e), cF(f))),
                       cNd(g, NULL, cNd(h, cF(i), NULL)));

  // Arbre *nums = creer_arbre(racine, afficherInt, comparerInt);

  // prefixe(racine, afficherInt);
  // printf("\n");
  // infixe(racine, afficherInt);
  // printf("\n");
  // postfixe(racine, afficherInt);

  // Noeud *p = trouverNoeud(racine, j, comparerInt);

  // if (p != NULL) {
  //   printf("\nNoeud trouve: %s", afficherInt(p->reference));
  // } else {
  //   printf("\nPas de noeud trouve!");
  // }

  bool trees_equal = egalite_arbre(racine1, racine1, comparerInt);

  if (trees_equal) {
    printf("EQUAL");
  } else {
    printf("NOPË");
  }

  return 0;
}