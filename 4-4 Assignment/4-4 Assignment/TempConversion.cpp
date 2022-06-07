//Curtis Felsher
//CS-210

#include <iostream>
// Allows file access and writing
#include <fstream>

using namespace std;

// Main declaration
int main()
{
    // Declaration of objects and variables
    ifstream fin; // Input file stream
    ofstream fout; // Output file stream
    string name[6]; // Stores cities names
    double tempF[6]; // Stores cities temps
    
    // Opens file to read
    fin.open("FahrenheitTemperature.txt");

    // Added error message if file cannot be accessed
    // for debugging/confirmation and exits app
    if (!fin)
    {
        cout << "File not found.";

        return 0;
    }

    // Sets beginning of input file to read
    int i = 0;

    // While loop to read from input file and 
    // output conversions to new file
    while (fin >> name[i] >> tempF[i])
    {
        i++;
    }

    // Closes input file
    fin.close();

    // Opens second file to write conversions to 
    fout.open("CelsiusTemperature.txt");

    // Loop to grab each city name/temp in farenheit
    for (int j = 0; j < i; j++)
    {
        // Outputs and writes to the file: City name and temp conversion
        fout << name[j] << " " << (tempF[j] - 32.0) * (5.0 / 9.0) << " Celsius" << "\n";
    }

    // Closes output file
    fout.close();

    // Exit message
    cout << "Temperatures have been converted. Thank you for using!" << endl;

    return 0;
}