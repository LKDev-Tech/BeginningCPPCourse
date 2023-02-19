#pragma once
#include "SavingsAccount.h"
class TrustAccount : public SavingsAccount {
private:
	static constexpr const char* def_name = "Unnamed Trust Account";
	static constexpr double def_balance = 0.0, def_int_rate = 0.0, bonusThreshold = 5000.0, maxWithdrawPercent = 0.2, bonus = 50.0;
	static constexpr int maxWithdrawals = 3;
protected:
	int numWithdrawal;
public:
	TrustAccount(std::string name = def_name, double balance = def_balance, double intRate = def_int_rate);
	bool deposit(double amount);
	bool withdraw(double amount);
};

