#include <iostream>
#include <vector>
using namespace std;

void display2dVectorContents(vector<vector<int>> twoDVector)
{
    for (size_t i = 0; i < twoDVector.size(); i++)
        for (size_t j = 0; j < twoDVector.at(i).size(); j++)
            cout << twoDVector.at(i).at(j) << ", ";
}

void displayVectorContents(vector<int> vec)
{
    for (size_t i = 0; i < vec.size(); i++)
        cout << vec.at(i) << ", ";
}

int main()
{
    vector <int> vector1;
    vector <int> vector2;

    vector1.push_back(10);
    vector1.push_back(20);
    cout << "Contents of vector 1: ";
    displayVectorContents(vector1);

    vector2.push_back(100);
    vector2.push_back(200);
    cout << "\nContents of vector 2: ";
    displayVectorContents(vector2);

    vector <vector<int>> vector2d;
    vector2d.push_back(vector1);
    vector2d.push_back(vector2);
    cout << "\nContents of vector2d: ";
    display2dVectorContents(vector2d);

    vector1.at(0) = 1000;

    return 0;
}