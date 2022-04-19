#ifndef INTEREST_H_
#define INTEREST_H_
#pragma once

//Defines InterestCal class and variables
class InterestCal {
private:
	double initialDeposit;

	double monthlyDeposit;

	double percentInterest;

	int numberYears;

public:
	InterestCal();

	//Setters
	void setInitialDeposit(double t_initialDeposit);

	void setMonthlyDeposit(double t_monthlyDeposit);

	void setPercentInterest(double t_percentInterest);

	void setNumberYears(int t_numberYears);

	//Getters
	double getInitialDeposit();

	double getMonthlyDeposit();

	double getPercentInterest();

	int getNumberYears();

	//Calculates monhtly balance
	double monthlyBalance(int t_months, double t_monthDeposit);

	//Calculates monthly interest
	double monthlyInterest(int t_months, double t_monthDeposit);

	//Calculates annual balance
	double annualBalance(int t_numYears, double t_depositAmount);

	//Calculates annual interest
	double annualInterest(int t_numYears, double t_depositAmount);

	//Displays report
	void showReport(double t_monthlyDep);
	void showReportWith(double t_monthlyDep);

};

#endif