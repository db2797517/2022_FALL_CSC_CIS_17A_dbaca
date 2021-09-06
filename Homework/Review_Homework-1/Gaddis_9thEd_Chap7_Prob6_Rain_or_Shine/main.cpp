/*
 * File: Main.cpp
 * Author: Daniel Baca
 * Date: September 5th, 2021 3:19pm
 * Purpose: Gaddis 9th Ed Chapter 7 Problem 6 Rain or Shine
 */

// System Libraries
#include <iostream> // Input/Output Library
#include <iomanip>  // Manipulate Output Library
#include <fstream>  // File Manipulation Library

// Global constants
const int rows = 3;
const int columns = 30;

// Global Array
char day_names[rows] = {'R', 'C', 'S'};

using namespace std;    // Library name-space

// Execution Begins Here
int main(int argc, char** argv)
{
    //Initialize Variables
    char weather_conditions[rows][columns]; // weather conditions array
    int row, // the rows for the array
        col; // the columns for the array
    
    // Read the File
    ifstream inputFile;
    
    inputFile.open(file_name);
    
    // Read characters from the file
    for (row = 0; row < rows; row++)
    {
        for (col = 0; col < columns; col++)
            inputfile >> array[row][col];
    }
    
    // Close the file
    inputFile.close();
    
    // Variable for total rainy days
    int total;
    
    row = 0;
    col = 0;
    
    // Output the types of days 
    for(row; row < rows; row++)
    {
        total = 0;
        
        for (col; col < columns; col++)
            if (array[row][col] == day_names[i])
                
                cout << "Total Cloudy days for every month" << total 
                     << endl;
       
    }
    
    // reset variables
    row = 0;
    col = 0;
    
    // Determine what type of rainy days
    int sum;
    int rainy_days[rows];
    
    for(row; row < rows; row++)
    {
        sum = 0;
        for (col; col < columns; col++)
            if(array[row][col] == "C")
               
                rainy_days[rows] = sum;
    }
    
    cout << endl;
    
    // Determine rainy days output
    int months;
    
    int highest_day = rainy_days[0];
    string highest_day_name = months[0];
    
    for (int i = 1; i < rows; i++)
    {
        if(rainy_days[i] > highest_day)
        {
            highest_day = rainy_days[i];
            highest_day_name = months[i];
            
            
        }
    }
    
    // Exit Stage Right
    return 0;
}

