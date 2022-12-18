#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "liste.h"

char *afficherInt(void *obj) {
  int *entier = (int *)obj;
  char *output = (char *)malloc(sizeof(int));
  snprintf(output, sizeof(int), "%d \n", *entier);
  return output;
}

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

int menu() {
  int cod;
  printf("\n\nGESTION D'UNE LISTE D'ENTIERS\n\n");
  printf("1-Creer une liste\n");
  printf("2-Insertion en tete de liste\n");
  printf("3-Insertion en fin de liste\n");
  printf("4-Retrait en tete de liste\n");
  printf("5-Retrait en fin de liste\n");
  printf("6-Retrait d'un objet a partir de sa reference\n");
  printf("7-Afficher les objets de la liste\n");
  printf("8-Chercher un objet\n");
  printf("9-Destruction de la liste\n");
  printf("10-Fin\n");
  printf("\n");
  printf("Votre choix?\n");
  scanf("%d", &cod);
  getchar();
  printf("\n");
  return cod;
}

void main() {
  Liste *li;
  int cod;
  int *pt = (int *)malloc(sizeof(int));
  int *obj = (int *)malloc(sizeof(int));

  bool fini = false;

  while (!fini) {
    switch (menu()) {
      case 1: {
        li = creer_liste(0, afficherInt, comparerInt);
        break;
      }
      case 2: {
        printf("Element a inserer en tete de liste: ");
        scanf("%d", pt);
        inserer_en_tete(li, pt);
        break;
      }
      case 3: {
        printf("Element a inserer en fin de liste: ");
        scanf("%d", pt);
        inserer_en_fin(li, pt);
        break;
      }
      case 4: {
        pt = (int *)extraire_en_tete(li);
        printf("l'objet extrait en tete de liste est %d\n", *pt);
        break;
      }
      case 5: {
        pt = (int *)extraire_fin(li);
        printf("l'objet extrait en fin de liste est %d\n", *pt);
        break;
      }
      case 6: {
        printf("Saisir l'objet que vous voulait extraire: ");
        scanf("%d", obj);
        Element *b = (Element *)chercher_objet(li, obj);
        if (extraire_objet(li, b))
          printf("L'objet est trouvee et extrait!");
        else
          printf("l'objet n est pas trouvee!");
        break;
      }
      case 7: {
        lister_liste(li);
        break;
      }
      case 8: {
        printf("Saisir l'objet recherche: ");
        scanf("%d", obj);
        if (chercher_objet(li, obj))
          printf("L objet est trouvee!");
        else
          printf("l objet n est pas trouvee!");
        break;
      }
      case 9: {
        detruire_liste(li);
        break;
      }
      case 10: {
        fini = true;
        break;
      }
      default:
        break;
    }
  }
}
