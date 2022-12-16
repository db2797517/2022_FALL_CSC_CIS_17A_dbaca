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
#include "SavingsAccount.h"
using namespace std;  //STD Name-space where Library is compiled

//Constructor
SavingsAccount::SavingsAccount(float b)
{
    //Check to see if initial balance input is valid
    if(b > 0)
        Balance = b;
    else 
        Balance = 0;
    
    //Initialize variables
    FreqWithDraw = 0;
    FreqDeposit = 0;
    
    //Generate a new seed every time to create pseudo-random numbers
    //srand((unsigned) time(NULL));
}
 
//Function used to determine whether or not to make a deposit or withdraw
void SavingsAccount::Transaction(float t)
{ 
    //Determine whether or not to make a deposit or withdraw
    if(t > 0)
        Deposit(t);
    else 
        Withdraw(t);
}

//Function used to get the new Balance after including all of the interest
float SavingsAccount::Total(float r, int y)
{
    //Float variable used to calculate the total savings made
    float savings = Balance;
     
    //Loop to calculate the total amount of savings made
    for(int i=0;i<7;i++)
    {
        if(savings != 0)
        savings += savings * r;
    }
    
    //Return the savings made
    return Balance*pow((1+r),float(y));
}

//Function used to recursively get the new Balance after including all of the 
//interest
float SavingsAccount::TotalRecursive(float r, int y)
{
    //Determine if the loop should end
    if(y == 0)
        return Balance;
    
    //Determine the amount of interest
    float interest = Balance * r;
    
    //Add the interest made to the balance
    Balance += interest;
    
    //Recursively loop until the total amount of interest is added to the 
    //balance
    return TotalRecursive(r, y-1);
}

//Function to output all of the properties
void SavingsAccount::toString()
{
    //Output all of the properties
    cout << "Balance=" << Balance << endl << "Withdraws=" << FreqWithDraw
         << endl << "Deposit=" << FreqDeposit << endl;
}

//Function to withdraw amount from balance
float SavingsAccount::Withdraw(float t)
{
    //Determine if the balance can withdraw the amount
    if((Balance + t) > 0)
    {
        //Withdraw amount from balance
        Balance += t;
        
        //Increment withdraw counter
        FreqWithDraw++;
    }
    else
        cout << "WithDraw not Allowed" << endl;
    
    //Return the new balance
    return Balance;   
}

//Function to Deposit amount into balance
float SavingsAccount::Deposit(float t)
{
    //Increment deposit counter
    FreqDeposit++;
    
    //Deposit amount into balance
    Balance += t;
    
    //Return the new Balance
    return Balance;
}