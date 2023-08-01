#include <stdio.h>

int setBit(unsigned int number, int position) {
  printf("setting bit %d\n", position);
  int mask = 1;
  mask = mask << position;
  number = number | mask;
  return number;
}

int clearBit(unsigned int number, int position) {

  printf("clearing bit %d\n", position);
  int mask = 1;
  mask = mask << position;
  mask = ~mask;
  number = number & mask;

  return number;
}

int toggleBit(unsigned int number, int position) {
  printf("toggling bit %d\n", position);
  int mask = 1;
  mask = mask << position;
  number = number ^ mask;

  return number;
}

int checkBit(unsigned int number, int position) {
  int mask = 1;
  mask = mask << position;
  if((number & mask) != 0)
    return 1;
  else
    return 0;
}

int countSetBits(unsigned int number) {
  int count = 0;
  int mask = 1;
  for(int i = 0; i < 32; i++) {
    if(number & mask)
      count++;
    mask = mask << 1;
  }

  return count;
}

int main() {

  int number = 1;
  int position;
  printf("Original number: %d\n", number);
  printf("Enter a position to set: ");
  scanf("%d", &position);
  number = setBit(number, position);
  printf("%d\n", number);
  printf("Enter a position to clear: ");
  scanf("%d", &position);
  number = clearBit(number, position);
  printf("%d\n", number);
  printf("Enter a position to toggle: ");
  scanf("%d", &position);
  number = toggleBit(number, position);
  printf("%d\n", number);
  printf("Enter a position to check: ");
  scanf("%d", &position);
  printf("Check bit result: %d\n", checkBit(number, position));
  printf("set bits: %d \n", countSetBits(number));

  return 0;
}
