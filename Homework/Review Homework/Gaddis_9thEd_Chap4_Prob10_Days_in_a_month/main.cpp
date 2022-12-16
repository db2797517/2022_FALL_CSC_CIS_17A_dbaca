/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Date: September 4, 2022, 5:30 PM
 * Purpose: Use input of the month and year to find and display the correct number of 
 * days in that month.
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
    int day_num = 0;    // number of days in the month
    
    // Prompt user to enter a month
    cout << "Please Enter a number for a month of the Year (1 - 12): ";
     cin >> month;
    cout << endl;
    
    // Prompt user to enter a year
    cout << "Please Enter a Year: ";
     cin >> year;
    cout << endl;
     
    // Cases for months with 31 days
    if(month ==1)
        month = 31;
    else if(month == 3)
        month = 31;
    else if(month == 5)
        month = 31;
    else if(month == 7)
        month = 31;
    else if(month == 8)
        month = 31;
    else if(month == 10)
        month = 31;
    else if(month == 12)
        month = 31;  
    // February test case
    else if(month == 2)
        {
            // Determine if the year is a leap year
            if((year % 100) == 0)
            {
                if((year % 400) == 0)
                    month = 29;
            }
            else
            {
                month = 28;
                
                if((year % 4) == 0)
                {
                    month = 29;
                }  
            }
        }
    //Case for months with 30 days
    else
        month = 30;
  
    // Set month value equal to number of days value.
    day_num = month;

    // Output result
    cout << "The number of days in that month are " << day_num << ".";
     
    // Exit Stage Right
    return 0;
}

