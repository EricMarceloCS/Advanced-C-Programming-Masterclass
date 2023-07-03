#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

void swapRows(void** ptr, unsigned row1, unsigned row2) {

  void* temp;
  temp = ptr[row1];
  ptr[row1] = ptr[row2];
  ptr[row2] = temp;

}

void swapColumns(int** ptr, unsigned col1, unsigned col2) {

  int temp;
  for(int i = 0; i < SIZE; i++) {
    temp = ptr[i][col1];
    ptr[i][col1] = ptr[i][col2];
    ptr[i][col2] = temp;
  }

}

int main() {
  int** matrix;
  int counter = 0;
  matrix = (int**)calloc(3, sizeof(int*));

  for(int i = 0; i < 3; i++) {
    matrix[i] = (int*)calloc(3, sizeof(int));
  }

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++) {
      matrix[i][j] = ++counter;
    }
  }

  printf("Before ROW SWAP...\n");
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  swapRows(matrix, 0, 1);
  printf("AFTER ROW SWAP...\n");
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  printf("Before COLUMN SWAP...\n");
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  swapColumns(matrix, 1, 2);
  printf("AFTER COLUMN SWAP...\n");
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }



  return 0;
}
