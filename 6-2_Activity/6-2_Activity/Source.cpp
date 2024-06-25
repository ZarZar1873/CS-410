/*
* Binary file created by SNHU
* C++ from binary file created by Dominic Drury
* 
* As a note for this recreation. I observed some issues from the start with my file. The first is that there
* is only a main function and a display function. With this program being one that does 3 distinct functions,
* I feel that seperating this program into a main, display, add, subtract, and multiply will be best for
* readabilty, maintainability, and security testing. I also observed that the exit does not function and the 
* arithmatic is not accurate and will need to be redone from scratch. There is also no validation for user input
* so if a user enters a non comppliant input the program becomes unresponsive. The program also does not give good
* instructions to the user during computations for what the program is asking the user for that will need to be 
* corrected.
*/

#include<iostream>

using namespace std;

void displayMenu();
long long add(int num1, int num2);
long long subtract(int num1, int num2);
long long multiply(int num1, int num2);

int main() {
	string userInput = ""; // Initialized variable for getting user input, by using string invalid inputs are easier to manage 
	int num1, num2 = 0; // Initialized varaibles for user inputs
	long long result = 0; // Initialized variable for result, set to long long to accomodate range of int max * int max

	while (userInput != "4") { // While the userInput is not 4 (exit from the menu)
		displayMenu(); // Display the menu to the user
		cin >> userInput; // Gets user menu choice from the provided menu

		if (userInput == "1") { // If the user selects add from the menu
			// Get first number from the user
			cout << "Please enter the first number you wish to add" << endl;
			cin >> num1;
			if (cin.fail()) { // ensures that an integer was entered
				cin.clear(); // clears the cin
				cin.ignore(256, '\n'); // ignores cin so that it is prepared for new input
				cout << "Invalid input, please enter a number between -2,147,483,646 and +2,147,483,646" << endl;
				cin >> num1;
			}

			// Get second number from the user
			cout << "Please enter the second number you wish to add" << endl;
			cin >> num2;
			if (cin.fail()) { // ensures that an integer was entered
				cin.clear(); // clears the cin
				cin.ignore(256, '\n'); // ignores cin so that it is prepared for new input
				cout << "Invalid input, please enter a number between -2,147,483,646 and +2,147,483,646" << endl;
				cin >> num2;
			}

			result = add(num1, num2);

			cout << num1 << " + " << num2 << " = " << result << endl;
		}
		else if (userInput == "2") { // If the user selects subtract from the menu
			// Get first number from the user
			cout << "Please enter the first number you wish to subtract" << endl;
			cin >> num1;
			if (cin.fail()) { // ensures that an integer was entered
				cin.clear(); // clears the cin
				cin.ignore(256, '\n'); // ignores cin so that it is prepared for new input
				cout << "Invalid input, please enter a number between -2,147,483,646 and +2,147,483,646" << endl;
				cin >> num1;
			}

			// Get second number from the user
			cout << "Please enter the second number you wish to subtract" << endl;
			cin >> num2;
			if (cin.fail()) { // ensures that an integer was entered
				cin.clear(); // clears the cin
				cin.ignore(256, '\n'); // ignores cin so that it is prepared for new input
				cout << "Invalid input, please enter a number between -2,147,483,646 and +2,147,483,646" << endl;
				cin >> num2;
			}

			result = subtract(num1, num2);

			cout << num1 << " - " << num2 << " = " << result << endl;
		}
		else if (userInput == "3") { // If the user selects multiply from the menu
			// Get first number from the user
			cout << "Please enter the first number you wish to multiply" << endl;
			cin >> num1;
			if (cin.fail()) { // ensures that an integer was entered
				cin.clear(); // clears the cin
				cin.ignore(256, '\n'); // ignores cin so that it is prepared for new input
				cout << "Invalid input, please enter a number between -2,147,483,646 and +2,147,483,646" << endl;
				cin >> num1;
			}

			// Get second number from the user
			cout << "Please enter the second number you wish to multiply" << endl;
			cin >> num2;
			if (cin.fail()) { // ensures that an integer was entered
				cin.clear(); // clears the cin
				cin.ignore(256, '\n'); // ignores cin so that it is prepared for new input
				cout << "Invalid input, please enter a number between -2,147,483,646 and +2,147,483,646" << endl;
				cin >> num2;
			}

			result = multiply(num1, num2);

			cout << num1 << " * " << num2 << " = " << result << endl;
		}
		else { // catchall for non accepted inputs from the user
			cout << "You entered an invalid input, please select an option from the menu" << endl;
		}
	}
	return 0;
}

/*
* Displays the menu to the user
* ----------------
* - 1)Add -
* - 2)Subtract -
* - 3)Multiply -
* - 4)Exit -
* ----------------
*/
void displayMenu() {
	cout << "----------------" << endl;
	cout << "- 1)Add -" << endl;
	cout << "- 2)Subtract -" << endl;
	cout << "- 3)Multiply -" << endl;
	cout << "- 4)Exit -" << endl;
	cout << "----------------" << endl;
}

/*
* Takes 2 numbers from the user and returns the sum of those two numbers
* Ex: if num1 is 1 and num2 is 2 then the function returns 3
* 1 + 2 = 3
*/
long long add(int num1, int num2) {
	long long result = 0; // Initialized variable for all ranges of the return of int + int
	result += num1; // Adds first number to result which ensures no loss of data from conversion
	result += num2; // Adds second number to result which ensures no loss of data from conversion
	return result; // Return result of arithmatic
}

/*
* Takes 2 numbers from the user and returns the difference of those two numbers
* Ex: if num1 is 1 and num2 is 2 then the function returns -1
* 1 - 2 = -1
*/
long long subtract(int num1, int num2) {
	long long result = 0; // Initialized variable for all ranges of the return of int - int
	// Subtracts first number to result which ensures no loss of data from conversion 
	// (set to num1 - result to avoid -(-) turing into +)
	result = num1 - result; 
	result -= num2; // Subtracts second number to result which ensures no loss of data from conversion
	return result; // Return result of arithmatic
}

/*
* Takes 2 numbers from the user and returns the multiplied result of those two numbers
* Ex: if num1 is 1 and num2 is 2 then the function returns 2
* 1 * 2 = 2
*/
long long multiply(int num1, int num2) {
	long long result = 1; // Initialized variable for all ranges of the return of int * int (to 1 for multiplication)
	result *= num1; // Multiplies first number to result which ensures no loss of data from conversion
	result *= num2; // Multiplies second number to result which ensures no loss of data from conversion
	return result; // Return result of arithmatic
}
