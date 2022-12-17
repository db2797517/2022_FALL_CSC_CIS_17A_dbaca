/* 
 * File:   Choice.h
 * Author: Daniel Baca
 *
 * Created on November 28, 2022, 8:19 PM
 */
 
#ifndef CHOICE_H
#define CHOICE_H
  
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
 
//Choice class, allowing players to ask for example input using a response
template <class T>
class Choice
{ 
private:
    T response; //Variable used to make decision
public:  
    //Initialize Constructor
    Choice()
    {   response = ' ';    }
    
    //Choice function used to output requested output
    void respond(char c)
    {
        response = c;
        
        //Use choice input to determine what to output
        if(response == 'Y' || response == 'y')
        {
            cout << endl << "    Name for Player: Mary Sue" << endl << endl
                 << "   Ship Coordinates -" << endl << endl
                 << "    Carrier: A5 A9" << endl
                 << " Battleship: F2 I2" << endl        
                 << "    Cruiser: E5 G5" << endl           
                 << "  Submarine: I8 I10" << endl               
                 << "  Destroyer: C2 D2" << endl << endl            
                 << "      --------------- Player Board ------------" << endl 
                 << "        1   2   3   4   5   6   7   8   9   10" << endl
                 << "        _   _   _   _   _   _   _   _   _   _ " << endl
                 << "   A  | 0 | 0 | 0 | 0 | X | X | X | X | X | 0 | " << endl
                 << "   B  | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | " << endl 
                 << "   C  | 0 | X | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | " << endl  
                 << "   D  | 0 | X | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | " << endl
                 << "   E  | 0 | 0 | 0 | 0 | X | 0 | 0 | 0 | 0 | 0 | " << endl 
                 << "   F  | 0 | X | 0 | 0 | X | 0 | 0 | 0 | 0 | 0 | " << endl                     
                 << "   G  | 0 | X | 0 | 0 | X | 0 | 0 | 0 | 0 | 0 | " << endl
                 << "   H  | 0 | X | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | " << endl 
                 << "   I  | 0 | X | 0 | 0 | 0 | 0 | 0 | X | X | X | " << endl 
                 << "   J  | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | " << endl 
                 << endl;
        }
    }
      
    //Choice function used to output requested output
    void respond(string c)
    {
        response = c;
          
        //Use choice input to determine what to output
        if(response == "Y" || response == "Y")
        {
            cout << endl << "    Name for Player: Mary Sue" << endl << endl
                 << "   Ship Coordinates -" << endl << endl
                 << "    Carrier: A5 A9" << endl
                 << " Battleship: F2 I2" << endl        
                 << "    Cruiser: E5 G5" << endl           
                 << "  Submarine: I8 I10" << endl               
                 << "  Destroyer: C2 D2" << endl << endl            
                 << "      --------------- Player Board ------------" << endl 
                 << "        1   2   3   4   5   6   7   8   9   10" << endl
                 << "        _   _   _   _   _   _   _   _   _   _ " << endl
                 << "   A  | 0 | 0 | 0 | 0 | X | X | X | X | X | 0 | " << endl
                 << "   B  | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | " << endl 
                 << "   C  | 0 | X | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | " << endl  
                 << "   D  | 0 | X | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | " << endl
                 << "   E  | 0 | 0 | 0 | 0 | X | 0 | 0 | 0 | 0 | 0 | " << endl 
                 << "   F  | 0 | X | 0 | 0 | X | 0 | 0 | 0 | 0 | 0 | " << endl                     
                 << "   G  | 0 | X | 0 | 0 | X | 0 | 0 | 0 | 0 | 0 | " << endl
                 << "   H  | 0 | X | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | " << endl 
                 << "   I  | 0 | X | 0 | 0 | 0 | 0 | 0 | X | X | X | " << endl 
                 << "   J  | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | " << endl 
                 << endl;
        }
    } 
    
    //Friendly overloaded << operator function
    friend ostream& operator<<(ostream& os, Choice<char> &same);
};

#endif /* CHOICE_H */

