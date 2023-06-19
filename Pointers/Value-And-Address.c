#include <stdio.h>

int main() {

    int grade1 = 80;
    int grade2 = 100;

    int *pG1;
    int *pG2;

    pG1 = &grade1;
    pG2 = &grade2;

    printf("Grade1 VALUE = %d\n", *pG1);
    printf("Grade1 ADDRESS = %p\n", pG1);
    printf("Grade2 VALUE = %d\n", *pG2);
    printf("Grade2 ADDRESS = %p\n", pG2);

    return 0;
}
