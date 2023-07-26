#include <stdio.h>
#include <stdlib.h>

int findSpecificValueMaxSum(int* array, int size) {
  int maxSum = 0;
  int value;
  int values[size + 1] = {};

  for(int i = 0; i < size; i++) {
    values[array[i]] += array[i];
    printf("%d ", array[i]);
    if(values[array[i]] > maxSum) {
      maxSum = values[array[i]];
      value = array[i];
    }
  }

  return value;;
}

int main() {
  int array1[] = {2, 1, 3, 2, 4, 2, 1};
  int array2[] = {2, 1, 3, 2, 4, 2, 7};

  int result;
  result = findSpecificValueMaxSum(array1, 7);
  printf("Result: %d\n", result);
  result = findSpecificValueMaxSum(array2, 7);
  printf("Result: %d\n", result);

  return 0;
}
