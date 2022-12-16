/*  
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on December 12th, 2022, 11:04 PM
 * Purpose: 
 * 
 * Given the following base 10 decimals
 * 
 * a)5.75
 * b)0.9
 * c)99.7
 * 1) Convert to binary, octal and hex, then
 * 2) Convert to NASA Hex float with first 24 bits representing the
 * signed fraction and the last 8 bits representing the
 * signed exponent. Scaled as 0.FRACTION x 2^EXPONENT
 * 3) convert a) to scaled integer binary 1 unsigned byte maximum bits,
 * convert b) to scaled integer binary 2 unsigned byte maximum bits,
 * convert c) to scaled integer binary 3 unsigned byte maximum bits,
 * 4) multiply 3) by 1 byte value 7 then shift back to integer and
 * output the result
 * 5) Then convert using IEEE 754 format
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
 
int main(int argc, char** argv) 
{ 
    //Output the results
    cout << endl
         << "Question 6 Answers:" << endl << endl
         << "   1.) Binary, Octal and Hex Conversions" << endl
         << "                                          " << endl
         << "          5.75(10) = " << endl
         << "            Binary = 101.11(2)     " << endl 
         << "             Octal = 5.6(8)     " << endl 
         << "               Hex = 5.C(16)    " << endl
         << "                                           " << endl
         << "           0.9(10) =                      " << endl
         << "            Binary = 0.1110(0110)(2) () = repeating    " << endl 
         << "             Octal = 0.7(1463)(8)    () = repeating     " << endl 
         << "               Hex = 0.E(6)(16)      () = repeating    " << endl 
         << "                                 " << endl
         << "          99.7(10) =          " << endl            
         << "            Binary = 1100011.1011(0011)(2) () = repeating" << endl 
         << "             Octal = 143.5(4631)(8)   () = repeating    " << endl 
         << "               Hex = 63.B(3)(16)      () = repeating   " << endl 
         << "                                 " << endl 
         << "   2.) NASA Float Representations" << endl
         << "                                 " << endl
         << "              5.75(10) = 5 C 0 0 0 0 0 3          " << endl
         << "                                 " << endl
         << "               0.9(10) = 7 3 3 3 3 3 0 0    " << endl
         << "                                 " << endl
         << "              99.7(10) = 6 3 B 3 3 3 0 7   " << endl
         << "                                           " << endl
         << "   3.) Scaled Binary" << endl
         << "                                 " << endl
         << "(View PDF for calculations) 5.75(10) = 10111000000000(2) = 11,776          " << endl
         << "                                 " << endl
         << "(View PDF for calculations)  0.9(10) = 1110011001100110011(2) = 471,859    " << endl
         << "                                 " << endl
         << "(View PDF for calculations) 99.7(10) = 1100011101100110011001100110011010(2) = 13,381,507,482   " << endl
         << "                                           " << endl
         << "   4.) Scaled Binary Multiplication " << endl << endl
         << "       7 x 11,776 = 82,432 = (shiftback) 101000.01 = 40.25(10) " << endl
         << "                         " << endl
         << "       7 x 471,859 = 3,303,013 = (shiftback) 110.0(1001) = 6.3(10) " << endl          
         << "                              " << endl
         << "       7 x 13,381,507,482 = 93,670,552,374 = (shiftback) 1010111001.111(0011) = 697.9(10) " << endl << endl
         << "   5.) IEEE 754 Format Representations" << endl
         << "                                 " << endl
         << "              5.75(10) = 4 0 B 8 0 0 0 0          " << endl
         << "                                 " << endl
         << "               0.9(10) = 3 F 6 6 6 6 6 6    " << endl
         << "                                 " << endl
         << "              99.7(10) = 4 2 C 7 6 6 6 6    " << endl
         << "                                           " << endl;

    return 0;
}

