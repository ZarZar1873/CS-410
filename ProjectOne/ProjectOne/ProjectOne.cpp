#include <iostream>
#include <string>
#include <vector>

using namespace std; 

// Class for client objects to store their name and choice
class Client {
public:
	string clientName = "";
	int clientChoice = 0;

	Client() = default;

	Client(const string& clientName, int clientChoice)
		: clientName(clientName), clientChoice(clientChoice)
	{
	}
};

vector<Client> clients; // Vector for storing clients
Client client; // Initialized client object for later use

/*
* Asks the user for their username and password and checks that information to ensure the user has permission
* to access the data.
* 
* For this program the username is username and the password that will be accepted is 123
*/
void CheckUserPermissionAccess() {
	string username, password; // Username and password variables recieved as input from user
	bool permissionGranted = false; // Bool for checking if user entered correct information
	int numAttempts = 1; // Number of attempts (started at attempt number 1)

	while (!permissionGranted) { // While permission has not been granted
		cout << "Enter your username:" << endl; // Print message to user to get username
		cin >> username; // Gets username from user

		cout << "Enter your password:" << endl; // Print message to user to get password
		cin >> password; // Gets username from user

		if (numAttempts < 3) { // if the number of attempts is less than 3
			// If the username is username and the password is 123
			if (username == "username" && password == "123") {
				permissionGranted = true; // set permissionGranted to true
			}
			else { // Else print error message to user and get information again
				cout << "Invalid Username or Password. Please try again" << endl;
				++numAttempts;
			}
		}
		else { // If the number of attempts exceed 3 then the program is exited
			cout << "The number of attempts have been exceeded." << endl;
			exit(0);
		}
	}

}

/*
* Displays the client information to the console. Format is as follows:
* Number of client in the list    Name of client  "selected option" option that the user has selected
* 
* Example of display:
* Client's name    Service Selected (1 = Brokerage, 2 = Retirement)
* 1. John Doe selected option 1
* 2. Jane Doe selected option 2
*/
void DisplayInfo() {
	// Iterate through list of clients and print to console
	// Example: 1. John Doe selected option 1
	for (int i = 0; i < clients.size(); ++i) {
		cout << i + 1 << ". " << clients[i].clientName << " selected option " << clients[i].clientChoice << endl;
	}
}

/*
* Change the selected choice of the client.
* 1 = Brokerage
* 2 = Retirement
*/
void ChangeCustomerChoice() {
	// Variables for client number in display and the new client choice
	string clientNumber, clientChoice;

	// ask for and get the client to be changed and the new client choice
	cout << "Enter the number of the client that you wish to change" << endl;
	cin >> clientNumber;
	cout << "Please enter the client's new service choice (1 = Brokerage, 2 = Retirement)" << endl;
	cin >> clientChoice;

	/*
	* stoi converts string to int. If the clientNumber is within the bounds of the list of clients and if the
	* client choice is either 1 or 2 (the 2 acceptable choices provided), then the selected clients choice is
	* changed. The index is set to clientNumber-1 because the index is one less than the displayed number to make
	* the list start at 1 instead of 0
	*/
	if (stoi(clientNumber) < clients.size()) {
		if (0 < stoi(clientChoice) < 3) {
			clients[stoi(clientNumber) - 1].clientChoice = stoi(clientChoice);
		}
	}
}

int main() {
	/*
	* String for users choice.I chose string because I ran into a bug where if the user inputs something that
	* is not a string then the original program would go through an infinite loop and not get another input from
	* the user.
	*/ 
	string userChoice = "0";

	// Populate client list with dummy data
	client.clientName = "Bob Jones";
	client.clientChoice = 1;
	clients.push_back(client);
	client.clientName = "Sarah Davis";
	client.clientChoice = 2;
	clients.push_back(client);
	client.clientName = "Amy Friendly";
	client.clientChoice = 1;
	clients.push_back(client);
	client.clientName = "Johnny Smith";
	client.clientChoice = 1;
	clients.push_back(client);
	client.clientName = "Carol Spears";
	client.clientChoice = 2;
	clients.push_back(client);

	cout << "====Created by Dominic Drury====" << endl << endl; // Output statement to show creater of program
	cout << "Hello! Welcome to our Investment Company" << endl; // Greeting message to user

	// Checks if user has the proper permission to move forward in the program
	CheckUserPermissionAccess();

	while (userChoice != "3") {
		// Display menu to user for their options. User must enter a number for valid input
		cout << "What would you like to do?" << endl;
		cout << "DISPLAY the client list (enter 1)" << endl;
		cout << "CHANGE a client's choice (enter 2)" << endl;
		cout << "EXIT the program (enter 3)" << endl;

		cin >> userChoice; // Get menu choice from user
		cout << "You chose " << userChoice << endl; // Prints the choice made back to user

		if (userChoice == "1") { // user chose DISPLAY option
			DisplayInfo();
		}
		else if (userChoice == "2") { // user chose CHANGE option
			ChangeCustomerChoice();
		}
		else if (userChoice == "3") { // user chose EXIT option
			break; // Breaks so program can exit
		}
		else {
			// Not a part of original program but I feel that this helps avoid issues with menu selection
			cout << "Invalid Input. Please try again" << endl;
		}
	}
	
	return 0;
}