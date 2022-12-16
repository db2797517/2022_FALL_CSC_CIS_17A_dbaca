/* 
 * File: main.cpp
 * Author: Daniel Baca
 * Date: 9/3/2022
 * Purpose: Output certain format of input to console
 * Version: 1st
 */

//System Libraries - Post Here
#include <iostream>
#include <iomanip>
using namespace std;

//Execution Begins Here
int main(int argc, char** argv) 
{
    //Declare variables or constants here
    //7 characters or less
    float num1, // 1st number input
        num2,   // 2nd number input
        num3,   // 3rd number input
        num4;   // 4th number input
    
    // Output the results
    cin >> num1;
    cout << "        " << num1 << "       " << fixed << setprecision(1) << num1 << "      " << setprecision(2) << num1 << endl;
    
     cin >> num2;
    cout << "        " << setprecision(0) << num2 << "       " << fixed  << setprecision(1) << num2 << "      " << setprecision(2) << num2 << endl;
    
     cin >> num3;
    cout << "        " << setprecision(0) << num3 << "       " << fixed  << setprecision(1) << num3 << "      " << setprecision(2) << num3 << endl;
    
     cin >> num4;
    cout << "        " << setprecision(0) << num4 << "       " << fixed  << setprecision(1) << num4 << "      " << setprecision(2) << num4;
    
    //Exit stage left
    return 0;
}