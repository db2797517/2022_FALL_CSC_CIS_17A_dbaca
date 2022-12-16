/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on November 20th, 2022, 5:36 PM
 * 
 * Purpose: 
 *  
 * Design an Essay Class that is derived from the GradedAcitivty class presented
 * in this chapter. The Essay class should determine the grade a student 
 * receives on an essay. The student's essay score can be up to 100, and is
 * determined in the following manner:
 * 
 * Grammar: 30 points
 * Spelling: 20 points
 * Correct length: 20 points
 * Content: 30 points
 * 
 * Demonstrate the class in a simple program.
 * 
 */
  
//System Libraries
#include "GradedActivity.h"
#include "Essay.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <cstring>
using namespace std;
      
//Execution of Code Begins Here
int main(int argc, char** argv) 
{  
    //Declare Variables
    float gram;     //Float for the number of points scored in Grammar
    float spell;    //Float for the number of points scored in Spelling
    float corlen;   //Float for the number of points scored for Correct length
    float cont;     //Float for the number of points scored in Content
    
    //Output the basic info
    cout << " - Enter the scores for each portion of the Essay - " << endl
         << endl;
    
    //Prompt the user to enter their grammar score
    cout << "        Grammar Score: ";
    cin >> gram;
    
    //Input validation for the grammar score
    while(gram < 0 || gram > 30)
    {
        cout << endl 
             <<"  Only a score of 0-30 is valid for this category. Try again."
             << endl << endl;
        cout << "        Grammar Score: ";
         cin >> gram; 
    }
    
    //Prompt the user to enter their spelling score
    cout << "       Spelling Score: ";
    cin >> spell;
    
    //Input validation for the spelling score
    while(spell < 0 || spell > 20)
    {
        cout << endl 
             <<"  Only a score of 0-20 is valid for this category. Try again."
             << endl << endl;
        cout << "       Spelling Score: ";
         cin >> spell; 
    }    
    
    //Prompt the user to enter their correct length score
    cout << " Correct Length Score: ";
    cin >> corlen;
    
    //Input validation for the correct length score
    while(corlen < 0 || corlen > 20)
    {
        cout << endl 
             << "  Only a score of 0-20 is valid for this category. Try again."
             << endl << endl;
        cout << " Correct Length Score: ";
         cin >> corlen; 
    }    

    //Prompt the user to enter their content score
    cout << "        Content Score: ";
    cin >> cont;
    
    //Input validation for the content score
    while(cont < 0 || cont > 30)
    {
        cout << endl
             << "  Only a score of 0-30 is valid for this category. Try again."
             << endl << endl;
        cout << "        Content Score: ";
         cin >> cont; 
    }   
     
    //Initialize the Essay object
    Essay essay(gram,spell,corlen,cont);
    
    //Output the Essay letter grade
    cout << endl;
    cout << "    Essay Letter Grade: " << essay.getlettergrade() << endl;
    cout << "           Total Score: " << essay.getscore();
 
    //Exit stage right
    return 0;  
}          



