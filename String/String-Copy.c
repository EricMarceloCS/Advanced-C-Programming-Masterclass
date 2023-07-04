#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stringCopy(char* destination, char* source) {

  int length = strlen(source);
  int i;
  for(i = 0; i < length; i++) {
    destination[i] = source[i];
  }
  destination[i] = '\0';
}

int main() {

  char str[5] = "Tech";
  char str2[10];

  stringCopy(str2, str);
  printf("str = %s \n", str);
  printf("str2 = %s \n", str2);
  return 0;
}
