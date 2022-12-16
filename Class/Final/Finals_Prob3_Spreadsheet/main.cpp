/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on December 11th, 2022, 1:55 PM
 * Purpose:  Problem 3 (Spreadsheet Stuff)
 * 
 * Class Specifications
 * 
 * template<class T>
 * class Prob3Table{
 * 
 * protected:
 * int rows; //Number of rows in the table
 * int cols; //Number of cols in the table
 * T *rowSum; //RowSum array
 * T *colSum; //ColSum array
 * T *table; //Table array
 * T grandTotal; //Grand total
 * void calcTable(void); //Calculate all the sums
 * 
 * public:
 * Prob3Table(char *,int,int); //Constructor then Destructor
 * ~Prob3Table(){delete [] table;delete [] rowSum;delete [] colSum;};
 * const T *getTable(void){return table;};
 * const T *getRowSum(void){return rowSum;};
 * const T *getColSum(void){return colSum;};
 * T getGrandTotal(void){return grandTotal;};
 * };
 * 
 * template<class T>
 * class Prob3TableInherited:public Prob3Table<T>{
 * 
 * protected:
 * T *augTable; //Augmented Table with sums
 * 
 * public:
 * 
 * Prob3TableInherited(char *,int,int); //Constructor
 * ~Prob3TableInherited(){delete [] augTable;}; //Destructor
 * const T *getAugTable(void){return augTable;};
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
#include "Prob3TableInherited.h"
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) 
{
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

    //Exit Stage Right
    return 0;
}

