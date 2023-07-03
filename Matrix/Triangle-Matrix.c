#include <stdio.h>
#include <stdlib.h>

int** createLowerTriangleMatrix(int height) {

  int** array;
  array = (int**)calloc(height, sizeof(int*));

  for(int i = 0; i < height; i++) {
    array[i] = (int*)calloc(i + 1, sizeof(int));
  }
  return array;
}

int** createUpperTriangleMatrix(int height) {

  int** array;
  array = (int**)calloc(height, sizeof(int*));

  for(int i = 0; i < height; i++) {
    array[i] = (int*)calloc(height - i, sizeof(int));
  }

  return array;
}

int main() {

  int** lowerArray;
  int** upperArray;
  int height;

  printf("Enter the height of the triangle: ");
  scanf("%d", &height);

  lowerArray = createLowerTriangleMatrix(height);
  upperArray = createUpperTriangleMatrix(height);

  return 0;
}
