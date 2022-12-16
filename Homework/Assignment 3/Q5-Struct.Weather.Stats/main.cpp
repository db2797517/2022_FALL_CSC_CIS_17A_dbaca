/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on September 14th, 2022, 4:29 pm
 * Purpose:  
 
Write a program that uses a structure to store the following weather data for a particular

month:

Month

Total Rainfall - Inches

High Temperature - Degrees Fahrenheit

Low Temperature -Degrees Fahrenheit

Average Temperature - Degrees Fahrenheit

The program should have an array of 12 structures to hold weather data for an

entire year. When the program runs, it should ask the user to enter data for each

month. (The average temperature should be calculated.) Once the data are entered

for all the months, the program should calculate and display the average monthly

rainfall, the total rainfall for the year, the highest and lowest temperatures for the

year (and the months they occurred in), and the average of all the monthly average

temperatures.

Input Validation: Only accept temperatures within the range between –100 and +140

degrees Fahrenheit.
 */
 
//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries - none

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes - none

//Struct for weather data
struct Weather_data
{
  string month;     // Name of the month
  float tot_rain;   // Total Rainfall - Inches
  float high_temp;  // High Temperature - Degrees Fahrenheit
  float low_temp;   // Low Temperature - Degrees Fahrenheit
  float ave_temp;   // Average temperature - Degrees Fahrenheit
  
};

// Execution Begins Here
int main()
{
    // Declare Variables
    int SIZE=12;            //Size of the array of structures
    float ave_mon_rain=0;   //The average monthly rainfall
    
struct Weather_data year_rec[SIZE]; //The array of structures for each month

    //Input all the data for the array of structures
    for(int i=0;i<SIZE;i++)
    {
        cin >> year_rec[i].month;
        cin >> year_rec[i].tot_rain;
        cin >> year_rec[i].low_temp;
        cin >> year_rec[i].high_temp;
        
        //Input Validation
        if(year_rec[i].low_temp > 140 || year_rec[i].low_temp < -100)
        {
            cout << "Please Enter a Low temperature in the range of -100 and 140." << endl;
            break;
        }
          
        //Input Validation  
        if(year_rec[i].high_temp > 140 || year_rec[i].high_temp < -100)
        {
            cout << "Please Enter a High temperature in the range of -100 and 140." << endl;
            break;
        }
    }
    
    //Get the average monthly rain total
    for(int i=0;i<SIZE;i++)
        ave_mon_rain += year_rec[i].tot_rain;
    
    //Calculate the average
    ave_mon_rain = ave_mon_rain / SIZE;
    
    //Display the average
    cout << "Average Rainfall " << fixed << showpoint << setprecision(1) << ave_mon_rain << " inches/month" << endl;
    
    //Find the smallest temperature
    int small = year_rec[0].low_temp;
    
    for(int i=0;i<SIZE;i++)
    {   
        if(year_rec[i].low_temp<small)
            small=year_rec[i].low_temp;
    }
    
    //Display the smallest temperature data
    for(int i=0;i<SIZE;i++)
    {   
        if(year_rec[i].low_temp==small)
            cout << "Lowest  Temperature " << year_rec[i].month 
                 << "  " << noshowpoint << setprecision(0)
                 << year_rec[i].low_temp << " Degrees Fahrenheit"
                 << endl;
    }
    
    //Find the highest temperature
    int high = year_rec[0].high_temp;
    
    for(int i=0;i<SIZE;i++)
    {   
        if(year_rec[i].high_temp>high)
            high=year_rec[i].high_temp;
    }
    
    //Display the highest temperature data
    for(int i=0;i<SIZE;i++)
    {   
        if(year_rec[i].high_temp==high)
            cout << "Highest Temperature " << year_rec[i].month 
                 << "  " << noshowpoint << setprecision(0)
                 << year_rec[i].high_temp << " Degrees Fahrenheit"
                 << endl;
    }
    
    //Find the average of the average monthly temperatures
    float ave_temp_ye=0;
    
    for(int i=0;i<SIZE;i++)
    {
        year_rec[i].ave_temp = (year_rec[i].low_temp + year_rec[i].high_temp) / 2;
    }
    for(int i=0;i<SIZE;i++)
    {
        ave_temp_ye += year_rec[i].ave_temp;
    }
    
    //Display the average
    cout << "Average Temperature for the year " << (ave_temp_ye/SIZE) << " Degrees Fahrenheit" << endl;
    
	//Exit
	return 0;
}