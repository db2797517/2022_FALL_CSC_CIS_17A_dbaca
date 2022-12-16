/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on October 10th, 2022, 2:28 PM
 * Purpose: 
 * Write a function named arrayToFile. The function should accept 3 arguments:
 * The name of the file, a pointer to an array, and the size of the array. The 
 * function should open the specified file in binary mode, write the contents 
 * of the array to file, and then close the file.
 *
 * Write another function named fileToArray. This function should accept 3 
 * arguments: the name of the file, a pointer, to an int array, and the size 
 * of the array. The function should open the specified file in binary mode, 
 * read its content into the array, and then close the file.
 * 
 * Write a complete program that demonstrates these functions by using the 
 * arrayTofile, and then using the fileToArray function to read the data from 
 * the same file. After the data are read from the file into the array, display
 * the arrays contents on the screen.
 */

//Libraries
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

//No Global Constants

//Function Prototypes 
void arrayToFile(string, int *, int);
void fileToArray(string, int *, int);

//Execution Begins Here
int main(int argc, char** argv)
{
    //Random time
    srand((unsigned)time(0));
    
    //Declare Variables
    int SIZE = 100; //Size of the array
    int arr[SIZE];  //Array of numbers
    string name;    //Name of the file
    
    //Load the array with random numbers
    for(int i=0;i <SIZE;i++)
        arr[i] = (rand()%SIZE)+1;
    
    //Prompt user to input file name
    cout << "Input the name of the file: ";
    getline(cin,name);
    cout << endl;
    
    //Load the array to the binary file
    arrayToFile(name,arr,SIZE);
    
    //Load the binary file into the array
    fileToArray(name,arr,SIZE);
      
    //Exit stage right
    return 0;
}

//open the file, load the array into the binary file, close the file
void arrayToFile(string name, int *arr,int SIZE)
{
    //Open the file
    ofstream file;
    file.open(name.c_str(), ios::out | ios:: binary);
    
    //Input the array into the binary file
    for(int i=0; i < SIZE;i++)
        file.write((char*) &arr[i],sizeof(arr));
    
    //Display the results
    cout << "Original Array Contents " << endl;
    
    //Output array
    for(int i =0;i<SIZE;i++)
    {
        if((i%10)==0)
            cout << endl;
        cout << arr[i] << " ";
    }
    
    //Formatting
    cout << endl;
    
    //Close the file
    file.close();
}
  
//open the file, load the binary file into the array, close the file
void fileToArray(string name, int *arr,int SIZE)
{
    //Open the file again
    ifstream file;
    file.open(name.c_str(), ios::in | ios::out | ios:: binary);
    
    //Reset the array
    for(int i =0;i<SIZE;i++)
        arr[i] = 0;
     
    //Output the file contents to the array
    for(int i =0;i<SIZE;i++)
        file.read((char *)&arr[i],sizeof(arr));
    
    //Display the results
    cout << endl << "File Array Contents" << endl;
    
    //Output array
    for(int i =0;i<SIZE;i++)
    {
        if((i%10)==0)
            cout << endl;
        cout << arr[i] << " ";
    }
     
    //Close the file
    file.close(); 
}

