/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on December 10th, 2022, 6:05 PM
 * Purpose: Problem 1 (Random Sequence) Create a class that returns a random 
 * number from the following set, 19,34,57,79,126. Loop 100,000 times with this
 * procedure and print the frequency of each of the 5 numbers obtained.  
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
#include "Prob1Random.h"
using namespace std;

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) 
{
    //Declare variables here
    char n=5;                        //Number of numbers in set
    char rndseq[]={19,34,57,79,126}; //Set of number 
    int ntimes=100000;               //Loop counter

    //Initialize Object
    Prob1Random a(n,rndseq);
    
    //Loop to get 100000 random numbers from the set
    for(int i=1;i<=ntimes;i++)
        a.randFromSet();
     
    //Retrieve the frequency array
    int *x=a.getFreq();
    
    //Retrieve the set of numbers
    char *y=a.getSet();
    
    //Output the amount of times each number occurred
    for(int i=0;i<n;i++)
        cout<<int(y[i])<<" occurred "<<x[i]<<" times"<<endl;

    //Output the total number of random numbers
    cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
    
    //Exit Stage Right
    return 0;
}


