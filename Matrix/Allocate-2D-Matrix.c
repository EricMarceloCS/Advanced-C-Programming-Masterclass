#include <stdio.h>
#include <stdlib.h>

int** allocate2DMatrix() {
  int rows, columns;
  int** matrix;
  printf("Enter the number of rows: ");
  scanf("%d", &rows);
  matrix = (int**)calloc(rows, sizeof(int*));
  if(!matrix)
    return NULL;
  for(int i = 0; i < rows; i++) {

    printf("Enter the number of columns: ");
    scanf("%d", &columns);
    matrix[i] = (int*)calloc(columns, sizeof(int));
    if(!matrix[i]) {

    }
  }

  return matrix;
}


int main() {

  int** matrix;
  matrix = allocate2DMatrix();

  return 0;
}
