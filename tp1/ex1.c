#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  /*
    NOTE: Using pointers for arrays is optional here. It's also a good habit to
    practice pointers.
  */
  int n, i, max, *arr;

  printf("N: ");
  scanf("%d", &n);

  srand(time(NULL));

  arr = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++) {
    *(arr + i) = rand();

    printf("%d, ", *(arr + i));
  }

  max = *arr;

  for (i = 0; i < n; i++) {
    if (*(arr + i) > max) {
      max = *(arr + i);
    }
  }

  printf("max: %d", max);

  return 0;
}