#include <stdio.h>
#include <string.h>

int stringCompare(char* string1, char* string2) {

  int string1Length = strlen(string1);
  int string2Length = strlen(string2);
  int length;
  if(string1Length <= string2Length) {
    length = string1Length;
  } else {
    length = string2Length;
  }

  for (int i = 0; i < length; i++) {
    if(string1[i] < string2[i]) {
      return -1;
    } else if (string1[i] > string2[i]){
      return 1;
    }
  }

  if(string2Length != string1Length && length == string1Length) {
    return -1;
  } else if(string1Length != string2Length && length == string2Length) {
    return 1;
  }

  return 0;
}

int main() {

  char* string1 = "Hello";
  char* string2 = "Hello";
  int result;
  result = stringCompare(string1, string2);

  printf("Comparison Result: %d\n", result);

  return 0;
}
