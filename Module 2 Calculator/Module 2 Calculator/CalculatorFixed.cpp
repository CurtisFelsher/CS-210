/*
 * Calculator.cpp
 *
 *  Date: [3/8/2022]
 *  Author: [Curtis Felsher]
 */

#include <iostream>

using namespace std;

/*Made whitespace changes for better readability and more pleasing formatting*/

/*Changed void to int for the calculator to return values*/
int main() {
	char statement[100];
	/*Seperated op1 and op2 to their own lines for better readability*/
	/*Chnaged op1 and op2 to double*/
	double op1;
	double op2;
	char operation;
	/*Changed "Y" to 'y' to match*/
	char answer = 'y';
		while (answer == 'y')
		{
			/*Changed <<endl to << endl since whitespace matters*/
			cout << "Enter expression" << endl;
			/*Switch around op1 and op2 to output in correct order*/
			cin >> op1 >> operation >> op2;
			/*Changed "+" to '+' and >> to << for output*/
			if (operation == '+') {
				cout << op1 << " + " << op2 << " = " << op1 + op2 << endl;
			}
			/*Changed >> to << for output*/
			if (operation == '-') {
				cout << op1 << " - " << op2 << " = " << op1 - op2 << endl;
			}
			if (operation == '*') {
			/*Changed "/" to "*"*/
				cout << op1 << " * " << op2 << " = " << op1 * op2 << endl;
			}
			if (operation == '/') {
			/*Changed "*" to "/" */
				cout << op1 << " / " << op2 << " = " << op1 / op2 << endl;
			}
			cout << "Do you wish to evaluate another expression? Y or N" << endl;
			cin >> answer;
		}
		    /*Added if statement for program to accept another equation*/
			if (answer == 'n') {
			cout << "Program finished.";
		}
		/*Must be added for main*/
		return 0;
}
