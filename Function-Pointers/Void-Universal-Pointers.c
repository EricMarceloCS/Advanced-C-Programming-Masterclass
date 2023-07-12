#include <stdio.h>

void printInt(void* a) {
  printf("%d ", *(int*)a);
}

void printFloat(void* a) {
  printf("%.2f ", *(float*)a);
}

void printDouble(void* a) {
  printf("%.2lf ", *(double*)a);
}

void printCharacter(void* a) {
  printf("%c ", *(char*)a);
}

void performOperation(void* array, int length, int byteSize, void (*ptrFunction)(void*)) {

  for(int i = 0; i < length; i++) {
    ptrFunction((char*)array+i*byteSize);
  }
  printf("\n");
}
int main() {

  int arrInt[] = {1, 2, 3};
  float arrFloat[] = {1.1, 2.2, 3.3};
  double arrDouble[] = {1.1, 2.2, 3.3};
  char arrCharacter[] = {'a', 'b', 'c'};

  performOperation(arrInt, 3, sizeof(int), printInt);
  performOperation(arrFloat, 3, sizeof(float), printFloat);
  performOperation(arrDouble, 3, sizeof(double), printDouble);
  performOperation(arrCharacter, 3, sizeof(char), printCharacter);
  return 0;
}
