/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on September 17th, 2022, 8:29 AM
 */

//Libraries
#include <iostream>
using namespace std;

//No Global Constants

//Function Prototypes
int *getData(int &);             //Return the array size and the array from the inputs
int *sumAry(const int *,int);    //Return the array with successive sums
void prntAry(const int *,int);   //Print the array

//Execution begins here
int main()
{
	//Declare variables and fill
	int input;                  //Input the size of the array
	int *arr=getData(input);    //Establish the dynamic array

    //Print the integer array
	prntAry(arr, input);	  
	     
	cout << endl;
	 
	//Sun up the elements of the first array   
	arr=sumAry(arr, input);
	
	//Print the new array    
	prntAry(arr, input);
	  
	//Exit  
	return 0;
}

//Input the size of the array and get the input for the array, return the array
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

//Sum up the elements of the array
int *sumAry(const int *arr1,int input)
{
    int z=0;
    
    int* arr2 = new int[input];
    
    for(int i=0;i<input;i++)
        arr2[i]=arr1[i];
    
    for(int pos=1;pos<input;pos++)
    {
        arr2[pos] = arr2[pos] + arr2[z];
        z++;
    }
    return arr2;
}
