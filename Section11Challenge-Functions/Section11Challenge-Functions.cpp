#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void ShowMenu();
void PrintNumbers(const vector<int> &v);
void DisplayList(const vector<int>& v);
void AddNumber(vector<int> &v);
void DisplayAverage(const vector<int> &v);
double GetAverage(const vector<int>& v);
void DisplaySmallestNum(const vector<int> &v);
void DisplayLargestNum(const vector<int> &v);
void FindNumber(const vector<int> &v);
vector<int> IndexList(const vector<int> &v, int num);
void ClearList(vector<int> &v);

int main() {
	vector <int> nums{};
	char option;
	do {
		ShowMenu();
		cin >> option;
		switch (option) {
		case 'P': case 'p':
			PrintNumbers(nums);
			break;
		case 'A': case 'a':
			AddNumber(nums);
			break;
		case 'M': case 'm':
			DisplayAverage(nums);
			break;
		case 'S': case 's':
			DisplaySmallestNum(nums);
			break;
		case 'L': case 'l':
			DisplayLargestNum(nums);
			break;
		case 'f': case 'F':
			FindNumber(nums);
			break;
		case 'c': case'C':
			ClearList(nums);
			break;
		case 'Q': case 'q':
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
	cout << "P - Print numbers in list\nA - Add a number\nM - Display average of the numbers\nS - Display the smallest number\nL - Display the largest number\nF - Find a number\nC - Clear the list\nQ - quit\n";
}

void PrintNumbers(const vector<int> &v) {
	if (v.size() > 0)
	{
		cout << "[ ";
		DisplayList(v);
		cout << "]" << endl;
	}
	else cout << "[] - the list is empty" << endl;
}

void DisplayList(const vector<int>& v) {
	for (int num : v)
		cout << num << " ";
}

void ClearList(vector<int>& v) {
	v.clear();
	cout << "List successfully cleared!" << endl;
}

void AddNumber(vector<int> &v) {
	int num{};
	cout << "Please enter the number you want to add: ";
	cin >> num;
	v.push_back(num);
	cout << num << " has been successfully added." << endl;
}

void DisplayAverage(const vector<int> &v) {
	if (v.size() > 0)
		cout << "The average of the list is: " << GetAverage(v) << endl;
	else cout << "Unable to determine the average - list is empty";
}

double GetAverage(const vector<int>& v) {
	double average{};
	for (int num : v)
		average += num;
	average /= static_cast<double>(v.size());
	return average;
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

void FindNumber(const vector<int> &v) {
	int num{};
	vector<int> indexes{};
	if (v.size() > 0)
	{
		cout << "Please enter the number you wish to find: ";
		cin >> num;
		indexes = IndexList(v, num);
		if (indexes.size() > 0)
		{
			cout << "The number " << num << " was found at indexes: ";
			DisplayList(indexes);
		}
		else cout << "The number " << num << " was not found in the list";
		cout << endl;
	}
	else cout << "Unable to search - list is empty" << endl;
}

vector<int> IndexList(const vector<int>& v, int numToFind) {
	vector<int> indexes{};
	auto it = v.begin();
	while ((it = find_if(it, v.end(), [numToFind](int x) {return x == numToFind; })) != v.end())
	{
		indexes.push_back(distance(v.begin(), it));
		it++;
	}
	return indexes;
}