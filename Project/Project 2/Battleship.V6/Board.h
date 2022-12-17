/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Board.h
 * Author: User
 *
 * Created on November 23, 2022, 8:39 PM
 */

#ifndef BOARD_H
#define BOARD_H

//System Libraries
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

class Board : public Player
{ 
private:
    int ship_coors[20][20]; //Number Array with the number coordinates converted
                            //from user input
    //string * shts_frd = new string[100]; //Dynamic String Array holding the 
                                         //shots fired by the player
    char player_board[10][10]; //C-string array holding the players board moves
    char enemy_board[10][10];  //C-string array holding the enemy board moves
    int count;
public:
    
    Board()
    {
        for(int i=0;i<20;i++)
            for(int j=0;j<20;j++)
                ship_coors[i][j]=0;
 
       // for(int i=0;i<100;i++)  
        //    shts_frd[i] = " ";
        
         
        for(int i=0;i<10;i++)
            for(int j=0;j<10;j++)
                player_board[i][j]='0';
        
        for(int i=0;i<10;i++)
            for(int j=0;j<10;j++)
                enemy_board[i][j]='0';
        
        count = 0;
    }
    
    /*
    ~Board()
    {
        delete[] shts_frd;
    }
    */
     
    /*
    void coorsTonum()
    {
        for(int i=0;i<5;i++)
        {
            //See if the string is a certain length and choose option based on it
            if(ships[i].length() == 5 || ships[i].length() == 6)
            {
            for(int j=0;j<5;j++)
            {   
                // Determine if the portion of the string is a letter and convert to
                // an int
                if(isalpha(ships[i][j]))
                    ship_coors[i][j] = ships[i][j] - 64;

                // Determine if the portion of the string is a number and convert to 
                // an int
                if(isdigit(ships[i][j]) && ships[i][j+1] == '0')
                {
                    ship_coors[i][j] = 10;
                    break;
                } 
                else if(isdigit(ships[i][j]))
                {
                    ship_coors[i][j] = ships[i][j] - 48;
                }
                // Determine if the portion of the string is a space
                if(isspace(ships[i][j]))
                    ship_coors[i][j] = 0;
            }
            }
            else
            {
                //Convert string of chars to usable number coordinates
                ship_coors[i][0] = ships[i][0] - 64;
                ship_coors[i][3] = ships[i][4] - 64;
                ship_coors[i][2] = 0;
                ship_coors[i][1] = 10;
                ship_coors[i][4] = 10;
            }
        }
    }
    
    //Function used to have the converted coordinates format the player boards with
    //each of their ships
    void numToboard()
    { 
        // Initialize empty board layout
        for(int i=0;i<11;i++)
            for(int j=0;j<11;j++)
            {
                player_board[i][j] = '0';
                enemy_board[i][j] = '0';
            }  

        // Place X's that represent ships on the player's boards
        for(int i=0;i<5;i++)
        {
        if(ship_coors[i][0] == ship_coors[i][3])
            for(int k=(ship_coors[i][1]-1);k<ship_coors[i][4];k++)
                player_board[(ship_coors[i][0]-1)][k] = 'X';
        else
            for(int a=(ship_coors[i][0]-1);a<ship_coors[i][3];a++)
                player_board[a][(ship_coors[i][1]-1)] = 'X';
        }    
    }
    */
    
