/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on November 14th, 2022, 7:37 PM
 *  
 * Purpose: 
 * 
 * Design a class Numbers that  can be used to translate whole dollar  amounts 
 * in the range 0 through 9999  into  an  English description of the number.  
 * For  example,  the  number  713 would  be translated into the string seven 
 * hundred  thirteen,  and 8203  would  be translated into eight thousand two 
 * hundred  three. The class should have a single integer member variable:
 * 
 * int numbers 
 * 
 * and a static array of string objects that specify how to translate key dollar  amounts 
 * into the desired format.  For example, you might use static strings such as
 * 
 * string lessThan20[ ] = {"zero", "one", …, "eighteen", "nineteen" };
 * string hundred = "hundred";
 * string thousand = "thousand";
 * 
 * The class should have a constructor that accepts a nonnegative  integer and 
 * uses it to initialize the  Numbers object.  It  should  have  a  member  
 * function  print() that  prints  the  English description of the Numbers 
 * object. Demonstrate the class by writing a main program that asks the user to
 * enter a number in the proper range and then prints out its English 
 * description. 
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

//Numbers Class 
class Numbers
{
    
private:  
    
    //member variables 
    int number;    //user number input to convert to english dollar amount
    static string lessthan20[20];   //Static 1 - 20 string
    static string ten[8];       //Static tens string
    static string hundred[9];   //Static hundreds string
    static string thousand[9];  //Static thousands string

public:  
    
    //Initialization constructor
    Numbers(int n)
    {   number = n; } 
    
    //Print the english dollar amount
    void print()
    {
        //Process or map Inputs to Outputs
        //Determine 1000's, 100's, 10's, 1's
        int n1000s,n100s,n10s,n1s;
        n1000s=number/1000;   //Shift 3 places to the left
        n100s=number%1000/100;//Remainder of division of 1000 then shift 2 left
        n10s=number%100/10;   //Remainder of division of 100 then shift 1 left
        n1s=number%10;        //Remainder of division by 10
        
        //Formatting
        cout << "   ";
         
        //Output the number of 1000's in Roman Numerals
        //Using the Switch Statement
        switch(n1000s)
        {
            case 9:cout<< thousand[8] << " ";
                        break;
            case 8:cout<< thousand[7] << " ";
                        break;
            case 7:cout<< thousand[6] << " ";
                        break;
            case 6:cout<< thousand[5] << " ";
                        break;
            case 5:cout<< thousand[4] << " ";
                        break;
            case 4:cout<< thousand[3] << " ";
                        break;
            case 3:cout<< thousand[2] << " ";
                        break;
            case 2:cout<< thousand[1] << " ";
                        break;
            case 1:cout<< thousand[0] << " ";
                        break;
        }
        
        //Output the number of 100's
        //Using the Ternary Operator
        cout<<(n100s==9?hundred[8]:
               n100s==8?hundred[7]:
               n100s==7?hundred[6]:
               n100s==6?hundred[5]:
               n100s==5?hundred[4]:
               n100s==4?hundred[3]:
               n100s==3?hundred[2]:
               n100s==2?hundred[1]:
               n100s==1?hundred[0]:" ");
        
        //Output the number of 10's
        //Using Independent If Statements
        if(n10s==9)cout<< ten[7];
        if(n10s==8)cout<< ten[6];
        if(n10s==7)cout<< ten[5];
        if(n10s==6)cout<< ten[4];
        if(n10s==5)cout<< ten[3];
        if(n10s==4)cout<< ten[2];
        if(n10s==3)cout<< ten[1];
        if(n10s==2)cout<< ten[0];
        if(n10s==1 && n1s == 9)cout << lessthan20[18];        
        if(n10s==1 && n1s == 8)cout << lessthan20[17];        
        if(n10s==1 && n1s == 7)cout << lessthan20[16];        
        if(n10s==1 && n1s == 6)cout << lessthan20[15];        
        if(n10s==1 && n1s == 5)cout << lessthan20[14];       
        if(n10s==1 && n1s == 4)cout << lessthan20[13];       
        if(n10s==1 && n1s == 3)cout << lessthan20[12];        
        if(n10s==1 && n1s == 2)cout << lessthan20[11];
        if(n10s==1 && n1s == 1)cout << lessthan20[10];
        if(n10s==1 && n1s == 0)cout<< lessthan20[9];
        
        //Output the number of 1's
        //Using Dependent If Statements
        if(n1s==9 && n10s != 1)cout<< lessthan20[8];
        else if(n1s==8 && n10s != 1)cout<< lessthan20[7];
        else if(n1s==7 && n10s != 1)cout<< lessthan20[6];
        else if(n1s==6 && n10s != 1)cout<< lessthan20[5];
        else if(n1s==5 && n10s != 1)cout<< lessthan20[4];
        else if(n1s==4 && n10s != 1)cout<< lessthan20[3];
        else if(n1s==3 && n10s != 1)cout<< lessthan20[2];
        else if(n1s==2 && n10s != 1)cout<< lessthan20[1];
        else if(n1s==1 && n10s != 1)cout<< lessthan20[0]; 
        
        if(number == 0)
            cout << "Zero dollars" << endl << endl;
        
        //Formatting
        if(number != 0)
            cout << " dollars" << endl;
    }   
};

    //Static numbers between 1 and 20 string
    string Numbers::lessthan20[20] = {"One", "Two", "Three","Four", "Five", 
    "Six","Seven", "Eight", "Nine","Ten", "Eleven", "Twelve","Thirteen", 
    "Fourteen", "Fifteen","Sixteen", "Seventeen", "Eighteen","Nineteen"};
    
    //Static tens string
    string Numbers::ten[8] = {"Twenty-","Thirty-","Forty-","Fifty-",
                              "Sixty-","Seventy-","Eighty-","Ninety-"};
    
    //Static hundreds string
    string Numbers::hundred[9] = {"One hundred ","Two hundred ","Three hundred ",
                                  "Four hundred ","Five hundred ","Six hundred ",
                                "Seven hundred ","Eight hundred ","Nine hundred "};
      
    //Static thousands string
    string Numbers::thousand[9] = {"One thousand", "Two thousand", 
                                   "Three thousand", "Four thousand", 
                                   "Five thousand", "Six thousand", 
                                   "Seven thousand", "Eight thousand", ""
            "                      Nine thousand"};

//Execution of Code Begins Here
int main(int argc, char** argv) 
{  
    //Declare Variables
    int number; //user number input to convert to english dollar amount
    
    //Loop for program to continue taking input
    do
    {
        //Prompt user to input dollar amount
        cout << endl << "   - Enter 0 to quit program -" << endl 
             << "   - Input a whole Dollar Amount -" << endl
             << "       #: $";
         cin >> number;
         cout << endl;

        //Input validation for number input 
        while(number < 0 || number > 9999)
        {
            cout << "       Please input a valid number (0-9999)" << endl;
            cout << endl << "       #: $";
             cin >> number;
            cout << endl;
        }
         
        //Initialize the Numbers class object
        Numbers num(number);

        //Print the english dollar amount
        num.print();

        //Output program end response
        if(number == 0)
            cout << "   - End Program -" << endl;
    
    }while(number != 0);
      
    //Exit stage right
    return 0;  
}    

