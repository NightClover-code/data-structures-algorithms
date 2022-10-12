#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int *arr, int n) {
  int i, j, temp;

  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (*(arr + i) > *(arr + j)) {
        temp = *(arr + i);
        *(arr + i) = *(arr + j);
        *(arr + j) = temp;
      }
    }
  }
}

void printArr(int *arr, int n) {
  int *p;

  for (p = arr; p <= arr + n - 1; p++) {
    printf("%d, ", *p);
  }
}

int main() {
  int n, i, *arr;

  printf("N: ");
  scanf("%d: ", &n);

  srand(time(NULL));

  arr = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++) {
    *(arr + i) = rand();
  }

  printf("Previous array: ");

  printArr(arr, n);

  sort(arr, n);

  printf("\nSorted array: ");

  printArr(arr, n);

  printf("\nComparaisons: %.2f", pow(n, 2) + n - 1);

  return 0;
}