#include <stdio.h>
#include <stdlib.h>

int stringLength(char* string) {

  int length = 0;

  while(string[length] != '\0') {
    printf("%c ", string[length]);
    length++;
  }

  return length;

}

int main() {

  char* string;
  int length;
  string = "Hello";

  length = stringLength(string);
  printf("strlen: %d\n", length);

  return 0;
}
