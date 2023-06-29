#include <stdio.h>
#include <stdlib.h>

void* insertToArray(void* array, int* size, int bytes, void* value, int index) {
  *size = *size + 1;
  char* temp = (char*)malloc(*size * bytes);
  if(temp == NULL) {
    return NULL;
  }

  for(int i = 0; i < *size * bytes; i++) {
    temp[i] = ((char*)array)[i];

  }
  for(int i = 0; i < bytes; i++) {
    temp[i + (*size * bytes) - bytes] = temp[i + (index * bytes)];
  }

  for(int i = 0; i < bytes; i++) {
     temp[i + (index * bytes)] = ((char*)value)[i];
  }
  array = temp;

  return array;

}

void printDoubleArray(double* array, int size) {
  for(int i = 0; i < size; i++){
    printf("%.2lf ", array[i]);
  }
  printf("\n");
}

void printIntArray(int* array, int size) {
  for(int i = 0; i < size; i++){
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main() {


  double* array;
  int arraySize = 3;
  array = (double*)malloc(sizeof(double) * arraySize);
  array[0] = 8.0;
  array[1] =  6.0;
  array[2] = 7.1;
  double doubleValue = 5.0;
  int doubleBytes = sizeof(double);
  printDoubleArray(array, arraySize);
  array = insertToArray(array, &arraySize, doubleBytes, &doubleValue, 2);
  printDoubleArray(array, arraySize);

/*
  int* array1;
  int array1Size = 3;
  array1 = (int*)malloc(sizeof(int) * arraySize);
  array1[0] = 8;
  array1[1] = 6;
  array1[2] = 1;

  int intValue = 15;
  int intBytes = sizeof(int);
  printIntArray(array1, array1Size);
  array1 = insertToArray(array1, &array1Size, intBytes, &intValue, 2);
  printIntArray(array1, array1Size);
*/
  return 0;
}
