#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copyArray(int* array, int** copy, int size) {
  int* newArray;
  newArray = (int*)malloc(sizeof(int) * size);
  memcpy(newArray, array, size * 4);

  *copy = newArray;
}

int main() {

  int array[] = {1, 2, 3};
  int* arrayCopy;
  copyArray(array, &arrayCopy, 3);
  for(int i = 0; i < 3; i++) {
    printf("%d ", arrayCopy[i]);
  }
  return 0;
}
