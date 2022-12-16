/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on November 13th, 2022, 4:30 PM
 * 
 * Purpose: 
 * 
 * Design an Inventory class that can hold information and calculate data for 
 * items in a retail store's inventory. The class should have the following
 * private member variables.
 * 
 * Variable name:
 * itemNumber-- An int that holds the item's item number
 * quantity-- An int for holding the quantity of the items on hand
 * cost-- A double for holding the wholesale per-unit cost of the item 
 * totalcost-- A double for holding the total inventory cost of the item
 * 
 * The class should have the following public member functions
 *  
 * Member function
 * Default constructor- Sets all the member variables to 0.
 * Constructor #2- Accepts an items number, cost, and quantity, as arguments. 
 *                 The function should copy these values to the appropriate 
 *                 member variables and then call the setTotalCost Function
 * setItemNumber-- Accepts an integer argument that is copied into the itemNumber member variable
 * setQuantity- Accepts an integer argument that is copied into the quantity member variable
 * setCost-- Accepts an float argument that is copied into the cost member variable
 * setTotalCost -- Calculates the total inventory cost for the item 
 *                 (quantity times cost) and stores the result in total cost
 * getItemNumber--Returns the value in ItemNumber
 * getQuantity- Returns the value in quantity
 * getCost-- Returns the value in cost
 * getTotalCost-- Return the value in totalCost 
 * 
 * Demonstrate the class in a driver program. Input Validation: Do not accept negative values for item number, 
 * quantity, or cost.
 */
  
//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <cstring>
using namespace std;

//RetailItem Class 
class Inventory
{
    
private:  
    
    //Class variables
    int itemn; //Int that holds the item's item number
    int quan;  //Int for holding the quantity of the items on hand
    float cost; //float for holding the wholesale per-unit cost of the item
    float totalc; //float for holding the total inventory cost of the item 
                   //(calculated as quantity times cost)
    
public:  
    
    //Default constructor
    Inventory()
    {
        //Initialize all variables
        itemn = 0;
        quan = 0;
        cost = 0;
        totalc = 0;        
    } 
    
    //Initialization constructor
    Inventory(int i, int q, float c)
    {
        //Set everything equal to input
        itemn = i;
        quan = q;
        cost = c;
        
        //Call the function to calculate the total cost
        setTotalCost();
    } 
    
    //Mutator functions
    void setItemnumber(int i)
        {   itemn = i; }
    
    void setQuantity(int q)
        {   quan = q;  }
    
    void setCost(float c)
        {   cost = c;    }
    
    void setTotalCost()
        {   totalc = quan * cost;    }
    
    //Accessor Functions
    int getItemNumber()
        {   return itemn;  }
    
    int getQuantity()
        {   return quan;   }
        
    float getCost()
        {   return cost;   }
    
    float getTotalCost()
        {   return totalc;   }      
};

//Execution of Code Begins Here
int main(int argc, char** argv) 
{  
    //Declare Variables
    int itemn = 0, quan =0;     //Ints for the item number and quantity of items
    float cost = 0, totalc = 0; // Floats for the cost and total cost of items
    
    //Formatting
    cout << endl;
    
    //Prompt the user for item number   
    cout << "  Item Number: ";
     cin >> itemn;
    
    //Input validation for item number
    while(itemn < 0)
    {
       cout << endl << "  Please enter a non-negative value." << endl << endl;
       cout << "  Item Number: ";
        cin >> itemn;
    } 

    //Prompt the user for quantity of item     
    cout << "     Quantity: ";
     cin >> quan;
     
    //Input validation for item number
    while(quan < 0)
    {
       cout << endl << "  Please enter a non-negative value." << endl << endl;
       cout << "     Quantity: ";
        cin >> quan;
    }
    
    //Prompt the user for the cost of item
    cout << "         Cost: $";
     cin >> cost;
     
    //Input validation for item number     
    while(cost < 0)
    {
       cout << endl << "  Please enter a non-negative value." << endl << endl;
       cout << "         Cost: $";
        cin >> cost;
    }
     
    Inventory item(itemn,quan,cost); //Object for the inventory class
    
    //Output the total cost of the item
    cout << endl << fixed << showpoint << setprecision(2) << "   Total cost: $" 
         << item.getTotalCost();
         
    //Exit stage right
    return 0;  
}    




 