#include <stdio.h>

void split(int* arrIn, int len, int splitter_length, int arrOut[len/splitter_length][splitter_length]) {
    for (int j = 0; j < len/splitter_length; j++) {
        for (int i = 0; i < splitter_length; i++) {
            arrOut[j][i] = arrIn[j*splitter_length + i];
        }
    }
}

void Print_Array(int lenR, int lenC, int arr[lenR][lenC]) {
    printf("Array Elements: ");
    for (int r = 0; r < lenR; r++) {
        printf("\n");
        for (int c = 0; c < lenC; c++) {
            printf("%d ", arr[r][c]);
        }
    }
}

int main() {
    int arrIn[] = {1,2,3,4,5,6,7,8,9};
    int arrOut[3][3];
    split(arrIn, 9, 3, arrOut);
    Print_Array(3,3, arrOut);
    return 0;
}