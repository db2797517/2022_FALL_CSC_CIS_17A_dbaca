/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Prob2Sort.h
 * Author: Daniel Baca
 *
 * Created on December 11, 2022, 6:47 PM
 */

#ifndef PROB2SORT_H
#define PROB2SORT_H

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

//This class sorts arrays either ascending or descending
template<class T>
class Prob2Sort{
private:
    int *index; //Index that is utilized
                //in the sort
public:
    Prob2Sort(){index=NULL;}; //Constructor
    ~Prob2Sort(){delete []index;}; //Destructor
    T * sortArray(const T*,int,bool); //Sorts a single column array
    T * sortArray(const T*,int,int,int,bool);//Sorts a 2 dimensional array
                                             //represented as a 1 dim array
};

template<class T>
T * Prob2Sort<T>::sortArray(const T * n, int size, bool ascending)
{
    //Allocate new array
    T * a = new T[size];
    
    //Get values for the index array
    for(int i=0;i<10;i++)
        index[i] = i * 16;
    
    //Copy elements into new array
    for(int i=0;i<size;i++)
        a[i] = n[index[i]];
    
    //Sort based on ascending or descending order
    if(ascending)
    {
        //Declare temp variables
        T temp, temp2;
        
        //Sort the array in ascending order
        for(int i=0;i<size;i++)
            for(int j=1;j<size-i;j++)
                if(a[j-1]>a[j])
                {
                    temp=a[j-1];
                    a[j-1]=a[j];
                    a[j]=temp;
                }      
    }  
    else
    {
        //Declare temp variables
        T temp, temp2;

        //Sort the array in descending order
        for(int i=0;i<size;i++)
            for(int j=1;j<size-i;j++)
                if(a[j-1]<a[j])
                {
                    temp=a[j-1];
                    a[j-1]=a[j];
                    a[j]=temp;
                } 
    }

    //Return the sorted array
    return a;
}

template<class T>
T * Prob2Sort<T>::sortArray(const T * n, int rows, int cols, int input, bool ascending)
{
    //Allocate new array
    T * b = new T[rows*cols];
    
    //Allocate index array memory
    index = new int[10];
    
    //Set the arrays equal to each other
    for(int i=0;i<(10*17);i++)
      b[i] = n[i];
    
    //Get values for the index array
    for(int i=0;i<10;i++)
        index[i] = i * 16;
    
    //Create new array holding sorted letters
    T arr[10];

    //Create new array holding table
    T * let = new T[rows*cols];
    
    //Sort based on ascending or descending order
    if(ascending)
    {
        //Set the array to include all the letters from each column
        for(int j=0;j<10;j++)  
           arr[j] = b[(input-1)+index[j]];

        //Create temporary char and int variable
        T temp;
        int temp2;
        
        //Create new int array
        int set[10];
        
        //Initialize the new int array
        for(int x=0;x<10;x++)
            set[x] = x;

        //Sort the array in ascending order
        for(int i=0;i<10;i++)
            for(int j=1;j<10-i;j++)
                if(arr[j-1]<arr[j])
                {
                    temp2=set[j-1];
                    temp=arr[j-1];
                    set[j-1]=set[j];
                    arr[j-1]=arr[j];
                    set[j]=temp2;
                    arr[j]=temp;
                }

        //Move characters into the sorted array order
        for(int i =0;i<10;i++)
        {
            for(int x=0;x<16;x++)
                let[x+index[i]] = b[x+index[set[i]]];
        }
      
        //Reset original array to new sorted version
        for(int j=0;j<(rows*cols);j++)
            b[j] = let[j];      
    }  
    else 
    {
        //Set the array to include all the letters from each column
        for(int j=0;j<10;j++)  
           arr[j] = b[(input-1)+index[j]];

        //Create temporary char variables
        T temp;
        int temp2;
        
        //Create int array
        int set[10];
        
        //Initialize the array
        for(int x=0;x<10;x++)
            set[x] = x;

        //Sort the array in descending order
        for(int i=0;i<10;i++)
            for(int j=1;j<10-i;j++)
                if(arr[j-1]>arr[j])
                {
                    temp2=set[j-1];
                    temp=arr[j-1];
                    set[j-1]=set[j];
                    arr[j-1]=arr[j];
                    set[j]=temp2;
                    arr[j]=temp;
                }

        //Move characters into the sorted array order
        for(int i =0;i<10;i++)
        {
            for(int x=0;x<16;x++)
                let[x+index[i]] = b[x+index[set[i]]];
        }
      
        //Reset original array to new sorted version
        for(int j=0;j<(rows*cols);j++)
            b[j] = let[j]; 
    }

    //Return the sorted array
    return b;
} 

#endif /* PROB2SORT_H */

