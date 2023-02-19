#include "TrustAccount.h"

TrustAccount::TrustAccount(std::string name, double balance, double intRate)
    : SavingsAccount{ name, balance, intRate }, numWithdrawals{ 0 } {

}

// Deposit additional $50 bonus when amount >= $5000
bool TrustAccount::deposit(double amount) {
    if (amount >= bonus_threshold)
        amount += bonus_amount;
    return SavingsAccount::deposit(amount);
}

// Only allowed 3 withdrawals, each can be up to a maximum of 20% of the account's value
bool TrustAccount::withdraw(double amount) {
    if (numWithdrawals >= max_withdrawals || (amount > balance * max_withdraw_percent))
        return false;
    else {
        ++numWithdrawals;
        return SavingsAccount::withdraw(amount);
    }
}

std::ostream& operator<<(std::ostream& os, const TrustAccount& account) {
    os << "[Trust Account: " << account.name << ": " << account.balance << ", " << account.intRate
        << "%, withdrawals: " << account.numWithdrawals << "]";
    return os;
}
