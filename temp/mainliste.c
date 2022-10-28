#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "liste.h"

int menu() {
  printf("\n\n GESTION D'UNE LISTE D'ENTIERS \n\n");
  printf("1 - Creer une liste\n");
  printf("2 - Insertion en tete de liste \n");
  printf("3 - Insertion en fin de liste \n");
  printf("4 - Retrait en tete de liste \n");
  printf("5 - Retrait en fin de liste \n");
  printf("6 - Retrait d’un objet à partir de sa reference\n");
  printf("7 - Afficher les objets de la liste \n");
  printf("8 - Chercher Un objet \n");
  printf("9 - Destruction de la liste \n");
  printf("10 - Fin\n");
  printf("\n");
  printf("Votre choix ? ");

  int code;

  scanf("%d", &code);
  getchar();
  printf("\n");

  return code;
}

int main() {
  // List *list = NULL;

  // init_list(list, 0, prinf(""))

  return 0;
}
