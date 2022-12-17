/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
  
#include "Player.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <cstring>
using namespace std;
 
    //Set player ship coordinates function
    void Player::setships(string s[])
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

