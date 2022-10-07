#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *link;  // pointer to the structure node
};

int main() {
  /*
    Notes:
      - A linked list is a collection of nodes
      - A node in the C language is a self-referential structure, which means
    that it is made out of data and a pointer to the next node
  */
  struct node *head = NULL;

  head = (struct node *)malloc(sizeof(struct node));

  head->data = 45;
  head->link = NULL;

  printf("%d", head->data);

  return 0;
}