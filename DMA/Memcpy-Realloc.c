#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* myRealloc(void* srcblock, unsigned oldsize, unsigned newsize) {

  void* array;
  array = malloc(newsize);
  int smallSize;
  if(oldsize < newsize)
    smallSize = oldsize;
  else
    smallSize = newsize;

  memcpy(array, srcblock, smallSize);
  return array;

}

int main() {

  int* array;
  int* array1 = NULL;
  array = (int*)malloc(sizeof(int) * 3);

  array[0] = 1;
  array[1] = 2;
  array[2] = 3;

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
  array2[2] = 6.0;

  array3 = myRealloc(array2, sizeof(double) * 3, sizeof(double) * 4);
  for(int i = 0; i < 4; i++) {
    printf("%.2lf ", array3[i]);
  }
  printf("\n");

  return 0;
}
