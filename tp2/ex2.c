#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int remove_at_position(int arr[], int n, int pos) {
  for (int i = pos; i <= n - 2; i++) {
    arr[i] = arr[i + 1];
  }

  n--;

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
  int *arr, n, pos;

  printf("N: ");
  scanf("%d", &n);

  printf("Position: ");
  scanf("%d", &pos);

  srand(time(NULL));

  arr = (int *)malloc(n * sizeof(int));

  randomizeArray(arr, n);

  printf("Previous array: ");

  printArr(arr, n);

  n = remove_at_position(arr, n, pos);

  printf("\nNew array: ");

  printArr(arr, n);

  return 0;
}
