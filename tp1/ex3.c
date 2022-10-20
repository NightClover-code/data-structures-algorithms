#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int cherche_dicht(int *arr, int n, int key) {
  /*
    NOTE: This is known as Binary Search, a faster algorithm than linear search
    for arrays. The drawback is that the array MUST be sorted before doing the
    search.

    Binary search time complexity: O(log(n)) worst/average case, O(1) best case.
  */
  int d = 1, f = n, i = 0;
  bool trouve = false;

  while (!trouve) {
    i = floor((d + f) / 2);

    if (*(arr + i) == key) {
      trouve = true;
    } else if (*(arr + i) < key) {
      d = i + 1;
    } else {
      f = i - 1;
    }
  }

  return i;
}

int main() {
  int arr[] = {1, 7, 8, 9, 12, 15, 18, 22, 30, 31};
  int n = sizeof(arr) / sizeof(arr[0]);

  int res = cherche_dicht(arr, n, 30);

  printf("res: %d", res);

  return 0;
}