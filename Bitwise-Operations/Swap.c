#include <stdio.h>

int main() {
  char a = 0b00000101;
  char b = 0b00000111;

  printf("a: %d\n", a);
  printf("b: %d\n", b);

  a = a ^ b;
  b = b ^ a;
  a = a ^ b;

  printf("a: %d\n", a);
  printf("b: %d\n", b);


  return 0;
}
