#include <stdio.h>
#include <stdlib.h>

int findDominantValue(int* array, int size) {
  int appearances[size + 1] = {};

  for(int i = 0; i < size; i++) {
    appearances[array[i]]++;
    printf("%d " , array[i]);
  }

  for(int i = 0; i < size+1; i++) {
    if(appearances[i] > size/2)
      return i;
  }

  return -1;
}

void getResult(int result) {
  if(result == -1) {
    printf("There is NO DOMINANT VALUE\n");
  } else {
    printf("The dominant value is %d\n", result);
  }
}

int main() {
  int array1[] = {3, 5, 4, 3, 3};
  int array2[] = {3, 5, 4, 2, 3};
  int result;
  result = findDominantValue(array1, 5);
  getResult(result);
  result = findDominantValue(array2, 5);
  getResult(result);

  return 0;
}
