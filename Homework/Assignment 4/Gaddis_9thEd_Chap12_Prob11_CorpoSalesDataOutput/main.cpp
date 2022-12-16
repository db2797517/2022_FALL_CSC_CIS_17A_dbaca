/*  
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on October 10th, 2022, 3:47 PM
 * Purpose: Write a program that uses a structure to store the following data 
 * on a company division: 
 * - Division Name (such as East, West, North, or South)
 * - Quarter(1,2,3,4)
 * - Quarterly Sales 
 * The user should be asked for the four quarters’ sales figures for each 
 * division. The data for each quarter for each division should be written to 
 * a file. 
 * Input Validation: Do not accept negative numbers for any sales figures.
 */ 

//Libraries
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//No Global Constants
const int SIZE = 4;

//Function Prototypes - none

//Structure for all four divisions
struct Division
{
    string name[SIZE] = {"East", "West", "North", "South"}; //Name of each division
    int quarter[SIZE] = {1,2,3,4}; //Quarter number
    float qrt1; //Quarter 1 Sales
    float qrt2; //Quarter 2 Sales
    float qrt3; //Quarter 3 Sales
    float qrt4; //Quarter 4 Sales
};

void div_sales(struct Division div[]);
void file_output(struct Division div[]);

//Execution Begins Here
int main(int argc, char** argv)
{
    //Array of divisions holding all divisions data
    Division div[SIZE];

    //Call function to get input
    div_sales(div);
    
    //Call function to setup file
    file_output(div);

    //Exit stage right
    return 0;
}

//Function for getting input
void div_sales(struct Division div[])
{   
    //User input for all four divisions and all four quarters sales
    for(int i=0;i <div[0].quarter[3];i++)
    {
        cout << "     - Enter " << div[i].name[i] << " quarterly sales -" << endl;
        cout << "Q1" << " Sales: $";
         cin >> div[i].qrt1;
         
         if(div[i].qrt1 < 0)
         {
             cout << "Please enter Positive values > 0.";
             break;
         }
         
        cout << "Q2" << " Sales: $";
         cin >> div[i].qrt2;
         
         if(div[i].qrt2 < 0)
         {
             cout << "Please enter Positive values > 0.";
             break;
         } 
        cout << "Q3" << " Sales: $"; 
         cin >> div[i].qrt3;

         if(div[i].qrt3 < 0)
         {
             cout << "Please enter Positive values > 0.";
             break;
         }
         
        cout << "Q4" << " Sales: $"; 
         cin >> div[i].qrt4;
         
         if(div[i].qrt4 < 0)
         {
             cout << "Please enter Positive values > 0.";
             break;
         }      
        cout << endl;
    }
}
 
//Function for outputting results to the file
void file_output(struct Division div[])
{
    //Establish the file
    ofstream file;
    
    //Open the file
    file.open("Output.txt");
      
    //Input the data to the file
    for(int i=0;i <div[0].quarter[3];i++)
    {
        file << "     - " << div[i].name[i] << " Division quarterly sales -" << endl;
        file << "Q1" << " Sales: $";
        file << div[i].qrt1;
        file << "\nQ2" << " Sales: $";
        file << div[i].qrt2;
        file << "\nQ3" << " Sales: $"; 
        file << div[i].qrt3;
        file << "\nQ4" << " Sales: $"; 
        file << div[i].qrt4;
        file << "\n" << endl;
    }
    
    //Close the file
    file.close();
}

