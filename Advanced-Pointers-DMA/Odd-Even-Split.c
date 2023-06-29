#include <stdio.h>
#include <stdlib.h>

void printArray(int* array, int size) {
  for(int i = 0; i < size; i++){
    printf("%d ", array[i]);
  }
  printf("\n");
}

void createOddEvenSplit(int* array, int size, int** evenPtr, int** oddPtr, int* evenCount, int* oddCount) {

  int* evenArray;
  int* oddArray;
  *evenCount = 0;
  *oddCount = 0;

  for(int i = 0; i < size; i++) {
    if(array[i] % 2 == 0) {
      *evenCount = *evenCount + 1;;
    }else {
      *oddCount = *oddCount + 1;
    }
  }

  evenArray = (int*)malloc(sizeof(int) * (*evenCount));
  oddArray = (int*)malloc(sizeof(int) * (*oddCount));
  int evenIndex = 0;
  int oddIndex = 0;
  for(int i = 0; i < size; i++) {
    if(array[i] % 2 == 0) {
      evenArray[evenIndex++] = array[i];
    } else {
      oddArray[oddIndex++] = array[i];
    }
  }

  *evenPtr = evenArray;
  *oddPtr = oddArray;
}

int main() {

  int array[] = {12, 5, 7, 8, 3, 10, 4, 9};
  int* evenArray;
  int* oddArray;
  int evenCount;
  int oddCount;

  printf("Before Split...\n");
  printArray(array, 8);
  createOddEvenSplit(array, 8, &evenArray, &oddArray, &evenCount, &oddCount);
  printf("\nAfter Split...\n");
  printf("Even Array\n");
  printArray(evenArray, evenCount);
  printf("Odd Array\n");
  printArray(oddArray, oddCount);

  return 0;
}
