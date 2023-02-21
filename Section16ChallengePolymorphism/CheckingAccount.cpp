#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(std::string name, double balance)
    : Account{ name, balance } {
}

bool CheckingAccount::withdraw(double amount) {
    amount += per_check_fee;
    return Account::withdraw(amount);
}

bool CheckingAccount::deposit(double amount) {
    return Account::deposit(amount);
}


void CheckingAccount::display(std::ostream& os) const {
    os << "[CheckingAccount: " << name << ": " << balance << "]";
}

