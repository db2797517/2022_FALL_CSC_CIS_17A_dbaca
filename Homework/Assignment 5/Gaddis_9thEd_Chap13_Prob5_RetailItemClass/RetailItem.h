/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RetailItem.h
 * Author: Daniel Baca
 *
 * Created on November 13, 2022, 3:17 PM
 */

#ifndef RETAILITEM_H
#define RETAILITEM_H

#include <string>
using namespace std;

//RetailItem Class 
class RetailItem
{
    
private:  
    
    //Class variables
    string description; //String that holds a brief description of the item
    int units; //Int that holds the number of units currently in inventory
    float price;    //float that holds the item's retail price
    
public:  
    
    //Initialization constructor
    RetailItem(string d, int u, float p)
    {
        description = d;
        units = u;
        price = p;       
    } 
   
    //Mutator functions
    void setdescription(string d)
        {   description = d; }
    
    void setunits(int u)
        {   units = u;  }
    
    void setprice(float p)
        {   price = p;    }
    
    //Accessor Functions
    string getdescription()
        {   return description;  }
    
    int getunits()
        {   return units;   }
        
    float getprice()
        {   return price;   }
        
};

#endif /* RETAILITEM_H */

