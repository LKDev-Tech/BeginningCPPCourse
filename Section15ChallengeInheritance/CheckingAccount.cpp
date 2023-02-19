#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(std::string name, double balance)
    : Account{name, balance} {}

bool CheckingAccount::withdraw(double amount) {
    amount += fee;
    return Account::withdraw(amount);
}