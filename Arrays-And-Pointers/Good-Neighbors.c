#include <stdio.h>
#include <stdlib.h>

int getGoodNeighbors(int* array, int size) {
    for(int i = 1; i < size-1; i++) {
        if(array[i] == array[i-1] + array[i+1]){
            return 1;
        }
    }

    return 0;
}

int main() {

    int array[] = {1, 4, 7, 3, 2};
    int result;

    result = getGoodNeighbors(array, 5);

    printf("Good Neighbors...\nYes: 1 No: 0\nResult: %d\n", result);
    return 0;
}
