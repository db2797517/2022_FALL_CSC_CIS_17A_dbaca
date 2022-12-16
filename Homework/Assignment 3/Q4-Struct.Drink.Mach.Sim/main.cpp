/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on September 16th, 2022, 4:56 PM
 * Purpose: 
  
Write a program that simulates a soft drink machine. The program should use a structure
that stores the following data:
Drink Name
Drink Cost
Number of Drinks in Machine
The program should create an array of five structures. The elements should be initialized
with the following data:
Drink Name - Cost - Number in Machine
Cola .75 20
Root Beer .75 20
Lemon-Lime .75 20
Grape Soda .80 20
Cream Soda .80 20 
Each time the program runs, it should enter a loop that performs the following
steps: A list of drinks is displayed on the screen. The user should be allowed to
either quit the program or pick a drink. If the user selects a drink, he or she will
next enter the amount of money that is to be inserted into the drink machine. The
program should display the amount of change that would be returned and subtract
one from the number of that drink left in the machine. If the user selects a drink that
has sold out, a message should be displayed. The loop then repeats. When the user
chooses to quit the program it should display the total amount of money the
machine earned.
Input Validation: When the user enters an amount of money, do not accept negative
values, or values greater than $1.00. 
 */
 
//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Struct for the drink machine
struct Soda_machine
{
    string drk_name;
    float drk_cost;
    float num_of_drks;
};

//Execution Begins Here
int main(int argc, char** argv) 
{
    //Declare Variables
    int SIZE=5;     //Number of available sodas
    string soda;    //The input name of the soda
    float money;    //The money input by user
    float total=0;  //The total amont of money the machine earned
    
    //Struct info for all of the sodas
    struct Soda_machine drinks[SIZE] = {{"Cola", .75, 20}, {"Root Beer", .75, 20}, {"Lemon-Lime", .75, 20},
                                        {"Grape Soda", .80, 20}, {"Cream Soda", .80, 20}};
    
    //Input the soda name and money spent
    getline(cin, soda);
    cin >> money;
    
    if(money > -1 && money < 101) 
    {
        //Display the soda machine menus and output
        do
        {
            //Set money value into cents
    	    money /=100;
    	
    	    //Display the soda menu
            for(int i=0; i<SIZE;i++)
            {
                if(i<SIZE-4)
                {
                cout <<drinks[i].drk_name << setw(9) << (drinks[i].drk_cost*100) ;
                cout << "  " << drinks[i].num_of_drks << endl;
                }
                else if(i<SIZE-3)
                {
                cout <<drinks[i].drk_name << setw(4) << (drinks[i].drk_cost*100) ;
                cout << "  " << drinks[i].num_of_drks << endl;
                }
                else if(i<SIZE-2)
                {
                cout <<drinks[i].drk_name << setw(3) << (drinks[i].drk_cost*100) ;
                cout << "  " << drinks[i].num_of_drks << endl;
                }
                else if(i<SIZE-1)
                {
                cout <<drinks[i].drk_name << setw(3) << (drinks[i].drk_cost*100) ;
                cout << "  " << drinks[i].num_of_drks << endl;
                }
                else if(i<SIZE)
                {
                cout <<drinks[i].drk_name << setw(3) << (drinks[i].drk_cost*100) ;
                cout << "  " << drinks[i].num_of_drks << endl;
                }
            }
        
            cout << "Quit" << endl;
        
            //Caulate the running total, change back and subtract 1 from total number of drinks
            for(int i=0; i<SIZE;i++)
            {
                if(drinks[i].drk_name == soda)
                {
                    
                    total += drinks[i].drk_cost;
                    
                    money -= drinks[i].drk_cost;
                    
                    drinks[i].num_of_drks -= 1;
                }
            }
            
            //Display the change
            cout << (money * 100) << endl;
            
            //Reset values for loop
            money = 0;
            
            cin.ignore();
            
            getline(cin, soda);
            cin >> money;
            
            if(money < 0 || money > 100)
            {
                cout << "Input not valid, try again." << endl;
                break; 
            }
        
        //Set flag value for the loop 
        }while(soda != "Quit" && soda != "quit");
    }
    else
            cout << "Input not valid, try again." << endl;

//Output the final soda menu with total money machine earned
    for(int i=0;i<SIZE;i++)
    {
	    if(soda == "Quit" || soda == "quit")
	    {
            if(i<SIZE-4)
            {
            cout <<drinks[i].drk_name << setw(9) << (drinks[i].drk_cost*100) ;
            cout << "  " << drinks[i].num_of_drks << endl;
            }
            else if(i<SIZE-3)
            {
            cout <<drinks[i].drk_name << setw(4) << (drinks[i].drk_cost*100) ;
            cout << "  " << drinks[i].num_of_drks << endl;
            }
            else if(i<SIZE-2)
            {
            cout <<drinks[i].drk_name << setw(3) << (drinks[i].drk_cost*100) ;
            cout << "  " << drinks[i].num_of_drks << endl;
            }
            else if(i<SIZE-1)
            {
            cout <<drinks[i].drk_name << setw(3) << (drinks[i].drk_cost*100) ;
            cout << "  " << drinks[i].num_of_drks << endl;
            }
            else if(i<SIZE)
            {
            cout <<drinks[i].drk_name << setw(3) << (drinks[i].drk_cost*100) ;
            cout << "  " << drinks[i].num_of_drks << endl;
            }
	    }
    }
                cout << "Quit" << endl;
                
                cout << (total*100) << endl;

    //Exit stage right!
    return 0;
}