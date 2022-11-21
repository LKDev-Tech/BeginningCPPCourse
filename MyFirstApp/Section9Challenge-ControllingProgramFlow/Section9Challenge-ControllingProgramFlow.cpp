#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> nums{2,4,5,1};

void ShowMenu(){
	cout << "P - Print numbers in list\nA - Add a number\nM - Display average of the numbers\nS - Display the smallest number\nL - Display the largest number\nQ - quit\n";
}

void PrintNumbers() {
	if (nums.size() > 0)
	{
		cout << "[ ";
		for (int num : nums)
			cout << num << " ";
		cout << "]";
	}
	else cout << "[] - the list is empty" << endl;
	cout << endl;
}

void AddNumber(){
	int num{};
	cout << "Please enter the number you want to add: ";
	cin >> num;
	nums.push_back(num);
	cout << num << " has been successfully added." << endl;
}

void DisplayAverage() {
	double average{};
	if (nums.size() > 0)
	{
		for (int num : nums)
			average += num;
		average /= static_cast<double>(nums.size());
		cout << "The average of the list is: " << average << endl;
	}
	else cout << "Unable to determine the smallest number - list is empty";
}

void DisplaySmallestNum() {
	if (nums.size() > 0) {
		auto smallest = min_element(begin(nums), end(nums));
		cout << "The smallest number is: " << *smallest << endl;
	}
	else cout << "Unable to determine smallest number - list is empty" << endl;
}

void DisplayLargestNum() {
	if (nums.size() > 0) {
		auto largest = max_element(begin(nums), end(nums));
		cout << "The smallest number is: " << *largest << endl;
	}
	else cout << "Unable to determine largest number - list is empty" << endl;
}

int main(){
	char option;
	do {
		ShowMenu();
		cin >> option;
		switch (option){
		case 'P':
		case 'p':
			PrintNumbers();
			break;
		case 'A':
		case 'a':
			AddNumber();
			break;
		case 'M':
		case 'm':
			DisplayAverage();
			break;
		case 'S':
		case 's':
			DisplaySmallestNum();
			break;
		case 'L':
		case 'l':
			DisplayLargestNum();
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