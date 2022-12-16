/*
 * File: Main.cpp
 * Author: Daniel Baca
 * Date: September 3rd, 2022 3:19pm
 * Purpose: Display the number of Rainy, Cloudy and Sunny days for each month 
 * and the entire three month period. Then determine which month has the highest
 * number of rainy days and display all that data.
 */

// System Libraries
#include <iostream> // Input/Output Library
#include <iomanip>  // Manipulate Output Library
#include <fstream>  // File Manipulation Library

// Global constants

using namespace std;    // Library name-space
 
// Execution Begins Here
int main(int argc, char** argv)
{
    //Initialize Variables
    const int rows = 3;      // Number of rows for arrays
    const int columns = 30;  // Number of columns for the array
    char weather[rows][columns]; // weather conditions array
    char day_names[rows] = {'R', 'C', 'S'}; // Letters for the types of day
    string months[rows] = {"June", "July", "August"}; // Names of the months
    string weather_names[rows] = {"Rainy", "Cloudy", "Sunny"}; // Names of 
                                                               // weathery days
    int num[rows][rows]; // Array holding Weather day counts for each month
    int nu[rows];        // Array holding total count for each type of weather
    
    int month; // Value for the month in the array

    int row, // the rows for the array
        col; // the columns for the array
    
    // Open the File
    ifstream file;
    
    // Find the file
    file.open("RainOrShine.txt");
    
    //Check to see if the file opens
    if(!file)
        cout << "Could not find the file. Please enter the file necessary." 
             << endl;
    
    // Read characters from the file
    for (row = 0; row < rows; row++)
    {
        for (col = 0; col < columns; col++)
            file >> weather[row][col];
    }

    // Close the file
    file.close();
    
    //Create total counter variable
    int total;
    
    //Gather the values for each kind of weather for each month
    for (int month =0; month < rows; month++)
    {
        for (row = 0; row < rows; row++)
        {
            total = 0;
            for (col = 0; col < columns; col++)
            {
                if(day_names[month] == weather[row][col])
                    total++;
                num[row][month] = total;
            }
        }
    }
    
    // Output the values for each kind of weather for each month
    for (row = 0; row < rows; row++)
    {
        
        cout << " --" << months[row] << "-- ";
        
        for (month = 0; month < rows; month++)
            cout << endl << weather_names[month] << " days: " 
                 << num[row][month];
        
        cout << endl;
    } 
    
    // Adjust Formatting
    cout << endl;
    
    // Gather and output the values for the total days of each kind of weather
    for (row = 0; row < rows; row++)
    {
        total = 0;
        
        for (month = 0; month < rows; month++)
            total+= num[month][row];
        
        nu[row]=total;
        cout << "Total " <<weather_names[row] << " days: " << total << endl;
    }
      
    // Format Output
    cout << endl;
    
    // Find the month with the highest number of rainy days
    int j=0;
    int max = num[j][0];
    for( j =0; j<rows; j++)
        if(num[j][0] > max)
            max = num[j][0];
    
    // Output the month with the highest number of rainy days
        for(int j =0; j<rows; j++)
        if(max == num[j][0])
            cout << months[j] << " had the highest number of rainy days at " 
                 << max << " days.";
    
    // Exit Stage Right
    return 0;
}

