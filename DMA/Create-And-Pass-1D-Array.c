#include <stdio.h>
#include <stdlib.h>

void create1DArrayByReference(int** ptr, int size) {

  int* array = (int*)malloc(sizeof(int) * size);
  for(int i = 0; i < size; i++) {
    printf("Enter an element: ");
    scanf("%d", &array[i]);
  }
  *ptr = array;
}

int main() {

  int* array;
  int size;
  array = (int*)malloc(sizeof(int) * size);
  printf("Enter the size of the array: ");
  scanf("%d", &size);

  create1DArrayByReference(&array, size);
  for(int i = 0; i < size; i++){
    printf("%d ", array[i]);
  }
  return 0;
}
