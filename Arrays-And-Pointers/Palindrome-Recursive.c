#include <stdio.h>

int isPalindrome(int* array, int size) {

    if(size <= 1){
        return 1;
    } else if(*array == *(array + size - 1)) {
        return isPalindrome(array + 1, size - 2);
    } else {
        return 0;
    }

}

void printResult(int result) {

    switch(result) {
        case 1:
            printf("The Array is a Palindrome.\n");
            break;
        case 0:
            printf("The Array is NOT A PALINDROME.\n");
            break;
        default:
            printf("Error\n");
    }
}

int main() {

    int array1[3] = {1, 2, 1};
    int array2[5] = {1, 2, 3, 4, 2};
    int array3[6] = {9, 8, 7, 7, 8, 9};
    int result;

    result = isPalindrome(array1, 3);
    printResult(result);

    result = isPalindrome(array2, 5);
    printResult(result);

    result = isPalindrome(array3, 6);
    printResult(result);



}
