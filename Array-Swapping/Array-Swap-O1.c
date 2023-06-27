#include <stdio.h>
#include <stdlib.h>

void swapO1(int** ptr1, int** ptr2) {

  int* temp;
  temp = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = temp;
}

void printArray(int* array, int size) {
  for(int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int* generateArray(int size) {
  int* array;
  array = (int*)malloc(sizeof(int)* size);
  for(int i = 0; i < size; i++) {
    printf("Enter an element value: ");
    scanf("%d", &array[i]);
  }

  return array;
}

int main() {

  int* array1;
  int* array2;
  int size;

  printf("Enter an array size: ");
  scanf("%d", &size);

  printf("Array 1: \n");
  array1 = generateArray(size);
  printf("Array 2: \n");
  array2 = generateArray(size);

  printf("Before Swap...\n");
  printArray(array1, size);
  printArray(array2, size);

  swapO1(&array1, &array2);

  printf("After Swap...\n");
  printArray(array1, size);
  printArray(array2, size);



  return 0;
}
