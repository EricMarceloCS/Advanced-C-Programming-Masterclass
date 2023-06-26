#include <stdio.h>

double getAverage(int* array, int size) {

    double currentAverage;
    if(size == 1)
        return *array;
    else{
        currentAverage = getAverage(array + 1, size - 1);
    }
    return (currentAverage * (size - 1) + *array) / size;
}


int main() {

    int array[3] = {1, 4, 3};
    double average = getAverage(array, 3);

    printf("The array average is %lf\n", average);

    return 0;
}
