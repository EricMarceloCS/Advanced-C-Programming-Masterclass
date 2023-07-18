#include <stdio.h>
#include <stdlib.h>

void createAndWriteFile(char* filename, char* string) {
  FILE* file = fopen(filename, "w");
  if(filename == NULL) {
    printf("Error opening file\n");
    return;
  }

  fputs(string, file);
  fclose(file);

}

void readFile(char* filename) {
  FILE* file = fopen(filename, "r");
  char buffer[100];

  if(file == NULL) {
    printf("Error Reading File\n");
    return;
  }

  while(fgets(buffer, 100, file)){
  printf("%s", buffer);
  }

  fclose(file);
}

void appendToFile(char* filename, char* string) {
  FILE* file = fopen(filename, "a");
  if(file == NULL) {
    printf("Error appending file\n");
    return;
  }

  fprintf(file, string);
  fclose(file);

}

void modifyLineInFile(char* filename, int lineNumber, char* string) {
  int line = 1;
  FILE* file = fopen(filename, "r");
  FILE* temp = fopen("tempFile.txt", "w");
  char buffer[100];
  if(file == NULL || temp == NULL) {
    printf("Error opening file\n");
    return;
  }
  while(fgets(buffer, 100, file)) {
    if(line++ == lineNumber) {
      fputs(string, temp);
    } else {
      fputs(buffer, temp);
    }
  }

  fclose(temp);
  if(line <= lineNumber) {
    temp = fopen("tempFile.txt", "a");
    fputs(string, temp);
    fclose(temp);
  }

  fclose(file);

  file = fopen(filename, "w");
  temp = fopen("tempFile.txt", "r");

  while(fgets(buffer, 100, temp)) {
    fputs(buffer, file);
  }
  fclose(file);
  fclose(temp);

}

int main() {
  createAndWriteFile("Assignment-3.txt", "Hello World!!\nThis is Assignment 3...\n");
  readFile("Assignment-3.txt");
  appendToFile("Assignment-3.txt", "With Appending Lines...\n");
  readFile("Assignment-3.txt");
  modifyLineInFile("Assignment-3.txt", 4, "And Adding Additional Lines...\n");
  readFile("Assignment-3.txt");
  modifyLineInFile("Assignment-3.txt", 3, "With Modifiying Lines...\n");
  readFile("Assignment-3.txt");

  return 0;
}
