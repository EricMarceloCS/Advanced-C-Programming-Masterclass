#include <stdio.h>
#include <stdlib.h>

void* myRealloc(void* srcblock, unsigned oldsize, unsigned newsize) {

  char* temp;
  temp = (char*)malloc(sizeof(newsize));

  if(temp == NULL){
    printf("Error in memory allocation...\n");
    exit(1);
  }

  for(int i = 0; i < oldsize; i++){
    temp[i] = ((char*)srcblock)[i];
  }

  free(srcblock);
  return temp;
}

int main() {

  int* array;
  int* array1 = NULL;
  array = (int*)malloc(sizeof(int) * 3);

  array[0] = 3;
  array[1] = 5;
  array[2] = 4;

  array1 = myRealloc(array, sizeof(int) * 3, sizeof(int) * 4);
  for(int i = 0; i < 4; i++) {
    printf("%d ", array1[i]);
  }
  printf("\n");

  double* array2;
  double* array3 = NULL;
  array2 = (double*)malloc(sizeof(double) * 3);

  array2[0] = 3.5;
  array2[1] = 5.0;
  array2[2] = 4.0;

  array3 = myRealloc(array2, sizeof(double) * 3, sizeof(double) * 4);
  for(int i = 0; i < 4; i++) {
    printf("%.2lf ", array3[i]);
  }
  printf("\n");

  return 0;
}
