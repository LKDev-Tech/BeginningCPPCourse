// Simple Account
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <iostream>
#include <string>
#include "I_Printable.h"

class Account : public I_Printable{
private:
    static constexpr const char* defName = "Unnamed Account";
    static constexpr double defBalance = 0.0;
protected:
    std::string name;
    double balance;
public:
    Account(std::string name = defName, double balance = defBalance);
    virtual bool deposit(double amount) = 0;
    virtual bool withdraw(double amount) = 0;
    virtual void display(std::ostream &os) const = 0;
    virtual ~Account() = default;
};
#endif