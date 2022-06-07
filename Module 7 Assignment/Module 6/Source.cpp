//Curtis Felsher
//CS-210
//April 13th, 2022

#include <Python.h>
#include <iostream>
#include <iomanip>
#define NOMINMAX
#include <Windows.h>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

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


//Defines DisplayMenu function
void DisplayMenu() {

    //DisplayMenu Variables
    int displayMenu = 0;
    int specificCount = 0;
    int itemQuantity = 0;
    int userColor = 0;
    string userInput;
    string itemName;
    ifstream fileInput;
    string cyanColor = "\033[36;1m";
    string redColor = "\033[31;1m";
    string whiteColor = "\033[0m";
    string blueColor = "\033[34;1m";
    string greenColor = "\033[32;1m";

    //Begins menu loop
    while (displayMenu != 4) {

        //Displays the User menu
        cout << "************************************************************************" << endl;
        cout << "*************** Welcome to Corner Grocer Tracking **********************" << endl;
        cout << "************************************************************************" << endl;
        cout << "*[1] Display all items purchased today and quantities                  *" << endl;
        cout << "*                                                                      *" << endl;
        cout << "*[2] Display how many times a specific item was purchased today        *" << endl;
        cout << "*                                                                      *" << endl;
        cout << "*[3] Display a histogram of all items purchased today                  *" << endl;
        cout << "*                                                                      *" << endl;
        cout << "*[4] Exit                                                              *" << endl;
        cout << "*                                                                      *" << endl;
        cout << "*[5] Change the color of the UI                                        *" << endl;
        cout << "************************************************************************" << endl;
        cout << "************************************************************************" << endl;
        cout << "Please enter a number: 1, 2, 3, 4, or 5." << endl;
        cout << endl;

        cin >> displayMenu;

        //Checks user input
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }


        //Start of the switch for user inputs
        switch (displayMenu) {
        
        //Clears the screen and calls the CountAllItems function
        case 1:
            system("cls");
            cout << "All items purchased today and their quantities:" << endl << endl;
            CallProcedure("CountAllItems");
            cout << endl;
            system("pause");
            system("cls");
            break;

        //Clears the screen, asks for user input, then calls the CountSpecific function
        case 2:
            system("cls");
            cout << "Display how many times a specific item was purchased today." << endl << endl;
            cout << "Please enter an item sold today:" << endl;
            cin >> userInput;
            specificCount = callIntFunc("CountSpecific", userInput);

            //Outputs formatted user input and frequency
            cout << endl << "Total amount of " << userInput << " sold today: " << specificCount << endl << endl;
            system("pause");
            system("cls");
            break;

        //Clears the screen and calls the CollectItemData function to display 
        //a histogram based on the data within frequency.dat
        case 3:
            system("cls");
            CallProcedure("CollectItemData");
            cout << setw(22) << left << "Item:" << setw(10) << right << "Quantity:" << endl << endl;

            fileInput.open("frequency.dat");

            fileInput >> itemName;
            fileInput >> itemQuantity;

            //Beggining of histogram creation
            while (!fileInput.fail()) {

                //Outputs formatted item name
                cout << setw(14) << left << itemName << setw(10);

                //Outputs item frequency
                for (int i = 0; i < itemQuantity; i++) {
                    cout << right << "*";
                }
                //Creates the next lines in the histogram
                cout << endl;
                fileInput >> itemName;
                fileInput >> itemQuantity;
            }

            //Closes the file
            fileInput.close();
            cout << endl;
            system("pause");
            system("cls");
            break;

        //Exits the porogram
        case 4:
            cout << endl;
            cout << "Thank you for using! Have a wonderful rest of your day!" << endl;
            exit(1);
            break;

        //I wanted to try this for fun to see if I could do it, allows user to change the UI color
        case 5:
            while (1) {
                system("cls");
                cout << "Please choose a color:" << endl << endl;
                cout << "1. Cyan" << endl;
                cout << "2. Red" << endl;
                cout << "3. Green" << endl;
                cout << "4. Blue" << endl;
                cout << "5. White" << endl << endl;
                cout << "Please enter your choice as a number: 1, 2, 3, 4, or 5." << endl;
                        
                cin >> userColor;
                cout << endl;

                        //Validates user input as a number
                        if (userColor > 5 || userColor < 1) {
                            cout << endl << "Invalid input." << endl << endl;
                            cin.clear();
                            cin.ignore(10000, '\n');
                            system("pause");
                            system("cls");
                            continue;
                        }

                        else if (userColor == 1) {
                            cout << cyanColor;
                            cout << "You chose Cyan." << endl;
                            system("pause");
                            system("cls");
                            break;
                        }

                        else if (userColor == 2) {
                            cout << redColor;
                            cout << "You chose Red." << endl;
                            system("pause");
                            system("cls");
                            break;
                        }

                        else if (userColor == 3) {
                            cout << greenColor;
                            cout << "You chose Green." << endl;
                            system("pause");
                            system("cls");
                            break;
                        }

                        else if (userColor == 4) {
                            cout << blueColor;
                            cout << "You chose Blue." << endl;
                            system("pause");
                            system("cls");
                            break;
                        }

                        else if (userColor == 5) {
                            cout << whiteColor;
                            cout << "You chose White." << endl;
                            system("pause");
                            system("cls");
                            break;
                        }

                    } 
            while (userColor > 5 || userColor < 1);
            break;

        //For handling invalid input
        default:
            cout << endl;
            cout << "Invalid input. Please try again.";
            cout << endl << endl;
            system("pause");
            system("cls");
            break;
        }
    }
}

//Main declaration, small as possible
int main()
{
    //Calls DisplayMenu and begins loop
    DisplayMenu();

}