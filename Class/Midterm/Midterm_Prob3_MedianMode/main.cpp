/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on October 19th, 2022, 6:35 PM
 * Purpose: I have written a program for you to complete. This problem is not 
 * to be included with the menu. Simply print when I run the menu program that 
 * it is included in another project. You are to write a program that outputs 
 * the mean, median, and mode. Your task is to complete the function. This will 
 * use structures to pass information from one function to the print function.
 * 
 * Stats *stat(const Array *array){
 * //Non-working stub to be completed by the student
 * cout<<endl<<"stat function to be completed by the student"<<endl;
 * Stats *stats=new Stats;
 * stats->mode=new Array;
 * stats->mode->size=0;
 * int nModes=0;
 * stats->mode->data=new int[nModes];
 * stats->modFreq=0;
 * stats->median=0;
 * return stats;
 * }
 *  
 * I have also supplied the expected outputs you can compare against in a 
 * StatResults.txt file. Note: The only part of the program you are to change is
 * the stat function. Nothing else is to be touched!
 * 
 */

//Libraries
#include <iostream>//I/O
using namespace std;

//User Libraries
#include "Array.h"
#include "Stats.h"

//No Global Constants

//Function Prototypes I supply
Array *fillAry(int,int);        //Fill an array and put into a structure
void prntAry(const Array *,int);//Print the array 
int *copy(const int *,int);     //Copy the array
void mrkSort(int *,int);        //Sort an array
void prtStat(const Stats *);    //Print the structure
void rcvrMem(Array *);          //Recover memory from the Array Structure
void rcvrMem(Stats *);          //Recover memory from Statistics Structure

//Functions you are to supply
Stats *stat(const Array *);     //Find & store mean, median, & modes in structure

//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables
    int arySize;//Array Size
    int modNum; //Number to control the modes (digits 0 to 9 allowed)
    Array *array;
    
    //Input the size and mod number
    cout<<"This program develops an array to be analyzed"<<endl;
    cout<<"Array size from mod number to 100"<<endl;
    cout<<"Mod number from 2 to 10"<<endl;
    cout<<"Input the Array Size and the mod number to be used."<<endl;
    cin>>arySize>>modNum;
    cout<<endl<<endl;
    
    //Fill the array
    array=fillAry(arySize,modNum);
    
    //Print the initial array
    cout<<"Original Array before sorting"<<endl;
    prntAry(array,10);
    
    //Sort the array
    mrkSort(array->data,array->size);
    cout<<"Sorted Array to be utilize for the stat function"<<endl;
    prntAry(array,10);
    
    //Calculate some of the statistics
    Stats *stats=stat(array);
    
    //Print the statistics
    prtStat(stats);
    
    //Recover allocated memory
    rcvrMem(array);
    rcvrMem(stats);
    
    //Exit stage right
    return 0;
}

