/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on November 21st, 2022, 2:07 PM
 * 
 * Purpose: 
 *  
 * Write a function template that accepts an argument and returns its absolute 
 * value. The absolute value of a number is its value with no sign. For example,
 * the absolute value of -5 is 5, and the absolute value of 2 is 2. Test the 
 * template in a simple driver program.
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

//Absolute value Function Template
template <class T>
T absvl(const T &var1)
{   return abs(var1);   }
            
//Execution of Code Begins Here
int main(int argc, char** argv) 
{  
    //Declare Variables
    int num = 0,
        temp = 0;    //Integers for input test
    
    float num2 = 0, 
          temp2 = 0; //Floats for input test

    //Output message for how to end the program
    cout << endl 
         << " - Enter 0 for either value or both to end the program -" << endl
         << endl;
    
    //Loop for number input and output
    do
    {
    //Prompt user to enter an integer
    cout << "      Enter an integer: ";
     cin >> num;
     
    //Prompt user to enter an integer again
    cout << "         Enter a float: ";
     cin >> num2;
    cout << endl;
    
    //Output integer abs value
    temp = absvl(num);
    cout << " Here is the absolute value of the integer: " << temp << endl;
    
    //Output float abs value
    temp2 = absvl(num2);
    cout << "   Here is the absolute value of the float: " << temp2 << endl << endl;
           
    //Output the end program message
    if(num == 0 || num2 == 0)
        cout << "   - End Program -" << endl;
    
    } while(num != 0 && num2 !=0);
   
    //Exit stage right
    return 0;  
}          

