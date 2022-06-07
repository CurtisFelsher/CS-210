//Curtis Felsher
//4-6-2022
//CS-210
#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>

using namespace std;

//Variable declaration
void displayMultTable();
void doubleAValue();
void printMenu();

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("PythonCode");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python function you wish to call and the int parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}

//Displays starting menu
void printMenu() {
	cout << "1: Display a multiplication table up to 10" << endl;
	cout << "2: Double the value of a number" << endl;
	cout << "3: Exit" << endl;
	cout << endl;
	cout << "Enter your selection as a number 1, 2, or 3" << endl;
}
//Calls python function to display a multiplication table
void displayMultTable() {
	//Variable declaration
	int userInput;
	bool keepGoing = true;
	//Loop to try and catch invalid inputs and retart loop
	while (true) {
		try {
			system("cls");
			cout << "Enter a number for the multiplication table: " << endl;
			cin >> userInput;
			cout << "You entered: " << userInput << endl;

			//Throws an error if input is invalid
			if (userInput == 0) {
				throw runtime_error("Input is not valid.");
			}
			////Calls a function within the callIntFunction and passes user input
			callIntFunc("MultiplicationTable", userInput);
			cout << endl;
			system("pause");
			system("cls");
			break;

		}
		//Catches invalid user inputs and restarts loop
		catch (runtime_error& error) {
			cout << "ERROR: Invalid input." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			cout << endl;
			system("pause"); 
			system("cls");
			continue;
		}
	}
}

//Calls python function to display a doubled value
void doubleAValue() {
	//Variable declaration
	int userInput;
	bool keepGoing = true;
	//Loop to try and catch invalid inputs and retart loop
	while (true) {
		try {
			system("cls");
			cout << "Enter a number to double: " << endl;
			cin >> userInput;
			cout << "You entered: " << userInput << endl;

			//Throws an error if input is invalid
			if (userInput == 0) {
				throw runtime_error("Input is not valid.");
			}

			//Calls a different function within the callIntFunction and passes user input
			callIntFunc("DoubleValue", userInput);
			cout << endl;
			system("pause");
			system("cls");
			break;
		}
		//Catches invalid user inputs and restarts loop
		catch (runtime_error& error) {
			cout << "ERROR: Invalid input." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			cout << endl;
			system("pause");
			system("cls");
			continue;
		}
	}
}


int main() {
	//For user inputs
	int userInput = 0;
	
	//Outputs starting menu and starts loop
	while (1) {

		printMenu();

		try {
			int userInput = 0;

			do {
				cin >> userInput;

				if (userInput > 3 || userInput < 1) {
					throw runtime_error("Invalid input number");
				}

				else if (userInput == 1) {
					displayMultTable();
					break;
				}
				else if (userInput == 2) {
					doubleAValue();
					break;
				}

				else if (userInput == 3) {
					cout << "Goodbye!" << endl;
					exit(1);
					break;
				}
				else {
					cout << "Enter valid choice as a number: 1, 2 or 3." << endl;
				}

			} while (userInput > 3 || userInput < 1);
		}
		//Catches invalid user inputs and restarts loop
		catch (runtime_error& error) {
			cout << "ERROR: Invalid input." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			cout << endl;
			system("pause");
			system("cls");
			continue;
		}
		cout << endl;
	}
}