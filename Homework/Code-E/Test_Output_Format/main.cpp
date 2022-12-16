/* 
 * File: main.cpp
 * Author: Daniel Baca
 * Date: 9/3/2022
 * Purpose: Output certain format to console.
 * Version: 1
 */

//System Libraries - Post Here
#include <iostream>
using namespace std;

//Execution Begins Here
int main(int argc, char** argv)
{
    //Declare variables or constants here
    //7 characters or less
    int num1;       // 1st Number input
    float num2;     // 2nd number input
     
    // Input first number
    cin >> num1;
    cout << num1 << endl;
    
    // Input second number
    cin >> num2;
    cout << num2;
    
    //Output results
    cout << endl << "Hello World     " << endl << "\t" << "Tab it!" << endl << "Compare . . . to space   ";

    
    //Exit stage left
    return 0;
}