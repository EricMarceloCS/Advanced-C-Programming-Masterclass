#include <stdio.h>
#include <stdbool.h>

bool compareAscending(int num1, int num2) {
  return num1 < num2;
}

bool compareDescending(int num1, int num2) {
  return num1 > num2;
}

void sort(int* array, int n, bool (*ptrCompare)(int, int)) {

  for(int i = n-1; i > 0; i--){
    for(int j = 0; j < i; j++) {
      if(!ptrCompare(array[j], array[j+1])) {
        int temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
      }
    }
  }

}

void printArray(int* array, int size) {
  for(int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main() {

  int array[5] = {5, 4, 3, 2, 1};

  printf("Before Sort\n");
  printArray(array, 5);
  sort(array, 5, compareAscending);
  printf("After Ascending Sort\n");
  printArray(array, 5);
  sort(array, 5, compareDescending);
  printf("After Descending Sort\n");
  printArray(array, 5);



  return 0;
}
