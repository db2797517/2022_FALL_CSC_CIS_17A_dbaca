/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on September 16th, 2022, 1:56 pm
 * Purpose:  
 
Write a program that uses a structure to store the following data on a company division:

Division Name(such as East, West, North, or South)

First-Quarter Sales

Second-Quarter Sales
 
Third-Quarter Sales

Fourth-Quarter Sales

Total Annual Sales

Average Quarterly Sales
 
The program should use four variables of this structure. Each variable should represent on of the following corporate divisions: 
East, West, North, and South. The user should be asked for the four quarters' sales figures for each division. Each division's 
total and average sales should be calculated and stored in the appropriate member of each structure variable. These figures 
should then be displayed on the screen.
 */
 
//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
    struct Company_div
    {
        string ary[4] = {"North", "West", "East", "South"}; // Names of each divison
        float quat1sales;   // Quater 1 sales
        float quat2sales;   // Quater 2 sales
        float quat3sales;   // Quater 3 sales
        float quat4sales;   // Quater 4 sales
        float totsales;     // Total annual sales
        float avequasales;  // Average Quarterly sales
    };

//Execution Begins Here
int main(int argc, char** argv)
{
    //Declare Variable Data Types and Constants
    struct Company_div East_div;    // The data structure for the east company division
    struct Company_div West_div;    // The data structure for the west company division
    struct Company_div North_div;   // The data structure for the north company division
    struct Company_div South_div;   // The data structure for the south company division
    int count =0;
    
    //Display the prompts for the north division input and output
    cout << North_div.ary[count] << endl;
    cout << "Enter first-quarter sales:" << endl;
     cin >> North_div.quat1sales;
    cout << "Enter second-quarter sales:" << endl;
     cin >> North_div.quat2sales;
    cout << "Enter third-quarter sales:" << endl;
     cin >> North_div.quat3sales;
    cout << "Enter fourth-quarter sales:" << endl;
     cin >> North_div.quat4sales;
    cout << "Total Annual sales:$";
    
    // Counter for name of division array
    count++;
    
    //Calculate the total sales
    North_div.totsales = North_div.quat1sales+North_div.quat2sales+North_div.quat3sales+North_div.quat4sales;

    //Display the total sales
    cout << fixed << showpoint << setprecision(2) << North_div.totsales << endl;
     
    cout << "Average Quarterly Sales:$";
    
    // Calculate the average quarterly sales
    North_div.avequasales =  North_div.totsales / 4;
    
    // Display the average quarterly sales
    cout << North_div.avequasales << endl;
    
    //Display the prompts for the west division input and output
    cout << West_div.ary[count] << endl;
    cout << "Enter first-quarter sales:" << endl;
     cin >> West_div.quat1sales;
    cout << "Enter second-quarter sales:" << endl;
     cin >> West_div.quat2sales;
    cout << "Enter third-quarter sales:" << endl;
     cin >> West_div.quat3sales;
    cout << "Enter fourth-quarter sales:" << endl;
     cin >> West_div.quat4sales;
    cout << "Total Annual sales:$";
    
    // Counter for name of division array
    count++;
    
    //Calculate the total sales
    West_div.totsales = West_div.quat1sales+West_div.quat2sales+West_div.quat3sales+West_div.quat4sales;

    //Display the total sales
    cout << fixed << showpoint << setprecision(2) << West_div.totsales << endl;
     
    cout << "Average Quarterly Sales:$";
    
    // Calculate the average quarterly sales
    West_div.avequasales =  West_div.totsales / 4;
    
    // Display the average quarterly sales
    cout << West_div.avequasales << endl;
     
    //Display the prompts for the east division input and output
    cout << East_div.ary[count] << endl;
    cout << "Enter first-quarter sales:" << endl;
     cin >> East_div.quat1sales;
    cout << "Enter second-quarter sales:" << endl;
     cin >> East_div.quat2sales;
    cout << "Enter third-quarter sales:" << endl;
     cin >> East_div.quat3sales;
    cout << "Enter fourth-quarter sales:" << endl;
     cin >> East_div.quat4sales;
    cout << "Total Annual sales:$";
    
    // Counter for name of division array
    count++;
    
    //Calculate the total sales
    East_div.totsales = East_div.quat1sales+East_div.quat2sales+East_div.quat3sales+East_div.quat4sales;

    //Display the total sales
    cout << fixed << showpoint << setprecision(2) << East_div.totsales << endl;
     
    cout << "Average Quarterly Sales:$";
    
    // Calculate the average quarterly sales
    East_div.avequasales =  East_div.totsales / 4;
    
    // Display the average quarterly sales
    cout << East_div.avequasales << endl;
    
    //Display the prompts for the south division input and output
    cout << South_div.ary[count] << endl;
    cout << "Enter first-quarter sales:" << endl;
     cin >> South_div.quat1sales;
    cout << "Enter second-quarter sales:" << endl;
     cin >> South_div.quat2sales;
    cout << "Enter third-quarter sales:" << endl;
     cin >> South_div.quat3sales;
    cout << "Enter fourth-quarter sales:" << endl;
     cin >> South_div.quat4sales;
    cout << "Total Annual sales:$";
    
    // Counter for name of division array
    count++;
      
    //Calculate the total sales
    South_div.totsales = South_div.quat1sales+South_div.quat2sales+South_div.quat3sales+South_div.quat4sales;

    //Display the total sales
    cout << fixed << showpoint << setprecision(2) << South_div.totsales << endl;
     
    cout << "Average Quarterly Sales:$";
    
    // Calculate the average quarterly sales
    South_div.avequasales =  South_div.totsales / 4;
    
    // Display the average quarterly sales
    cout << South_div.avequasales;
    
    //Exit stage right!
    return 0;
}