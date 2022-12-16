/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Date: September 3, 2022, 7:03 PM
 * Purpose: Use a binary search to find a string in an array.
 */

//System Libraries
#include<iostream> // Input/Output Libraries
using namespace std;    // Library Name-Space

// Functions

//swap the content of a and b
void swapping(string &a, string &b) 
{      
   string temp;
   temp = a;
   a = b;
   b = temp;
}

// Use selection sort to sort the array
void selectionSort(string names[], int size) 
{
   int i, j, min;
   for(i = 0; i<(size-1); i++)
   {
      min = i;   //get index of minimum data
      for(j = i+1; j<size; j++)
         if(names[j] < names[min])
            min = j;
         //placing in correct position
         swap(names[i], names[min]);
   }
}

// Use the binary search to search strings
int binarySearch(string names[], int size, string name)
{
    int first = 0,
        last = size - 1,  // 19
        middle,
        position = -1;
    bool found = false;

    while (!found && first <= last)
    {
        middle = (first + last) / 2; // (0 + 19) / 2 = 8

        if (names[middle] == name)     // Middle
        {
            position = middle;
            found = true;
        }
        else if (names[middle] > name)   // Lower Half
            last = middle - 1; // 8 - 1 = 7  // 8, 4, 4, 3, 2, 3, 
        else                                  // Upper Half
            first = middle + 1;  // 8 + 1 = 9
        
    }
    return position;
}

// Execution begins here
int main() 
{
    // initialize variables
    int num_of_names = 20;  // number of names total
    string name;    // user input name
    int result;     // bool value for search
    string names[num_of_names] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                               "Griffin, Jim", "Stamey, Marty", "Rose, Geri", 
                               "Taylor, Terri", "Johnson, Jill", 
                               "Allison, Jeff", "Looney, Joe", "Wolfe, Bill", 
                               "James, Jean", "Weaver, Jim", "Pore, Bob", 
                               "Rutherford, Greg", "Javens, Renee", 
                               "Harrison, Rose", "Setzer, Cathy",
                               "Pike, Gordon", "Holland, Beth" };
      
    // Prompt user to enter a name to search
    cout << "Please Enter a name: ";
    getline(cin,name);
   
    // Sort names
    selectionSort(names, num_of_names);
   
    //Output sorted names;
    cout << endl << "Sorted Names:"
         << endl << "----------------" << endl;
    for(int i=0;i<20;i++)
       cout << names[i] << endl;
   
   // Search for name
   result = binarySearch(names, num_of_names, name);
   
   // Output Result
   if (result != -1)
       cout << endl << name << " has been found." << endl;
   else
       cout << endl << name << " has not been found." << endl;
   
   //Exit Stage Right
   return 0;
}