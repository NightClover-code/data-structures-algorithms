#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "functions.h"

void part1() {
  int *arr, n, pos;

  printf("N: ");
  scanf("%d", &n);

  printf("Position: ");
  scanf("%d", &pos);

  srand(time(NULL));

  arr = (int *)malloc(n * sizeof(int));

  randomize_array(arr, n);

  printf("Previous array: ");

  print_array(arr, n);

  // n = insert_at_position(arr, n, pos, 99);
  // n = remove_at_position(arr, n, pos);
  // reverse_array(arr, n);

  printf("\nNew array: ");

  print_array(arr, n);
}

void part2() {
  int *arr1, *arr2, *arr3, n, m, p;

  printf("N: ");
  scanf("%d", &n);

  printf("M: ");
  scanf("%d", &m);

  p = n + m;

  srand(time(NULL));

  arr1 = (int *)malloc(n * sizeof(int));
  arr2 = (int *)malloc(m * sizeof(int));
  arr3 = (int *)malloc(p * sizeof(int));

  randomize_array(arr1, n);
  randomize_array(arr2, m);

  sort_array(arr1, n);
  sort_array(arr2, m);

  printf("Previous arrays sorted: \n");
  print_array(arr1, n);
  printf("\n");
  print_array(arr2, m);

  // n = insert_at_position(arr, n, pos, 99);
  // n = remove_at_position(arr, n, pos);
  // reverse_array(arr, n);

  merge_arrays(arr1, arr2, arr3, n, m, p);
  sort_array(arr3, p);

  printf("\nNew array sorted: \n");
  print_array(arr3, p);
}

int main() {
  int n;
  char *s;

  s = (char *)calloc(1, sizeof(s));

  printf("String: ");
  scanf("%s", s);

  printf("N: ");
  scanf("%d", &n);

  printf("%s", multichar(s, n));

  // part2();

  return 0;
}
