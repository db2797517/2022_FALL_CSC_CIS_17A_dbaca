/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on November 21th, 2022, 2:00 AM
 * 
 * Purpose: 
 *  
 * Write templates for the two functions minimum and maximum. The minimum 
 * function should accept two arguments and return the value of the argument 
 * that is the lesser of the two. The maximum function should accept two 
 * arguments and return the value of the argument that is the greater of the 
 * two. Design a simple driver program that demonstrates the templates with 
 * various data types.
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

//Minimum Function Template
template <class T1, class T2>
T1 minimum(const T1 &var1, T2 &var2 )
{
    if(var1 < var2)
        return var1;
    else
        return var2;
}

//Maximum Function Template
template <class T1, class T2>
T1 maximum(const T1 &var1, T2 &var2 )
{
    if(var1 > var2)
        return var1;
    else
        return var2;
}
            
//Execution of Code Begins Here
int main(int argc, char** argv) 
{  
    //Declare Variables
    int n1 = 0, 
        n2 = 0,
        temp = 0;    //Integers for input test
    
    float n3 = 0,
          n4 = 0,
          temp2 = 0; //Floats for input test
    
    char n5,
         n6, 
         temp3;      //Chars for input test

    //Prompt user to enter an integer
    cout << "      Enter an integer: ";
     cin >> n1;
    
    //Prompt user to enter an integer again
    cout << " Enter another integer: ";
     cin >> n2;
    cout << endl;
    
    //Output minimum value
    temp = minimum(n1,n2);
    cout << "Here is the smallest number input: " << temp << endl;
    
    //Output maximum value
    temp = maximum(n1,n2);
    cout << " Here is the largest number input: " << temp << endl << endl;
    
    //Prompt user to enter a float
    cout << "       Enter a float: ";
     cin >> n3;
    
    //Prompt user to enter a float again
    cout << " Enter another float: ";
     cin >> n4;
    cout << endl;
    
    //Output minimum value
    temp2 = minimum(n3,n4);
    cout << "Here is the smallest number input: " << temp2 << endl;
    
    //Output maximum value
    temp2 = maximum(n3,n4);
    cout << " Here is the largest number input: " << temp2 << endl << endl;
     
    //Prompt user to enter a char
    cout << "       Enter a char: ";
     cin >> n5;
     
    //Prompt user to enter a char again
    cout << " Enter another char: ";
     cin >> n6;
    cout << endl;
    
    //Output minimum value
    temp3 = minimum(n5,n6);
    cout << "Here is the smallest number input: " << temp3 << endl;
    
    //Output maximum value
    temp3 = maximum(n5,n6);
    cout << " Here is the largest number input: " << temp3;
   
    //Exit stage right
    return 0;    
}          

