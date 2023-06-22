#include <stdio.h>


void printFrequency(int* array, int size) {

    int current, selection, index;
    for(int i = 0; i < size-1; i++) {
        current = array[i];
        selection = array[i+1];
        for(int j = i + 2; j < size; j++) {
            if(array[j] < selection){
                selection = array[j];
                index = j;
            }
        }
        if(selection < current) {
            array[i] = selection;
            array[index] = current;
        }
    }

    int leftPointer = 0, i = 0;
    current = array[0];
    int count = 0;
    while(index < size) {

        while(i < size && array[i] == current) {
            count++;
            i++;
        }
        printf("%d appeared %d times\n", current, count);
        current = array[i];
        count = 0;
        index = i;
    }


}

int main() {

    int array[5] = {5, 6, 7, 6, 5};

    printFrequency(array, 5);

    return 0;
}
