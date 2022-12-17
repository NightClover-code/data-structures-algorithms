#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "liste.h"

int menu() {
  int cod;
  printf("\n\nGESTION D'UNE LISTE D'ENTIERS\n\n");
  printf("1-Creer une liste\n");
  printf("2-Retourner le nombre des objets\n");
  printf("3-Verifier si la liste est vide\n");
  printf("4-Insertion en tete de liste\n");
  printf("5-Insertion en fin de liste\n");
  printf("6-Retrait en tete de liste\n");
  printf("7-Retrait en fin de liste\n");
  printf("8-Retrait d'un ovjet a partir de sa reference\n");
  printf("9-Afficher les objets de la liste\n");
  printf("10-Chercher un objet\n");
  printf("11-Destruction de la liste\n");
  printf("12-Fin\n");

  printf("\n");
  printf("Votre choix?\n");
  scanf("%d", &cod);
  printf("\n");
  return cod;
}

char *ecrireEntier(void *obj) {
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

void main() {
  Liste *li;
  int cod;
  int *pt, *obj;
  bool fini = false;

  while (!fini) {
    switch (menu()) {
      case 1: {
        li = cree_liste(0, ecrireEntier, comparerInt);
        break;
      }
      case 2: {
        printf("Le nombre d'element est : %d element.", li->nbElt);
        break;
      }
      case 3: {
        if (li->premier == NULL || li->nbElt == 0)
          printf("La liste est vide");
        else
          printf("La liste contient %d element!", li->nbElt);
        break;
      }
      case 4: {
        printf("Element a inserer en tete de liste:");
        scanf("%d", pt);
        inserer_en_tete(li, pt);
        break;
      }
      case 5: {
        printf("Element a inserer en fin de liste:");
        scanf("%d", pt);
        inserer_en_fin(li, pt);
        break;
      }
      case 6: {
        pt = (int *)extraire_en_tete(li);
        printf("l'objet extrait en tete de liste  est %d\n", *pt);
        break;
      }
      case 7: {
        pt = (int *)extraire_fin(li);
        printf("l'objet extrait en fin de liste  est %d\n", *pt);
        break;
      }
      case 8: {
        printf("Saisir l'objet que vous voulait extraire");
        scanf("%d", obj);
        Element *b = (Element *)chercher_objet(li, obj);
        if (extraire_objet(li, b))
          printf("L'objet est trouvee et extrait!");
        else
          printf("l'objet n est pas trouvee!");
        break;
      }
      case 9: {
        afficher_liste(li);
        break;
      }
      case 10: {
        printf("Saisir l'objet recherche");
        scanf("%d", obj);
        if (chercher_objet(li, obj))
          printf("L objet est trouvee!");
        else
          printf("l objet n est pas trouvee!");
        break;
      }
      case 11: {
        detruire_liste(li);
        break;
      }
      case 12: {
        fini = true;
        break;
      }
      default:
        break;
    }
  }
}
