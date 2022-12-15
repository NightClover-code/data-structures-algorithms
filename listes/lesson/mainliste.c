#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "liste.h"

char* ecrire(Objet* objet) {
  int* p = (int*)objet;
  char* output = (char*)malloc(sizeof(int));

  snprintf(output, sizeof(int), "%d", *p);

  return output;
}

int main() {
  Liste* li = cree_liste(0, ecrire, NULL);

  int* pNum = (int*)malloc(sizeof(int));

  printf("Entrez num: ");
  scanf("%d", pNum);

  inserer_en_tete(li, pNum);

  return 0;
}
