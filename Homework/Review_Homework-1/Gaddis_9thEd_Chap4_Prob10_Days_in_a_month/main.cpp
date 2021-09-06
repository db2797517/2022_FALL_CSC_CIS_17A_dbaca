/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Date: September 5, 2021, 2:30 PM
 * Purpose: Gaddis 9th Edition Chapter 4 Problem 10 Celsius-Fahrenheit
 */

//System Libraries
#include <iostream> // Input/Output Libraries
#include <iomanip>  // Output Manipulation Libary

using namespace std;    // Library Name-Space

// Execution starts here
int main(int argc, char** argv) 
{
    // Initialize variables
    int month;  // month of the year
    int year;   // year
    int day_num;    // number of days in the month
    
    // Prompt user to enter a month
    cout << "Please Enter a number for a month of the Year (1 - 12): ";
     cin >> month;
    cout << endl;
     
    // Determine num of days for each month
    if (month == 1)
        month = 31;
    else if (month == 3)
        month = 31;
    else if (month == 5)
        month = 31;
    else if (month == 7)
        month = 31;
    else if (month == 8)
        month = 31;
    else if (month == 10)
        month = 31;
    else if (month == 12)
        month = 31;
    
    if (month == 4)
        month = 31;
    else if (month == 6)
        month = 31;
    else if (month == 9)
        month = 31;
    else if (month == 11)
        month = 31;
     
    // Prompt user to enter a year
    cout << "Please Enter a Year: ";
     cin >> year;
    cout << endl;
    
    // Determine if the year is a leap year.
    if (year % 100 == 0)
    {
        if (year % 400 == 0)
            month = 29;
        else
            month = 28;
    }
    else if (year % 100 != 0)
    {
        if (year % 4 == 0)
            month = 29;
        else
            month = 28;
    }
    
    day_num = month;
    
    // Output result
    cout << "The number of days in that month are " << day_num << ".";
     
    // Exit Stage Right
    return 0;
}

