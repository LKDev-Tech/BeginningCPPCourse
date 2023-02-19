#pragma once
#include "Account.h"
class CheckingAccount : public Account
{
private:
	static constexpr const char* def_name = "Unnamed Checking Account";
	static constexpr double def_balance = 0.0, def_fee = 0.0, fee = 1.5;
public:
	CheckingAccount(std::string name = def_name, double balance = def_balance);
	bool withdraw(double amount);
};

