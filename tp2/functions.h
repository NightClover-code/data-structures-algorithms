#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void print_array(int *arr, int n);
void randomize_array(int *arr, int n);
int insert_at_position(int arr[], int n, int pos, int m);
int remove_at_position(int arr[], int n, int pos);
void reverse_array(int *arr, int n);
void sort_array(int *arr, int n);
void merge_arrays(int arr1[], int arr2[], int arr3[], int n, int m, int p);
char *multichar(char *s, int n);
void suite(int n);
void add_matrices(int **arr1, int **arr2, int m, int l, int n, int p);
void multiply_matrices(int **arr1, int **arr2, int m, int l, int n, int p);
void print_matrix(int **Tableau, int n, int m);
void randomize_matrix(int **Tableau, int n, int m);

#endif
