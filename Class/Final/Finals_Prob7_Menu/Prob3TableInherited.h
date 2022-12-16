/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Prob3TableInherited.h
 * Author: Daniel Baca
 *
 * Created on December 11, 2022, 2:03 PM
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
#include <functional>
#include "Prob3Table.h"
using namespace std;
 
#ifndef PROB3TABLEINHERITED_H
#define PROB3TABLEINHERITED_H
 
//Prob3TableInherited
template<class T>
class Prob3TableInherited:public Prob3Table<T>
{
protected:
    T *augTable; //Augmented Table with sums
public:
    Prob3TableInherited(const char *,int,int); //Constructor
    ~Prob3TableInherited(){delete [] augTable;}; //Destructor
    const T *getAugTable(void){return augTable;};
};

template <class T>
Prob3TableInherited<T>::Prob3TableInherited(const char *fileName,int r,int c):Prob3Table<T> (fileName,r,c)
{ 
    //Allocate new memory
    augTable = new int[(r+1) * (c+1)];
    
    //Calculate all of the values for the augmented array
    this->calcTable();
    
    //Read in the values from the original table
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            augTable[i*(c+1)+j] = this->table[i*c+j];
     
    //Input the row sums into the new array
    for(int j=0;j<c;j++)
            augTable[(j+1)*(c)+j] = this->rowSum[j];
    
    //Input the column sums into the new array
    for(int i=35;i<42;i++)
        augTable[i] = this->colSum[i-35];
    
    //Set the grandTotal in the new array
    augTable[41] = this->grandTotal;
}

#endif /* PROB3TABLEINHERITED_H */

