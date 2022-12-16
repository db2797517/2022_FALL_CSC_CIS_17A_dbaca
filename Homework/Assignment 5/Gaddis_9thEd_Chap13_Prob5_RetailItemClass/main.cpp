/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on November 13th, 2022, 3:12 PM
 * Purpose: 
 *  
 * Write a class named RetailItem that holds data about an item in a retail 
 * store. The class should have the following member variables:
 * • description -a string that holds a brief description of the item.
 * • unitsOnHand - an int that holds the number of units currently in inventory. 
 * • price - a double that holds the item’s retail price.
 * 
 * Write a constructor that accepts arguments for each member variable, 
 * appropriate mutator methods that store values in these member variables, and 
 * accessor functions that return the values in these member variables. Once you
 * have written the class, write a separate program that creates three 
 * RetailItem objects and stores the following data in them:
 * 
 * Description      Units on Hand     Price
 * Jacket             12              59.95
 * Designer Jeans     40              34.95
 * Shirt              20              24.95
 */
 
//System Libraries
#include "RetailItem.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <cstring>
using namespace std;

//Class is in the "RetailItem.h" file
 
//Execution of Code Begins Here
int main(int argc, char** argv) 
{  
    //All three RetailItem objects
    RetailItem item1("Jacket", 12, 59.95);
    RetailItem item2("Designer Jeans", 40, 34.95);
    RetailItem item3("Shirt", 20, 24.95);
    
    //Formatting
    cout << endl;
     
    //Output the information for Item #1
    cout << "         -- Item # 1 --" << endl
         << "    Description: " << item1.getdescription() << endl
         << "  Units on Hand: " << item1.getunits() << endl            
         << "          Price: " << item1.getprice() << endl << endl;

    //Output the information for Item #2
    cout << "         -- Item # 2 --" << endl
         << "    Description: " << item2.getdescription() << endl
         << "  Units on Hand: " << item2.getunits() << endl            
         << "          Price: " << item2.getprice() << endl << endl; 

    //Output the information for Item #3
    cout << "         -- Item # 3 --" << endl
         << "    Description: " << item3.getdescription() << endl
         << "  Units on Hand: " << item3.getunits() << endl            
         << "          Price: " << item3.getprice() << endl << endl;         
     
    //Exit stage right
    return 0; 
}    

 


