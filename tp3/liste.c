#include "liste.h"

#include <stdio.h>
#include <stdlib.h>

/*
  NOTES:
    - When head changes position or is created for the first time, we return it
  from the function.
*/

struct node* create_list(int num1, int num2) {
  struct node* head = malloc(sizeof(struct node));
  head->data = num1;
  head->link = NULL;

  struct node* ptr = malloc(sizeof(struct node));
  ptr->data = num2;
  ptr->link = NULL;

  head->link = ptr;  // linking the first two nodes

  return head;
}

void print_list_data(struct node* head) {
  if (head == NULL) {
    printf("Linked list is empty!");
  }

  struct node* ptr = NULL;
  ptr = head;

  while (ptr != NULL) {  // printing linked list data
    printf("%d, ", ptr->data);
    ptr = ptr->link;
  }
}

void insert_at_end(struct node* head, int num) {
  struct node *ptr, *end;
  ptr = head;
  end = malloc(sizeof(struct node));

  end->data = num;
  end->link = NULL;

  while (ptr->link != NULL) {  // traversing a linked list
    ptr = ptr->link;
  }

  ptr->link = end;  // insert node at end
}

struct node* insert_at_beginning(struct node* head, int num) {
  struct node* ptr = malloc(sizeof(struct node));
  ptr->data = num;
  ptr->link = head;

  head = ptr;

  return head;
}

struct node* remove_beginning(struct node* head) {
  if (head == NULL) {
    printf("List is already empty!");
  }

  struct node* temp = head;
  head = head->link;
  free(temp);  // deleting first node
  temp = NULL;

  return head;
}

void remove_end(struct node* head) {
  if (head == NULL) {
    printf("List is already empty!");
  } else if (head->link == NULL) {
    free(head);
    head = NULL;
  } else {
    struct node* temp = head;
    struct node* temp2 = head;

    while (temp->link != NULL) {  // temp is always one node ahead of temp2
      temp2 = temp;
      temp = temp->link;
    }

    free(temp);
    temp = NULL;
    temp2->link = NULL;
  }
}
