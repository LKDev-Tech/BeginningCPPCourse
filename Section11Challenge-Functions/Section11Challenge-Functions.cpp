#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void ShowMenu();
void PrintNumbers(const vector<int> &v);
void AddNumber(vector<int> &v);
void DisplayAverage(const vector<int> &v);
void DisplaySmallestNum(const vector<int> &v);
void DisplayLargestNum(const vector<int> &v);


int main() {
	vector <int> nums{};
	char option;
	do {
		ShowMenu();
		cin >> option;
		switch (option) {
		case 'P':
		case 'p':
			PrintNumbers(nums);
			break;
		case 'A':
		case 'a':
			AddNumber(nums);
			break;
		case 'M':
		case 'm':
			DisplayAverage(nums);
			break;
		case 'S':
		case 's':
			DisplaySmallestNum(nums);
			break;
		case 'L':
		case 'l':
			DisplayLargestNum(nums);
			break;
		case 'Q':
		case 'q':
			cout << "Thank you for using the system.";
			break;
		default:
			cout << "Invalid option. Please try again.";
			ShowMenu();
			cin >> option;
			break;
		}
	} while (option != 'Q' && option != 'q');
}

void ShowMenu() {
	cout << "P - Print numbers in list\nA - Add a number\nM - Display average of the numbers\nS - Display the smallest number\nL - Display the largest number\nQ - quit\n";
}

void PrintNumbers(const vector<int> &v) {
	if (v.size() > 0)
	{
		cout << "[ ";
		for (int num : v)
			cout << num << " ";
		cout << "]";
	}
	else cout << "[] - the list is empty" << endl;
	cout << endl;
}

void AddNumber(vector<int> &v) {
	int num{};
	cout << "Please enter the number you want to add: ";
	cin >> num;
	v.push_back(num);
	cout << num << " has been successfully added." << endl;
}

void DisplayAverage(const vector<int> &v) {
	double average{};
	if (v.size() > 0)
	{
		for (int num : v)
			average += num;
		average /= static_cast<double>(v.size());
		cout << "The average of the list is: " << average << endl;
	}
	else cout << "Unable to determine the smallest number - list is empty";
}

void DisplaySmallestNum(const vector<int> &v) {
	if (v.size() > 0) {
		auto smallest = min_element(begin(v), end(v));
		cout << "The smallest number is: " << *smallest << endl;
	}
	else cout << "Unable to determine smallest number - list is empty" << endl;
}

void DisplayLargestNum(const vector<int> &v) {
	if (v.size() > 0) {
		auto largest = max_element(begin(v), end(v));
		cout << "The smallest number is: " << *largest << endl;
	}
	else cout << "Unable to determine largest number - list is empty" << endl;
}