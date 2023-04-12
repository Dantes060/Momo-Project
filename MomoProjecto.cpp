#include<iostream>
using namespace std;

int main() {
	
	string pin = "0000", input_pin, number;
	float balance = 1000;
	int attempts = 0, choice;
	bool authenticated = false;
	
	// Authenticate user
	while (!authenticated && attempts < 3) {
		cout << "Enter your Momo PIN:\n";
		cin >> input_pin;
		
		if (input_pin == pin) {
			// Correct pin entered, reset attempts counter
			authenticated = true;
			attempts = 0;
		}
		else {
			// Incorrect pin entered, increment attempts counter
			attempts++;
			cout << "Incorrect PIN. Try again.\n";
		}
	}
	
	if (!authenticated) {
		// Too many attempts, exit program
		cout << "Too many attempts. Exiting program.\n";
		return 0;
	}
	
	// Loop until user exits
	while (true) {
		cout << "Welcome to Mobile Money Service" << endl;
		cout << "1. Check balance\n";
		cout << "2. Send money\n";
		cout << "3. Change/reset PIN\n";
		cout << "4. Exit\n";
		cout << "Enter your choice:\n";
		cin >> choice;
		
		// user choice
		switch (choice) {
			case 1:
				// Check balance
				cout << "Enter PIN to check balance:\n";
				cin >> input_pin;
				if (input_pin == pin) {
					cout << "Your balance is Ghc " << balance << endl;
				}
				else {
					cout << "Wrong PIN.\n";
				}
				break;
			case 2:
				// Send money
				int amount;
				cout << "Enter number to send to:\n";
				cin >> number;
				cout << "Enter amount to send:\n";
				cin >> amount;
				cout << "Enter PIN to send money:\n";
				cin >> input_pin;
				if (input_pin == pin) {
					if (amount > balance) {
						cout << "Insufficient balance.\n";
					}
					else {
						balance -= amount;
						cout << amount << " sent to " << number << endl;
						cout << "Your new balance is Ghc " << balance << endl;
					}
				}
				else {
					cout << "Wrong PIN.\n";
				}
				break;
			case 3:
				// Change/reset PIN
				cout << "Enter your current PIN:\n";
				cin >> input_pin;
				if (input_pin == pin) {
					cout << "Enter new PIN:\n";
					cin >> input_pin;
					pin = input_pin;
					cout << "Your new PIN is " << pin << endl;
				}
				else {
					cout << "Wrong PIN.\n";
				}
				break;
			case 4:
				// Exit program
				cout << "Exiting program.\n";
				return 0;
			default:
				// Invalid choice
				cout << "Invalid choice. Try again.\n";
				break;
		}
	}
	
	return 0;
}
