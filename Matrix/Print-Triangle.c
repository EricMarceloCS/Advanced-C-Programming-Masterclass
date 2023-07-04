#include <stdio.h>
#include <stdlib.h>

void printLowerTraingle(int** array, int height) {

  for(int i = 0; i < height; i++) {
    for(int j = 0; j < height; j++) {
      if(j <= i){
        printf("%d ", array[i][j]);
      } else {
        printf("0 ");
      }
    }
    printf("\n");
  }
}

void printUpperTriangle(int** array, int height) {
  for(int i = 0; i < height; i++) {
    for(int j = 0; j < height; j++) {
      if(j >= i){
        printf("%d ", array[i][j]);
      } else {
        printf("0 ");
      }
    }
    printf("\n");
  }
}
int main() {

  return 0;
}
