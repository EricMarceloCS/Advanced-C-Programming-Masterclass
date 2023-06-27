#include <stdio.h>
#define SIZE 5

int* createArray() {

  int* array;
  array = (int*)malloc(sizeof(int) * SIZE);

  if(!array){
    printf("Error occurred allocating memory...\n");
    exit(1);
  }

  printf("Create Array\n");
  for(int i = 0; i < SIZE; i++) {
    printf("Enter element %d: \n", i);
    scanf("%d", &array[i]);
  }
  printf("\n");
  return array;
}

void printDynamicallyAllocatedArray(int* array) {
  printf("Printing Array...\n");
  for(int i = 0; i < SIZE; i++) {
    printf("%d ", i, array[i]);
  }
  printf("\n");
}

int main() {
  int* array = createArray();
  printDynamicallyAllocatedArray(array);

 return 0;
}
