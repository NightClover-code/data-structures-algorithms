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
  struct node* head = NULL;
  struct node* new_head = NULL;
  int num1, num2, num, pos, code;
  bool quit = false;

  while (!quit) {
    code = menu();
    switch (code) {
      case 1:
        printf("\nEnter 2 numbers: ");
        scanf("%d %d", &num1, &num2);

        head = create_list(num1, num2);

        printf("\nCreated list: ");
        print_list_data(head);
        break;
      case 2:
        printf("\nEnter a number to insert: ");
        scanf("%d", &num);

        new_head = insert_at_beginning(head, num);
        head = new_head;

        printf("\nList after insert at beginning: ");
        print_list_data(head);
        break;
      case 3:
        printf("\nEnter a number to insert: ");
        scanf("%d", &num);

        insert_at_end(head, num);

        printf("\nList after insert at end: ");
        print_list_data(head);
        break;
      case 4:
        new_head = remove_beginning(head);
        head = new_head;

        printf("\nList after remove beginning: ");
        print_list_data(head);
        break;
      case 5:
        remove_end(head);

        printf("\nList after remove end: ");
        print_list_data(head);
        break;
      case 6:
        printf("\nEnter position of number to remove: ");
        scanf("%d", &pos);

        remove_at_position(&head, pos);

        printf("\nList after remove end: ");
        print_list_data(head);
        break;
      case 7:
        printf("\nList: ");
        print_list_data(head);
        break;
      case 8:
        printf("\nEnter the number to find: ");
        scanf("%d", &num);

        search(head, num);

        break;
      case 9:
        destroy_list(&head);

        print_list_data(head);
        break;
      case 10:
        quit = true;
      default:
        break;
    }
  }

  return 0;
}
