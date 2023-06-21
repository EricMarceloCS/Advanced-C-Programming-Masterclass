#include <stdio.h>

void getMinAndMax(int* array, int size, int* pMin, int* pMax) {

    *pMin = array[0];
    *pMax = array[0];
    int current;

    for(int i = 1; i < size; i++) {
        current = array[i];
        if(current > *pMax) {
            *pMax = current;
        }
        if(current < *pMin) {
            *pMin = current;
        }
    }

    return;
}

int main() {

    int grades[] = {80, 90, 100};
    int min, max;

    getMinAndMax(grades, 3, &min, &max);

    printf("Min: %d\nMax: %d\n", min, max);

    return 0;
}
