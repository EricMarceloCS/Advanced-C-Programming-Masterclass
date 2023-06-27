#include <stdio.h>

void printDynamicallyAllocatedArray(int* array, int size) {
  printf("Printing Grades...\n");
  for(int i = 0; i < size; i++) {
    printf("grades[%d] = %d\n", i, array[i]);
  }
}

void enterGrades(int* array, int size) {
  for(int i = 0; i < size; i++) {
    printf("Enter grade: ");
    scanf("%d", &array[i]);
  }
  printf("\n");
}


int main() {
  int* grades;
  int size;

  printf("Enter the number of courses: ");
  scanf("%d", &size);
  enterGrades(grades, size);
  printDynamicallyAllocatedArray(grades, size);

  return 0;
}
