#include <stdio.h>

void printResult(int result) {

    switch(result) {
        case 0:
            printf("Two adjacent elements have the same sign.\n");
            break;
        case 1:
            printf("No two elements have the same sign.\n");
            break;
        default:
            printf("Error\n");
    }
}

int getChangingSigns(int* array, int size) {

    if(size == 1) {
        return 1;
    }

    int current = *array;
    int next = *(array + 1);

    if((next < 0 && current > 0) || (next > 0 && current < 0)) {
        return getChangingSigns(array+1, size - 1);
    } else {
        return 0;
    }
}

int main() {
    int result;
    int array1[3] = {-1, 2, -4};
    int array2[5] = {1, -2, 4, 5, -3};

    result = getChangingSigns(array1, 3);
    printResult(result);

    result = getChangingSigns(array2, 5);
    printResult(result);

    return 0;
}
