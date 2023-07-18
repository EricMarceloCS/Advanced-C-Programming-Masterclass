#include <stdio.h>
#include <stdlib.h>

void splitOddEven(char* filename) {
  printf("%s", filename);
  FILE* sourceFile = fopen(filename, "r");
  FILE* oddFile = fopen("Odd.txt", "w");
  FILE* evenFile = fopen("Even.txt", "w");

  if(sourceFile == NULL) {
    printf("Error\n");
  }

  int num;
  while(fscanf(sourceFile, "%d", &num) != EOF){
    if(num % 2 == 0) {
      fprintf(evenFile, "%d ", num);
    } else {
      fprintf(oddFile, "%d ", num);
    }
  }

  fclose(sourceFile);
  fclose(evenFile);
  fclose(oddFile);
}

int main() {
  char* file = "Numbers.txt";
  printf("%s\n", file);
  splitOddEven(file);

  return 0;
}
