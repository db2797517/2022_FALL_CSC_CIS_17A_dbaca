/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on October 10th, 2022, 2:18 PM
 * Purpose: Write a program that asks the user for two file names. The first 
 * file will be opened for input and the second file will be opened for output.
 * (It will be assumed that the first file contains sentences that end with a 
 * period.) The program will read the contents of the first file and change all
 * the letters to lowercase except the first letter of each sentence, which 
 * should be made uppercase. The revised contents should be stored in the 
 * second file. NOTE: Using an editor, you should create a simple text file 
 * that can be used to test this program.
 */
    
//Libraries
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
    string input,       //String for input file name
          output;       //String for output file name
    string sentence;    //String for each sentence input
    
    //Read the two files names
    cout << "Please Enter the name of the input file: ";
    getline(cin,input);
    cout << endl;
     
    cout << "Please Enter the name of the output file: ";
    getline(cin,output);
    cout << endl;
     
    //Declare the two files
    ofstream inputfile;
    ofstream outputfile;
    
    //Open the two files
    inputfile.open(input);
    outputfile.open(output);
    
    //Prompt the user how to use the program
    cout << "Please enter the contents of the Input File, " << endl << "after "
         << "every sentence press Enter." << endl
         << "Enter exit to end the program." << endl << endl;
    
    //Read in the first sentence to the input file
    getline(cin,sentence);
    
    //Loop for output file format changes
    do
    {  
        inputfile << sentence << "\n";
        
        sentence[0]=toupper(sentence[0]);
         
        for(int i=1;i<sentence.length();i++)
                sentence[i]=tolower(sentence[i]);
         
        outputfile << sentence << "\n";
        
        //Establish flag to break the loop
        if(sentence == "Exit" || sentence == "exit")
            break;
        
    }while(getline(cin,sentence));
    
    //Close the two files
    inputfile.close();
    outputfile.close();

    //Exit Stage Right
    return 0;
}

