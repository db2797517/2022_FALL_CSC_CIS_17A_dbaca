/*  
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on October 21st, 2022, 10:48 PM
 * Purpose: 
 * Conversion to NASA 4 byte float format 
 * • a) Convert the following 3 numbers to binary, octal and hex 49.1875, 
 *      3.07421875, 0.2. When done, convert the following to a float 
 *      representation by the definition in class. In other words, I want an 8 
 *      digit hex number representation using the 4 byte float specification 
 *      defined in class. An example .pdf is attached for you to review. 
 * • b) Do the same for a) given they are negative values. 
 * • c) Convert the float representations of the following into the decimal 
 *      number given the definition in class. 69999902, 69999903, 966667FF 
 * 
 * Note: This doesn’t require a program, however, I want you 
 * to write a simple function that outputs the answers you did by hand with 
 * ”cout”. Also, scan in your calculations done by hand.
 */

//Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants - none
  
//Function Prototypes
void prnt();
 
//Executions begins here
int main(int argc, char** argv) 
{
    //Print the question output
    prnt();
    
    //Exit Stage Right
    return 0;
}

void prnt()
{ 
    //Output the results
    cout << endl
         << "Question 6 Answers:" << endl << endl
         << "   a.) Binary, Octal and Hex Conversions" << endl
         << "                                          " << endl
         << "       49.1875(10) = " << endl
         << "            Binary = 110001.0011(2)     " << endl 
         << "             Octal = 61.14(8)     " << endl 
         << "               Hex = 31.3(16)    " << endl
         << "                                           " << endl
         << "    3.07421875(10) =                      " << endl
         << "            Binary = 0011.00010011(2)     " << endl 
         << "             Octal = 3.046(8)     " << endl 
         << "               Hex = 3.13(16)    " << endl 
         << "                                 " << endl
         << "           0.2(10) =          " << endl            
         << "            Binary = 0.(0011)(2) () = repeating" << endl 
         << "             Octal = 0.(1463)(8)     " << endl 
         << "               Hex = 0.(3)(16)    " << endl 
         << "                                 " << endl 
         << "        NASA Float Representations" << endl
         << "                                 " << endl
         << "           49.1875(10) = 6 2 6 0 0 0 0 6          " << endl
         << "                                 " << endl
         << "        3.07421875(10) = 6 2 6 0 0 0 0 2   " << endl
         << "                                 " << endl
         << "               0.2(10) = 6 6 6 6 6 6 F E   " << endl
         << "                                           " << endl
         << "   b.) Negative NASA Float Representations" << endl
         << endl
         << "     - 6 2 6 0 0 0 0 6 = 9 D A 0 0 0 0 6         " << endl
         << "                                  " << endl
         << "     - 6 2 6 0 0 0 0 2 = 9 D A 0 0 0 0 2   " << endl
         << "                                 " << endl
         << "     - 6 6 6 6 6 6 F E = 9 9 9 9 9 A F E  " << endl 
         << endl
         << "   c.) NASA Float to Decimal Representation " << endl << endl
         << "       69999902 = 3.3(10) " << endl
         << "                         " << endl
         << "       69999903 = 6.6(10)         " << endl           
         << "                              " << endl
         << "       966667FF = 0.4125(10)                " << endl;
} 
 
 


