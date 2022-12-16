/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on September 15th, 2022, 9:32 pm
 * Purpose: 
 
Modify the program that you wrote for programming challenge 4 (weather statistics) 
so it defines an enumerated data type with enumerators for months
(JANUARY, FEBRUARY, so on). The program should use the enumerated type to step 
through the elements of the array.

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
  float tot_rain;   // Total rainfall for a month
  float high_temp;  // Highest rainfall for a month
  float low_temp;   // Lowest rainfall for a month
  float ave_temp;   // Average rainfall for a month
};

// Execution Begins Here
int main()
{
    // Declare Variables
    float ave_mon_rain=0;   //The average monthly rainfall
    
//Enumerated data representing month of the year
enum Months {January, February, March, April, May, June, July};
    
struct Weather_data year_rec[July]; //The array of structures for each month

    //Input all the data for the array of structures
    for(int i=0;i<July;i++)
    {
        cout << "Enter the total rainfall for the month:" << endl;
        cout << "Enter the high temp:" << endl;
        cout << "Enter the low temp:" << endl;       
        
        cin >> year_rec[i].tot_rain;
        cin >> year_rec[i].high_temp;
        cin >> year_rec[i].low_temp;
        
        //Input Validation
        if(year_rec[i].low_temp > 140 || year_rec[i].low_temp < -100)
        {
            cout << "Please Enter a Low temperature in the range of -100 and 140." << endl;
            break;
        }
          
        //Input Validation  
        if(year_rec[i].high_temp > 140 || year_rec[i].high_temp < -100)
        {
            cout << "Please Enter a Low temperature in the range of -100 and 140." << endl;
            break;
        }
    }
    
    //Get the average monthly rain total
    for(int i=0;i<July;i++)
        ave_mon_rain += year_rec[i].tot_rain;
    
    //Calculate the average
    ave_mon_rain = ave_mon_rain / July;
    
    //Display the average
    cout << "Average monthly rainfall:" << fixed << showpoint << setprecision(2) << ave_mon_rain << endl;
    
    //Find the highest temperature
    int high = year_rec[0].high_temp;
    
    for(int i=0;i<July;i++)
    {   
        if(year_rec[i].high_temp>high)
            high=year_rec[i].high_temp;
    }
    
    //Display the highest temperature data
    for(int i=0;i<July;i++)
    {   
        if(year_rec[i].high_temp==high)
            cout << "High Temp:"
                 << noshowpoint << setprecision(0)
                 << year_rec[i].high_temp << endl;
    }
    
        //Find the smallest temperature
    int small = year_rec[0].low_temp;
    
    for(int i=0;i<July;i++)
    {   
        if(year_rec[i].low_temp<small)
            small=year_rec[i].low_temp;
    }
    
    //Display the smallest temperature data
    for(int i=0;i<July;i++)
    {   
        if(year_rec[i].low_temp==small)
            cout << "Low Temp:"
                 << noshowpoint << setprecision(0)
                 << year_rec[i].low_temp << endl;
    }
    
    //Find the average of the average monthly temperatures
    float ave_temp_ye=0;
    
    for(int i=0;i<July;i++)
    {
        year_rec[i].ave_temp = (year_rec[i].low_temp + year_rec[i].high_temp) / 2;
    }
    for(int i=0;i<July;i++)
    {
        ave_temp_ye += year_rec[i].ave_temp;
    }
    
    //Display the average
    cout << "Average Temp:" << fixed << showpoint << setprecision(1) << ave_temp_ye / July;
    
	//Exit
	return 0;
}