#include <stdio.h>
#include <stdlib.h>

int* createArray(int* size) {
  int* array;
  int* temp;
  int input;
  int elements = 2;
  int i = 0;

  array = (int*)realloc(array, sizeof(int) * (elements));
  printf("Enter an array element: ");
  scanf("%d", &input);

  while(input != -1) {
    if(i == elements) {
      elements *= 2;
      temp = (int*)realloc(array, sizeof(int) * (elements));
      if(temp == NULL){
        printf("Error occurred...\n");
        exit(1);
      }
      array = temp;
    }

    if(array == NULL) {
      printf("Error occurred...\n");
      exit(1);
    }
    array[i++] = input;
    printf("Enter an array element: ");
    scanf("%d", &input);
  }
  *size = i;
  return array;
}

int main() {
  int size = 0;
  int* array = createArray(&size);

  for(int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  return 0;
}
