#include <stdio.h>

void locker() {
    int nums[100] = {0};

    for (int i = 1; i <= 100; i++) {
        for (int j = i; j <= 100; j += i) {
            if (nums[j-1] == 0) {
                nums[j-1] = 1;
            } else {
                nums[j-1] = 0;
            }
        }
    }

    printf("Open lockers: ");
    for (int k = 0; k < 100; k++) {
        if (nums[k] == 1) {
            printf("%d ", k+1);
        }
    }
}

int main() {
    locker();
    return 0;
}