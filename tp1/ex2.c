#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int *arr, int n) {
  /*
    NOTE: This is known as Bubble Sort. A slow sorting algorithm, but definitely
    an easy one to implement.

    Bubble sort time complexity: O(n²) worst/average case, O(1) best case.
  */
  int i, j, temp;

  for (i = 0; i < n; i++) {           // n iteration
    for (j = i + 1; j < n; j++) {     // n * (n + 1) / 2 - 1 iteration
      if (*(arr + i) > *(arr + j)) {  // n * (n - 1) /2 iteration
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

  float c = n + (n * (n - 1)) / (float)2 + (n * (n + 1)) / (float)2 - 1;

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

  printf("\nComparaisons reelles: %.2f", c);
  printf("\nComparaisons cours: %.2f", pow(n, 2) + n - 1);

  return 0;
}