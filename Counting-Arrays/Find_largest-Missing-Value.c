#include <stdio.h>
#include <stdlib.h>

int findLargestMissingValue(int* array, int n) {
  int values[n+1] = {};

  for(int i = 0; i < n; i++) {
    values[array[i]]++;
    printf("%d ", array[i]);
  }

  for(int i = n; i >= 0; i--) {
    if(values[i] == 0)
      return i;
  }
  return -1;
}

int main() {
  int array1[] = {2, 1, 3, 2, 4, 2, 7};
  int array2[] = {2, 1, 2, 4, 5, 6, 7};
  int result;
  result = findLargestMissingValue(array1, 7);
  printf("Largest Missing Value: %d\n", result);
  result = findLargestMissingValue(array2, 7);
  printf("Largest Missing Value: %d\n", result);
  return 0;
}
