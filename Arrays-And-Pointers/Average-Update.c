#include <stdio.h>

void updateAverage(int num1, int num2, float* pAverage) {
    *pAverage = (float)(num1 + num2) / 2.0;
}
int main() {

    int a, b;
    float average;

    printf("Enter the first value: ");
    scanf("%d", &a);

    printf("Enter the next value: ");
    scanf("%d", &b);

    updateAverage(a, b, &average);

    printf("Average: %.2f\n", average);

    return 0;
}