    //Function used to have player 1 shoot at player 2, output hits and ships hit or
//missed, and decide if the game is over yet
    //template <class T>
    /*
bool shooting1()
{
    //Declare Variables
    int num[2];    //Array holding converted user number coordinates
    int hits = 0;  //Number of ship coordinates not yet shot
    int count = 0; //Counter used to determine what kind of ship was hit
    
    // Initial shot user input
    cout << endl << "    " << player_name << ", where to shoot? ";
    getline(cin,shts_frd[count]);
    cout << endl;
    
    //Check to see if player wants to quit the game
    if(shts_frd[count][0] == 'Q' || shts_frd[count][0] == 'q')
    {
        cout << "    Game over!" << endl << endl;
        return true;
    }
        
    // Input Validation for user shot input
    while(!isalpha(shts_frd[count][0]) 
          && !isupper(shts_frd[count][0])  
          || !isdigit(shts_frd[count][1]))
    {
        cout << "Please input a correct coordinate. (ex. A10, B7, I3)" << endl;
        cout << endl << "    " << player_name << ", where to shoot? ";
        getline(cin,shts_frd[count]);
        cout << endl;
    } 
     
    // Convert the input coordinates into usable number coordinates
    for(int j=0;j<2;j++)
    {   
        if(isalpha(shts_frd[count][j]))
            num[j] = shts_frd[count][j] - 64;
 
        if(isdigit(shts_frd[count][j]) && shts_frd[count][j+1] == '0')
        { 
            num[j] = 10;
            break;
        }
        else if(isdigit(shts_frd[count][j]))
        {
            num[j] = shts_frd[count][j] - 48;
        }
    }  
      
    // Change the game board to show missed and hit shots and output it
    for(int m=0;m<11;m++)
    {   
        for(int l=0;l<11;l++)
        {
            if(l == num[1] && m == num[0])
            {
                if(player_board[m-1][l-1]== 'X')
                {
                    //Output that a ship has been hit
                    cout << "    !!!!! It was a Hit! !!!!!" << endl;
                    enemy_board[m-1][l-1] = 'H';
                    player_board[m-1][l-1] = 'H';
                    
                    //Determine what ship has been shot at
                    for(int x=0;x<5;x++)
                    {
                        if(m >= ship_coors[x][0] && m <= ship_coors[x][3] 
                           && l == ship_coors[x][1] &&  l == ship_coors[x][4])
                        {
                            //Length of the ship shot used for output
                            count = (ship_coors[x][3]+1) - ship_coors[x][0];
                            
                            //Output which ship was hit
                            if(count == 5)
                                cout << "    ! You hit their Carrier !" 
                                     << endl; 
                            else if(count == 4)
                                cout << "    ! You hit their Battleship !" 
                                     << endl;
                            else if(count == 3)
                                cout << "    ! You hit their Submarine or" 
                                     << " Cruiser !" << endl;
                            else if(count == 2)
                                cout << "    ! You hit their Destroyer !" 
                                     << endl;
                        }
                        else if(l >= ship_coors[x][1] && l <= ship_coors[x][4] 
                           && m == ship_coors[x][0] &&  m == ship_coors[x][3])
                        {
                            //Length of the ship shot used for output
                            count = (ship_coors[x][4]+1) - ship_coors[x][1];
                            
                            //Output which ship was hit
                            if(count == 5)
                                cout << "    ! You hit their Carrier !" 
                                     << endl; 
                            else if(count == 4)
                                cout << "    ! You hit their Battleship !" 
                                     << endl;
                            else if(count == 3)
                                cout << "    ! You hit their Submarine or" 
                                     << " Cruiser !" << endl;
                            else if(count == 2)
                                cout << "    ! You hit their Destroyer !" 
                                     << endl;
                        }
                    }
                }
                else
                {
                    //Output that the shot has missed hitting any ships and 
                    //record it
                    cout << "    !!!!! It was a Miss! !!!!!" << endl;
                    enemy_board[m-1][l-1] = 'M';
                    player_board[m-1][l-1] = 'M';
                }
            }
        }  
    }
       
    // Detect to see if there are any ships coordinates not shot yet
    for(int z=0;z<11;z++)
        for(int y=0;y<11;y++)
            if(player_board[z][y] == 'X')
                hits++;
     
    // Condition to see if the game has ended yet   
    if(hits == 0)
    {
            cout << endl << "    " << player_name
                 << " has won the game!" << endl << endl;
            return true;
    }
    
    // Increase count for recording shots
    count++;
        
    // Return false if the game hasn't ended
    return false;
}
};
 */
};

#endif /* BOARD_H */

