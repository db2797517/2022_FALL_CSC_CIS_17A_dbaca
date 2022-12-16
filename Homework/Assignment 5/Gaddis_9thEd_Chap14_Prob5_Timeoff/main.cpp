/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on November 16th, 2022, 8:06 PM
 * 
 * Purpose: 
 * 
 * Design a class named TimeOff. The purpose of the class is to track an 
 * employee s sick leave, vacation, and unpaid time off. It should have, as 
 * members, the following instances of the NumDays class described in 
 * Programming Challenge 4: 
 * 
 * maxSickDays A NumDays object that records the maximum number of days of sick 
 * leave the employee may take. 
 * 
 * sickTaken A NumDays object that records the number of days of sick leave the 
 * employee has already taken. 
 * 
 * maxVacation A NumDays object that records the maximum number of days of paid 
 * vacation the employee may take. 
 * 
 * vacTaken A NumDays object that records the number of days of paid vacation 
 * the employee has already taken. 
 * 
 * maxUnpaid A NumDays object that records the maximum number of days of unpaid 
 * vacation the employee may take. 
 * 
 * unpaidTaken A NumDays object that records the number of days of unpaid leave 
 * the employee has taken. 
 * 
 * Additionally, the class should have members for holding the employee's name 
 * and identification number. It should have an appropriate constructor and 
 * member functions for storing and retrieving data in any of the member 
 * objects. 
 * Input Validation: Company policy states that an employee may not accumulate 
 * more than 240 hours of paid vacation. The class should not allow the 
 * maxVacation object to store a value greater than this amount.
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
    {   
        hrs = h;
        convrt();
    } 
    
    //Mutator functions
    void sethrs(int h)
    {   
        hrs = h; 
        convrt();
    }
    
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
 
//Timeoff class
class Timeoff
{
    
private:  
    
    //Member variables 
    string empnm; //String for the employee's name
    int idnum;    //The employee's id number
    NumDays maxsick;     //Max sick hours and days object
    NumDays sicktaken;   //Sick hours and days taken object
    NumDays maxvac;      //Max vacation hours and days object
    NumDays vactaken;    //Vacation hours and days taken object
    NumDays maxunp;      //Max unpaid hours and days object
    NumDays unpaidtaken; //Unpaid hours and days taken object    
    
public:  
    
    //Default constructor
    Timeoff()
    {  
        empnm = "";
        idnum = 0;
    }
          
    //Initialization constructor
    Timeoff(string e, int i, int ms, int st, int mv, int vt, int mu, int ut)
    {   
        empnm = e;
        idnum = i;
        
        maxsick.sethrs(ms);
        sicktaken.sethrs(st);
        maxvac.sethrs(mv);
        vactaken.sethrs(vt);
        maxunp.sethrs(mu);
        unpaidtaken.sethrs(ut);        
    } 
    
    //Mutator functions
    void setempnm(string e)
        {   empnm = e; }
    
    void setidnum(int i)
        {   idnum = i; }
    
    //Accessor Functions
    string getempnm()
        {   return empnm; }
    
    int getidnum()
        {   return idnum; }
    
    //Print the final days results
    void print()
    {
        NumDays temp;
        
        temp = maxsick - sicktaken;
        temp.convrt();
        
        cout << " - Number of days left for each - " << endl << endl
             << "     - Sick Days: " << temp.getdays() << endl; 
        
        temp = maxvac - vactaken;
        temp.convrt();
        
        cout << " - Vacation Days: " << temp.getdays() << endl;
        
        temp = maxunp - unpaidtaken;
        temp.convrt();
  
        cout << "   - Unpaid Days: " << temp.getdays() << endl;
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
    int hrs;      //Number of hours worked
    string empnm; //String for the employee's name
    int idnum;    //The employee's id number
    
    //Temporary hours variables
    int maxsk;
    int sktkn;
    int maxvac;
    int vactkn;
    int mxunp;
    int unptkn;
    
    //Prompt the user to enter their name and id number
    cout << "      - Enter Employee Name: ";
    getline(cin,empnm);
    cout << "    - Enter Employee Number: ";
     cin >> idnum;
     cout << endl;
    
    //Prompt the user to enter the max number of sick hours
    cout << "       Max # of Sick Hours: ";
    cin >> maxsk;
    
    //Prompt the user to enter the number of sick hours taken
    cout << "     # of Sick Hours Taken: ";
    cin >> sktkn;
    cout << endl;
    
    //Prompt the user to enter the max number of vacation hours
    cout << "   Max # of Vacation Hours: ";
    cin >> maxvac;
    
    //Input validation for max vacation hours
    while(maxvac < 1 || maxvac > 240)
    {
        cout << endl
             << "  Vacation hours cannnot exceed 240 hours and cannot be less "
             << "than 1 hours" << endl << endl;
        
        cout << "   Max # of Vacation Hours: ";
         cin >> maxvac;
    }
    
    //Prompt the user to enter the number of vacation hours taken
    cout << " # of Vacation Hours Taken: ";
    cin >> vactkn;
    cout << endl;
    
    //Prompt the user to enter the max number of unpaid hours
    cout << "     Max # of Unpaid Hours: ";
    cin >> mxunp;
    
    //Prompt the user to enter the number of unpaid hours taken
    cout << "   # of Unpaid Hours Taken: ";
    cin >> unptkn;
    cout << endl;
    
    //Initialize the Timeoff object
    Timeoff emp(empnm,idnum,maxsk,sktkn,maxvac,vactkn,mxunp,unptkn);
    
    //Print the final results
    emp.print();
    
    //Exit stage right
    return 0;  
}          

