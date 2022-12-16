/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on November 20th, 2022, 8:35 PM
 * 
 * Purpose: 
 *  
 * Modify the MilTime class you created for Programming Challenge 4 of Chapter 
 * 15 (Time Format). The class should implement the following exceptions:
 * 
 * BadHour - Throw when an invalid hour (< 0 or > 2359) is passed to the class.
 * BadSeconds - Throw when an invalid number of seconds (< 0 or > 59) is passed 
 * to the class.
 * 
 * Demonstrate the class in a driver program.
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
    bool tryAgain = true; //Bool variable used for input validation
    
    //Output the basic info
    cout << endl << " - Enter the time in military format - " << endl;
     
    //Prompt the user to enter the time in military time
    cout << "    Time in Hours: ";
     cin >> milh;
     
    //Prompt the user to enter the time in seconds
    cout << "  Time in seconds: ";
     cin >> mils;
     
    //Output both the military and standard times while also validating input
    while(tryAgain)
    {
        try
        { 
            //Initialize the MilTime object
            MilTime time(milh,mils); 
            
            //Output the military and standard times
            cout << endl << "  Military Time: " << time.gethour() 
                 << " hours and " << time.getsec() << " second(s)" << endl;
            cout << "  Standard Time: " << time.getstandhr() << ":" 
                 << time.getmin() << ":" << time.getsec();
 
            //Output the portion of time for standard time
            if(time.gethour() > 1199)
                cout << " PM";
            else
                cout << " AM";
            
            //End loop is all is good
            tryAgain = false;
        }
        catch(MilTime::BadHour)
        {
            cout << endl;
            cout << "Please enter a valid number of military hours (0 - 2359)."
                 << endl << endl;
            cout << "    Time in Hours: ";
             cin >> milh; 
        }   
        catch(MilTime::BadSeconds)
        {
            cout << endl << "Please enter a valid number of seconds (0 - 59)."
                 << endl << endl;
            cout << "  Time in seconds: ";
             cin >> mils;            
        }
    }

    //Exit stage right
    return 0;  
}          




