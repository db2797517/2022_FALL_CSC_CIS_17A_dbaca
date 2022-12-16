/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Date: September 4, 2022, 1:20 PM
 * Purpose: Convert American Dollars to Japanese Yen and Euro equivalent.
 */

// System Libraries
#include <iostream> // Input/Output Library
#include <iomanip>  // Output Library

using namespace std;    // Library Name-Space

// Execution Begins Here
int main(int argc, char** argv)
{   
    // Initialize Variables
    float amount;   // dollar amount
    float YEN_PER_DOLLAR = 98.93;   // yen conversion unit
    float yen_amount;   // yen conversion amount
    float EURO_PER_DOLLAR = 0.74; // euro conversion unit
    float euro_amount;  // euro conversion amount

    // Display prompt to enter amount
    cout << "Please Enter an amount in U.S. Dollars: $" ;
     cin >> amount;
     
    // Compute yen and euro amount
     yen_amount = (amount * YEN_PER_DOLLAR);
             
    euro_amount = (amount * EURO_PER_DOLLAR);
    
    // Output result to console
    cout << "$" << fixed << showpoint << setprecision(2) << amount << " is " 
         << yen_amount << " yen." << endl;
    cout << "$" << amount << " is " << fixed << showpoint << setprecision(2)
         << euro_amount << " euro(s)." << endl;
     
    // Exit Stage Right
    return 0;
}

