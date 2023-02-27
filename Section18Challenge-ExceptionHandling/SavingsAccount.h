#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_
#include "Account.h"
#include <iostream>
#include <string>

class SavingsAccount : public Account {
private:
    static constexpr const char* defName = "Unnamed Savings Account";
    static constexpr double defBalance = 0.0;
    static constexpr double defIntRate = 0.0;
protected:
    double intRate;
public:
    SavingsAccount(std::string name = defName, double balance = defBalance, double intRate = defIntRate);
    bool deposit(double amount);
    virtual void display(std::ostream& os)const;
    virtual bool withdraw(double amount);
    virtual ~SavingsAccount() = default;
};

#endif // _SAVINGS_ACCOUNT_H_
