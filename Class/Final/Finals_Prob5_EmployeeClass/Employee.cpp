/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
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
#include "Employee.h"
using namespace std;
 
//Initialization Constructor
Employee::Employee(const char n[], const char t[], float r)
{
    //Initialize the MyName char array
    for(int i=0;i<20;i++)
        MyName[i] = n[i];
    
    //Initialize the JobTitle char array
    for(int i=0;i<20;i++)
        JobTitle[i] = t[i];
       
    //Secondary Input validation for the hourly rate
    if(r > 0 && r <= 200)
        HourlyRate = r;
    else
    {
        cout << "Unacceptable Hourly Rate" << endl;
        HourlyRate = 0;
    }
      
    //Initialize the variables
    HoursWorked = 0;
    GrossPay = 0;
    NetPay =0;
}

//Function to calculate the amount of tax
double Employee::Tax(float g)
{
    //Initialize the tax Variable
    double tax = 0;
    
    //Calculate the amount of tax to pay
    if(g <= 500)
        tax += g * 0.1;
    else if(g > 500 && g <= 1000)
    {
        tax += 500 * 0.1;
        tax += (g - 500) * 0.2;
    }
    else if(g > 1000)
    {
        tax += 500 * 0.1;
        tax += 500 * 0.2;
        tax += (g - 1000) * 0.3;
    }

    //Return the amount of tax to pay
    return tax;  
}

//Function to calculate the Gross pay and the Net Pay
float Employee::CalculatePay(float x, int y)
{
    return getNetPay(getGrossPay(setHourlyRate(x),setHoursWorked(y)));
}

//Function to calculate and return the Gross Pay
float Employee::getGrossPay(float r, int h)
{
    //Floats used to calculate the Gross pay
    float pay =0, 
          pay1 =0,
          pay2 =0;
    
    //Calculate the Gross pay based on the number of hours worked
    if(h <= 40)
        pay = r * h;
    else if(h > 40 && h <= 50)
    {
        pay1 = r * 40;
        pay = (r * 1.5) * (h - 40);
        
        pay += pay1;
    }
    else if(h > 50)
    {
        pay1 = r * 40;
        pay2 = (r * 1.5) * 10;
        pay = (r * 2) * (h - 50);
        
        pay += pay1;
        pay += pay2;
    }
       
    //Set the Gross Pay
    GrossPay = pay;
    
    //Return the Gross Pay
    return GrossPay;
}

//Function to return the Employee's Net Pay
float Employee::getNetPay(float g)
{ 
    //Set Net Pay equal to Gross pay
    NetPay = g;
    
    //Subtract taxes from Net Pay
    NetPay -= float(Tax(g));
    
    //Return the Net Pay
    return NetPay;
}

//Function to output all properties
void Employee::toString()
{
    //Output all of the properties
    cout << "Name = " << MyName << " Job Title = " << JobTitle << endl
         << " Hourly Rate = " << HourlyRate << " Hours Worked = " 
         << HoursWorked << " Gross Pay = " << GrossPay << " Net Pay = "
         << NetPay << endl;
}

//Function to write and receive the hourly rate
float Employee::setHourlyRate(float r)
{   
    //Input Validation for the hourly rate
    if(r > 0 && r <= 200)
    {
        HourlyRate = r;
        return HourlyRate;
    }
    else
    {
        cout << "Unacceptable Hourly Rate" << endl;
        return 0;
    }
}

//Function to write and receive the hours worked
int Employee::setHoursWorked(int h)
{   
    //Input Validation for the hours worked
    if(h > 0 && h <= 84)
    {
        HoursWorked = h;
        return HoursWorked;
    }
    else
    {
        cout << "Unacceptable Hours Worked" << endl;
        return 0;
    }
}



