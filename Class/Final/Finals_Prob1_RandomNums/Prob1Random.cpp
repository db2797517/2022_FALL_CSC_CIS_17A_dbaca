/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
 
#include "Prob1Random.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <cstring>
using namespace std;

//Constructor
Prob1Random::Prob1Random(const char n, const char * s)
{ 
    //Initialize variable
    nset = n;
   
    //Allocate Dynamic memory
    set = new char[nset];
    freq = new int[nset];
    
    //Set the object array equal to the parameter array
    for(int i=0;i<nset;i++)
        set[i] = s[i];
    
    //Initialize the array
    for(int i=0;i<nset;i++)
        freq[i] = 0;
     
    //Initialize the counter to 0
    numRand = 0;
    
    //Generate a new seed every time to create pseudo-random numbers
    srand((unsigned) time(NULL));
}
 
//Destructor
Prob1Random::~Prob1Random(void)
{
    //Delete the allocated memory
    delete [] set;
    delete [] freq;
}
 
//Returns a random number from the set
char Prob1Random::randFromSet()
{
    //Declare Variables
    int num =0; //Int to hold random number generated
    
    //Generate a random number
    num = rand()%5;
    
    //Use the random number and count the frequency of each one
    if(num == 0)
    {
        num = set[0];
        freq[0]++;
    }
    else if(num == 1)
    {
        num = set[1];
        freq[1]++;
    } 
    else if(num == 2)
    {
        num = set[2];
        freq[2]++;
    }
    else if(num == 3)
    {
        num = set[3];
        freq[3]++;
    } 
    else if(num == 4)
    {
        num = set[4];
        freq[4]++;
    }
    
    //Count up the number of times a random number is made
    numRand++;
    
    //return the random number from the set
    return num;
}

//Returns the frequency histogram
int * Prob1Random::getFreq(void) const
{   return freq; }

//Returns the set used
char * Prob1Random::getSet(void) const
{   return set; }

//Return number of times randFromSet has been called
int Prob1Random::getNumRand(void) const
{   return numRand; }


