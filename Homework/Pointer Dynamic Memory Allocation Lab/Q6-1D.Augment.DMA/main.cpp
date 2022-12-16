/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on September 16th, 2022, 10:56 PM
 */

//Libraries
#include <iostream>
using namespace std;

//No Global Constants

//Function Prototypes
int *getData(int &);            // Read the array           
int *augment(const int *,int);  // Augment and copy the original array
void prntAry(const int *,int);  // Print the array

//Execution begins here
int main()
{
	//Declare variables and fill
	int input;                  // The input for the number of elements in the array
	int *arr= getData(input);   // The dynamic array
    
        //Print the array
	    prntAry(arr, input);	  
	    
	    cout << endl;
	    
	    //Augment the array
	    arr=augment(arr,input);
 
        //Print the augmented array
	    prntAry(arr, input+1);
    	
	return 0;
}

//Input the number of elements and array elements, return the array
int *getData(int &input)
{
	cin >> input;
		
	int *arr= new int(input);
	
	for(int i =0;i<input;i++)
	    cin>>arr[i];
	 
	 return arr;   
}

//Print the array
void prntAry(const int *arr, int input)
{
    
    for(int i =0;i<input;i++)
    {
        cout << arr[i];
        if(i <input-1)
	       cout << " ";
    }
        
}
 
//Augment the original array
int *augment(const int *arr,int input)
{
    int *arr2=new int(input);
    
    arr2[0]=0;
    
    input+=1;
    
	for(int i =0;i<input;i++)
	    arr2[i+1]=arr[i];
	    
	return arr2;
}