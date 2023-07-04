#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* stringConcatenate(char* string1, char* string2) {
  char* newString;
  int string1Length = strlen(string1);
  int string2Length = strlen(string2);
  newString = (char*)malloc(string1Length + string2Length + 1);

  for(int i = 0; i < string1Length; i++) {
    newString[i] = string1[i];
  }

  for(int i = 0; i < string2Length; i++) {
    newString[i + string1Length] = string2[i];
  }
  newString[string1Length + string2Length] = '\0';
  return newString;

}

int main() {

  char* string1 = "Hello";
  char* string2 = "World";
  char* result;

  result = stringConcatenate(string1, string2);

  printf("%s ", result);

  return 0;
}
