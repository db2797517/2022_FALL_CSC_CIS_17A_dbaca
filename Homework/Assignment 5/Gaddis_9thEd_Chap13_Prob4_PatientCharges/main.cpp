/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on November 12th, 2022, 10:41 PM
 * Purpose:  
 * 
 * Create a class named Patient and follow the instructions for what to include
 * and output.
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
 
//Patient Class 
class Patient
{
    
private:  
    
    //Class variables
    string frstnm ,midnm ,lstnm; //Name string variables
    string add,city,state,zip;    //Address Related String Variables
    string phnum, name, emphnum; //Contact String Variables
    
public:  
    
    //Initialization constructor
    Patient(string f, string m, string l, string a, string c, string s, string z, string p, string n, string e)
    {
        frstnm = f;
        midnm = m;        
        lstnm = l;
        add = a;
        city = c;
        state = s;
        zip = z;
        phnum = p;
        name = n;
        emphnum = e;    
    } 
   
    //Mutator functions
    void setfrstnm(string f)
        {   frstnm = f; }
    
    void setmidnm(string m)
        {   midnm = m;  }
    
    void setlstnm(string l)
        {   add = l;    }
    
    void setadd(string a)
        {   add = a;    }
    
    void setcity(string c)
        {   city = c;   }
    
    void setstate(string s)
        {   state = s;  }
    
    void setzip(string z)
        {   zip = z;    }
    
    void setphnum(string p)
        {   phnum = p;  }
    
    void setname(string n)
        {   name = n;   }
    
    void setemphnum(string e)
        {   emphnum = e; }
    
    //Accessor Functions
    string getfrstnm()
        {   return frstnm;  }
    
    string getmidnm()
        {   return midnm;   }
        
    string getlstnm()
        {   return lstnm;   }
    
    string getadd()
        {   return add; }    
    
    string getcity()
        {   return city; }
    
    string getstate()
        {   return state;   }    
    
    string getzip()
        {   return zip; }
    
    string getphnum()
        {   return phnum;   }    
    
    string getname()
        {   return name;    }
    
    string getemphnum()
        {   return emphnum; }   
};

//Procedure class
class Procedure
{
private:
    
    //Class variables
    string prcd; //String for procedure
    string date; //String for the date
    string name; //String for practitioner's name
    float charges; //Float for procedure charge
public:
    //Initialization constructor
    Procedure(string p, string d, string n, float c)
    {
        prcd = p;
        date = d;
        name = n;
        charges = c;
    }
    
    //Mutator functions
    void setprcd(string p)
        {   prcd = p; }
    
    void setdate(string d)
        {   date = d; }
    
    void setcname(string n)
        {   name = n; }
    
    void setcharges(float c)
        {   charges = c; }
    
    //Accessor Functions
    string getprcd()
        {   return prcd; }
    
    string getdate()
        {   return date;   }    
    
    string getname()
        {   return name;    }
    
    float getcharges()
        {   return charges; }  
};  

//Execution of Code Begins Here
int main(int argc, char** argv) 
{
    //Declare all variables
    //Patient Class initialization variable
    Patient patient("Donald","M","Glover","1234 Cool Street","Riverside","CA",
                    "92508","(951)-123-4567","Danny Boii","(951)-678-2345");
    
    float total;    //Variable for the running total of all charges
    
    //Array for the Procedure class variables
    Procedure pro[3] = {
        Procedure("Physical Exam", "November 10th, 2022", "Dr. Irvine", 250.00),
        Procedure("X-Ray", "November 11th, 2022", "Dr. Jamison", 500.00),
        Procedure("Blood test", "November 12th, 2022", "Dr. Smith", 200.00)
    };
    
    //Output patient name
    cout << endl << "          -- Patient's Information --" << endl;
    cout << "              First name: " << patient.getfrstnm() << endl;
    cout << "             Middle name: " << patient.getmidnm() << endl;
    cout << "               Last name: " << patient.getlstnm() << endl;
      
    //Formatting
    cout << endl;
     
    //Output patient address info
    cout << "                 Address: " << patient.getadd() << endl;
    cout << "                    City: " << patient.getcity() << endl;
    cout << "                   State: " << patient.getstate() << endl;
    cout << "                ZIP code: " << patient.getzip() << endl;

    //Formatting
    cout << endl;

    //Output patient contact info
    cout << "                 Phone #: " << patient.getphnum() << endl;
    cout << "          Contact's Name: " << patient.getname() << endl;
    cout << "       Contact's Phone #: " << patient.getemphnum() << endl 
         << endl;
     
    //Formatting
    cout << fixed << showpoint << setprecision(2);
    
    for(int i=0;i<3;i++)
    {
        //Output procedure information
        cout << "              -- Procedure # " << (i+1) << " -- " << endl;  
        cout << "               Procedure: " << pro[i].getprcd() << endl;
        cout << "                    Date: " << pro[i].getdate() << endl;
        cout << "     Practitioner's Name: " << pro[i].getname() << endl;
        cout << "                  Charge: " << pro[i].getcharges() << endl;
        cout << endl;
        
        //Get running total of charges
        total += pro[i].getcharges();
    }
    
    //Output total charges
    cout << "           Total Charges: " << total << endl;
     
    //Exit stage right
    return 0;
}    

 
