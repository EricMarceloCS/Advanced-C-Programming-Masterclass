#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void thinDough() {
  printf("Thin Crust\n");
}

void thickDough() {
  printf("Thick Crust\n");
}

void tomatoSauce() {
  printf("Tomato Sauce\n");
}

void pestoSauce() {
  printf("Pesto Sauce\n");
}

void mozzarellaCheese() {
  printf("Mozarella Cheese");
}

void threeCheese() {
  printf("Three Cheese\n");
}

void createPizza(void (*ptrDough)(), void (*ptrSauce)(), void (*ptrCheese)()) {
  ptrDough();
  ptrSauce();
  ptrCheese();
}
int main()
{
  printf("Pizza 1:\n");
  createPizza(thickDough, tomatoSauce, threeCheese);
  printf("----------------\n");
  printf("Pizza 2:\n");
  createPizza(thinDough, pestoSauce, threeCheese);
    return 0;
}
