#include "liste.h"

#include <stdbool.h>
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

  struct node* current = NULL;
  current = head;

  while (current != NULL) {  // printing linked list data
    printf("%d, ", current->data);
    current = current->link;
  }
}

void insert_at_end(struct node* head, int num) {
  struct node *current, *end;
  current = head;
  end = malloc(sizeof(struct node));

  end->data = num;
  end->link = NULL;

  while (current->link != NULL) {  // traversing a linked list
    current = current->link;
  }

  current->link = end;  // insert node at end
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
    struct node* current = head;
    struct node* previous = head;

    while (current->link != NULL) {
      previous = current;
      current = current->link;
    }

    free(current);
    current = NULL;
    previous->link = NULL;
  }
}

void remove_at_position(struct node** head_ref, int pos) {
  struct node* current = *head_ref;
  struct node* previous = *head_ref;

  if (*head_ref == NULL) {
    printf("List is already empty!");
  } else if (pos == 1) {
    *head_ref = current->link;
    free(current);
    current = NULL;
  } else {
    while (pos != 1) {
      previous = current;
      current = current->link;
      pos--;
    }

    previous->link = current->link;
    free(current);
    current = NULL;
  }
}

void search(struct node* head, int num) {
  int pos = 1;
  bool found = false;

  struct node* current = head;

  while (current != NULL) {
    if (current->data == num) {
      found = true;
      printf("%d found at position %d", num, pos);
    }

    current = current->link;
    pos++;
  }

  if (found == false) {
    printf("%d is not in the list.", num);
  }
}

void destroy_list(struct node** head_ref) {
  struct node* current = *head_ref;
  struct node* next;

  while (current != NULL) {
    next = current->link;
    free(current);
    current = next;
  }

  *head_ref = NULL;
}