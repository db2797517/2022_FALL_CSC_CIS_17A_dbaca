/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on November 14th, 2022, 9:12 PM
 * 
 * Purpose: 
 *  
 * Assuming that a year has 365 days, write a class named DayOfYear that takes 
 * an integer representing a day of the year and translates it to a string 
 * consisting of the month followed by day of the month. For example,
 * 
 * Day 2 would be January 2
 * Day 32 would be February 1
 * Day 365 would be December 31.
 * 
 * The constructor for the class should take as parameter an integer 
 * representing the day of the year, and the class should have a member 
 * function print() that prints the day in the month- day format. The class 
 * should have an integer member variable to represent the day, and should have 
 * static member variables holding string objects that can be used to assist in 
 * the translation from the integer format to the month-day format. 
 * 
 * Test your class by inputting various integers representing days and printing 
 * out their representation in the month-day format.
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

//DayofYear Class 
class DayofYear
{
    
private:  
    
    //member variables 
    int num;                //number input to be converted into date
    static string mon[12];  //Static month string array
    static string days[31]; //Static days string array

public:  
    
    //Initialization constructor
    DayofYear(int n)
    {   num = n; } 
      
    //Print the english dollar amount
    void print()
    {
        //Output the day number input
        if(num != 0)
            cout << " Day #" << num << ": ";
        
        //Output the date in the month-day format
        if(num > 0 && num < 32)
            cout << mon[0] << " " << days[num-1]; 
        else if(num >= 32 && num < 60)
            cout << mon[1]<< " " << days[num-32];
        else if(num >= 60 && num < 91)
            cout << mon[2] << " " << days[num-60];
        else if(num >= 91 && num < 121)
            cout << mon[3] << " " << days[num-91];        
        else if(num >= 121 && num < 152)
            cout << mon[4] << " " << days[num-121];        
        else if(num >= 152 && num < 182)
            cout << mon[5] << " " << days[num-152];       
        else if(num >= 182 && num < 213)
            cout << mon[6] << " " << days[num-182];        
        else if(num >= 213 && num < 244)
            cout << mon[7] << " " << days[num-213];        
        else if(num >= 244 && num < 274)
            cout << mon[8] << " " << days[num-244];        
        else if(num >= 274 && num < 305)
            cout << mon[9] << " " << days[num-274];
        else if(num >= 305 && num < 335)
            cout << mon[10] << " " << days[num-305];
        else if(num >= 335 && num < 366)
            cout << mon[11] << " " << days[num-335];
        
        //Formatting
        cout << endl << endl; 
    }   
};

    string DayofYear::mon[12] = {"January","February","March","April","May",
                                 "June","July","August","September","October",
                                 "November","December"};
    
    string DayofYear::days[31] = {"1","2","3","4","5","6","7","8","9","10",
                              "11","12","13","14","15","16","17","18","19","20",
                        "21","22","23","24","25","26","27","28","29","30","31"};
    

//Execution of Code Begins Here
int main(int argc, char** argv) 
{  
    //Declare Variables
    int num; //user number input to convert to date
    
    //Output how to end program
    cout << endl << "   - Enter 0 to quit program -" << endl;
    
    //Loop for program to continue taking input
    do
    {
        //Prompt user to input day number 
        cout << "   - Enter Day #: ";
         cin >> num;
         cout << endl;
  
        //Input validation for number input 
        while(num < 0 || num > 365)
        {
            cout << "       Please input a valid number (0-365)" << endl;
            cout << endl << "       #: $";
             cin >> num;
            cout << endl;
        }
         
        //Initialize the DayofYear class object
        DayofYear number(num);

        //Print the date
        number.print();

        //Output program end response
        if(num == 0)
            cout << "   - End Program -" << endl;
    
    }while(num != 0);
      
    //Exit stage right
    return 0;  
}    

