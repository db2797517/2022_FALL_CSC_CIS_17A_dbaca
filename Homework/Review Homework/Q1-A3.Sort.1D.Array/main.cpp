/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * 9/4/2022 14:28pm
 * Purpose:  Sorting an array of characters if specified correctly
 */

//System Libraries Here
#include <iostream>//cout,cin
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
 
//Function Prototypes Here
int read(char []);
void sort(char [],int);
void print(const char [],int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;//Larger than needed
    char array[SIZE]; //Character array larger than needed
    int sizeIn,sizeDet;//Number of characters to be read, check against length
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of characters and sort"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of characters and determine it's size
    cout<<"Now read the Array"<<endl;
    sizeDet=read(array);//Determine it's size

    //Compare the size input vs. size detected and sort if same
    //Else output different size to sort
    if(sizeDet==sizeIn){
       sort(array,sizeIn);   //Sort the array
        print(array,sizeIn); //Print the array
    }else{
        cout<<(sizeDet<sizeIn?"Input size less than specified.":
            "Input size greater than specified.")<<endl;
    }
    
    //Exit
    return 0;
}

// Read the input
int read(char array[])
{
    int size1;
    
    for (int i = 0; i < 20; i++ )
    {
        cin >> array[i];
    }
    
    size1 = strlen(array);
    
    return size1;
}

// Sort the input
void sort(char array [], int sizeIn)
{
    int i,
        j,
     temp,
     pass = 0;
    
        
    for(i = 0; i<sizeIn; i++) {
   for(j = i+1; j<sizeIn; j++)
   {
      if(array[j] < array[i]) {
         temp = array[i];
         array[i] = array[j];
         array[j] = temp;
      }
   }
pass++;
}
}

// Print the output
void print(const char array[], int sizeIn)
{
        for (int i = 0; i < sizeIn; i++ )
    {
        cout << array[i];
    }
    cout << endl;
}
