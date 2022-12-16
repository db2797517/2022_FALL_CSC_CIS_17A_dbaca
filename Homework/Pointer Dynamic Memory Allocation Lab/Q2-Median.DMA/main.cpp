/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on September 17th, 2022, 10:32 AM
 */

//Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//No Global Constants

//Function Prototypes
int *getData(int &);       // Return the array size and the array            
void Sort(int *,int);      // Sort the array
float *median(int *,int);  // Fill the median Array with the Float array size, the median, and the integer array data
void prntDat(int *,int);   // Print the integer array
void prntMed(float *);     // Print the median Array
 
//Execution begins here
int main()
{
	//Declare variables and fill
	int input;
	int *arr=getData(input);
	
	//Print the input array
	prntDat(arr, input);
	    
	//Get the middle array
	float *middle = median(arr,input);
	    
	//Print the middle array
	prntMed(middle);
	    
    delete[]middle;
	  
	return 0;
}

//Get the input data and input array data
int *getData(int &input)
{
    // Input array size
    cin >> input;
    
    //Establish dynamic array
    int *array= new int(input);
    
    //Get all input for array
	for(int i=0;i<input;i++)
	    cin>>array[i];
	   
	//Return the input array 
	return array;
}

//Print the integer array data
void prntDat(int *arr, int input)
{
    for(int i = 0; i < input; i++)
    {
        cout << arr[i];
        if(i <input-1)
	       cout << " ";
    }
    
    cout << endl;
}

//Get the median array data
float *median( int *arr, int input)
{
    //Establish the dynamic median array
    float *median=new float[input+2];
    
    //Set first elemnt to size of elements
    median[0] = input+2;
    
    //Input the integer array into median array
    for(int i =2;i<input+2;i++)
        median[i]=arr[i-2];
    
    //Sort the integer array
    Sort(arr,input);
    
    //Determine if size of input array is even or odd to determine how to find median
    if(input%2)
        median[1]=arr[input/2];
    else
        median[1]=(arr[(input-1)/2]+arr[input/2])/2.0f;
    
    //Return the median array
    return median;
}

//Sort the integer array
void Sort(int *arr, int input)
{
    for(int i=0;i<input-1;i++)
        for(int j =i+1;j<input;j++)
            if(arr[i]>arr[j])
            {
                int temp =arr[i];
                arr[i] = arr[j];
                arr[j]=temp;
            }
}

//Print the median array data
void prntMed(float *middle)
{
    cout << middle[0] << " " 
         << fixed << setprecision(2) << showpoint;
    
    for(int i=1;i<middle[0];i++)
    {
        cout << middle[i];
        if(i<middle[0]-1) 
            cout << " ";
    }

}


