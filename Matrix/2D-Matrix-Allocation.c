#include <stdio.h>
#include <stdlib.h>

void allocate2DMatrix(int*** matrix, int rows, int columns) {

  int** temp;
  temp = (int**)calloc(rows, sizeof(int*));
  if(!temp) {
    return;
  }

  for(int i = 0; i < rows; i++) {
    temp[i] = (int*)calloc(columns, sizeof(int));
  }
  *matrix = temp;
}

int main() {

  int** matrix;
  int rows, columns;
  int count = 0;

  printf("Enter the number of rows: ");
  scanf("%d", &rows);

  printf("Enter the number of columns: ");
  scanf("%d", &columns);

  allocate2DMatrix(&matrix, rows, columns);
  if(!matrix) {
    printf("Allocation Error\n");
    exit(1);
  }

  for(int i = 0; i < rows; i++){
    for(int j = 0; j < columns; j++) {
      matrix[i][j] = ++count;
    }
  }

  for(int i = 0; i < rows; i++){
    for(int j = 0; j < columns; j++) {
      printf("%5d ", matrix[i][j]);
    }
    printf("\n");
  }
  return 0;
}
