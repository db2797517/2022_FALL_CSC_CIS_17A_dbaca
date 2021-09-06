/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Date: September 5, 2021, 5:20 PM
 * Purpose: Gaddis 9th Edition Chapter 5 Problem 11 Population
 */

// System Libraries 
#include <iostream> // Input/Output Library
#include <iomanip>  // Output Manipulation Library

using namespace std;

// Execution Begins Here
int main(int argc, char** argv) 
{
    // Initialize Variables
    float population;   // starting population
    float perc_incr;    // population increase percent
    float num_days; // number of days population increases
    int count = 1;  // establish counter
    
    // Prompt to user to enter population
    cout << "What is your starting population? ";
     cin >> population;
    cout << endl;
    
    // Input validation
    if (population < 2)
    {
        cout << "Please Enter a starting population higher than or equal to 2";
    }
    else
    {
    // Prompt user to enter percent increase
    cout << "What is the average daily population increase?(0.0%) ";
     cin >> perc_incr;
    cout << endl;
    // More input validation
    if (perc_incr <= 0)
    {
        cout << "Please Enter an average daily population increase that " 
             << "is non-negative";
    }
    else 
    {
    // Prompt the user to enter number of days
    cout << "What is the number of days they will multiply? ";
     cin >> num_days;
     cout << endl;

    // Even more input validation
     if (num_days < 1)
     {
        cout << "Please Enter a number of days higher than 1.";
     }
     else
     {
     // Output results
     while (count <= num_days)
     {
        if (count == 1)
        {
            cout << "Day " << count << ":" << population << endl;
            
            count += 1;
        }
        else
        {
         population += (population * perc_incr);
                 
         cout << "Day " << count << ":" << population << endl;
         
         count += 1;
        }
     }
     }
    }
    }
    
    //Exit Stage Right
    return 0;
}

