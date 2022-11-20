#include <iostream>
using namespace std;

int main()
{
    const short sRoomCharge { 25 }, lRoomCharge{ 35 }, timeValidEstimate{ 30 };
    const double taxRate { 0.06 };

    cout << "Greetings and welcome to Yuzu's carpet cleaners! :)" << endl;
    cout << "Please enter the number of small rooms: ";
    short sRoom{0};
    cin >> sRoom;
    cout << "Please enter the number of large rooms: ";
    short lRoom{ 0 };
    cin >> lRoom;
    cout << "Estimate for the cleaning Service\nNumber of small rooms: " << sRoom << endl;
    cout << "Number of large rooms: " << lRoom << endl;
    cout << "Price per small room: $" << sRoomCharge << "\nPrice per large room: $" << lRoomCharge << endl;
    int cost {(sRoom*sRoomCharge)+(lRoom*lRoomCharge)};
    double tax {cost*taxRate};
    cout << "Cost: $" << cost << "\nTax: " << tax << "\n==================================================================" << endl;
    cout << "Total estimate: $" << cost+tax << "\nThis estimate is valid for " << timeValidEstimate << endl;
    return 0;
}
