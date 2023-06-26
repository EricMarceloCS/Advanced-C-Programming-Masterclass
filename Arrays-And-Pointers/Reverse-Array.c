#include <stdio.h>
#include <stdlib.h>

void reversArrayIterative(char* array, int size) {

    for(int i = 0; i < size / 2; i++) {
        char temp = array[i];
        array[i] = array[size-1-i];
        array[size-1-i] = temp;
    }
    return;
}

void reverseArrayRecursive(char* array, int size) {

    if(size / 2 == 0){
        return;
    }

    char temp;
    temp = *array;
    *array = *(array+size-1*sizeof(char));
    *(array+(size-1)*sizeof(char)) = temp;
    reverseArrayRecursive(array+1, size-2);

    return;
}

void printArray(char* array, int size) {

    for(int i = 0; i < size; i++) {
        printf("%c ", array[i]);
    }

    printf("\n");
    return;
}

int main() {

    char array[] = {'a', 'f', 'd', 'k', 'j'};

    printf("Before Reversal...\n");
    printArray(array, 5);

    printf("After Iterative Reversal...\n");
    reversArrayIterative(array, 5);
    printArray(array, 5);

    printf("After Recursive Reversal...\n");
    reverseArrayRecursive(array, 5);
    printArray(array, 5);

    return 0;
}
