#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void swap(int* val1, int* val2) {

    int temp = *val1;
    *val1 = * val2;
    *val2 = temp;
}

void swapON(int* arr1, int* arr2) {

  for(int i = 0; i < SIZE; i++) {
    swap(&arr1[i], &arr2[i]);
  }
}

void printArray(int* array) {
  for(int i = 0; i < SIZE; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main() {

  int array1[SIZE] = {1, 3, 6, 8, 10};
  int array2[SIZE] = {2, 2, 4, 11, 17};

  printf("Before swap...\n");
  printArray(array1);
  printArray(array2);

  swapON(array1, array2);

  printf("After swap...\n");
  printArray(array1);
  printArray(array2);


  return 0;
}
