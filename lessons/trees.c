#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node* left;
  struct node* right;
} Node;

Node* create_node(int value) {
  Node* result = (Node*)malloc(sizeof(Node));
  result->left = NULL;
  result->right = NULL;
  result->value = value;
  return result;
}

void print_tabs(int numTabs) {
  for (int i = 0; i < numTabs; i++) {
    printf("\t");
  }
}

void print_tree(Node* root, int level) {
  if (root == NULL) {
    print_tabs(level);
    printf("---<empty>--\n");
    return;
  }
  // preorder traversal
  print_tabs(level);
  printf("value = %d\n", root->value);
  print_tabs(level);
  printf("left\n");

  print_tree(root->left, level + 1);
  print_tabs(level);
  printf("right\n");

  print_tree(root->right, level + 1);

  print_tabs(level);
  printf("done\n");
}

int main() {
  Node* n1 = create_node(10);
  Node* n2 = create_node(11);
  Node* n3 = create_node(12);
  Node* n4 = create_node(13);
  Node* n5 = create_node(14);
  Node* n6 = create_node(15);
  Node* n7 = create_node(16);

  n1->left = n2;
  n1->right = n3;
  n3->left = n4;
  n3->right = n5;
  n4->left = n6;
  n4->right = n7;

  print_tree(n1, 0);

  free(n1);
  free(n2);
  free(n3);
  free(n4);
  free(n5);
  free(n6);
  free(n7);

  return 0;
}