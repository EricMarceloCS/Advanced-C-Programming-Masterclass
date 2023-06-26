#include <stdio.h>

void printArrayForward(int* array, int size) {

  if(size == 0){
    printf("\n");
    return;
  } else {
    printf("%d ", *array);
    return printArrayForward(array + 1, size - 1);
  }
}

void printArrayReverse(int* array, int size) {

  if(size == 0) {
    return;
  } else {
    printArrayReverse(array + 1, size - 1);
    printf("%d ", *array);
  }
  return;
}

int main() {

  int array[4] = {1, 2, 3, 4};
  printArrayForward(array, 4);
  printArrayReverse(array, 4);

  return 0;
}
