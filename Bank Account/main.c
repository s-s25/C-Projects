#include <stdio.h>

struct BankAccount {
    int accountNumber;
    int balance;
};

void deposit(struct BankAccount account, int amount) {
    account.balance += amount;
}

void withdraw(struct BankAccount account, int amount) {
    if (account.balance >= amount ) {
        account.balance -= amount;
    } else {
        account.balance -= (amount*1.2);
    }
}