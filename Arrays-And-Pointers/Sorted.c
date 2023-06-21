#include <stdio.h>

int getSortedIterative(int* array, int size, int* sorted) {

    *sorted = 1;
    int previous = array[0];
    int current;
    for(int i = 1; i < size; i++) {
        current = array[i];
        if(previous > current) {
            *sorted = 0;
            return 0;
        }else if( previous == current) {
            *sorted = 0;
        }
        previous = current;
    }
    return 1;
}

int getSortedRecursive(int* array, int size, int* sorted) {

    if(size == 1) {
        return 1;
    }else if( *(array-1 * sizeof(int)) > *array) {
        *sorted = 0;
        return 0;
    }else if( *(array-1 * sizeof(int)) == *array) {
        *sorted = 0;
        return getSortedRecursive(array+1, size-1, sorted);
    }else {
        return getSortedRecursive(array+1, size-1, sorted);
    }

}

int main() {

    int array[] = {1, 2, 5, 7, 10};
    //int array[] = {1, 2, 2, 5, 10};
    //int array[] = {1, 2, 5, 3, 10};
    int sorted;
    int result;
    result = getSortedIterative(array, 5, &sorted);

    if(result == 1 && sorted == 1) {
        printf("Really Sorted\n");
    }else if( result == 1 && sorted == 0) {
        printf("Sorted\n");
    }else {
        printf("Not Sorted\n");
    }

    result = getSortedRecursive(array+1, 5, &sorted);

    if(result == 1 && sorted == 1) {
        printf("Really Sorted\n");
    }else if( result == 1 && sorted == 0) {
        printf("Sorted\n");
    }else {
        printf("Not Sorted\n");
    }

    return 0;
}
