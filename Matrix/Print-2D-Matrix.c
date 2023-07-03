#include <stdio.h>

void print2DMatrix(int** matrix, int rows, int columns) {

  for(int row = 0; row < rows; row++) {
    printf("[");
    for(int column = 0; column < columns; column++) {
      printf("%10d", matrix[row][column]);
      if(column < columns - 1){
        printf(", ");
      }
    }
    printf("]");
  }
}

int main() {

  return 0;
}
