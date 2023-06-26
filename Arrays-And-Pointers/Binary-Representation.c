#include <stdio.h>

void printBinaryRepresentation(int n) {

  if(n / 2 == 0) {
    printf("%d", n % 2);
    return;
  }
  printBinaryRepresentation(n / 2);
  printf("%d", n % 2);
  return;

}

int main() {

  int n;

  printf("Enter an integer: ");
  scanf("%d", &n);
  printBinaryRepresentation(n);

  return 0;
}
