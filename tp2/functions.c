#include "functions.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int insert_at_position(int arr[], int n, int pos, int m) {
  for (int i = n - 1; i >= pos; i--) {
    arr[i + 1] = arr[i];
  }

  arr[pos] = m;

  n++;

  return n;
}

int remove_at_position(int arr[], int n, int pos) {
  for (int i = pos; i <= n - 2; i++) {
    arr[i] = arr[i + 1];
  }

  n--;

  return n;
}

void print_array(int *arr, int n) {
  int *p;

  for (p = arr; p <= arr + n - 1; p++) {
    printf("%d, ", *p);
  }
}

void randomize_array(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    *(arr + i) = rand();
  }
}

void reverse_array(int arr[], int n) {
  int temp;

  for (int i = 0; i <= n / 2; i++) {
    temp = arr[i];
    arr[i] = arr[n - i - 1];
    arr[n - i - 1] = temp;
  }
}

void sort_array(int *arr, int n) {
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

void merge_arrays(int arr1[], int arr2[], int arr3[], int n, int m, int p) {
  int i, j;

  // copy arr1 to arr3
  for (i = 0; i < n; i++) {
    arr3[i] = arr1[i];
  }

  // add arr2 to arr3
  for (j = 0, i = n; i < p && j < m; j++, i++) {
    arr3[i] = arr2[j];
  }
}
