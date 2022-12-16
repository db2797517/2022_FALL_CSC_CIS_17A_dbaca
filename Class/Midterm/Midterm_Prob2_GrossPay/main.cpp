/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on October 17th, 2022, 5:28 PM
 * Purpose: 
 * Develop an application using an array of structures created dynamically that 
 * will determine the gross pay for any number of employees input. i.e. ask up 
 * front how many employees you are inputting. The company pays ”straight-time” 
 * for the first 20 hours worked, double time for all hours worked in excess of 
 * 20 hours but less than 40 hours, and triple time for any hours worked over 
 * 40 hours. The program should be able to loop and input the employee’s name, 
 * hours worked, and the rate of pay. Once this has been done then output this 
 * information including the gross pay in the form of a paycheck. The process 
 * starts all over again until you input an invalid rate of pay or hours worked. 
 * This means a negative rate of pay or negative number of hours worked is not 
 * acceptable. Print it out like an actual paycheck with English language 
 * representing the check amount. Printout like a company Paycheck with format:
 *  • Company
 *  • Address
 *  • Name: Amount: numerical
 *  • Amount: English of numerical value 
 *  • Signature Line:
 * Hint: Utilize the Roman Numeral Conversion Program to help with producing the
 * check.
 */
 
//Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Global Constants - none

//Function Prototypes - none

//Structure of gross play for each employee
struct GrossPay
{
    string name;
    int hours_wrk;
    int rt_pay;
    int grs_pay;
};
 
//Execution begins here
int main(int argc, char** argv) 
{
    //Declare Variables
    int num_emp;         //User input number of employees to write 
                         //checks for
    GrossPay* emps = new GrossPay[num_emp]; //Dynamically Allocate the array of 
                                            //structures
    int n2Cnvrt;                            //Number to convert to Roman 
                                            //numerals

    //Enter the number of employee's to write checks for
    cout << endl << "  Enter number of employee's: ";
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
    
    for(int i=0; i < num_emp;i++)
    {
        //Display Employee number
        cout << endl << "     - Employee #" << i+1 << " Information -" 
             << endl;
        
        //Formatting
        cin.ignore();
        
        //Prompt user to enter their name
        cout << endl << "     Enter Name Here: ";
        getline(cin, emps[i].name); 
        
        //Prompt user to enter the hours worked
        cout << endl << "  Enter hours worked: ";
         cin >> emps[i].hours_wrk; 
          
        //Input Valdiation for hours of work
        if(emps[i].hours_wrk < 0)
        {
            // Prompt for correct input validation
            cout << endl << "  Please enter a number of valid work hours,"
                 << " no negative numbers." << endl;
            
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
                 << "no negative numbers." << endl;

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
             << endl;
        
        //Formatting
        cin.ignore(0);  
    }
    
    //Delete the dynamic array of structures
    delete[] emps;
    
    //Exit Stage Right
    return 0;
}


