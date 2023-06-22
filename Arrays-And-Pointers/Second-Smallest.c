#include <stdio.h>

int getSecondSmallest(int* array, int size) {
    int smallest, secondSmallest;
    int current;

    if(array[0] < array[1]) {
        smallest = array[0];
        secondSmallest = array[1];
    } else {
        smallest = array[1];
        secondSmallest = array[0];
    }

    for(int i = 2; i < size; i++) {
        current = array[i];
        if(current < smallest) {
            secondSmallest = smallest;
            smallest = current;
        }else if(current > smallest && current < secondSmallest) {
            secondSmallest = current;
        }
    }

    return secondSmallest;

}

int main() {

    int array[] = {5, 13, 7, 4, 9};
    int secondSmallest = getSecondSmallest(array, 5);

    printf("Second Smallest element: %d\n", secondSmallest);

    return 0;
}
