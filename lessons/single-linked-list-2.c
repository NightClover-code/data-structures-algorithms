#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *link;
};

int main() {
  /*x
    Notes:
      - This is a better method to create a single linked list.
      - We can use the head pointer to reference the next ones; eg: head->link
    points to the 2nd node, head->link->link points to the 3rd node and so on.
    - With this method, no need to create another pointer for every new node.
  */
  struct node *head = malloc(sizeof(struct node));

  head->data = 45;
  head->link = NULL;

  struct node *current = malloc(sizeof(struct node));

  current->data = 98;
  current->link = NULL;
  head->link = current;

  current->data = 10;
  current->link = NULL;
  head->link->link = current;

  return 0;
}