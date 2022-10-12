#include <stdio.h>
#include <stdlib.h>

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

  for (i = 0; i < n; i++) {
    printf("arr[%d]: ", i);
    scanf("%d", &arr[i]);
  }

  printf("Previous array: ");

  printArr(arr, n);

  sort(arr, n);

  printf("\nSorted array: ");

  printArr(arr, n);

  return 0;
}
