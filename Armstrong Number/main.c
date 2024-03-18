#include <stdio.h>
#include <math.h>

int numOfDigits(int num) {
    int count = 0;
    while (num > 0) {
        num /= 10;
        count++;
    }
    return count;
}

int isArmstrong(int num) {
    int result = 0;
    int count = numOfDigits(num);
    int temp = num;

    while (temp > 0) {
        int digit = temp % 10;
        result += pow(digit, count);
        temp /= 10;
    }

    if (result == num) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    printf("%d\n", isArmstrong(153));
}