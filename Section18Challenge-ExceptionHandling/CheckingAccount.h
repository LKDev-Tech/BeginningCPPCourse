#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_
#include <iostream>
#include <string>
#include "Account.h"

class CheckingAccount : public Account {
private:
    static constexpr const char* def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
    static constexpr double per_check_fee = 1.5;
public:
    CheckingAccount(std::string name = def_name, double balance = def_balance);
    bool withdraw(double);
    bool deposit(double);
    virtual void display(std::ostream& os)const;
    virtual ~CheckingAccount() = default;
    // Inherits the Account::deposit method
};

#endif // _CHECKING_ACCOUNT_H_
