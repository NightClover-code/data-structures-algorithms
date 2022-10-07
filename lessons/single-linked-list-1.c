#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *link;
};

int main() {
  /*x
    Notes:
      - A linked list is a collection of nodes
      - Each node holds data and a pointer to the next node
      - This is the 1st method to create a single linked list
  */
  struct node *head = malloc(sizeof(struct node));

  head->data = 45;
  head->link = NULL;

  struct node *current = malloc(sizeof(struct node));

  current->data = 98;
  current->link = NULL;
  head->link = current;

  struct node *current2 = malloc(sizeof(struct node));

  current2->data = 120;
  current2->link = NULL;
  current->link = current2;

  return 0;
}