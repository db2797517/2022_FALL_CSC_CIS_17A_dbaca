/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Date: September 3, 2022, 6:45 PM
 * Purpose: Show the conversion of a value to Celsius from Fahrenheit and then
 * also show  the Celsius to Fahrenheit Conversions table using a function.
 */

// System Libraries
#include <iostream> // Input/Output Libraries
#include <iomanip>  // Output Manipulation Library

using namespace std;    // Library Name-Space

float celcius(float);   // fUNCTION prototype

// Execution begins here
int main(int argc, char** argv) 
{
    // Initialize Variables
    float temp; // temperature
    float min_temp = 0, // minimum temperature for loop
            max_temp = 20; // maximum temperature for loop
            
    // Prompt user to enter temperature
    cout << "Please Enter a temperature in degrees Fahrenheit: ";
     cin >> temp;
     cout << endl;
     
    // Compute result
    temp = celcius(temp);
    
    // Output Result
    cout << "That temperature in Celsius is " << fixed << showpoint 
         << setprecision(2)<< temp << " degrees." << endl << endl;
    
    // Display table
    cout << "Fahrenheit           Celsius" << endl
         << "----------------------------" << endl;
    
    // Output table results
    for (min_temp; min_temp <= max_temp; min_temp++)
    {
        temp = celcius(min_temp);
        cout << min_temp << "                  ";
        cout << fixed << showpoint << setprecision(2) << temp << endl;
    }
    
    //Exit Stage Right
    return 0;
}

// Conversion function
float celcius(float temp)
{
    return ((5 * (temp - 32))/9);
}

