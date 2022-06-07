//Curtis Felsher
//March 16, 2022
//CS-210
#include <iostream>
using namespace std;

//Class that tracks time
class Time {
public:
	int hour{};
	int minute{};
	int second{};
	virtual void addOneHour() = 0;
	virtual void addOneMinute() = 0;
	virtual void addOneSecond() = 0;
};

//12 hour clock with inheritance from the Time class
class _12HourClock : public Time {

	//Tracks 12 hour time
public:
	_12HourClock(int h, int m, int s) {
		hour = h;
		minute = m;
		second = s;
	}
	//Adds one hour to the clock
	void addOneHour() {
		if (hour == 12) {
			hour = 1;
		}
		else { hour += 1; }
	}

	//Adds one minute to the clock 
	void addOneMinute() {
		if (minute == 59) {
			minute = 0;
			addOneHour();
		}
		else {
			minute += 1;
		}
	}
	//Adds one second to the clock 
	void addOneSecond() {
		if (second == 59) {
			second = 0;
			addOneMinute();
		}
		else {
			second += 1;
		}
	}
};
//24 hour clock with inheritance from the Time class
class _24HourClock : public Time {

	//Tracks 24 hour time
public:
	_24HourClock(int h, int m, int s) {
		hour = h;
		minute = m;
		second = s;
	}

	//Adds one hour to the clock 
	void addOneHour() {
		if (hour == 23) {
			hour = 0;
		}
		else {
			hour += 1;
		}
	}
	//Adds one minute to the clock 
	void addOneMinute() {
		if (minute == 59) {
			minute = 0;
			addOneHour();
		}
		else {
			minute += 1;
		}
	}
	//Adds one second to the clock 
	void addOneSecond() {
		if (second == 59) {
			second = 0;
			addOneMinute();
		}
		else {
			second += 1;
		}
	}
};
//Displays the clock interfaces
void displayTime(const _12HourClock& clock12, const _24HourClock& clock24) {
	cout << "***************** *****************\n";
	cout << "* 12-hour Clock * * 24-Hour Clock *\n";
	cout << "* ";
	if (clock12.hour < 10) cout << "0"; cout << clock12.hour << ":";
	if (clock12.minute < 10) cout << "0"; cout << clock12.minute << ":";
	if (clock12.second < 10) cout << "0"; cout << clock12.second;
	if (clock24.hour < 12) cout << " A.M."; else cout << " P.M.";
	cout << " * ";
	cout << "*    ";
	if (clock24.hour < 10) cout << "0"; cout << clock24.hour << ":";
	if (clock24.minute < 10) cout << "0"; cout << clock24.minute << ":";
	if (clock24.second < 10) cout << "0"; cout << clock24.second;
	cout << "   *\n";
	cout << "***************** *****************\n";
}
//Displays the user interface
void displayMenu() {
	cout << "**********************\n";
	cout << "* 1 - Add One Hour   *\n";
	cout << "* 2 - Add One Minute *\n";
	cout << "* 3 - Add One Second *\n";
	cout << "* 4 - Exit Program   *\n";
	cout << "**********************\n";
}
//Main method
int main()
{
	//Creates the clocks at specific times to test for full functionality
	_12HourClock twelve_Hour_Clock(11, 59, 59);
	_24HourClock twentyfour_Hour_Clock(23, 59, 59);
	displayTime(twelve_Hour_Clock, twentyfour_Hour_Clock);
	while (true) {
		displayMenu();
		int choice;
		cin >> choice;
		//Switch for using the interface
		switch (choice) {
		case 1:

			twelve_Hour_Clock.addOneHour();
			twentyfour_Hour_Clock.addOneHour();
			displayTime(twelve_Hour_Clock, twentyfour_Hour_Clock);
			break;

		case 2:

			twelve_Hour_Clock.addOneMinute();
			twentyfour_Hour_Clock.addOneMinute();
			displayTime(twelve_Hour_Clock, twentyfour_Hour_Clock);
			break;

		case 3:

			twelve_Hour_Clock.addOneSecond();
			twentyfour_Hour_Clock.addOneSecond();
			displayTime(twelve_Hour_Clock, twentyfour_Hour_Clock);
			break;


		case 4:

			cout << "Exiting...Thank you for using!";
			exit(1);
			break;


		default:

			//Error message for invalid selection
			cout << "Invalid selection.\n";
			break;


		}
	}
}