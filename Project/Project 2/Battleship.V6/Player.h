/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.h
 * Author: User
 *
 * Created on November 23, 2022, 5:00 PM
 */

#ifndef PLAYER_H
#define PLAYER_H

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

class Player
{
protected:
    string player_name;  //C-string Array holding the name of the player
    string ships[5];        //String Array holding the ship coordinates input 
                            //by the player
public:  
    Player()
    {
        player_name = " ";
                
        for(int i=0; i<5;i++)
        { ships[i] = " ";  }
        
        //for(int i=0; i<20;i++)
         //   for(int j=0; j<20;j++)
         //   {  ship_coors[i][j] = 0;  }
    }
     
    Player(string pn, string s[])
    {
        player_name = pn;
        
        for(int i=0; i<5;i++)
        { ships[i] = s[i];  }
    }
    
    class BadShips
    {   };
    
    void setplyrnm(string pn)
    {
        player_name = pn;
    }
     
    void setships(string s[])
    {
        for(int i=0;i<5;i++)
        {
            if(s[i].length() > 7 || !isupper(s[i][0]) || !isdigit(s[i][1]))
                throw BadShips(); 
            else
                ships[i] = s[i];
        }
    }
      
    /*
    void setshpcors(int sc[20][20])
    {
        for(int i=0; i<20;i++)
            for(int j=0; j<20;j++)
            {  ship_coors[i][j] = sc[i][j];  }
    }
    */
    
    string getplyrnm()
    {
        return player_name;
    }
    
    void getships()
    {
        for(int i =0; i<5;i++)
            cout << ships[i] << endl;
    }
    
    Player operator=(const Player &);
};

#endif /* PLAYER_H */

