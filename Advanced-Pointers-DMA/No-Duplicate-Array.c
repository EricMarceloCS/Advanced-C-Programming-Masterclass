#include <stdio.h>
#include <stdlib.h>

int* createNoDuplexArray(int* sourceArray, int size, int* newSize) {
  int* noDuplexArray;

  if(size == 1) {
    return sourceArray;
  }
  int lp = 0;
  int rp = 1;
  int count = 1;
  int current = sourceArray[lp];
  int next;

  while(rp < size) {
    next = sourceArray[rp];
    if(next != current){
      count++;
      current = next;
      lp = rp;
    }
    rp++;
  }
  *newSize = count;
  int i = 0;
  noDuplexArray = (int*)malloc(sizeof(int) * count);
  lp = 0;
  rp = 1;
  current = sourceArray[lp];
  noDuplexArray[i++] = current;
  while(rp < size) {
    next = sourceArray[rp];
    if(next != current){
      noDuplexArray[i++] = next;
      current = next;
      lp = rp;
    }
    rp++;
  }

  return noDuplexArray;
}

void printArray(int* array, int size) {
  for(int i = 0; i < size; i++){
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main() {
  int originalArray[] = {1, 3, 3, 5, 6, 7, 7, 7, 8, 12, 12};
  int* result;
  int newSize;

  printArray(originalArray, 11);
  result = createNoDuplexArray(originalArray, 11, &newSize);
  printArray(result, newSize);



  return 0;
}
