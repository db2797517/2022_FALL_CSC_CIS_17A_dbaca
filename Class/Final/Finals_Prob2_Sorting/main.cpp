/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on December 11th, 2022, 6:44 PM
 * Purpose: Problem 2 (All Kinds of Sorting) Sort a single column array and/or 
 * sort a 2 dimensional array of characters given any column. Here is what I 
 * used as my template specification.
 * 
 * //This class sorts arrays either ascending or descending
 * template<class T>
 * class Prob2Sort{
 * private:
 * int *index; //Index that is utilized
 *             //in the sort
 * public:
 * Prob2Sort(){index=NULL;}; //Constructor
 * ~Prob2Sort(){delete []index;}; //Destructor
 * T * sortArray(const T*,int,bool); //Sorts a single column array
 * T * sortArray(const T*,int,int,int,bool);//Sorts a 2 dimensional array
 *                                          //represented as a 1 dim array
 * 
};

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
#include "Prob2Sort.h"
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions
 
//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) 
{
    //Output beginning of program
    cout<<"The start of Problem 2, the sorting problem"<<endl;
    
    //Initialize the object variable
    Prob2Sort<char> rc;
       
    //Set variables, pointers and files
    bool ascending=true;
    ifstream infile;
    infile.open("Problem2.txt",ios::in);
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
    
    //Exit Stage Right
    return 0;
}