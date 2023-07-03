#include <stdio.h>
#include <stdlib.h>

void freeMatrix(int** matrix, int rows) {

  for(int i = 0; i < rows; i++) {
    free(matrix[i]);
  }

  free(matrix);
}

int main() {

  return 0;
}
