/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on December 10th, 2022, 8:49 PM
 * Purpose: Problem 5 (Employee Class) Create an Employee class with the 
 *          following specification
 * 
 * public:
 * Employee(char[],char[],float); //Constructor
 * float CalculatePay(float,int); //Procedure
 * float getGrossPay(float,int); //Procedure
 * float getNetPay(float); //Procedure
 * void toString(); //Procedure
 * int setHoursWorked(int); //Procedure
 * float setHourlyRate(float); //Procedure
 * 
 * private:
 * double Tax(float); //Utility Procedure
 * char MyName[20]; //Property
 * char JobTitle[20]; //Property
 * float HourlyRate; //Property
 * int HoursWorked; //Property
 * float GrossPay; //Property
 * float NetPay; //Property
 * 
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
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) 
{
    //Initialize Object variable
    Employee Mark("Mark","Boss",215.50);
     
    //Set the hours worked
    Mark.setHoursWorked(-3);
    
    //Output the results
    Mark.toString();
    
    //Calculate the pay of the employee and output it
    Mark.CalculatePay(Mark.setHourlyRate(20.0),Mark.setHoursWorked(25));
    Mark.toString();
     
    //Calculate the pay of the employee and output it
    Mark.CalculatePay(Mark.setHourlyRate(40.0),Mark.setHoursWorked(25));
    Mark.toString();
    
    //Calculate the pay of the employee and output it
    Mark.CalculatePay(Mark.setHourlyRate(60.0),Mark.setHoursWorked(25));
    Mark.toString();
    
    //Initialize second Object variable
    Employee Mary("Mary","VP",50.0);
    
    //Output the results
    Mary.toString();
      
    //Calculate the pay of the employee and output it
    Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHoursWorked(40));
    Mary.toString();
    
    //Calculate the pay of the employee and output it
    Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHoursWorked(50));
    Mary.toString();
    
    //Calculate the pay of the employee and output it
    Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHoursWorked(60));
    Mary.toString();

    //Exit Stage Right
    return 0;
}

