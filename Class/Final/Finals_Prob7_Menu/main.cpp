/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on December 10th, 2022, 7:49 PM
 * 
 * Purpose: Menu Program showing all of the Final problems.
 * 
 */

//System Libraries
#include "Prob1Random.h"
#include "Prob2Sort.h"
#include "Prob3TableInherited.h"
#include "Employee.h"
#include "SavingsAccount.h"
#include <cstdlib>
#include <iomanip> 
#include <cmath>
#include <ctime>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
 
//User Libraries
 
//Global Constants
 
//Functions for the menu and each problem
void menu();
void prblm1();
void prblm2();
void prblm3();
void prblm4();
void prblm5();
void prblm6();

//Execution Begins Here
int main(int argc, char** argv) 
{
    //Initialize Variables
    char choice; //Number input for menu
    
    //Loop to use each program
    do
    {
        //Display the menu
        menu();
        
        //Prompt user to enter menu input
        cout << endl << "  Enter a menu input: ";
         cin >> choice;
        cout << endl;
        
        //Switch used to determine what program to run
        switch(choice)
        {
            case '1':{prblm1();break;}
            case '2':{prblm2();break;}
            case '3':{prblm3();break;}
            case '4':{prblm4();break;}
            case '5':{prblm5();break;}
            case '6':{prblm6();break;}
           default: cout << "  - Exiting Menu -" << endl;                            
        }
        
    }while(choice>='1'&&choice<='6');
    //Run loop until input to end program has been input
    
    //Exit stage right!
    return 0;
} 
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Menu
//Input:  -> N/A
//Output: -> Menu for the all of the problems
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void menu() 
{
    //Display menu
    cout<<endl<<"   Choose from the following Menu"<<endl;
    cout<<"   Type 1 for Problem 1"<<endl;
    cout<<"   Type 2 for Problem 2"<<endl;
    cout<<"   Type 3 for Problem 3"<<endl;  
    cout<<"   Type 4 for Problem 4"<<endl; 
    cout<<"   Type 5 for Problem 5"<<endl;    
    cout<<"   Type 6 for Problem 6"<<endl<<endl;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 1
//Input:  -> N/A
//Output: -> The entire Random Number Generator Program
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm1()
{
    //Declare variables here
    char n=5;                        //Number of numbers in set
    char rndseq[]={19,34,57,79,126}; //Set of number 
    int ntimes=100000;               //Loop counter

    //Initialize Object
    Prob1Random a(n,rndseq);
    
    //Loop to get 100000 random numbers from the set
    for(int i=1;i<=ntimes;i++)
        a.randFromSet();
    
    //Retrieve the frequency array
    int *x=a.getFreq();
    
    //Retrieve the set of numbers
    char *y=a.getSet();
    
    //Output the amount of times each number occurred
    for(int i=0;i<n;i++)
        cout<<int(y[i])<<" occurred "<<x[i]<<" times"<<endl;

    //Output the total number of random numbers
    cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 2
//Input:  -> N/A
//Output: -> All Kinds of Sorting Program
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm2()
{
    cout << " ****Note: I couldn't get this program to work in the menu, for "
         << endl << "           whatever reason I can't enter the text file into "
         << endl << "           the program without it simply failing on me. "
         << endl << "           View the actual individual program for a "
         << endl << "           working version. " << endl << endl << endl;
     
    //Output beginning of program
    cout<<"The start of Problem 2, the sorting problem"<<endl;
    
    //Initialize the object variable
    Prob2Sort<char> rc;
      
    //Set variables, pointers and files
    bool ascending=true;
    fstream infile;
    infile.open("Problem2.txt",ios::in);
    
    if(!infile)
        cout << endl << "error" << endl;
    
    char *ch2=new char[10*16];
    char *ch2p=ch2;
    
    //Set pointer for single column array and sort
    char *ch3=new char[16];
    char *ch3p=ch2;
    
    //Read from the file
    while(infile.get(*ch2)){cout<<*ch2;ch2++;}
    infile.close();
    
    //Formatting
    cout<<endl;
    
    //Output prompt for column input
    cout<<"Sorting on which column"<<endl;
    
    //Declare and receive input
    int column;
    cin>>column;
    
    //Call object and receive 2D sorted array
    char *zc=rc.sortArray(ch2p,10,17,column,ascending);
    
    //Output the sorted array
    for(int i=0;i<10;i++)
        for(int j=0;j<16;j++)
            cout<<zc[i*16+j];
    
    //Output the new sorted 1D array prompt
    cout<< endl << "Sorting Column array"<<endl<< endl;
    
    //Call object and receive 1D sorted array
    char *yc=rc.sortArray(ch3p,10,ascending);
    
    //Output the sorted 1D array
    for(int i=0;i<10;i++)
            cout<<yc[i];
    
    //Delete memory
    delete []zc;
    delete []yc;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 3 
//Input:  -> N/A
//Output: -> Spreadsheet Program
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm3()
{
    cout << " ****Note: I couldn't get this program to work in the menu, for "
         << endl << "           whatever reason I can't enter the text file into "
         << endl << "           the program without it simply failing on me. "
         << endl << "           View the actual individual program for a "
         << endl << "           working version. " << endl << endl << endl;
     
    //Output start of program
    cout<<"Entering problem number 3"<<endl;
    
    //Declare Variables
    int rows=5;
    int cols=6;
    
    //Initialize Object variable
    Prob3TableInherited<int> tab("Problem3.txt",rows,cols);
     
    //Retrieve initial table
    const int *naugT=tab.getTable();
    
    //Output the original table
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
            cout<<naugT[i*cols+j]<<" ";
        
        cout<<endl;
    }
     
    //Formatting
    cout<<endl;
    
    //Receive the augmented table
    const int *augT=tab.getAugTable();
    
    //Output the augmented table
    for(int i=0;i<=rows;i++)
    {
        for(int j=0;j<=cols;j++)
            cout<<augT[i*(cols+1)+j]<<" ";
        
        cout<<endl;
    }
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 4
//Input:  -> N/A
//Output: -> Savings Account Program
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm4()
{ 
    //Declare variables here
    SavingsAccount mine(-300);
    
    cout << " ****Note: The output generated here is pseudo-random, for the "
         << endl << "           expected output view the original program "
         << endl << "           itself." << endl << endl;
    
    //Loop for random transaction amounts deposited or withdrawn
    for(int i=1;i<=10;i++)
        mine.Transaction((float)(rand()%500)*(rand()%3-1));
    
    //Output the properties
    mine.toString();
    
    //Output the Balance after adding all of the savings
    cout<<"Balance after 7 years given 10% interest = "
        <<mine.Total((float)(0.10),7)<<endl;
    
    //Output the Balance after adding all of the savings using the recursive 
    //function
    cout<<"Balance after 7 years given 10% interest = "
        <<mine.TotalRecursive((float)(0.10),7)
        <<" Recursive Calculation "<<endl;
} 
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 5
//Input:  -> N/A
//Output: -> Employee Class Program
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm5() 
{   
    //Initialize Object variable
    Employee Mark("Mark","Boss",215.50);
    
    //Set the hours worked
    Mark.setHoursWorked(-3);
    
    //Output the results
    Mark.toString();
    
    //Calculate the pay of the employee and output it
    Mark.CalculatePay(Mark.setHourlyRate(20.0),Mark.setHoursWorked(25));
    Mark.toString();
    
    //Calculate the pay of the employee and output it
    Mark.CalculatePay(Mark.setHourlyRate(40.0),Mark.setHoursWorked(25));
    Mark.toString();
    
    //Calculate the pay of the employee and output it
    Mark.CalculatePay(Mark.setHourlyRate(60.0),Mark.setHoursWorked(25));
    Mark.toString();
    
    //Initialize second Object variable
    Employee Mary("Mary","VP",50.0);
    
    //Output the results
    Mary.toString();
      
    //Calculate the pay of the employee and output it
    Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHoursWorked(40));
    Mary.toString();
    
    //Calculate the pay of the employee and output it
    Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHoursWorked(50));
    Mary.toString();
     
    //Calculate the pay of the employee and output it
    Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHoursWorked(60));
    Mary.toString();
} 
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 6
//Input:  -> N/A
//Output: -> The answers to the Conversions Problem
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm6()
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
} 





