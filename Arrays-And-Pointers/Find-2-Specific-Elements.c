#include <stdio.h>
#include <stdbool.h>
#define SIZE 7

int getTwoElements(int* array, int sum, int* index1, int* index2) {

    *index1 = 0;
    *index2 = 0;
    int lp = 0, rp = 1;
    bool right = true;

    while(lp < SIZE - 1 && rp < SIZE) {
        if(array[lp] + array[rp] == sum) {
            *index1 = lp;
            *index2 = rp;
            return 1;
        } else if(array[lp] + array[rp] > sum) {
            break;
        }else if(right) {
            rp++;
            right = false;
        }else {
            lp++;
            right = true;
        }
    }
    return 0;
}

int main() {

    int arr[SIZE] = {1, 3, 4, 7, 9, 10, 12};
    int result;
    int index1, index2;
    int sum;

    printf("Enter the total sum: ");
    scanf("%d", &sum);

    result = getTwoElements(arr, sum, &index1, &index2);

    switch(result) {
        case 1:
            printf("The indices of the two elements are: [%d, %d]\n", index1, index2);
            break;
        case 0:
            printf("The are no two elements that make up that sum.\n");
            break;
        default:
            printf("Error\n");
    }

    return 0;
}
