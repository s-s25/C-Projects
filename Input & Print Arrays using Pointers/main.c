#include <stdio.h>

void Print_Array(int* arr, int len) {
    printf("Array Elements: ");
    for (int i = 0; i < len; i++) {
        printf("%d ",*(arr + i));
    }
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    Print_Array(arr, 10);
}