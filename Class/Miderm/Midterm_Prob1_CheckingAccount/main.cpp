/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on October 17th, 2022, 4:00 PM
 * Purpose: 
 * Develop an application using a structures for a customer that will determine 
 * if he/she has exceeded his/her checking account balance. For each customer, 
 * the following facts are available and the structure should include in the 
 * following order:
 * • a. Account number (Five digits only, i.e. test for this)
 * • b. Name
 * • c. Address
 * • d. Balance at the beginning of the month
 * • e. Record all checks written by this customer this month Loop until 
 *     customer is through entering checks. Use dynamic Array.
 * • f. Record all deposits credited to this customer’s account this month. Loop
 *      until customer is through entering deposits. Use Dynamic Array.
 * Dynamically create the structure. The program should input each of these 
 * facts from input dialogs, store in a structure,calculate the new balance, 
 * display the new balance and debit the account $35 if overdrawn. Also, if 
 * overdrawn, tell the customer the additional $35 fee has been accessed and 
 * what the balance would be with this fee included. Make sure to output the 
 * contents of the structure.
 */  
 
//Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
 
//No Global Constants - none
 
//Function Prototypes - none
 
//Dynamic Checking Account Structure
struct Checking
{ 
    string acc_num;         //The number of the account
    string name;            //The user's name in the account
    string address;         //The address of the user in the account
    float balance;          //The initial balance give by the user
    int num_of_chks;        //The total number of checks inputted
    int num_of_deps;        //The total number of deposits inputted
    float * num_chks = new float[num_of_chks]; //Dynamic array for each check amount
    float * num_deps = new float[num_of_deps]; //Dynamic array for each deposit amount
};
   
//Execution Begins Here
int main(int argc, char** argv) 
{
    struct Checking *customer;  //Struct variable of the customer checking 
    customer = new Checking;    //account, which is Dynamically created
    
    float total[2];         //The array holding the total amount from all checks 
                            //written and the total amount deposited into 
                            //the account.
    bool invalid =false;    //Bool value for input validation loop
    
    //Prompt the user to enter the account number
    cout << "          -Please Enter Account Information-" << endl;
     
    //Initialize the total array
    for(int i=0;i<2;i++)
        total[i] =0;
 
    //Input validation for account number
     do
    { 
        //Set bool value
        invalid = false;
         
        //Resubmit the account number
        cout << " Account Number: ";
         cin >> customer->acc_num;
 
        //Determine if the string has any letters in it
        for(int i=0;i<customer->acc_num.length();i++)
             if(isalpha(customer->acc_num[i]))
                 invalid = true;
         
        //Display the input validation result
        if(customer->acc_num.length() != 5 || invalid)
        cout << endl
             << " Please enter an account number with exactly five digits"
             << " and no letters. Thank You." << endl << endl;
         
    }while(customer->acc_num.length() != 5 || invalid);
     
        //Prompt the user to enter the account name
        cout << "   Account Name: ";
        cin.ignore();
        getline(cin,customer->name);   
        
        //Prompt the user to enter the account address
        cout << "Account Address: ";
        getline(cin,customer->address);

        //Prompt the user to enter the initial account balance
        cout << "Account Balance: $";
         cin >> (cin,customer->balance);

        //Prompt user to enter the number of checks written
        cout << " Enter the number of checks to write: ";
         cin >> customer->num_of_chks; 
         
        //Prompt user to enter the number of deposits made
        cout << "Enter the number of deposits to make: ";
         cin >> customer->num_of_deps; 

        //Prompt and Input number amount for each check
        cout << "Enter the amount of each check = " << endl;
        for(int i = 0; i < customer->num_of_chks;i++)
        {
            //Read the checks written
            cout << i+1 << ".) $";
             cin >> customer->num_chks[i];
        }
        
        // Prompt and Input number amount for each deposit
        cout << "Enter the amount of each deposit = " << endl;
        for(int i = 0; i < customer->num_of_deps;i++)
        {
            //Read the checks written
            cout << i+1 << ".) $";
             cin >> customer->num_deps[i];
        }
         
        // Establish numeric output formatting
        cout << fixed << showpoint << setprecision(2);
        
        //Output all account information
        cout << "          -All Account Information-" << endl;
        cout << "  Account Number: " << customer->acc_num << endl;
        cout << "    Account Name: " << customer->name << endl;
        cout << " Account Address: " << customer->address << endl;
        cout << " Account Balance: $" << customer->balance << endl;
        cout << " Number of checks written: " << customer->num_of_chks << endl;
        cout << "  Number of deposits made: " << customer->num_of_deps << endl;
        cout << "  Checks Written: ";

        //Gather running total of amount in checks deposited and display checks
        for(int i=0;i<customer->num_of_chks;i++)
        {
            total[0] += customer->num_chks[i];
            cout << "$" << customer->num_chks[i] << " ";
        }

        cout << endl << "   Deposits Made: ";

        //Gather running total of amount deposited and display amount deposited
        for(int i=0;i<customer->num_of_deps;i++)
        {
            total[1] += customer->num_deps[i];
            cout << "$" << customer->num_deps[i] << " ";
        }

        //Calculate the new account balance
        customer->balance -= total[0];
        customer->balance += total[1];
        
        //Output the new account balance
        cout << endl << endl << "New Customer Balance: $" << fixed << showpoint 
             << setprecision(2) << customer->balance << endl;

        //Check to see if the account has overdrawn
        if(customer->balance < 0)
        {
            //Subtract $25 because of overdraft
            customer->balance -= 35;
             
            //Display overdraft result
            cout << endl << "Your account has been overdrawn, $35 has been "
                 << "removed from your balance." << endl << endl
                 << "Final Balance: $" << customer->balance;
        }
        else 
        { 
            //Display end message if there is no overdraft
            cout << endl << "Thank you, come again.";
        }
        
    // Deallocate memory
    delete[] customer;
    delete[] customer->num_chks;
    delete[] customer->num_deps;
    
    //Exit Stage Right
    return 0;
}

  


