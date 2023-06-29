#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* removeFromArray(void* array, int* size, int bytes, int index) {

  char* temp = (char*)realloc(array, bytes * (*size - 1));
  int currentIndex = 0;
  memcpy(temp, array, index*bytes);
  memcpy(temp+(index*bytes), array+((index + 1)*bytes), (*size - (index + 1)) * bytes);

  array = temp;
  return array;
}

int main() {
  int* array;
  int arraySize = 4;
  array = (int*)malloc(sizeof(int) * arraySize);
  array[0] = 80;
  array[1] = 90;
  array[2] = 70;
  array[3] = 100;
  int index = 2;
  int bytes = sizeof(int);
  array = removeFromArray(array, &arraySize, bytes, index);
  for(int i = 0; i < 3; i++) {
    printf("%d ", array[i]);
  }

  return 0;
}
