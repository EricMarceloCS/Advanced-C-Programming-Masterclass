#include <stdio.h>
#include <stdlib.h>

int areAllLettersIncluded(char* array1, char* array2, int size1, int size2) {
  int count[26] = {};

  for(int i = 0; i < size2; i++) {
    count[array2[i] - 'a']++;
  }

  for(int i = 0; i < size1; i++) {
    if(0 == count[array1[i] - 'a']--)
      return 0;
  }
  return 1;
}

void printResult(int result) {
 switch(result) {
    case 0 :
      printf("All characters ARE NOT INCLUDED\n");
      break;
    case 1 :
      printf("All characters ARE INCLUDED\n");
      break;
    default:
      printf("Error\n");
  }
}

int main() {

  char seq1[] = {'d', 'o', 'g'};
  char seq2[] = {'g', 'o', 'o', 'd'};

  char seq3[] = {'d', 'o', 'g'};
  char seq4[] = {'c', 'a', 't'};

  char seq5[] = {'l', 'o', 'l'};
  char seq6[] = {'l', 'o', 'r', 'd'};

  int result;
  result = areAllLettersIncluded(seq1, seq2, 3, 4);
  printResult(result);
  result = areAllLettersIncluded(seq3, seq4, 3, 3);
  printResult(result);
  result = areAllLettersIncluded(seq5, seq6, 3, 4);
  printResult(result);


  return 0;
}
