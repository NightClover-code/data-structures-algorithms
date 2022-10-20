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
  struct node* head = NULL;
  int code = menu();

  while (1) {
    switch (code) {
      case 1:
        int num1, num2;

        printf("\nEnter 2 numbers: ");
        scanf("%d %d", &num1, &num2);

        head = create_list(num1, num2);

        printf("\nCreated list: ");
        print_list_data(head);
        code = menu();
        break;
      case 2:
        int num;

        printf("\nEnter a number to insert: ");
        scanf("%d", &num);

        struct node* new_head = insert_at_beginning(head, num);

        head = new_head;

        printf("\nList after insert: ");
        print_list_data(head);
        code = menu();
        break;
      default:
        break;
    }
  }

  return 0;
}
