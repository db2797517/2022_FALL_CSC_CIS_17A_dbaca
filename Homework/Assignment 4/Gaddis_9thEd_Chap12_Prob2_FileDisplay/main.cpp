/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on October 10th, 2022, 4:32 PM
 * Purpose: Write a program that asks the user for the name of a file. The 
 * program should display the contents of the file on the screen. If the file’s 
 * contents won’t fit on a single screen,the program should display 24 lines of
 * output at a time, and then pause. Each time the program pauses, it should 
 * wait for the user to strike a key before the next 24 lines are displayed.
 */ 
     
//Libraries
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
  
//No Global Constants

//Function Prototypes - none

//Execution Begins Here
int main(int argc, char** argv)
{
    //Declare Variables
    string input;       //String for input file name
    string sentence;    //String for each sentence input
    string line;        //String for each line of the file
    int count = 1;      //Counter for the loop
    int count1 = 0;     //Second counter for the loop
    
    //Read the file name
    cout << "File Name: ";
    getline(cin, input);
     
    //Declare the file
    ofstream inputfile;
    
    //Open the file
    inputfile.open(input);
    
    //Prompt user what to do in program
    cout << "Please Enter what you would like to put in the file." << endl
         << "Enter Exit to end the program" << endl << endl;
    
    //Read in the first sentence to the input file
    getline(cin,sentence);
    
    do
    {  
        count++;
        
        inputfile << sentence << "\n";
        
        //Establish flag to break the loop
        if(sentence == "Exit" || sentence == "exit")
            break;
    }while(getline(cin,sentence));
    
    //Close the output file
    inputfile.close();
    
    //Open the input file
    ifstream inpfile; 
    
    inpfile.open(input);
        
    cout << endl;
    
    //Output the file contents
    cout << "File Output:" << endl;
    
    //Show one screen of data
    if(count <= 11)
    {
        //Display the contents of the file
        while(getline(inpfile, line))
        {  
            cout << line << endl;
        } 
    }
    // Show the rest of the data normally or in sets
    else if(count > 11)
    {
        //Display the contents of the file
        while(getline(inpfile, line))
        {  
            count1++;
            
            cout << line << endl;
            
            if(count1 == 24)
            {
                cout << "Press Enter Again to See the next set of data." 
                     << endl;
                cin.ignore();
                count1 = 0;
            }
        }   
    }
    
    //Close the two files
    inpfile.close();

    //Exit
    return 0;
}



