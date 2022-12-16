/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on November 20th, 2022, 1:59 PM
 * 
 * Purpose: 
 *  
 * Design a class named Employee. The class should keep the following 
 * information:
 * 
 * - Employee name
 * - Employee number
 * - Hire Date
 * 
 * Write one or more constructors and the appropriate accessor and mutator 
 * functions, for the class.
 * 
 * Next, write a class named ProductionWorker that is derived from the Employee 
 * class. The ProductionWorker class should have member variables to hold the 
 * following information:
 * 
 * - Shift (an integer)
 * - Hourly pay rate (a double)
 * 
 * The workday is divided into two shifts: day and night. The shift variable 
 * will hold an integer value representing the shift that the employee works. 
 * The day shift is shift 1 and the night shift is shift 2. Write one or more 
 * constructors and the appropriate accessor and mutator functions, for the 
 * class. Demonstrate the classes by writing a program that uses a 
 * ProductionWorker object.
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

//Employee Class 
class Employee
{
    
private:  
    
    //Member variables 
    string empnm;   //String for the name of the employee
    int empnum;     //Integer for the employee number
    string date;    //The date the employee was hired
    
public:  
    
    //Default constructor
    Employee()
    {  
        empnm = "";
        empnum = 0;
        date = "";
    }
    
    //Initialization constructor
    Employee(string en, int enm, string d)
    {   
        empnm = en;
        empnum = enm;
        date = d;
    } 
    
    //Mutator functions
    void setempnm(string en)
        {   empnm = en; }
    
    void setempnum(int enm)
        {   empnum = enm; }
    
    void setdate(string d)
        {   date = d; }    
    
    //Accessor Functions
    string getempnm()
        {   return empnm; }
    
    int getempnum()
        {   return empnum; }
    
    string getdate()
        {   return date; }    
};

//ProductionWorker Class 
class ProductionWorker : public Employee
{
    
private:  
    
    //Member variables 
    int shift; //Integer indicating which shift it is
    float hpr; //The hourly pay rate of the employee
    
public:  
    
    //Default constructor
    ProductionWorker()
    {  
        shift = 0;
        hpr = 0.0;
    }
    
    //Initialization constructor
    ProductionWorker(int s, float h, string en, int enm, string d)
    {   
        shift = s;
        hpr = h;
        
        setempnm(en);
        setempnum(enm);
        setdate(d);
    } 
    
    //Mutator functions
    void setshift(int s)
        {   shift = s; }
    
    void sethpr(int h)
        {   hpr = h; }    
    
    //Accessor Functions
    int getshift()
        {   return shift; }
    
    float gethpr()
        {   return hpr; }
}; 
      
//Execution of Code Begins Here
int main(int argc, char** argv) 
{  
    //Declare Variables
    string nm, date;    //Strings for the name and date hired of the employee
    int num = 0,        //Integer for the employee number
        shift = 0;      //Integer indicating which shift it is
    float hpr = 0;      //The hourly pay rate of the employee
    
    //Output starting info 
    cout << endl << " - Enter the following Employee Information - " << endl;
    
    //Prompt the user to enter their name
    cout << endl << "             Name: ";
    getline(cin, nm);

    //Prompt the user to enter their employee number
    cout << "       Employee #: ";
     cin >> num;
     
    //Formatting
    cin.ignore();
    
    //Prompt the user to enter the date they were hired
    cout << "       Date Hired: ";
    getline(cin, date);
    
    //Prompt the user to enter the shift number
    cout << "          Shift #: ";
     cin >> shift;
      
    //Input validation for the shift number
    while(shift != 1 && shift != 2)
    {
        cout << endl;
        cout << "Please enter a valid shift number (1 or 2)." << endl << endl;
        cout << "          Shift #: ";
         cin >> shift;
    }
    
    //Prompt the user to enter the hourly day rate
    cout << "  Hourly Pay Rate: $";
     cin >> hpr;
     
    //Initialize ProductioWorker class object
    ProductionWorker emp(shift, hpr, nm, num, date);
     
    //Output employee info
    cout << endl << " - Currently Listed Employee Information - " << endl;
    cout << "             Name: " << emp.getempnm() << endl;
    cout << "       Employee #: " << emp.getempnum() << endl;
    cout << "       Date Hired: " << emp.getdate() << endl;
    cout << "          Shift #: " << emp.getshift() << endl;
    cout << fixed << showpoint << setprecision(2);
    cout << "  Hourly Pay Rate: $" << emp.gethpr() << endl;

    //Exit stage right
    return 0;  
}          


