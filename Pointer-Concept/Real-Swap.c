#include <stdio.h>

void swap(int* pA, int* pB) {

    int temp;
    temp = *pA;
    *pA = *pB;
    *pB = temp;

    return;
}

int main() {

    int a;
    int b;

    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);

    printf("Before Swap...\n");
    printf("a: %d b: %d\n", a, b);
    swap(&a, &b);
    printf("After Swap...\n");
    printf("a: %d b: %d\n", a, b);


    return 0;
}
