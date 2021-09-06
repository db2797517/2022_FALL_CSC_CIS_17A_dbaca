/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Date: September 5, 2021, 8:52 PM
 * Purpose: Gaddis 9th Edition Chapter 3 Problem 12 Celsius-Fahrenheit
 */

// System Libraries
#include <iostream> // Input/Output Library
using namespace std; //Library Name-Space

// Execution Begins Here
int main(int argc, char** argv) 
{
    // Initialize variables
    float temp;  // input temperature
    
    // Prompt user to enter temperature
    cout << "Please Enter a temperature in degrees Celsius: ";
    cin >> temp;
    
    // compute output
    temp = ((9 * temp)/5) + 32;
    
    // output result
    cout << "That temperature in Fahrenheit is " << temp << "." 
         << endl;
    
    // exit stage right
    return 0;
}

