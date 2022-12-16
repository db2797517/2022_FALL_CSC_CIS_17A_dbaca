/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * 9/10/2022 9:23am
 * Purpose:  Input something, output it reversed with some modifications
 * Note:Range should be 5 digits, 321 = 00321 reverse = 12300 before subtraction
 *      12300 - 999 = 11301 after subtraction
 *      12300 = 00321 = 321 after reversal and no subtraction
 */

//System Libraries Here
#include <iostream>//cin,cout,endl
#include <cstring> //strlen()
using namespace std;
//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
bool  inRange(const char [],unsigned short &);//Output true,unsigned or false
bool  reverse(unsigned short,signed short &);//Output true,short or false
short subtrct(signed short,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;     //More than enough
    char  digits[SIZE];    //Character digits or not
    unsigned short unShort;//Unsigned short
    short snShort;         //Signed short
    
    //Input or initialize values Here
    cout<<"Reverse a number and subtract if possible."<<endl;
    cout<<"Input a number in the range of an unsigned short"<<endl;
    cin>>digits;
    
    //Test if it is in the Range of an unsigned short
    if(!inRange(digits,unShort))
    {
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    
    //Reverse and see if it falls in the range of an signed short
    if(!reverse(unShort,snShort)){
       cout<<"No Conversion Possible"<<endl;
       return 0;
    }
    
    //Now subtract if the result is not negative else don't subtract
    snShort=subtrct(snShort,999);
    
    //Output the result
    cout<<snShort<<endl;
    
    //Exit
    return 0;
}

// Check the range of the value
bool inRange(const char digits[],unsigned short & unShort)
{ 
    int length; // Variable for length of number
    
    // Get the value of the input
    length = strlen(digits);
    
    // Check for letters in the input
    for(int i=0;i<length;i++)
    {
        if(isalpha(digits[i]))
            return false;
    } 
    
    // Convert the string to a integer
    int k = 0;
    int val =0;
    for(int i = 0; i< length ; i++)
        val = (digits[i] - '0') + (val * 10);

    // Verify the input is within the range of the unsigned
    if(val >= 0 && val <= 65535)
    {
        unShort = val;
        return true;
    }
    
    // If nothing is true, then return false
    return false;
} 
    
// Reverse the value and then check to see it is within the range of a signed short
bool reverse(unsigned short unShort, signed short & snShort)
{ 
    unsigned short rev_uns;     // Variable for the reverse of the unsigned short value
    short snShort_val = 32767;  // Value for the range of the signed short
    
    // Reverse the unShort variable
    while(unShort > 0) 
    {
        rev_uns = (rev_uns * 10) + (unShort % 10);
        unShort /= 10;
    }
    
    //Readjust the formatting of the reversed value
    if (rev_uns < 10)
        rev_uns *= 10000;
    else if(rev_uns < 100)
        rev_uns *= 1000;
    else if(rev_uns < 1000)
        rev_uns *= 100;   
    else if(rev_uns < 10000)
        rev_uns *= 10; 
    
    // Check if the reversed value is within the range of a signed short
    if(rev_uns >= snShort_val)
        return false;
    else
    {
        // Convert the value from unsigned to signed short
        snShort = (signed short)rev_uns;
        return true;
    }
        
    // If nothing else happens, then return false    
    return false;
}

short subtrct(signed short snShort, int sub_val)
{
    //Check to see if the value of the subtraction is positive or negative
    if((snShort - (signed short)sub_val) != 0);
        snShort -= (signed short)sub_val;
    
    // Return the final value
    return snShort;
} 

