#include <stdio.h>

void removeSpaceCharacters(char* inputFile, char* outputFile) {

  FILE* iFile = fopen(inputFile, "r");
  FILE* oFile = fopen(outputFile, "w");

  if(iFile == NULL || oFile == NULL) {
    fclose(iFile);
    fclose(oFile);
    printf("Error Opening file(s)\n");
    return;
  }

  char c = fgetc(iFile);
  rewind(oFile);
  while(c != EOF) {
    if(c != ' ')
      fputc(c, oFile);
    printf("%c", c);
    c = fgetc(iFile);
  }

  fclose(iFile);
  fclose(oFile);
}


int main() {

  removeSpaceCharacters("MyFile.txt", "MyOutputFile.txt");

  return 0;
}
