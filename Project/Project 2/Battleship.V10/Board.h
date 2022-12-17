/* 
 * File:   Board.h
 * Author: Daniel Baca
 *
 * Created on November 23, 2022, 8:39 PM
 */
 
#ifndef BOARD_H
#define BOARD_H
 
//System Libraries
#include "Player.h"
#include "Choice.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <cstring>
using namespace std;
  
//Board class holding board related info for each player as the game goes on
class Board : public Player
{  
private:
    static int ship_coors1[20][20]; //Player 1's number Array with the number 
                                    //coordinates converted from user input
    static int ship_coors2[20][20]; //Player 2's number Array with the number 
                                    //coordinates converted from user input
    string * shts_frd = new string[100]; //Dynamic String Array holding the 
                                         //shots fired by the player
    Choice<char> output;    //Aggregated class for initial output response
    static char player1_board[10][10]; //C-string array holding Player 1's player 
                                       //board moves
    static char enemy2_board[10][10];  //C-string array holding Player 2's enemy
                                       //board moves
    static char player2_board[10][10]; //C-string array holding Player 2's player
                                       //board moves
    static char enemy1_board[10][10];  //C-string array holding Player 1's enemy
                                       //board moves
    static int count1; //Counter used to keep track of how many shots Player 1 
                       //has made
    static int count2; //Counter used to keep track of how many shots Player 2 
                       //has made
public:
    //Initial Constructor
    Board()
    {
        //Initialize the ship coordinates
        for(int i=0;i<20;i++)
            for(int j=0;j<20;j++)
                ship_coors1[i][j]=0;
        
        for(int i=0;i<20;i++)
            for(int j=0;j<20;j++)
                ship_coors2[i][j]=0;  
  
        //Initialize the player boards
        for(int i=0;i<10;i++)
            for(int j=0;j<10;j++)
                player1_board[i][j]='0';
        
        for(int i=0;i<10;i++)
            for(int j=0;j<10;j++)
                enemy1_board[i][j]='0';
        
        for(int i=0;i<10;i++)
            for(int j=0;j<10;j++)
                player2_board[i][j]='0';
        
        for(int i=0;i<10;i++)
            for(int j=0;j<10;j++)
                enemy2_board[i][j]='0';
    }
    
    //Overloaded == operator
    bool operator==(Board &same)
    {
        int num = 0; //Temporary counter variable
        
        //Determine if the player names are the same
        if(player_name==same.player_name)
        {
            //Check to see if the ships coordinates are the same
            for(int i=0;i<5;i++)
            {
                if(ships[i]==same.ships[i])
                    num++;
            }
             
            //Return true if the two objects have the same values
            if(num == 5)
            return true;
        }
        
        //Return false if the two objects don't have the same values
        return false;
    }
    
    //Overloaded != operator
    bool operator!=(Board &same)
    {
        int num = 0; //Temporary counter variable
        
        if(player_name!=same.player_name)
            return true;
        
        for(int i=0;i<5;i++)
        {
            if(ships[i]==same.ships[i])
                num++;
        }
               
        //Return true if the two objects don't have the same values
        if(num < 5)
        return true;
        
        //Return false if the two objects do have the same values
        return false;
    }
    
    //Destructor 
    ~Board()
    {
        delete[] shts_frd;
    }
    
    //Copy Constructor
    Board(Board &obj)
    {
        shts_frd = new string[100];
          
        for(int i=0;i<100;i++)
            shts_frd[i] = obj.shts_frd[i];
    }
     
    //Function prototypes
    void coorsTonum1();
    void coorsTonum2();
    void numToboard1();
    void numToboard2();
    bool shooting1();
    bool shooting2();
    void disp_board1();
    void disp_board2();
    void results1();
    void results2();
     
    //Set player name function
    void setplyrnm(string pn)
    {
        player_name = pn;
    }
    
    //Get player name function
    string getplyrnm()
    {
        return player_name;
    }
    
    //Setchoice function to get player initial response
    void setchoice(char c)
    {
        cout << output;
        output.respond(c);
    }  
};  
 
#endif /* BOARD_H */

