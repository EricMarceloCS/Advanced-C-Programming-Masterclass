#include <stdio.h>
#define SIZE 4

int getMaximum(int* array, int size) {
    int max = -2000000000;
    int current;
    for(int i = 0; i < size; i++) {
        current = array[i];
        if(current > max) {
            max = current;
        }
    }

    return max;
}

int main() {
    int grades[SIZE] = {80, 85, 72, 90};
    int maxGrade;

    maxGrade = getMaximum(grades, SIZE);
    printf("Maximum Value: %d\n", maxGrade);

    return 0;
}
