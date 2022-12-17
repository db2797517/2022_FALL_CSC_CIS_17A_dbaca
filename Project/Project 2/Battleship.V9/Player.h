/* 
 * File:   Player.h
 * Author: Daniel Baca
 *
 * Created on November 23, 2022, 5:00 PM
 */

#ifndef PLAYER_H
#define PLAYER_H
 
//System Libraries
#include "AbsPlayer.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <cstring>
using namespace std;
  
//Player class holding basic info for each player as the game goes on
class Player : public AbsPlayer
{
protected:
    string player_name;     //String Array holding the name of the player
    string ships[5];        //String Array holding the ship coordinates input 
                            //by the player
public:  
    //Default Constructor
    Player()
    {
        player_name = " ";
                
        for(int i=0; i<5;i++)
        { ships[i] = " ";  }
    }
    
    //Initial Constructor
    Player(string pn)
    {
        player_name = pn;
        
        for(int i=0; i<5;i++)
        { ships[i] = " ";  }
    }
     
    //Initial Constructor
    Player(string pn, string s[])
    {
        player_name = pn;
        
        for(int i=0; i<5;i++)
        { ships[i] = s[i];  }
    }

    //Exception class
    class BadShips
    {   };
    
    //Set player name function
    void setplyrnm(string pn)
    {
        player_name = pn;
    }
     
    //Set player ship coordinates function
    void setships(string s[])
    { 
        //Verify to make sure input is valid
        for(int i=0;i<5;i++)
        {
            if(s[i].length() > 7 || s[i].length() <= 4 || 
               !isupper(s[i][0]) || !isdigit(s[i][1]))
                throw BadShips(); 
            else
                ships[i] = s[i];
        }
    }
    
    //Get player name function
    string getplyrnm()
    {
        return player_name;
    }   
};

#endif /* PLAYER_H */

