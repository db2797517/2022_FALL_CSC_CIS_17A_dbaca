/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on November 21st, 2022, 3:25 PM
 * 
 * Purpose: 
 *    
 * Write a template for a function called total. The function should keep a 
 * running total of values entered by the user, then return the total. The 
 * argument sent into the function should be the number of values the function 
 * is to read. Test the template in a simple driver program that sends values 
 * of various types as arguments and displays the results.
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

//Running Total Function Template
template <class T>
T total(const T var1)
{   
    T total = 0,
      num = 0;      //Variables for input and total
    
    //Loop for the requested number of inputs
    for(int i=0;i<var1;i++)
    {
        cout << " #" << (i+1) << ": ";
        cin >> num;
        total += num;
    }
     
    cout << endl << " Total: ";

    //Return the running total
    return total; 
}
            
//Execution of Code Begins Here
int main(int argc, char** argv) 
{  
    //Declare Variables
    int num = 0;    //Variable holding the number of inputs to make

    //Output message for how to end the program
    cout << endl 
         << " - Enter the number of inputs to get and then calculate the "
         << "inputs' running total -" << endl
         << endl;

    //Prompt user to enter an number of integers to input
    cout << endl << "   Enter the number of integers to input: ";
     cin >> num;
    
    //Output the integer total
    cout << endl << total<int>(num) << endl;
    
    //Prompt user to enter the number of floats to input
    cout << endl << "     Enter the number of floats to input: ";
     cin >> num;
    
    //Output the float total
    cout << endl << total<float>(num) << endl;
    
    //Exit stage right
    return 0;  
}          

