/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on November 14th, 2022, 9:12 PM
 * 
 * Purpose: 
 *  
 * Modify the DayofYear class, written in the Programming Challenge 2, to add a 
 * constructor that takes two parameters: a string object representing a month 
 * and an integer in the range 0 through 31 representing the day of the month. 
 * The constructor should then initialize the integer member of the class to 
 * represent the day specified by the month and day of month parameters. The 
 * constructor should terminate the program with an appropriate error message if
 * the number entered for a day is outside the range of days for the month given.
 * 
 * Add the following overload operators:
 *  
 * ++ prefix and postfix increment operators. These operators should modify the
 * DayofYear object so it represents the next day. If the day is already the end
 * of the year, the new value of the object will represent the first day of 
 * the year.
 * 
 * -- prefix and postfix decrement operators. These operators should modify the 
 * DayofYear object so it represent the previous day. If the day is already 
 * the first day of the year, the new value of the object will represent the 
 * last day of the year.
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
     
    //++ operator functions
    DayofYear& operator++();
    DayofYear operator++(int);
    
    //-- operator functions
    DayofYear& operator--();
    DayofYear operator--(int);
    
    //Initialization constructor
    DayofYear(int n)
    {   num = n; } 
    
    DayofYear(string m, int n)
    { 

        //Convert the string and number input to day number
        if(m == "January")
        {
            num = n;
            
            //Determine if the day number input is valid
            if(n < 0 || n > 31)
            {
                cout << endl 
                     << " Day is not within the valid range (0-31). Ending "
                     << "Program." << endl;
                exit(0);
            }
        }
        else if(m == "February")
        {
            //Determine if the day number input is valid
            if(n < 0 || n > 28)
            {
                cout << endl 
                     << " Day is not within the valid range (0-28). Ending "
                     << "Program." << endl;
                exit(0);
            }
            
            num = n + 31;
        }
        else if(m == "March")
        {
            //Determine if the day number input is valid
            if(n < 0 || n > 31)
            {
                cout << endl 
                     << " Day is not within the valid range (0-31). Ending "
                     << "Program." << endl;
                exit(0);
            }
            num = n + 59;  
        }
        else if(m == "April")
        {
            //Determine if the day number input is valid
            if(n < 0 || n > 30)
            {
                cout << endl 
                     << " Day is not within the valid range (0-30). Ending "
                     << "Program." << endl;
                exit(0);
            }
            
            num = n + 90; 
        }
        else if(m == "May")
        {
            //Determine if the day number input is valid
            if(n < 0 || n > 31)
            {
                cout << endl 
                     << " Day is not within the valid range (0-31). Ending "
                     << "Program." << endl;
                exit(0);
            }
            
            num = n + 120;
        }
        else if(m == "June")
        {
            //Determine if the day number input is valid
            if(n < 0 || n > 30)
            {
                cout << endl 
                     << " Day is not within the valid range (0-30). Ending "
                     << "Program." << endl;
                exit(0);
            }
            
            num = n + 151;
        }
        else if(m == "July")
        {
            //Determine if the day number input is valid
            if(n < 0 || n > 31)
            {
                cout << endl 
                     << " Day is not within the valid range (0-31). Ending "
                     << "Program." << endl;
                exit(0);
            }
            
            num = n + 181;
        }
        else if(m == "August")
        {
            //Determine if the day number input is valid
            if(n < 0 || n > 31)
            {
                cout << endl 
                     << " Day is not within the valid range (0-31). Ending "
                     << "Program." << endl;
                exit(0);
            }
            
            num = n + 212;
        }
         
        else if(m == "September")
        {
            //Determine if the day number input is valid
            if(n < 0 || n > 30)
            {
                cout << endl 
                     << " Day is not within the valid range (0-30). Ending "
                     << "Program." << endl;
                exit(0);
            }
            
            num = n + 243; 
        }
        else if(m == "October")
        {
            //Determine if the day number input is valid
            if(n < 0 || n > 31)
            {
                cout << endl 
                     << " Day is not within the valid range (0-31). Ending "
                     << "Program." << endl;
                exit(0);
            }
            
            num = n + 273; 
        }
        else if(m == "November")
        {
            //Determine if the day number input is valid
            if(n < 0 || n > 30)
            {
                cout << endl 
                     << " Day is not within the valid range (0-30). Ending "
                     << "Program." << endl;
                exit(0);
            }
            
            num = n + 304;
        }
        else if(m == "December")
        {
            //Determine if the day number input is valid
            if(n < 0 || n > 31)
            {
                cout << endl 
                     << " Day is not within the valid range (0-31). Ending "
                     << "Program." << endl;
                exit(0);
            }
            
            num = n + 334;   
        }
    }
    
    //Accessor Function
    getnum()
    {   return num; }
      
    //Print the english dollar amount
    void print()
    {
        //Output the day number input
        if(num != 0)
            cout << "         Day #" << num << ": ";
        
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
   
    //Static string for months
    string DayofYear::mon[12] = {"January","February","March","April","May",
                                 "June","July","August","September","October",
                                 "November","December"};
    
    //Static string for days
    string DayofYear::days[31] = {"1","2","3","4","5","6","7","8","9","10",
                              "11","12","13","14","15","16","17","18","19","20",
                        "21","22","23","24","25","26","27","28","29","30","31"};
    
    //prefix ++ operator overloading function
    DayofYear& DayofYear::operator++()
    {
        num++;
        
        if(num > 365)
            num =1;
        
        return *this;
    }
    
    //postfix ++ operator overloading function
    DayofYear DayofYear::operator++(int)
    {
        DayofYear temp = *this;
        ++*this;
        
        if(num > 365)
        {
            num = 0;
        }
        return temp;
    }
    
    //postfix ++ operator overloading function
    DayofYear& DayofYear::operator--()
    {
        num--;
        
        if(num <= 0)
            num = 365;
        
        return *this;
    }
    
    //postfix ++ operator overloading function
    DayofYear DayofYear::operator--(int)
    {
        DayofYear temp = *this;
        --*this;
        
        if(num <= 0)
            num = 365;
        
        return temp;
    }
    
//Execution of Code Begins Here
int main(int argc, char** argv) 
{  
    //Declare Variables
    int num; //user number input to convert to date
    string mon;
    int choice;
    
    //Output how to end program
    cout << endl << "   - Enter 0 to quit program -" << endl;
    
    cout << "1 - To enter month and day and get the Day #,and previous and"
         << " following dates" << endl
         << "2 - To enter the day number and get the date" << endl;
    cout << endl << "   Choice: ";
     cin >> choice;
    cout << endl;
     
     
    if(choice == 1)
    {
    //Loop for program to continue taking input
    do
    {   
        cin.ignore();
        
        //Prompt user to input day number 
        cout << "   - Enter Month: ";
        getline(cin,mon);
        cout << endl;
        cout << "     - Enter Day: ";
         cin >> num;
        cout << endl;
         
        //Initialize the DayofYear class object
        DayofYear number(mon,num);
        
        //Output original Day number
        cout << "      Input Day #" << number.getnum() << endl << endl;

        cout <<"   Following day and Previous day:" << endl;
        ++number;
        number.print();
        --number;
        --number;
        number.print();

        //Output program end response
        if(num == 0)
            cout << "   - End Program -" << endl;
    
    }while(num != 0 || mon != "0");
    }
    else if (choice == 2)
    {
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
            cout << endl << "   - Enter Day #: ";
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
    }
    else
        cout << endl << "Please Try again and enter a valid choice." << endl;
    
      
    //Exit stage right
    return 0;  
}    
 
