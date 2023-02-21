// Section 16
// Challenge
#include <iostream>
#include <vector>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "TrustAccount.h"
#include "AccountUtil.h"
#include "I_Printable.h"

using namespace std;

int main() {
    cout.precision(2);
    cout << fixed;

    /*Accounts
    vector<Account> accounts;
    accounts.push_back(Account{});
    accounts.push_back(Account{ "Larry" });
    accounts.push_back(Account{ "Moe", 2000 });
    accounts.push_back(Account{ "Curly", 5000 });

    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts, 2000);*/

    // Savings

    Account* pSA1 = new SavingsAccount{};
    Account* pSA2 = new SavingsAccount{  "Superman" } ;
    Account* pSA3 = new SavingsAccount{  "Batman", 2000 } ;
    Account* pSA4 = new SavingsAccount{  "Wonderwoman", 5000, 5.0 } ;

    // Checking

    Account* pCA1 = new CheckingAccount{};
    Account* pCA2 = new CheckingAccount{ "Kirk" };
    Account* pCA3 = new CheckingAccount{ "Spock", 2000 };
    Account* pCA4 = new CheckingAccount{  "Bones", 5000};

    // Trust

    Account* pTA1 = new TrustAccount{};
    Account* pTA2 = new TrustAccount{ "Athos", 10000, 5.0 };
    Account* pTA3 = new TrustAccount{ "Porthos", 20000, 4.0 };
    Account* pTA4 = new TrustAccount{ "Aramis", 30000 };

    vector<Account*> accounts{ pSA1, pSA2, pSA3, pSA4, pCA1, pCA2, pCA3, pCA4, pTA1, pTA2, pTA3, pTA4, };

    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts, 2000);
    withdraw(accounts, 3000);

    // Withdraw 5 times from each trust account
    // All withdrawals should fail if there are too many withdrawals or if the withdrawl is > 20% of the balance
    for (int i = accounts.size() - 1; i >= accounts.size() - 4; i--)
        withdraw(accounts, 1000);

    delete pSA1;
    delete pSA2;
    delete pSA3;
    delete pSA4;
    delete pCA1;
    delete pCA2;
    delete pCA3;
    delete pCA4;
    delete pTA1;
    delete pTA2;
    delete pTA3;
    delete pTA4;

    return 0;
}

