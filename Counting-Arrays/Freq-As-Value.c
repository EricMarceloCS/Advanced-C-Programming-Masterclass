#include <stdio.h>
#include <stdlib.h>

int freqAsValue(int* array, int size, int k) {
  int frequency[(k+1)] = {};

  for(int i = 0; i < size; i++) {
    printf("%d ", array[i]);
    frequency[array[i]]++;
  }

  for(int i = 0; i < k+1; i++) {
    if(frequency[i] != i)
      return 0;
  }
  return 1;
}

void getResult(int result) {
  switch(result) {
    case 0 :
      printf("Frequency DOES NOT equal value\n");
      break;
    case 1 :
      printf("Frequency DOES equal value.\n");
      break;
    default:
      printf("Error\n");
  }
}

int main() {
  int array[6] = {1, 2, 2, 1, 4, 3};
  int array1[6] = {3, 2, 2, 1, 3, 3};
  int result;

  result = freqAsValue(array, 6, 4);
  getResult(result);
  result = freqAsValue(array1, 6, 3);
  getResult(result);

  return 0;
}
