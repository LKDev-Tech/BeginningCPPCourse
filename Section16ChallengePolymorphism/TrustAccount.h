#ifndef _TRUSTACCOUNT_H_
#define _TRUSTACCOUNT_H_
#include <iostream>
#include <string>
#include "SavingsAccount.h"

class TrustAccount : public SavingsAccount {
private:
    static constexpr const char* def_name = "Unnamed Trust Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
    static constexpr double bonus_amount = 50.0;
    static constexpr double bonus_threshold = 5000.0;
    static constexpr int max_withdrawals = 3;
    static constexpr double max_withdraw_percent = 0.2;
protected:
    int numWithdrawals;
public:
    TrustAccount(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);

    // Deposits of $5000.00 or more will receive $50 bonus
    bool deposit(double amount);

    // Only allowed maximum of 3 withdrawals, each can be up to a maximum of 20% of the account's value
    bool withdraw(double amount);
    virtual ~TrustAccount() = default;
    virtual void display(std::ostream& os)const;
};

#endif // _TRUST_ACCOUNT_H_
