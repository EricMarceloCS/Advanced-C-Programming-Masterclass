#include <stdio.h>
#define SIZE 5

int getAdjacentElementsMaximum(int* array, int size) {

    if(size == 2) {
           return array[0] + array[1];
    }

    int current;
    int test;
    current = array[0] + array[1];
    test = getAdjacentElementsMaximum(array + 1, size - 1);
    if(current > test) {
        return current;
    }else {

    return test;
    }
}

int main() {
    int array1[SIZE] = {1, 2, 4, 3, 1};
    int array2[SIZE] = {9, 2, 4, 5, 3};
    int max = 0;

    max = getAdjacentElementsMaximum(array1, SIZE);
    printf("The maximum sum of two adjacentelements is %d.\n", max);

    max = getAdjacentElementsMaximum(array2, SIZE);
    printf("The maximum sum of two adjacentelements is %d.\n", max);




    return 0;
}
