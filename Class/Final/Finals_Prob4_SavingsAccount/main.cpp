/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on December 11th, 2022, 12:14 PM
 * Purpose:  Problem 4 (Savings Account Class) Create a SavingsAccount class 
 * with the following specification
 * 
 * public:
 * SavingsAccount(float); //Constructor
 * void Transaction(float); //Procedure
 * float Total(float=0,int=0); //Savings Procedure
 * float TotalRecursive(float=0,int=0);
 * void toString(); //Output Properties
 * 
 * private:
 * float Withdraw(float); //Utility Procedure
 * float Deposit(float); //Utility Procedure
 * float Balance; //Property
 * int FreqWithDraw; //Property
 * int FreqDeposit; //Property  
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
#include "SavingsAccount.h"
using namespace std;  //STD Name-space where Library is compiled
 
//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
 
//Code Begins Execution Here with function main
int main(int argc, char** argv) 
{
    //Declare variables here
    SavingsAccount mine(-300);
    
    //Loop for random transaction amounts deposited or withdrawn
    for(int i=1;i<=10;i++)
        mine.Transaction((float)(rand()%500)*(rand()%3-1));
    
    //Output the properties
    mine.toString();
    
    //Output the Balance after adding all of the savings
    cout<<"Balance after 7 years given 10% interest = "
        <<mine.Total((float)(0.10),7)<<endl;
    
    //Output the Balance after adding all of the savings using the recursive 
    //function
    cout<<"Balance after 7 years given 10% interest = "
        <<mine.TotalRecursive((float)(0.10),7)
        <<" Recursive Calculation "<<endl;
    
    //Exit Stage Right
    return 0;
}

