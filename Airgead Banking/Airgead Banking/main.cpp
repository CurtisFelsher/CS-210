//Curtis Felsher
//CS-210 Project Two
//March 30, 2022

#include <iostream>
#include "Interest.h"
#include <vector>
#include <iomanip>
#include <conio.h>

using namespace std;

//Outputs start of program display and gathers user inputs
InterestCal InitialDisplay(InterestCal inputData) {
	//Variable declarations
	double deposit;
	double monthly;
	double interest;
	bool keepGoing = true;
	int years;

	//Loop to try and catch invalid inputs and retart loop
	while (true) {
		try {
			cout << "**Welcome to Airgead Banking!**" << endl;
			cout << "*******************************" << endl;
			cout << "********** Data Input *********" << endl;
			cout << "Initial Investment Amount:" << endl;
			cout << "$";
			cin >> deposit;
			if (deposit < 0) {
				throw runtime_error("Starting Amount must greater than 0.");
			}
			inputData.setInitialDeposit(deposit);
			cout << "Monthly Deposit:" << endl;
			cout << "$";
			cin >> monthly;
			if (monthly < 0) {
				throw runtime_error("Monthly Deposit must be greater than 0");
			}
			inputData.setMonthlyDeposit(monthly);
			cout << "Annual Interest:" << endl;
			cout << "%";
			cin >> interest;
			if (interest < 0) {
				throw runtime_error("Annual Interest must be greater than 0");
			}
			inputData.setPercentInterest(interest);
			cout << "Number of years:" << flush << endl;
			cin >> years;
			if (years < 1) {
				throw runtime_error("Number of Years must be 1 or greater.");
			}
			inputData.setNumberYears(years);
			cout << "Press any key to continue..." << endl;
			cout << endl;
		}
		//Catches invalid user inputs and restarts loop
		catch (runtime_error& error) {
			cout << "ERROR: Invalid input." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			cout << endl;
			continue;

		}
		return inputData;
	}
}

//Main declaration
int main() {

	//Dectects user inputs
	char ch = 0;

	//Outputs initial display
	while (1) {
		//Calls interestCalc class
		InterestCal inputData;
		inputData = InitialDisplay(inputData);

		//Waits for user input
		ch = _getch();

		//Outputs report before monthly deposit is taken into account
		inputData.showReport(0);
		cout << endl << endl;

		//Outputs report with monthly deposit included
		inputData.showReportWith(inputData.getMonthlyDeposit());
		cout << endl << endl;
		cout << "Press any key to continue..." << endl;
		cout << endl << endl;

		ch = _getch();

		//Asks user to try again
		cout << endl << "Try again? (y = yes or press any other key to exit): ";

		string choice;

		cin >> choice;

		//If user doesnot want to try another, break the loop

		if (choice != "y") {

			break;

		}

		cout << endl;

	}
	return 0;
}
