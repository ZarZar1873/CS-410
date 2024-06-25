#include <iostream>
#include <iomanip>

using namespace std;

void fileOne() {
	for (int i = 1; i <= 9; ++i) {
		for (int j = 1; j <= 9; ++j) {
			cout << i << " * " << j << " = " << i * j << endl;
		}
	}
}

void fileTwo() {
	float radius, volume = 0, pi = 3.14;

	cout << "Enter Radius:" << endl;
	cin >> radius;

	volume = radius * radius * radius * pi;

	cout << "The volume is: " << fixed << setprecision(2) << volume << endl;
}

void fileThree() {
	int numRows = 0;
	char rowChar = '*';

	cout << "Enter number of rows" << endl;

	cin >> numRows;

	// loop for upper half of diamond
	for (int i = 0; i <= numRows; ++i) {
		// loop for spaces before character(s)
		for (int j = 1; j <= numRows - i; ++j) {
			cout << " ";
		}
		// loop to print character(s)
		for (int j = 1; j <= (2 * i) - 1; ++j) {
			cout << rowChar;
		}
		cout << endl;
	}
	// loop for lower hald of diamond
	for (int i = numRows - 1; 1 <= i; --i) {
		// loop to print spaces before the character(s)
		for (int j = 1; j <= numRows - i; ++j) {
			cout << " ";
		}
		// loop to print the character(s)
		for (int j = 1; j <= (2 * i) - 1; ++j) {
			cout << rowChar;
		}
		cout << endl;
	}
}

void fileFour() {
	int binNum, hexDecNum = 0, base = 1;

	cout << "Enter the binary number:" << endl;
	cin >> binNum;

	while (binNum) {
		int lastDigit = binNum % 10;
		binNum /= 10;

		hexDecNum += lastDigit * base;
		base *= 2;
	}

	cout << endl << "Equivalent hexadecimal value: " << hexDecNum << endl;
}

int main() {
	// comment out any you do not want run as they are all independent
	fileOne();
	fileTwo();
	fileThree();
	fileFour();
	return 0;
}