#include <stdio.h>

int isPartsSorted(double* array, int size) {

  if(size == 1) {
    return 1;
  }

  if(((int)*array <= (int)*(array+1)) && (*array - (int)*array >= *(array + 1) - (int)*(array + 1))){
    return isPartsSorted(array + 1, size - 1);
  } else {
    return 0;
  }
}

void printResult(int result) {
    switch(result) {
    case 0:
      printf("The parts of the values ARE NOT sorted.\n");
      break;
    case 1:
      printf("The parts of the values ARE sorted.\n");
      break;
    default:
      printf("ERROR\n");
  }
}

int main() {
  double array1[3] = {1.4, 3.25, 4.5};
  double array2[3] = {1.4, 3.25, 4.2};
  int result;

  result = isPartsSorted(array1, 3);
  printResult(result);

  result = isPartsSorted(array2, 3);
  printResult(result);


  return 0;
}
