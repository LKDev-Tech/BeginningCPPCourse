#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int cents{};
    const int dollar = 100, quart = 25, dime = 10, nick = 5, cent = 1;
    cout << "Enter an amount in cents: ";
    cin >> cents;

    cout << "\nYou can provide this change as follows:" << endl;
    cout << "Dollars: " << cents / dollar << endl;
    cents %= dollar;
    cout << "Quarters: " << cents / quart << endl;
    cents %= quart;
    cout << "Dimes: " << cents / dime << endl;
    cents %= dime;
    cout << "Nickels: " << cents / nick << endl;
    cents %= nick;
    cout << "Cents: " << cents / cent << endl;
    cents %= cent;

    return 0;
}