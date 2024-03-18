#include <stdio.h>

int fibonacci(int n) {
    int a = 0;
    int b = 1;
    int c = 1;
    for (int i = 0; i < n - 1; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    int n = 25;
    printf("%dth Term = %d\n", n, fibonacci(n));
    return 0;
}