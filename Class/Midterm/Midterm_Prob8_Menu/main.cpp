/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on October 18th, 2022, 8:06 PM
 * 
 * Purpose: Menu Program showing all of the midterm problems.
 * 
 */

//System Libraries
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
 
//User Libraries
 
//Global Constants

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

//Structure of gross play for each employee
struct GrossPay
{
    string name;
    int hours_wrk;
    int rt_pay;
    int grs_pay;
};

struct Prime  // Prime numbers storage structure
{
    unsigned short prime;
    unsigned char power;
};  

struct Primes // Prime numbers structure holding the prime number info arrays
{
    unsigned char nPrimes;

    Prime *prime;
};
 
//Functions for the menu and each problem
void menu();
void prblm1();
void prblm2();
void prblm3();
void prblm4();
void prblm5();
void prblm6();
void prblm7();

//Function Prototypes
Primes *factor(int);        //Function to find factored data and return it
void prntPrm(Primes * prm); //Function to output factored output
 
//Execution Begins Here
int main(int argc, char** argv) 
{
    //Initialize Variables
    char choice; //Number input for menu
    
    //Loop to use each program
    do
    {
        //Display the menu
        menu();
        
        //Prompt user to enter menu input
        cout << endl << "  Enter a menu input: ";
         cin >> choice;
        cout << endl;
        
        //Switch used to determine what program to run
        switch(choice)
        {
            case '1':{prblm1();break;}
            case '2':{prblm2();break;}
            case '3':{prblm3();break;}
            case '4':{prblm4();break;}
            case '5':{prblm5();break;}
            case '6':{prblm6();break;}
            case '7':{prblm7();break;}
           default: cout << "  - Exiting Menu -" << endl;                            
        }
        
    }while(choice>='1'&&choice<='7');
    //Run loop until input to end program has been input
    
    //Exit stage right!
    return 0;
} 
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Menu
//Input:  -> N/A
//Output: -> Menu for the all of the problems
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void menu() 
{
    //Display menu
    cout<<endl<<"   Choose from the following Menu"<<endl;
    cout<<"   Type 1 for Problem 1"<<endl;
    cout<<"   Type 2 for Problem 2"<<endl;
    cout<<"   Type 3 for Problem 3"<<endl;  
    cout<<"   Type 4 for Problem 4"<<endl; 
    cout<<"   Type 5 for Problem 5"<<endl;    
    cout<<"   Type 6 for Problem 6"<<endl; 
    cout<<"   Type 7 for Problem 7"<<endl<<endl;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 1
//Input:  -> N/A
//Output: -> The entire working Checking account program
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm1()
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
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 2
//Input:  -> N/A
//Output: -> The entire working Gross Pay / Check program
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm2()
{
    //Declare Variables
    int num_emp = 0;         //User input number of employees to write 
                         //checks for
    int n2Cnvrt;                            //Number to convert to Roman 
                                            //numerals

    //Enter the number of employee's to write checks for
    cout << "  Enter number of employee's: ";
    cin >> num_emp;
    
    //Input Validation for number of employees
    while(num_emp < 0)
    {
        // Prompt for correct input validation
        cout << endl << "  Please enter a valid number of employees, "
             << "no negative numbers." << endl;
 
        //Prompt user to re-enter the number of employees
        cout << endl << "  Enter number of employee's: ";
         cin >> num_emp; 
    }
    
    GrossPay* emps = new GrossPay[num_emp]; //Dynamically Allocate the array of 
                                            //structures
   
    for(int i=0; i < num_emp;i++)
    {
        //Display Employee number
        cout << endl << "     - Employee #" << i+1 << " Information -" 
             << endl;
        
        //Formatting
        cin.ignore(1);
        
        //Prompt user to enter their name
        cout << endl << "     Enter Name Here: ";
        getline(cin, emps[i].name); 
        
        
        //Prompt user to enter the hours worked
        cout << endl << "  Enter hours worked: ";
         cin >> emps[i].hours_wrk; 
          
        //Input Validation for hours of work
        if(emps[i].hours_wrk < 0)
        {
            // Prompt for correct input validation
            cout << endl << "  Please enter a number of valid work hours,"
                 << " no negative numbers." << endl << endl;
            
            //Break the loop 
            break;
        }
            
        //Prompt user to enter the rate of pay
        cout << endl << "   Enter rate of pay: $";
         cin >> emps[i].rt_pay;
         
        //Input Validation for rate of pay
        if(emps[i].rt_pay < 0)
        {
            // Prompt for correct input validation
            cout << endl << "   Please enter a valid rate of pay, "
                 << "no negative numbers." << endl << endl;

            //Break the loop
            break;
        }
          
        cout << endl;
        
        //Calculate the gross pay for 20 hours or less worked
        if(emps[i].hours_wrk <= 20)
        {
            emps[i].grs_pay = emps[i].hours_wrk * emps[i].rt_pay;
        }
        //Calculate the gross pay for hours worked between 20 and 40 hours
        else if(emps[i].hours_wrk > 20 && emps[i].hours_wrk <= 40)
        {
            emps[i].grs_pay = 20 * emps[i].rt_pay;
            emps[i].hours_wrk -= 20;
            emps[i].grs_pay += emps[i].hours_wrk * (emps[i].rt_pay * 2);
        }
        //Calculate the gross pay for more than 60 hours worked
        else if(emps[i].hours_wrk > 40)
        {
            emps[i].grs_pay = 20 * emps[i].rt_pay;
            emps[i].grs_pay += 20 * (emps[i].rt_pay * 2);
            emps[i].hours_wrk -= 40;
            emps[i].grs_pay += emps[i].hours_wrk * (emps[i].rt_pay * 3);  
        }
           
        //Set the conversion number equal to gross pay
        n2Cnvrt = emps[i].grs_pay;
         
        //Display the first half of the check
        cout << "_____________PayCheck Information____________________" << endl
             << "| ACME inc."<< endl;
        cout << "| 1234 Cool Street " << endl
             << "| Riverisde, CA 92506" << endl
             << "|" << endl
             << endl << "| Name: " << emps[i].name << "   " << "Amount: $" 
             << fixed << showpoint << setprecision(2) << emps[i].grs_pay << endl;
        cout << "| Amount: ";
    
        //Check for a valid input
        //Process or map Inputs to Outputs
        //Determine 1000's, 100's, 10's, 1's
        int n1000s,n100s,n10s,n1s;
        n1000s=n2Cnvrt/1000;   //Shift 3 places to the left
        n100s=n2Cnvrt%1000/100;//Remainder of division of 1000 then shift 2 left
        n10s=n2Cnvrt%100/10;   //Remainder of division of 100 then shift 1 left
        n1s=n2Cnvrt%10;        //Remainder of division by 10
         
        //Output the number of 1000's in Roman Numerals
        //Using the Switch Statement
        switch(n1000s)
        {
            case 9:cout<<"  Nine Thousand ";
                        break;
            case 8:cout<<" Eight Thousand ";
                        break;
            case 7:cout<<" Seven Thousand ";
                        break;
            case 6:cout<<"   Six Thousand ";
                        break;
            case 5:cout<<"  Five Thousand ";
                        break;
            case 4:cout<<"  Four Thousand ";
                        break;
            case 3:cout<<" Three Thousand ";
                        break;
            case 2:cout<<"   Two Thousand ";
                        break;
            case 1:cout<<"   One Thousand ";
                        break;
        }
        
        //Output the number of 100's
        //Using the Ternary Operator
        cout<<(n100s==9?"Nine Hundred ":
               n100s==8?"Eight Hundred ":
               n100s==7?"Seven Hundred ":
               n100s==6?"Six Hundred ":
               n100s==5?"Five Hundred ":
               n100s==4?"Four Hundred ":
               n100s==3?"Three Hundred ":
               n100s==2?"Two Hundred ":
               n100s==1?"One Hundred ":" ");
        
        //Output the number of 10's
        //Using Independent If Statements
        if(n10s==9)cout<<"Ninety ";
        if(n10s==8)cout<<"Eighty ";
        if(n10s==7)cout<<"Seventy ";
        if(n10s==6)cout<<"Sixty ";
        if(n10s==5)cout<<"Fifty ";
        if(n10s==4)cout<<"Fourty ";
        if(n10s==3)cout<<"Thirty ";
        if(n10s==2)cout<<"Twenty ";
        if(n10s==1 && n1s == 9)cout << "Nineteen ";        
        if(n10s==1 && n1s == 8)cout << "Eighteen ";        
        if(n10s==1 && n1s == 7)cout << "Seventeen ";        
        if(n10s==1 && n1s == 6)cout << "Sixteen ";        
        if(n10s==1 && n1s == 5)cout << "Fifteen ";       
        if(n10s==1 && n1s == 4)cout << "Fourteen ";       
        if(n10s==1 && n1s == 3)cout << "Thirteen ";        
        if(n10s==1 && n1s == 2)cout << "Twelve ";
        if(n10s==1 && n1s == 1)cout << "Eleven ";
        if(n10s==1 && n1s == 0)cout<<"Ten ";
         
        //Output the number of 1's
        //Using Dependent If Statements
        if(n1s==9 && n10s != 1)cout<<"Nine ";
        else if(n1s==8 && n10s != 1)cout<<"Eight ";
        else if(n1s==7 && n10s != 1)cout<<"Seven ";
        else if(n1s==6 && n10s != 1)cout<<"Six ";
        else if(n1s==5 && n10s != 1)cout<<"Five ";
        else if(n1s==4 && n10s != 1)cout<<"Four ";
        else if(n1s==3 && n10s != 1)cout<<"Three ";
        else if(n1s==2 && n10s != 1)cout<<"Two ";
        else if(n1s==1 && n10s != 1)cout<<"One ";
        cout << "and 00/100 Dollars" << endl;

        //Output rest of the check
        cout << "|" << endl
             << "| Signature:" << endl
             << "|" << endl
             << "|   __________________________________________ X" << endl  
             << "|" << endl
             << "|_____________________________________________________"
             << endl << endl;
        
        //Formatting
        cin.ignore(0);  
    }
    
    //Delete the dynamic array of structures
    delete[] emps;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 3
//Input:  -> N/A
//Output: -> Display message informing user of where the Problem 3 Program is.
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm3()
{
    //Prompt to the user, look in the Problem 3 project for the program.
    cout << "  The program for Problem 3 is located in a separate project,"
         << endl << "  called Midterm_Prob3_MedianMode, "
         << "please look there for the program." << endl << endl;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 4
//Input:  -> N/A
//Output: -> The entire Encryption / Decryption program
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm4()
{ 
        //Declare Variables
    int SIZE = 4;   //Size of the arrays
    int arr[SIZE];  //Array holding converted string values
    int input;     //Number input for menu
    string nums;    //String holding four digit number
    int temp;       //Temporary value used for holding and switching values
    int temp1=0;    //Second temporary value same purpose as the other one
    int tempary[SIZE]; //Temporary array holding possible configurations             
    int count[SIZE];   //Array used in combination loop
    int temps[0];      //Second array used in combination loop
    bool result = 1;   //Input validation result 
    
    //Display Menu
    cout << "Select an option:" << endl
         << " - 1 - > Encrypt Four digit integer" << endl
         << " - 2 - > Decrypt Four digit integer" << endl
         << endl
         << "--> Input: ";

    //Receive input for menu
    cin >> input;
    cout << endl;
    
    //Formatting
    cin.ignore();
    
    //Menu input validation
    while(input != 1 && input != 2)
    {
        cout << "Please enter enter a valid option (ex. 1 or 2)" << endl;
        cout << endl << "--> Input: ";
        cin >> input; 
        cout << endl;
        
        //Formatting
        cin.ignore(1);
    }
    
    //Chose which operation to do based on menu input
    switch(input)
    {
        case 1:
                //Loop for input validation
                do
                { 
                   
                //Reset bool value in case of loop
                result = 1;
                   
                //Prompt user for number to encrypt
                cout << endl << "Encryption Number: ";
                 cin >> nums;
                
                //Check to make sure input is only four digits long
                int i = 0;
                while (nums[i])
                i++;
                     
                //Input validation for the user number input
                for(int i = 0; i < nums.length(); i++)
                    if(nums[i] == '9' || nums[i] == '8' || isalpha(nums[i]))
                        result = 0; 
                
                //If string is too long or too short then retry
                if(i > 4 || i < 4)
                result = 0;
                
                //Output the input validation prompt
                if(result == 0)
                cout << endl << "Only enter digits from (0-7) and exactly four"
                     << " digits" << endl;
                
                }while(result != 1);
                //As long as the input is invalid keep looping

                //Change string values to usable int values
                for(int i = 0; i < SIZE; i++)
                {
                    arr[i] = nums[i] - 48;
                }
                 
                //Perform the encryption
                for(int i = 0; i < SIZE; i++)
                {
                    temp = arr[i];
                    temp += 6;
                    temp = temp % 8;
                    arr[i] = temp; 
                }
      
                temp = 0;
 
                //Swap the values around
                temp = arr[3];
                temp1 = arr[1];
                arr[3] = temp1;
                arr[1] = temp;

                temp = arr[2];
                temp1 = arr[0];
                arr[2] = temp1;
                arr[0] = temp;
 
                //Output the final encrypted number
                cout << endl << " Encrypted Number: ";               
                for(int i = 0; i < SIZE; i++)
                {
                    cout << arr[i];
                }
                cout << endl << endl;

                break;
        case 2:
                //Loop for input validation
                do
                { 
                   
                //Reset bool value in case of loop
                result = 1;
                   
                //Prompt user for number to encrypt
                cout << endl << "Decryption Number: ";
                 cin >> nums;
                
                //Check to make sure input is only four digits long
                int i = 0;
                while (nums[i])
                i++;
                     
                //Input validation for the user number input
                for(int i = 0; i < nums.length(); i++)
                    if(nums[i] == '9' || nums[i] == '8' || isalpha(nums[i]))
                        result = 0;
                
                //If string is too long or too short then retry
                if(i > 4 || i < 4)
                result = 0;
                
                //Output the input validation prompt
                if(result == 0)
                cout << endl << "Only enter digits from (0-7) and exactly four"
                     << " digits" << endl;
                
                }while(result != 1);
                //As long as the input is invalid keep looping
                
                //Convert string input to int array values
                for(int i = 0; i < SIZE; i++)
                    arr[i] = nums[i] - 48;

                //Initialize all elements withing the arrays
                for(int i = 0; i < 4; i++)
                {
                    tempary[i] = 0;
                    count[i]=0;
                    temps[i]=0;
                }

                //Encrypt all possible combinations and find matching decrypted
                //and encrypted combinations
                for(int a = 0; a < 8; a++)
                {
                    if(count[0]==8)
                    {
                        tempary[1]=0; 
                        tempary[2]=0;
                        tempary[3]=0; 
                        count[0]=0;
                    }       
                    for(int b = 0; b < 8; b++)
                    {
                        if(count[1]==8)
                        {
                            tempary[1]=0; 
                            tempary[2]=0;
                            tempary[3]=0;
                            count[1]=0;
                        }
                        for(int c = 0; c < 8; c++)
                        {
                            if(count[2]==8)
                            {
                                tempary[2]=0;
                                tempary[3]=0; 
                                count[2]=0;
                            }
                            for(int d = 0; d < 8; d++)
                            { 
                                if(count[3]==8)
                                {
                                    tempary[3]=0;
                                    count[3]=0;
                                }

                                 temps[0]=tempary[0];
                                 temps[1]=tempary[1];
                                 temps[2]=tempary[2];
                                 temps[3]=tempary[3];

                            for(int i = 0; i < SIZE; i++)
                            {
                                temp = tempary[i];
                                temp += 6;
                                temp = temp % 8;
                                tempary[i] = temp; 
                            }
  
                            temp = tempary[3];
                            temp1 = tempary[1];
                            tempary[3] = temp1;
                            tempary[1] = temp;

                            temp = tempary[2];
                            temp1 = tempary[0];
                            tempary[2] = temp1;
                            tempary[0] = temp;                  

                            //Display the decrypted number
                            if(!memcmp(arr, tempary, sizeof(arr)))
                            {           
                                cout << endl << " Decrypted Number: ";
                                cout << temps[0] << temps[1] 
                                     << temps[2] << temps[3] << endl;
                            }

                            tempary[0]=temps[0];
                            tempary[1]=temps[1];
                            tempary[2]=temps[2];
                            tempary[3]=temps[3];

                                count[3]++;
                                tempary[3]++;
                            }
                            count[2]++;
                            tempary[2]++; 
                        }
                        count[1]++;
                        tempary[1]++;
                    }
                    count[0]++;
                    tempary[0]++;
                }

                //Formatting
                cout << endl;
                break; 
    }
} 
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 5
//Input:  -> N/A
//Output: -> Display the results of finding the highest possible factorials for
//           each type of variable
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm5() 
{   
    //Output the results 
    cout << "              Question 5 Answers:" << endl << endl
         << "   a.)   Largest n for a signed byte variable -> 5" << endl
         << "      Largest n for an unsigned byte variable -> 5" << endl 
         << endl  
         << "   b.)  Largest n for a signed short variable -> 7" << endl  
         << "      Largest n for a unsigned short variable -> 8" << endl 
         << endl                               
         << "          Largest n for a signed int variable -> 12" << endl                                
         << "        Largest n for a unsigned int variable -> 12" << endl 
         << endl            
         << "         Largest n for a signed long variable -> 12" << endl                                
         << "       Largest n for a unsigned long variable -> 12" << endl 
         << endl 
         << "    Largest n for a signed long long variable -> 20" << endl                                
         << "  Largest n for a unsigned long long variable -> 20" << endl
         << endl 
         << "        Largest n for a signed float variable -> 34" << endl                                
         << "      Largest n for a unsigned float variable -> 34" << endl 
         << endl 
         << "       Largest n for a signed double variable -> 170" << endl                                
         << "     Largest n for a unsigned double variable -> 170" << endl
         << endl 
         << "  Largest n for a signed long double variable -> 1754" << endl                                
         << "Largest n for a unsigned long double variable -> 1754" << endl 
         << endl;
} 
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 6
//Input:  -> N/A
//Output: -> Display the findings of the NASA Float Conversion problem
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm6()
{
        //Output the results
    cout << "      Question 6 Answers:" << endl << endl
         << "   a.) Binary, Octal and Hex Conversions" << endl
         << "                                          " << endl
         << "       49.1875(10) = " << endl
         << "            Binary = 110001.0011(2)     " << endl 
         << "             Octal = 61.14(8)     " << endl 
         << "               Hex = 31.3(16)    " << endl
         << "                                           " << endl
         << "    3.07421875(10) =                      " << endl
         << "            Binary = 0011.00010011(2)     " << endl 
         << "             Octal = 3.046(8)     " << endl 
         << "               Hex = 3.13(16)    " << endl 
         << "                                 " << endl
         << "           0.2(10) =          " << endl            
         << "            Binary = 0.(0011)(2) () = repeating" << endl 
         << "             Octal = 0.(1463)(8)     " << endl 
         << "               Hex = 0.(3)(16)    " << endl 
         << "                                 " << endl 
         << "        NASA Float Representations" << endl
         << "                                 " << endl
         << "           49.1875(10) = 6 2 6 0 0 0 0 6          " << endl
         << "                                 " << endl
         << "        3.07421875(10) = 6 2 6 0 0 0 0 2   " << endl
         << "                                 " << endl
         << "               0.2(10) = 6 6 6 6 6 6 F E   " << endl
         << "                                           " << endl
         << "   b.) Negative NASA Float Representations" << endl
         << endl
         << "     - 6 2 6 0 0 0 0 6 = 9 D A 0 0 0 0 6         " << endl
         << "                                  " << endl
         << "     - 6 2 6 0 0 0 0 2 = 9 D A 0 0 0 0 2   " << endl
         << "                                 " << endl
         << "     - 6 6 6 6 6 6 F E = 9 9 9 9 9 A F E  " << endl 
         << endl
         << "   c.) NASA Float to Decimal Representation " << endl << endl
         << "       69999902 = 3.3(10) " << endl
         << "                         " << endl
         << "       69999903 = 6.6(10)         " << endl           
         << "                              " << endl
         << "       966667FF = 0.4125(10)                " << endl << endl;
} 
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 7  
//Input:  -> N/A
//Output: -> The entire working Prime Number Factoring program
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm7()
{
    struct Primes * prm = new Primes; //Dynamic Prime Number structure
    int input =0;                     //User number input to factor
    
    //Prompt the user for a number to factor
    cout << endl << " Enter a number to factor: ";
    cin >> input;
    
    //Input Validation Loop
    while(input < 2 || input > 65000)
    {
        //Prompt User to input valid number
        cout << endl
             << " Please enter a number in the range (2 - 65000). Try Again."
             << endl;
          
        //Prompt the user for a new number to factor
        cout << endl << " Enter a number to factor: ";
        cin >> input;
    }
       
    //Find factored data and enter it into the structure
    prm = factor(input);
    
    //Output the format for the number input
    cout << endl << "    " << input << " = ";
    
    //Print the factored output
    prntPrm(prm);
    
    //Formatting
    cout << endl;
    
    //Delete the dynamic structure
    delete[] prm; 
}

//Function used to factorize the input number and store the output
Primes *factor(int input)
{
    struct Primes * prm = new Primes;   //Dynamically allocated structure
    prm->prime = new Prime[50];         //Dynamically allocated array of 
                                        //structures
    unsigned char power =0; //Temporary value holding the power of each prime #
    int count =0;    //Counter for size of the array           
    int c = 2;       //Prime number value counter
    int i = 0;       //Array element counter
    
    //Check to see if number is entirely factored
    while(input>1)
    {
        //Check to see if input is modable by the prime number counter
        if(input%c==0)
        {
        prm->prime[i].prime = c;
        input/=c;
        power++;
        
            if(input == 1)
            {
                prm->prime[i].power = power;
                i++;
                count++;
                power =0;
            }
        }
        else 
        {
            //Raise the prime number counter by 1
            c++;
            
            //Check to see if the input is modable by the counter
            if(input%c==0 )
            {
            prm->prime[i].power = power;
            i++;
            count++;
            power =0;
            }
        }
    }
    
    //Set the number of primes value
    prm->nPrimes = count;

    //Return the prm structure
    return prm;
}

//Function for the final factored results
void prntPrm(Primes * prm)
{
    //Output the final factored results
    if(prm->prime[0].prime > 1000)
    {
        for(int i=1;i<prm->nPrimes;i++)
        {
            if(i == (prm->nPrimes-1))
            cout << prm->prime[i].prime << "^" 
                 << static_cast<int>(prm->prime[i].power) << " ";
            else
                cout << prm->prime[i].prime << "^" 
                 << static_cast<int>(prm->prime[i].power) << " * ";
        }
    }
    else
    {  
        for(int i=0;i<prm->nPrimes;i++)
        {
            if(i == (prm->nPrimes-1))
            cout << prm->prime[i].prime << "^" 
                 << static_cast<int>(prm->prime[i].power) << " ";
            else
                cout << prm->prime[i].prime << "^" 
                 << static_cast<int>(prm->prime[i].power) << " * ";
        }
    }
}

