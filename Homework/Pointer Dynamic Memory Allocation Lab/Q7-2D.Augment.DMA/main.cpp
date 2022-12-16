/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on September 17, 2022, 5:05 PM
 */

// Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//No Global Constants

//Function Prototypes
int **getData(int &,int &);//Get the Matrix Data
void prntDat(const int * const *,int,int);//Print the Matrix
int **augment(const int * const *,int,int);//Augment the original array
void destroy(int **,int);//Destroy the Matrix, i.e., reallocate memory

//Execution begins here
int main()
{
	//Declare variables and fill
	int input1; //The number of rows in the array
	int input2; //The number of columns in the array
	int **arr=getData(input1,input2);   //Input the Dynamic 2-D array
	
	//Print the 2-D array
	prntDat(arr,input1,input2);
	
	cout << endl;
	
	//Augment the array
	arr=augment(arr,input1+1,input2+1);

    //Print the augmented array
    prntDat(arr,input1+1, input2+1);
    
    //Deallocate memory
    destroy(arr,input1);
	    
	//Exit
	return 0;
}

//Get the input for the rows,cols and the return 2-D array
int **getData(int &input1,int &input2)
{
    cin >> input1;
	
	cin >> input2;
	
	int **arr= new int*[input1];
	
	for(int row=0;row<input1;row++)
        arr[row]=new int[input2];
    
    for (int i = 0; i < input1; i++) 
        for (int j = 0; j < input2; j++) 
            cin >> arr[i][j];
            
    return arr;
}

//Augment the array by 1 row and 1 column
int **augment(const int * const * arr, int input1, int input2)
{
    
   	int **brr= new int*[input1];
	
	for(int row=0;row<input1;row++)
        brr[row]=new int[input2];
  
    
    for(int i = 0; i < input1; ++i)
        for(int j = 0; j < input2; ++j)
            brr[i][j] = 0;
  
    for(int i = 0; i < input1-1; ++i)
        for(int j = 0; j < input2-1; ++j)
            brr[i+1][j+1] = arr[i][j];         
    
    return brr;
}

//Print the 2-D array and the augmented array
void prntDat(const int * const *arr, int input1, int input2)
{

    for (int i = 0; i < input1; i++) 
    {
        if(i<input1-1)
        {
        for (int j = 0; j < input2; j++) 
        {
            cout << arr[i][j];
            if(j <input2-1)
	        cout << " ";
        }
                cout << endl;
        }
        else
        {
        for (int j = 0; j < input2; j++) 
        {
            cout << arr[i][j];
            if(j <input2-1)
	        cout << " ";
        } 
        }
    }
}
  
//Deallocate memory
void destroy(int **arr,int input1)
{
    for(int i=0;i<input1;i++)
    {
        delete [] arr[i];
    }
    
    delete []arr;
    arr=0;
}

