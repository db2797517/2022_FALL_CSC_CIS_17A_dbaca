/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on October 18th, 2022, 6:28 PM
 * Purpose: 
 * • a) Using a byte variable, what is the largest n where n!=factorial that can be 
 * calculated. A factorial is simply n! = 1 * 2 * 3 * 4 ... * (n-2) * (n-1) * n 
 * For instance, 1! = 1, 2! = 2, 3! = 6, 4! = 24, 5! = 120 etc.... Signed as 
 * well as unsigned.  
 * • b) What would be the largest n for n! using short, int, long, long long, 
 * float, double, etc... Use all the primitive data types that you are familiar 
 * with signed as well as unsigned. 
 * 
 * Note: I want you to investigate this and the program you turn in should just 
 * print ”cout” the final results. You don’t know how to capture errors yet so 
 * run each till it overflows then back off by 1. Don’t need the program that 
 * tests for this.

 */

//Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants - none

//Function Prototypes - none

//Executions begins here
int main(int argc, char** argv) 
{
    //Output the results 
    cout << endl
         << "              Question 5 Answers:" << endl << endl
         << "   a.)   Largest n for a signed byte variable -> 5" << endl
         << "      Largest n for an unsigned byte variable -> 5" << endl 
         << endl  
         << "   b.)  Largest n for a signed short variable -> 7" << endl  
         << "      Largest n for a unsigned short variable -> 8" << endl 
         << endl                               
         << "          Largest n for a signed int variable -> 12" << endl                                
         << "        Largest n for a unsigned int variable -> 12" << endl 
         << endl            
         << "         Largest n for a signed long variable -> 12" << endl                                
         << "       Largest n for a unsigned long variable -> 12" << endl 
         << endl 
         << "    Largest n for a signed long long variable -> 20" << endl                                
         << "  Largest n for a unsigned long long variable -> 20" << endl
         << endl 
         << "        Largest n for a signed float variable -> 34" << endl                                
         << "      Largest n for a unsigned float variable -> 34" << endl 
         << endl 
         << "       Largest n for a signed double variable -> 170" << endl                                
         << "     Largest n for a unsigned double variable -> 170" << endl         
         << endl 
         << "  Largest n for a signed long double variable -> 1754" << endl                                
         << "Largest n for a unsigned long double variable -> 1754" << endl;    
    
 
    //Exit Stage Right
    return 0;
}