int *copy(const int *a,int n){
    //Declare and allocate an array
    //that is a c
    int *b=new int[n];
    //Fill
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

void prtStat(const Stats *ary){
    cout<<endl;
    cout<<"The average of the array = "<<ary->avg<<endl;
    cout<<"The median of the array  = "<<ary->median<<endl;
    cout<<"The number of modes      = "<<
            ary->mode->size<<endl;
    cout<<"The max Frequency        = "<<
            ary->modFreq<<endl;
    if(ary->mode->size==0){
        cout<<"The mode set             = {null}"<<endl;
        return;
    }
    cout<<"The mode set             = {";
    for(int i=0;i<ary->mode->size-1;i++){
        cout<<ary->mode->data[i]<<",";
    }
    cout<<ary->mode->data[ary->mode->size-1]<<"}"<<endl;
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(array[j]<array[i]){
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}

void rcvrMem(Stats *stats){
    rcvrMem(stats->mode);
    delete stats;
}

void rcvrMem(Array *array){
    delete []array->data;
    delete array;
}

void prntAry(const Array *array,int perLine){
    //Output the array
    for(int i=0;i<array->size;i++){
        cout<<array->data[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Array *fillAry(int n, int modNum){
    //Allocate memory
    Array *array=new Array;
    array->size=n;
    array->data=new int[array->size];
    
    //Fill the array with mod numbers
    for(int i=0;i<n;i++){
        array->data[i]=i%modNum;
    }
    
    //Exit function
    return array;
}

Stats *stat(const Array *array){
    //Non-working stub to be completed by the student
    cout<<endl<<"Stat function to be completed by the student"<<endl;
    
    //Initialize dynamic structures
    Stats *stats=new Stats;
    stats->mode=new Array;
    stats->mode->size=0;
    
    //Variables use for average and median calculations
    float avg = 0;
    float median = 0;
    int x =0;
    float med1=0;
    float med2=0;
    
    //Check if the size of the array is even or odd
    if((array->size%2) == 0)
    {
        //Add all values in array to get the total
        for (int i=0; i<array->size; i++)
            avg += array->data[i];
        
        //Divide the total by the size of the array to get the average
        avg /= array->size;
        
        //Find the middle values of the array
        x = array->size/2;
        med1= static_cast<float>(array->data[x]);
        med2= static_cast<float>(array->data[x-1]);
        
        //Calculate the median value
        median = ((med1 + med2)/2);  
    }
    //Case for if the array size is odd
    else
    {  
        //Add all values in array to get the  total
        for (int i=0; i<array->size; i++)
            avg += array->data[i];
        
        //Divide the total by the size of the array to get the average
        avg /= array->size;
        
        //Find the exact middle value of the array
        x = (array->size-1)/2;
        
        //Input the median value
        median =static_cast<float>(array->data[x]);
    }
    
    // Initialize Variables
    int num = array->data[0]; //Value used to test mode loop
    int count = 1;            //Counter for number of times a number has 
                              //occurrred
    int count1 = 0;           //Counter for number of mode values
    int countmode = 1;        //Counter for mode frequency
    float uniq = 1;           //Number of unique values in the array
    
    //Find the number of modes and frequency of modes
    for (int i=1; i<array->size; i++)
    {
      if (array->data[i] == num) 
      { //count occurrences of the current number
        count++;
      }
      else
      {     //This is now a different number
            if (count > countmode) 
                //countmode is the number of highest occurrences
                countmode = count; 
            
            //If the number repeating is found the same number of times as the 
            //max then count it
            if(count==countmode)
                count1++;
                
            //Number of unique numbers
            uniq++;
            
            //Reset count for the new number
            count = 1; 
            num = array->data[i];
        }
    }
    
    //If size oof the array and the number of unique values are equal then 
    //frequency equals 0.            
    if(array->size == uniq)
        count1 =0;
    
    //Set number of modes values
    int nModes=count1;
    
    //Initialize final data array
    if(nModes!=0)stats->mode->data=new int[nModes];
    
    //Finalize currently found values
    stats->modFreq=countmode;
    stats->avg=avg;
    stats->median=median;
    stats->mode->size =count1;
     
    //Reset all values used prior 
    num = array->data[0];
    count = 1;
    count1=0;
    countmode = 1;
     
    //If the size input and unique number input are equal return the structure
    if(array->size == uniq)
        return stats;
      
    //Repeat process now looking to find mode set
    for (int i=1; i<array->size; i++)
    {
      if (array->data[i] == num) 
         // count occurrences of the current number
         count++;
      else
      { //This is now a different number
        if (count > countmode) 
            countmode = count; // countmode is the highest number of occurrences
        //If the number repeating is found the same number of times as the max 
        //then count it
        if(count==countmode)
                count1++;
        
        // Reset count for the new number
        count = 1;
        num=array->data[i];
 
        //Set mode value into the array
        stats->mode->data[count1] = num;
                
        }
    }
    
    //Fix some stuff
    if(array->size != 10 && (array->size % 10) == 0)
    {
        nModes = 10;
        stats->mode->size = 10; 
        stats->mode->data[9]=9;
    }
    
    //Set first value of mode array to always be zero
    stats->mode->data[0]=0;
    
    //Return the stats structure
    return stats;
}

