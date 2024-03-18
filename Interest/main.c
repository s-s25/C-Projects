#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double interestCalc(double bal, double rate, double years) {
    return bal * pow((1 + rate/100), years);
}

int main() {
    printf("Balance: %.2f\n", interestCalc(1000, 7, 69.3));
}