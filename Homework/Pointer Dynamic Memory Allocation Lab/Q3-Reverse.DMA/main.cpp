/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on September 16th, 2022, 9:17 PM
 */

//Libraries
#include <iostream>
using namespace std;

//No Global Constants

int *getData(int &);       //Fill the array
int *Sort(const int *,int);           //Sort smallest to largest
int *reverse(const int *,int);  //Sort in reverse order
void prntDat (const int *,int);       //Print the array

//Execution begins here
int main()
{
    //Declare variables and fill
	int input;                  // The size of the array
	int *array= getData(input);   // Establish the dynamic array
 
    // Sort the array;
	array=Sort(array,input);
	    
	//Print the integer array
	prntDat(array,input);
	    
	cout << endl;
	    
	//Reverse the input array
	array=reverse(array,input);
	   
	//Print the reverse array 
	prntDat(array,input);
    
    // Exit
	return 0;
}

// Input the size of the array and input the array data, return the array
int *getData(int &input)
{
    cin >> input;
    
    int *array= new int (input);
    
	for(int i =0;i<input;i++)
	    cin>>array[i];
	    
	return array;
}

// Sort the input array, return the array
int *Sort(const int *arr1, int input)
{
    int* arr2 = new int[input];
    
    for(int i=0;i<input;i++)
        arr2[i]=arr1[i];
    
    for(int i=0;i<input-1;i++)
        for(int j =i+1;j<input;j++)
            if(arr2[i]>arr2[j])
            {
                int temp =arr2[i];
                arr2[i] = arr2[j];
                arr2[j]=temp;
            }


    
    return arr2;
}

//Print the initial array
void prntDat(const int *arr, int input)
{
    for(int i =0;i<input;i++)
    {
        cout << arr[i];
        if(i <input-1)
	       cout << " ";
    }
}

//Reverse the input array
int *reverse(const int *arr1, int input)
{
    // Make copy dynamic array
    int* arr2 = new int[input];
    
    for(int i=0;i<input;i++)
        arr2[i]=arr1[i];
    
    int i =0;
    int j= input-1;
    
    while ( i < j)
    {
        int temp = arr2[i];
        arr2[i] = arr2[j];
        arr2[j] = temp;
        i++;
        j--;
    }
    return arr2;
} 
