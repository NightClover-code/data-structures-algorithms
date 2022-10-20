#include <stdio.h>
#include <stdlib.h>

#include "liste.h"

int main() {
  struct node* head = create_list(45, 90);

  insert_at_end(head, 80);
  insert_at_end(head, 100);
  insert_at_end(head, 200);

  destroy_list(&head);

  print_list_data(head);

  return 0;
}