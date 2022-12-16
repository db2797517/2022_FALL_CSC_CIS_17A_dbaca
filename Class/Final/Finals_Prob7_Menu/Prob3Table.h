/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Prob3Table.h
 * Author: Daniel Baca
 *
 * Created on December 11, 2022, 2:01 PM
 */

#ifndef PROB3TABLE_H
#define PROB3TABLE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <cstring>
using namespace std; 

//Prob3Table Template Class
template<class T>
class Prob3Table{
protected:
    int rows; //Number of rows in the table
    int cols; //Number of cols in the table
    T *rowSum; //RowSum array
    T *colSum; //ColSum array
    T *table; //Table array
    T grandTotal; //Grand total
    void calcTable(void); //Calculate all the sums
public:
    Prob3Table(const char *,int,int); //Constructor then Destructor
    ~Prob3Table(){delete [] table;delete [] rowSum;delete [] colSum;};
    const T *getTable(void){return table;};
    const T *getRowSum(void){return rowSum;};
    const T *getColSum(void){return colSum;};
    T getGrandTotal(void){return grandTotal;};
};
  
template <class T>
Prob3Table<T>::Prob3Table(const char *fileName,int rows,int cols)
{
    //Set values
    this->rows = rows;
    this->cols = cols;
    
    //Allocate  memory
    table = new int[rows * cols];
    rowSum = new int[rows+1];
    colSum = new int[cols+1];
    
    //Initialize the variable
    grandTotal = 0;
    
    //Initialize the table
    for(int i=0;i<(rows*cols);i++)
        table[i] = 0;
      
    //Open the file
    fstream file;
    file.open(fileName);
    
    //Verify the file was opened
    if(!file)
        cout << endl << "error" << endl;
    
    //Read in from the file
    for(int j=0;j<(rows*cols);j++)
        file >> table[j];
    
    //Close the file
    file.close();
    
    //Initialize the row and column sum arrays
    for(int i=0;i<cols;i++)
    {
        rowSum[i] = 0;
        colSum[i] = 0;
    }
    
}

template <class T>
void Prob3Table<T>::calcTable()
{
    //Declare Variables
    int count = 0;
    int i =0;
    
    //Calculate the row sums
    for(int j=0;j<(rows*cols);j++)
    {
        rowSum[i] += table[j];
        count++;
        
        if(count == 6)
        {
            i++;
            count = 0;
        }
    }
     
    //Calculate the columns sums
    for(int i=0;i<cols;i++)
    {
        colSum[i] += table[0+i];
        colSum[i] += table[6+i];
        colSum[i] += table[12+i];
        colSum[i] += table[18+i];
        colSum[i] += table[24+i];
    }
 
    //Calculate the grandTotal
    for(int i=0;i<(rows*cols);i++)
        grandTotal += table[i];
}

#endif /* PROB3TABLE_H */

