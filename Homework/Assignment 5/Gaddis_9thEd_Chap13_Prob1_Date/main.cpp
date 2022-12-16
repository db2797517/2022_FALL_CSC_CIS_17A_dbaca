/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on November 12th, 2022, 7:41 PM
 * Purpose:  
 * Design a class called Date. The class should store a date in three integers: 
 * month, day, and year. There should be member functions to print the date in 
 * the following forms:
 * 
 * 12/25/2018
 * December 25, 2018
 * 25 December 2018
 * 
 * Demonstrate the class by writing a complete program implementing it.
 * 
 * Input Validation: Do not accept values for the day greater than 31 or less 
 * than 1. Do not accept values for the month greater than 12 or less than 1.
 */
 
//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <cstring>
using namespace std;

//Date Class 
class Date
{
    
private:  
    
    //Class variables
    int month; //Month number variable
    int day;   //Day number variable
    int year;  //Year number variable
    
public:  
    
    //Function to set the month variable
    void setmonth(int m)
        {   month = m;  }
    
    //Function to set the day variable    
    void setday(int d)
        {   day = d;  }
     
    //Function to set the year variable
    void setyear(int y)
        {   year = y;  }
    
    //Function to output the month variable
    int getmonth()
        {   return month;  }
    
    //Function to output the day variable    
    int getday()
        {   return day; }
      
    //Function to output the year variable
    int getyear()
        {   return year;  }
    
    //Function to display the first date format
    void dateform1()
    {   cout << "   " << month << "/" << day << "/" << year << endl;  }
    
    //Function to display the second date format
    void dateform2()
    {   
        string result;  //String holding month string
          
        //Determine the month and corresponding  string equivalent
        if (month == 1)
        {   result = "January";   }
        else if(month == 2) 
        {   result = "February"; }
        else if(month == 3) 
        {   result = "March"; }
        else if(month == 4)  
        {   result = "April"; }
        else if(month == 5) 
        {   result = "May"; }
        else if(month == 6)  
        {   result = "June"; }
        else if(month == 7) 
        {   result = "July"; }
        else if(month == 8) 
        {   result = "August"; }           
        else if(month == 9) 
        {   result = "September"; }             
        else if(month == 10) 
        {   result = "October"; }
        else if(month == 11)
        {   result = "November"; }           
        else if(month == 12)
        {   result = "December"; }
        
        //Output the date
        cout << "   " << result << " " << day << "," << year << endl;   
    }
     
    //Function to display the third date format
    void dateform3()
    {   
        string result;  //String holding month string
         
        //Determine the month and corresponding  string equivalent
        if (month == 1)
        {   result = "January";   }
        else if(month == 2) 
        {   result = "February"; }
        else if(month == 3) 
        {   result = "March"; }
        else if(month == 4)  
        {   result = "April"; }
        else if(month == 5) 
        {   result = "May"; }
        else if(month == 6)  
        {   result = "June"; }
        else if(month == 7) 
        {   result = "July"; }
        else if(month == 8) 
        {   result = "August"; }           
        else if(month == 9) 
        {   result = "September"; }             
        else if(month == 10) 
        {   result = "October"; }
        else if(month == 11)
        {   result = "November"; }           
        else if(month == 12)
        {   result = "December"; }
    
        //Output the date
        cout << "   " << day << " " << result << " " << year << endl;
    }
};

//Execution of Code Begins Here
int main(int argc, char** argv) 
{
    //Declare all variables
    int month = 0, day = 0, year = 0; //Three date variables initialized
    Date date;  // Date Class variable
    
    //Formatting
    cout << endl;
    
    //Prompt the user to enter the month
    cout << "   Enter the month: ";
     cin >> month;
     
    //Input validation for month input
    while(month < 1 || month > 12)
     {
         cout << endl << "Invalid Input. Months range from 1 - 12." << endl;
         cout << endl << "   Enter the month: ";
          cin >> month;
     }

    //Prompt the user to enter the day
    cout << "     Enter the day: ";
     cin >> day;
     
    //Input validation for day input
    while(day < 1 || day > 31)
     {
         cout << endl << "Invalid Input. Days range from 1 - 31." << endl;
         cout << endl << "     Enter the day: ";
          cin >> day;
     }
    
    //Prompt the user to enter the year
    cout << "    Enter the year: ";
     cin >> year;
     
    //Formatting
    cout << endl;
    
    //Set the class values equal to the input values
    date.setmonth(month);
    date.setday(day);
    date.setyear(year);
    
    //Output the dates in each format
    date.dateform1();
    date.dateform2();
    date.dateform3();
    
    //Exit stage right
    return 0;
}
 

