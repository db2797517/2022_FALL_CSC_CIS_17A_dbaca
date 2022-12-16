/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on September 15, 2022, 11:20 PM
 */

//Libraries
#include <iostream>
using namespace std;

//No Global Constants

//Function Prototypes
int **getData(int &,int &);     //Return the 2-D array and its size.       
void prntDat(const int * const *,int,int);   //Print the 2-D Array
int sum(const int * const *,int,int);         //Return the Sum
void destroy(int **,int,int);   //Deallocate memory

//Execution begins here
int main()
{
	//Declare variables and fill
	int input1; //The number of rows in the array
	int input2; //The number of columns in the array
	int num=0;  //The total sum of the array
	int **arr=getData(input1,input2);   //Input the Dynamic 2-D array
	
	//Print the 2-D array
	prntDat(arr,input1, input2);
 
    //Get the total sum of the array
    num=sum(arr,input1,input2);
    
    //Output the total sum
    cout << num;
    
    //Deallocate memory
    destroy(arr,input1,input2);
	    
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

//Print the 2-D array
void prntDat(const int * const *arr, int input1, int input2)
{
    for (int i = 0; i < input1; i++) 
    {
        for (int j = 0; j < input2; j++) 
        {
            cout << arr[i][j];
            if(j <input2-1)
	            cout << " ";

        }
        cout << endl;
    }
} 

//Get the total sum
int sum(const int * const *arr,int input1,int input2)
{
    int num=0;
    
    for (int i = 0; i < input1; i++) 
        for(int j=0;j<input2;j++)
            num += arr[i][j];
    
    return num;
}

//Deallocate the memory
void destroy(int **arr,int input1,int input2)
{
    for(int i=0;i<input1;i++)
        delete [] arr[i];
    
    delete []arr;
    arr=0;
}