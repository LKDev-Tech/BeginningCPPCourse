#include "TrustAccount.h"

TrustAccount::TrustAccount(std::string name, double balance, double intRate) : SavingsAccount{ name, balance, intRate }, numWithdrawal{0} {}

bool TrustAccount::withdraw(double amount) {
	if (amount < balance * maxWithdrawPercent && numWithdrawal < maxWithdrawals)
	{
		numWithdrawal++;
		return SavingsAccount::withdraw(amount);
	}
	else return false;
}

bool TrustAccount::deposit(double amount) {
	if (amount >= bonusThreshold)
		amount += bonus;
	return SavingsAccount::deposit(amount);
}
