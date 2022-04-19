#include "Interest.h"
#include <iostream>
#include <iomanip>

using namespace std;

//Constructor
InterestCal::InterestCal() {
	initialDeposit = 0.00;
	monthlyDeposit = 0.00;
	percentInterest = 0.00;
	numberYears = 0;
}

//Setters
void InterestCal::setInitialDeposit(double t_initialDeposit) {
	initialDeposit = t_initialDeposit;
}

void InterestCal::setMonthlyDeposit(double t_monthlyDeposit) {
	monthlyDeposit = t_monthlyDeposit;
}

void InterestCal::setPercentInterest(double t_percentInterest) {
	percentInterest = t_percentInterest;
}

void InterestCal::setNumberYears(int t_numberYears) {
	numberYears = t_numberYears;
}

//Getters
double InterestCal::getInitialDeposit() {
	return initialDeposit;
}

double InterestCal::getMonthlyDeposit() {
	return monthlyDeposit;
}

double InterestCal::getPercentInterest() {
	return percentInterest;
}

int InterestCal::getNumberYears() {
	return numberYears;
}

//Calculates monthly balance and interest
double InterestCal::monthlyBalance(int t_months, double t_monthDeposit) {
	double balAmount = getInitialDeposit();
	for (int i = 0; i < t_months; i++) {
		balAmount = balAmount + t_monthDeposit;
		balAmount = balAmount + ((balAmount * getPercentInterest() / 100) / 12);
	}
	return balAmount;
}

//Calculates monthly interest
double InterestCal::monthlyInterest(int t_months, double t_monthDeposit) {
	double intAmount;
	double monthlyInterestRate = (getPercentInterest() / 100) / 12;
	intAmount = (monthlyBalance(t_months - 1, t_monthDeposit) + t_monthDeposit) * monthlyInterestRate;
	return intAmount;
}

//Calculates annual balance
double InterestCal::annualBalance(int t_numYears, double t_depositAmount) {
	int numMonths;
	double annualBal = 0.00;
	numMonths = t_numYears * 12;
	for (int i = 0; i < t_numYears; i++) {
		annualBal = monthlyBalance(numMonths, t_depositAmount);
	}
	return annualBal;
}

//Calculates annual interest
double InterestCal::annualInterest(int t_numYears, double t_depositAmount) {
	int numMonths;
	double annualInt = 0.00;
	double priorYears = 0.00;
	numMonths = t_numYears * 12;
	for (int i = 0; i < numMonths; i++) {
		annualInt = annualInt + monthlyInterest(i + 1, t_depositAmount);
	}
	for (int j = 0; j < numMonths - 12; j++) {
		priorYears = priorYears - monthlyInterest(j + 1, t_depositAmount);
	}
	annualInt = annualInt + priorYears;

	return annualInt;
}

//Outputs first report
void InterestCal::showReport(double t_monthlyDep) {
	cout << "**********************************************************" << endl;
	cout << "*Balance and Interest Without Additional Monthly Deposits*" << endl;
	cout << "**********************************************************" << endl;
	cout << setw(8) << "** Year **" << setw(18) << " Year End Balance **" << setw(28) << " Year End Earned Interest **" << endl;
	cout << "**********************************************************" << endl;
	cout << setprecision(2) << fixed << endl;

	for (int i = 0; i < getNumberYears(); i++) {
		cout << right << setw(5) << i + 1 << setw(18) << annualBalance(i + 1, t_monthlyDep) << setw(26) << annualInterest(i + 1, t_monthlyDep) << endl;
	}

	return;
}

//Outputs second report
void InterestCal::showReportWith(double t_monthlyDep) {
	cout << "**********************************************************" << endl;
	cout << "***Balance and Interest With Additional Monthly Deposits**" << endl;
	cout << "**********************************************************" << endl;
	cout << setw(8) << "** Year **" << setw(18) << " Year End Balance **" << setw(28) << " Year End Earned Interest **" << endl;
	cout << "**********************************************************" << endl;
	cout << setprecision(2) << fixed << endl;

	for (int i = 0; i < getNumberYears(); i++) {
		cout << right << setw(5) << i + 1 << setw(18) << annualBalance(i + 1, t_monthlyDep) << setw(26) << annualInterest(i + 1, t_monthlyDep) << endl;
	}
	return;
}
