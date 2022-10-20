#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int insert(int arr[], int n, int i, int m) {
  for (int j = n - 1; j >= i - 1; j--) {
    arr[j + 1] = arr[j];
  }

  arr[i - 1] = m;

  n++;

  return n;
}

void printArr(int *arr, int n) {
  int *p;

  for (p = arr; p <= arr + n - 1; p++) {
    printf("%d, ", *p);
  }
}

void randomizeArray(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    *(arr + i) = rand();
  }
}

int main() {
  int *arr, n;

  printf("N: ");
  scanf("%d", &n);

  srand(time(NULL));

  arr = (int *)malloc(n * sizeof(int));

  randomizeArray(arr, n);

  printf("Previous array: ");

  printArr(arr, n);

  n = insert(arr, n, 2, 99);

  printf("\nNew array: ");

  printArr(arr, n);

  return 0;
}
