# include <stdio.h>

void swap(int *int1, int *int2) {
    int temp = *int1;
    *int1 = *int2;
    *int2 = temp;
}

int main() {
    int num1 = 10;
    int num2 = 20;
    swap(&num1, &num2);
    printf("Values after swapping:\nnum1 = %d\nnum2 = %d\n", num1, num2);
}