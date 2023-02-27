#include <iostream>
#include <vector>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "TrustAccount.h"
#include "AccountUtil.h"
#include "I_Printable.h"
#include "IllegalBalanceException.h"
#include "InsufficientFundsException.h"

using namespace std;

int main() {
	std::unique_ptr<Account> moesAccount;
	std::unique_ptr<Account> larrysAccount;
	try
	{
		larrysAccount = std::make_unique<SavingsAccount>("Larry", -2000.0);
		std::cout << *larrysAccount << std::endl;
	}
	catch (const IllegalBalanceException &ex)
	{
		std::cerr << ex.what() << std::endl;
	}

	try
	{
		moesAccount = std::make_unique<SavingsAccount>("Moe",1000.0);
		std::cout << *moesAccount << std::endl;
		moesAccount->withdraw(500.0);
		std::cout << *moesAccount << std::endl;
		moesAccount->withdraw(1000.0);
		std::cout << *moesAccount << std::endl;

	}
	catch (const IllegalBalanceException &ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	catch (const InsufficientFundsException &ex) {
		std::cerr << ex.what() << std::endl;
	}
	std::cout << "Program completed Sufccessfully" << std::endl;
	return 0;
}

