#ifndef LISTE_H
#define LISTE_H

struct node {
  int data;
  struct node *link;
};

struct node *create_list(int num1, int num2);
void print_list_data(struct node *head);
void insert_at_end(struct node *head, int num);
struct node *insert_at_beginning(struct node *head, int num);
struct node *remove_beginning(struct node *head);
void remove_end(struct node *head);
void remove_at_position(struct node **head_ref, int pos);
void search(struct node *head, int num);
void destroy_list(struct node **head_ref);

#endif
