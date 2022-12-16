/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on November 15th, 2022, 6:30 PM
 * 
 * Purpose: 
 *  
 * Design a class called NumDays. The class’s purpose is to store a value that 
 * represents a number of work hours and convert it to a number of days. For 
 * example, 8 hours would be converted to 1 day, 12 hours would be converted to 
 * 1.5 days, and 18 hours would be converted to 2.25 days. The class should have
 * a constructor that accepts a number of hours, as well as member functions for
 * storing and retrieving the hours and days. The class should also have the 
 * following overloaded operators: 
 * 
 * + Addition operator. When two NumDays objects are added together, the 
 * overloaded + operator should return the sum of the two objects’ hours 
 * members. 
 * 
 * - Subtraction operator. When one NumDays object is subtracted from another, 
 * the overloaded − operator should return the difference of the two objects’ 
 * hours members. 
 * 
 * ++ Prefix and postfix increment operators. These operators should increment 
 * the number of hours stored in the object. When incremented, the number of 
 * days should be automatically recalculated. 
 * 
 * -- Prefix and postfix decrement operators. These operators should decrement 
 * the number of hours stored in the object. When decremented, the number of 
 * days should be automatically recalculated.
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

//NumDays Class 
class NumDays
{
    
private:  
    
    //Member variables 
    int hrs;    //Number of hours worked
    float days; //Number of days worked based on hours worked
    
public:  
     
    //+ and - operator functions
    NumDays operator + (const NumDays &);
    NumDays operator - (const NumDays &);
    
    //++ operator functions
    NumDays& operator++();
    NumDays operator++(int);
    
    //-- operator functions
    NumDays& operator--();
    NumDays operator--(int);
    
    //Default constructor
    NumDays()
    {  
        hrs = 0;
        days = 0;
    }
    
    //Initialization constructor
    NumDays(int h)
    {   hrs = h; } 
    
    //Mutator functions
    void sethrs(int h)
        {   hrs = h; }
    
    void setdays(int d)
        {   days = d; }
    
    //Accessor Functions
    int gethrs()
        {   return hrs; }
    
    float getdays()
        {   return days; }
      
    //Convert hours to days
    void convrt()
    {
        days = static_cast<float>(hrs / 8.0);
    } 
};

    //+ operator overloading function
    NumDays NumDays::operator + (const NumDays &right)
    {
        NumDays temp;
        
        temp.hrs = this->hrs + right.hrs; 
        
        convrt();
                
        return temp;
    }
    
    //- operator overloading function
    NumDays NumDays::operator-(const NumDays &right)
    {
        NumDays temp;
        
        temp.hrs = hrs - right.hrs;
        
        convrt();
                
        return temp;
    }
        
    //prefix ++ operator overloading function
    NumDays& NumDays::operator++()
    {
        hrs++;
        convrt();
        return *this;
    }
    
    //postfix ++ operator overloading function
    NumDays NumDays::operator++(int)
    {
        NumDays temp = *this;
        ++*this;
        convrt();
        return temp;
    }
    
    //postfix ++ operator overloading function
    NumDays& NumDays::operator--()
    {
        hrs--;
        convrt();
        
        return *this;
    }
    
    //postfix ++ operator overloading function
    NumDays NumDays::operator--(int)
    {
        NumDays temp = *this;
        --*this;
        convrt();
        return temp;
    }
    
//Execution of Code Begins Here
int main(int argc, char** argv) 
{  
    //Declare Variables
    int hrs;    //Number of hours worked
    NumDays wk; //Initialize wk object
        
    //Prompt user to input hours worked
    cout << "     - EMP #1's Hours Worked: ";
     cin >> hrs;
    
    //Initialize work object
    NumDays work(hrs);
    
    //Prompt user to input hours worked
    cout << "     - EMP #2's Hours Worked: ";
     cin >> hrs;
    cout << endl;
    
    //Initialize wrk object
    NumDays wrk(hrs);
    
    //Convert the hours worked into days worked
    work.convrt();
    wrk.convrt();   
    
    //Output days worked for EMP #1 and EMP #2
    cout << "      - EMP #1's Days worked: " << work.getdays() << endl; 
    cout << "      - EMP #2's Days worked: " << wrk.getdays() << endl;
    
    //Combine EMP #1 and EMP #2 hours and put it into EMP #3
    wk = work + wrk;
    wk.convrt();
    
    //Output EMP #1 and EMP #2 hours and put it into EMP #3
    cout << endl << " EMP 1's Hours combined with EMP #2's Hours into EMP #3"
         << endl << endl << "            - Days worked: " << wk.getdays()
         << endl;
    
    //Subtract the EMP #2 hours from  EMP#3
    wk = wk - wrk;
    wk.convrt();
    
    //Output the new days worked for EMP #3
    cout << endl << " EMP 3's Hours minus EMP #2's Hours"
         << endl << endl << "            - Days worked: " << wk.getdays()
         << endl;
    
    //Add an hours to EMP #3 hours
    wk++;
    
    //Output the new days worked for EMP #3
    cout << endl << " EMP 3's days worked when given and subtracted an hour"
         << endl << endl << "    +1 hour - Days worked: " << wk.getdays();
    
    //Subtract 2 hours from the EMP #3 hours
    wk--;
    wk--;
    
    //Output the new days worked for EMP #3
    cout << endl << endl << "   - 1 Hour - Days worked: " << wk.getdays()
         << endl;   
    
    //Exit stage right
    return 0;  
}          

