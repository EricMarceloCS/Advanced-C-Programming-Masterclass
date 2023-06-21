#include <stdio.h>
#define SIZE 4

int getArraySum(int* array, int size) {
    int sum = 0;

    for(int i = 0; i< size; i++) {
        sum += array[i];
    }

    return sum;
}

double getAverage(int* array, int size) {

    int sum = getArraySum(array, size);
    double average = (double) sum / size;

    return average;
}

int main() {
    int grades[SIZE] = {80, 85, 72, 90};
    double average;

    average = getAverage(grades, SIZE);

    printf("Average: %f\n", average);

    return 0;
}
