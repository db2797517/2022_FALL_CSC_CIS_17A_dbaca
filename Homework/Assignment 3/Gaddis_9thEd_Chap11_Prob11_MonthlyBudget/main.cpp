/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on September 15th , 2022, 2:20 PM
 * Purpose: 
  
 Write a program that has a MonthlyBudget structure designed to hold 
 each of these expense categories. The program should pass the 
 structure to a function that asks the user to enter the amounts spent
 in each budget category during a month. The program should then pass 
 the structure to a function that displays a report indicating the 
 amount over or under in each category, as well as the amount over or 
 under for the entire monthly budget.
 */
  
//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Struct of a given monthly budget
struct Monthly_Budget
{
    // Variables for each expense category
    float housing   =500.0;
    float utilities =150.0;
    float house_exp =65.0;
    float transp    =50.0;
    float food      =250.0;
    float medical   =30.0;
    float insurance =100.0;
    float enterta   =150.0;
    float clothing  =75.0;
    float misc      =50.0;
    float total     =1420;
};
    
//Function Prototypes
float getData(struct Monthly_Budget budget[]);
void prntData(struct Monthly_Budget budget[], float &);

//Execution Begins Here
int main(int argc, char** argv)
{
    //Declare Variable Data Types and Constants
    int SIZE=2;                         //The size of the array of structures
    float total;                        //The total spent by the user for the budget
    struct Monthly_Budget budget[SIZE]; //The two monthly budget structures holding original and input data
    
    //Get all of the input data and return the total spent
    total=getData(budget);
    
    //Print the results of the budget spent
    prntData(budget, total);

    //Exit stage right!
    return 0;
}

//Get all of the inputs into the structure and get return running total
float getData(struct Monthly_Budget budget[])
{
    float total = 0;
    
    cout << "Enter housing cost for the month:$" << endl;
     cin >> budget[1].housing;
     
    total += budget[1].housing;
        
    cout << "Enter utilities cost for the month:$" << endl;
     cin >>  budget[1].utilities;
     
    total += budget[1].utilities;
    
    cout << "Enter household expenses cost for the month:$" << endl;
     cin >>  budget[1].house_exp;
     
    total += budget[1].house_exp;
    
    cout << "Enter transportation cost for the month:$" << endl;
     cin >>  budget[1].transp;  
     
    total += budget[1].transp;
    
    cout << "Enter food cost for the month:$" << endl;
     cin >>  budget[1].food; 

    total += budget[1].food;
    
    cout << "Enter medical cost for the month:$" << endl;
     cin >>  budget[1].medical; 
     
    total += budget[1].medical;
    
    cout << "Enter insurance cost for the month:$" << endl;
     cin >>  budget[1].insurance; 
     
    total += budget[1].insurance;
    
    cout << "Enter entertainment cost for the month:$" << endl;
     cin >>  budget[1].enterta; 
     
    total += budget[1].enterta;
    
    cout << "Enter clothing cost for the month:$" << endl;
     cin >>  budget[1].clothing;
      
    total += budget[1].clothing;
    
    cout << "Enter miscellaneous cost for the month:$" << endl;
     cin >>  budget[1].misc;
     
    total += budget[1].misc;

    return total;
}

//Print the results of the data inputs
void prntData(struct Monthly_Budget budget[], float &total)
{  
    //Output result for housing cost spent
   cout << "Housing ";
   if(budget[0].housing == budget[1].housing)
   {
       cout << "Even" << endl;
   }
   else if(budget[0].housing < budget[1].housing)
   {
        cout << "Over" << endl;
   }
   else
   {
        cout << "Under" << endl;  
   }
   
    //Output result for utilities cost spent
   cout << "Utilities ";
   if(budget[0].utilities == budget[1].utilities)
   {
       cout << "Even" << endl;
   }
   else if(budget[0].utilities < budget[1].utilities)
   {
        cout << "Over" << endl;
   }
   else
   {
        cout << "Under" << endl;  
   }
   
    //Output result for household expenses cost spent
    cout << "Household Expenses ";
   if(budget[0].house_exp == budget[1].house_exp)
   {
       cout << "Even" << endl;
   }
   else if(budget[0].house_exp < budget[1].house_exp)
   {
        cout << "Over" << endl;
   }
   else
   {
        cout << "Under" << endl;  
   }
   
    //Output result transportation cost spent
    cout << "Transportation ";
   if(budget[0].transp == budget[1].transp)
   {
       cout << "Even" << endl;
   }
   else if(budget[0].transp < budget[1].transp)
   {
        cout << "Over" << endl;
   }
   else
   {
        cout << "Under" << endl;  
   }
   
    //Output result for food cost spent
    cout << "Food ";
   if(budget[0].food == budget[1].food)
   {
       cout << "Even" << endl;
   }
   else if(budget[0].food < budget[1].food)
   {
        cout << "Over" << endl;
   }
   else
   {
        cout << "Under" << endl;  
   }
   
    //Output result for medical cost spent
    cout << "Medical ";
   if(budget[0].medical == budget[1].medical)
   {
       cout << "Even" << endl;
   }
   else if(budget[0].medical < budget[1].medical)
   {
        cout << "Over" << endl;
   }
   else
   {
        cout << "Under" << endl;  
   }   
   
    //Output result for insurance cost spent
    cout << "Insurance ";
   if(budget[0].insurance == budget[1].insurance)
   {
       cout << "Even" << endl;
   }
   else if(budget[0].insurance < budget[1].insurance)
   {
        cout << "Over" << endl;
   }
   else
   {
        cout << "Under" << endl;  
   }   
   
     //Output result for entertainment cost spent
      cout << "Entertainment ";
   if(budget[0].enterta == budget[1].enterta)
   {
       cout << "Even" << endl;
   }
   else if(budget[0].enterta < budget[1].enterta)
   {
        cout << "Over" << endl;
   }
   else
   {
        cout << "Under" << endl;  
   }   
   
    //Output result for clothing cost spent
   cout << "Clothing ";
   if(budget[0].clothing== budget[1].clothing)
   {
       cout << "Even" << endl;
   }
   else if(budget[0].clothing < budget[1].clothing)
   {
        cout << "Over" << endl;
   }
   else
   {
        cout << "Under" << endl;  
   }   
   
     //Output result for miscellaneous cost spent
   cout << "Miscellaneous ";
   if(budget[0].misc == budget[1].misc)
   {
       cout << "Even" << endl;
   }
   else if(budget[0].misc < budget[1].misc)
   {
        cout << "Over" << endl;
   }
   else
   {
        cout << "Under" << endl;  
   } 
   
   //Output the overall spend over or under the total budget
   cout << "You were $" << fixed << showpoint << setprecision(2) << abs(budget[0].total - total);
   
   if(budget[0].total - total >= 0)
    cout << " under budget";
   else
    cout << " over budget";
    
}
