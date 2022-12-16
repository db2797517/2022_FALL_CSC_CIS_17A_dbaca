/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on November 20th, 2022, 3:22 PM
 * 
 * Purpose: 
 *  
 * In Program 15-20 , the file Time.h contains a Time class. Design a class 
 * called MilTime that is derived from the Time class. The MilTime class should 
 * convert time in military (24-hour) format to the standard time format used by
 * the Time class. The class should have the following member variables:
 * 
 * milHours : Contains the hour in 24-hour format. For example, 1:00 pm would be
 *            stored as 1300 hours, and 4:30 pm would be stored as 1630 hours.
 * milSeconds : Contains the seconds in standard format.
 * 
 * The class should have the following member functions:
 * 
 * Constructor : The constructor should accept arguments for the hour and 
 *               seconds, in military format. The time should then be converted 
 *               to standard time and stored in the hours , min , and sec 
 *               variables of the Time class.
 * setTime : Accepts arguments to be stored in the milHours and milSeconds
 *           variables. The time should then be converted to standard time and
 *           stored in the hours , min , and sec variables of the Time class.
 * getHour : Returns the hour in military format.
 * getStandHr : Returns the hour in standard format.
 * 
 * Demonstrate the class in a program that asks the user to enter the time in 
 * military format. The program should then display the time in both military 
 * and standard format.
 * Input Validation: The MilTime class should not accept hours greater than 
 * 2359, or less than 0. It should not accept seconds greater than 59 or less 
 * than 0.
 */
  
//System Libraries
#include "Time.h"
#include "MilTime.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <cstring>
using namespace std;
       
//Execution of Code Begins Here
int main(int argc, char** argv) 
{  
    //Declare Variables
    int milh; //Contains the hours in 24-hour format
    int mils; //Contains the seconds in standard format
    
    //Output the basic info
    cout << endl << " - Enter the time in military format - " << endl;
    
    //Prompt the user to enter the time in military time
    cout << "    Time in Hours: ";
     cin >> milh;
     
    //Input validation for the hours
    while(milh < 0 || milh > 2359 || (milh % 100) > 59)
    {
        cout << endl;
        cout << "Please enter a valid number of military hours (0 - 2359)."
             << endl << endl;
        cout << "    Time in Hours: ";
         cin >> milh; 
    }
     
    //Prompt the user to enter the time in seconds
    cout << "  Time in seconds: ";
     cin >> mils;
    
    //Input validation for the seconds
    while(mils < 0 || mils > 59)
    {
        cout << endl << "Please enter a valid number of seconds (0 - 59)."
             << endl << endl;
        cout << "  Time in seconds: ";
         cin >> mils; 
    }
      
    //Initialize the MilTime object
    MilTime time(milh,mils); 
     
    //Output the military and standard times
    cout << endl << "  Military Time: " << time.gethour() << " hours and " 
         << time.getsec() << " second(s)" << endl;
    cout << "  Standard Time: " << time.getstandhr() << ":" << time.getmin() << ":" 
         << time.getsec();
      
    //Output the portion of time for standard time
    if(time.gethour() > 1199)
        cout << " PM";
    else
        cout << " AM";

    //Exit stage right
    return 0;  
}          




