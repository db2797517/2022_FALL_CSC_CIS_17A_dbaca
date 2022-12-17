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
    static int ship_coors1[20][20]; //Number Array with the number coordinates converted
                            //from user input
    static int ship_coors2[20][20]; //Number Array with the number coordinates converted
                            //from user input
    string * shts_frd = new string[100]; //Dynamic String Array holding the 
                                         //shots fired by the player
    static char player1_board[10][10]; //C-string array holding the players board moves
    static char enemy2_board[10][10];  //C-string array holding the enemy board moves
    static char player2_board[10][10]; //C-string array holding the players board moves
    static char enemy1_board[10][10];  //C-string array holding the enemy board moves
public:
    
    Board()
    {
        for(int i=0;i<20;i++)
            for(int j=0;j<20;j++)
                ship_coors1[i][j]=0;
        
        for(int i=0;i<20;i++)
            for(int j=0;j<20;j++)
                ship_coors2[i][j]=0;
 
       // for(int i=0;i<100;i++)  
        //    shts_frd[i] = " ";
        
  
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
    
    ~Board()
    {
        delete[] shts_frd;
    }
    
    Board(Board &obj)
    {
        shts_frd = new string[100];
    }
    
    void coorsTonum1()
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
                    ship_coors1[i][j] = ships[i][j] - 64;

                // Determine if the portion of the string is a number and convert to 
                // an int
                if(isdigit(ships[i][j]) && ships[i][j+1] == '0')
                {
                    ship_coors1[i][j] = 10;
                    break;
                } 
                else if(isdigit(ships[i][j]))
                {
                    ship_coors1[i][j] = ships[i][j] - 48;
                }
                // Determine if the portion of the string is a space
                if(isspace(ships[i][j]))
                    ship_coors1[i][j] = 0;
            }
            }
            else
            {
                //Convert string of chars to usable number coordinates
                ship_coors1[i][0] = ships[i][0] - 64;
                ship_coors1[i][3] = ships[i][4] - 64;
                ship_coors1[i][2] = 0;
                ship_coors1[i][1] = 10;
                ship_coors1[i][4] = 10;
            }
        }
    }
    
    void coorsTonum2()
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
                    ship_coors2[i][j] = ships[i][j] - 64;

                // Determine if the portion of the string is a number and convert to 
                // an int
                if(isdigit(ships[i][j]) && ships[i][j+1] == '0')
                {
                    ship_coors2[i][j] = 10;
                    break;
                } 
                else if(isdigit(ships[i][j]))
                {
                    ship_coors2[i][j] = ships[i][j] - 48;
                }
                // Determine if the portion of the string is a space
                if(isspace(ships[i][j]))
                    ship_coors2[i][j] = 0;
            }
            }
            else
            {
                //Convert string of chars to usable number coordinates
                ship_coors2[i][0] = ships[i][0] - 64;
                ship_coors2[i][3] = ships[i][4] - 64;
                ship_coors2[i][2] = 0;
                ship_coors2[i][1] = 10;
                ship_coors2[i][4] = 10;
            }
        }
    }
    
    //Function used to have the converted coordinates format the player boards with
    //each of their ships
    void numToboard1()
    { 
        // Initialize empty board layout
        for(int i=0;i<10;i++)
            for(int j=0;j<10;j++)
            {
                player1_board[i][j] = '0';
                enemy2_board[i][j] = '0';
            }  

        // Place X's that represent ships on the player's boards
        for(int i=0;i<5;i++)
        {
        if(ship_coors1[i][0] == ship_coors1[i][3])
            for(int k=(ship_coors1[i][1]-1);k<ship_coors1[i][4];k++)
                player1_board[(ship_coors1[i][0]-1)][k] = 'X';
        else
            for(int a=(ship_coors1[i][0]-1);a<ship_coors1[i][3];a++)
                player1_board[a][(ship_coors1[i][1]-1)] = 'X';
        }    
    }
    
    //Function used to have the converted coordinates format the player boards with
    //each of their ships
    void numToboard2()
    { 
        // Initialize empty board layout
        for(int i=0;i<10;i++)
            for(int j=0;j<10;j++)
            {
                player2_board[i][j] = '0';
                enemy1_board[i][j] = '0';
            }  

        // Place X's that represent ships on the player's boards
        for(int i=0;i<5;i++)
        {
        if(ship_coors2[i][0] == ship_coors2[i][3])
            for(int k=(ship_coors2[i][1]-1);k<ship_coors2[i][4];k++)
                player2_board[(ship_coors2[i][0]-1)][k] = 'X';
        else
            for(int a=(ship_coors2[i][0]-1);a<ship_coors2[i][3];a++)
                player2_board[a][(ship_coors2[i][1]-1)] = 'X';
        }    
    }
    
    //Function used to have player 1 shoot at player 2, output hits and ships hit or
//missed, and decide if the game is over yet
    //template <class T>

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
                if(player2_board[m-1][l-1]== 'X')
                {
                    //Output that a ship has been hit
                    cout << "    !!!!! It was a Hit! !!!!!" << endl;
                    player2_board[m-1][l-1] = 'H';
                    enemy1_board[m-1][l-1] = 'H';
                    
                    //Determine what ship has been shot at
                    for(int x=0;x<5;x++)
                    {
                        if(m >= ship_coors2[x][0] && m <= ship_coors2[x][3] 
                           && l == ship_coors2[x][1] &&  l == ship_coors2[x][4])
                        {
                            //Length of the ship shot used for output
                            count = (ship_coors2[x][3]+1) - ship_coors2[x][0];
                            
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
                        else if(l >= ship_coors2[x][1] && l <= ship_coors2[x][4] 
                           && m == ship_coors2[x][0] &&  m == ship_coors2[x][3])
                        {
                            //Length of the ship shot used for output
                            count = (ship_coors2[x][4]+1) - ship_coors2[x][1];
                            
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
                    enemy1_board[m-1][l-1] = 'M';
                    player2_board[m-1][l-1] = 'M';
                }
            }
        }  
    }
       
    // Detect to see if there are any ships coordinates not shot yet
    for(int z=0;z<11;z++)
        for(int y=0;y<11;y++)
            if(player2_board[z][y] == 'X')
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

    //Function used to have player 1 shoot at player 2, output hits and ships hit or
//missed, and decide if the game is over yet
    //template <class T>

bool shooting2()
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
                if(player1_board[m-1][l-1]== 'X')
                {
                    //Output that a ship has been hit
                    cout << "    !!!!! It was a Hit! !!!!!" << endl;
                    enemy2_board[m-1][l-1] = 'H';
                    player1_board[m-1][l-1] = 'H';
                    
                    //Determine what ship has been shot at
                    for(int x=0;x<5;x++)
                    {
                        if(m >= ship_coors1[x][0] && m <= ship_coors1[x][3] 
                           && l == ship_coors1[x][1] &&  l == ship_coors1[x][4])
                        {
                            //Length of the ship shot used for output
                            count = (ship_coors1[x][3]+1) - ship_coors1[x][0];
                            
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
                        else if(l >= ship_coors1[x][1] && l <= ship_coors1[x][4] 
                           && m == ship_coors1[x][0] &&  m == ship_coors1[x][3])
                        {
                            //Length of the ship shot used for output
                            count = (ship_coors1[x][4]+1) - ship_coors1[x][1];
                            
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
                    enemy2_board[m-1][l-1] = 'M';
                    player1_board[m-1][l-1] = 'M';
                }
            }
        }  
    }
        
    // Detect to see if there are any ships coordinates not shot yet
    for(int z=0;z<11;z++)
        for(int y=0;y<11;y++)
            if(player1_board[z][y] == 'X')
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

// Function used to display the boards for each player on their turns
void disp_board1()
{
    // The char array for letters in the game board
    char letters[10] = {'A','B','C','D','E','F','G','H','I','J'};
      
    // Format the output and general layout of the game boards
    cout << "           -------- Enemy Board -----------        "
         << "X = Your ships" << endl
         << "        1   2   3   4   5   6   7   8   9   10"
         << "     H = The enemy ship has been hit" << endl
         << "        _   _   _   _   _   _   _   _   _   _ "
         << "     M = Your shot has not hit any ships" << endl << endl;
    
    // Loop for more accurate board displays
    for(int x=0;x<10;x++)    
    {
        cout << "   " << letters[x] << "  ";
                
        for(int z=0;z<10;z++)
            cout << "| " << enemy1_board[x][z]<< " ";
        
        cout << "|" << endl 
             << "      -   -   -   -   -   -   -   -   -   -   -"<< endl;
    }

    //Formatting
    cout << endl;
     
    // Format the output and general layout of the game boards
    cout << "           -------- Player Board -----------       "
         << "X = Your ships" << endl
         << "        1   2   3   4   5   6   7   8   9   10"
         << "     H = Your ship has been hit" << endl
         << "        _   _   _   _   _   _   _   _   _   _ "
         << "     M = The enemy has missed your ships" << endl << endl;
    
    // Loop for more accurate board displays
    for(int x=0;x<10;x++)    
    {
        cout << "   " << letters[x] << "  ";
                
        for(int z=0;z<10;z++)
            cout << "| " << player1_board[x][z]<< " ";
        
        cout << "|" << endl 
             << "      -   -   -   -   -   -   -   -   -   -   -"<< endl;
    }
    
    //Formatting
    cout << endl;
}

// Function used to display the boards for each player on their turns
void disp_board2()
{
    // The char array for letters in the game board
    char letters[10] = {'A','B','C','D','E','F','G','H','I','J'};
      
    // Format the output and general layout of the game boards
    cout << "           -------- Enemy Board -----------        "
         << "X = Your ships" << endl
         << "        1   2   3   4   5   6   7   8   9   10"
         << "     H = The enemy ship has been hit" << endl
         << "        _   _   _   _   _   _   _   _   _   _ "
         << "     M = Your shot has not hit any ships" << endl << endl;
    
    // Loop for more accurate board displays
    for(int x=0;x<10;x++)    
    {
        cout << "   " << letters[x] << "  ";
                
        for(int z=0;z<10;z++)
            cout << "| " << enemy2_board[x][z]<< " ";
        
        cout << "|" << endl 
             << "      -   -   -   -   -   -   -   -   -   -   -"<< endl;
    }

    //Formatting
    cout << endl;
     
    // Format the output and general layout of the game boards
    cout << "           -------- Player Board -----------       "
         << "X = Your ships" << endl
         << "        1   2   3   4   5   6   7   8   9   10"
         << "     H = Your ship has been hit" << endl
         << "        _   _   _   _   _   _   _   _   _   _ "
         << "     M = The enemy has missed your ships" << endl << endl;
    
    // Loop for more accurate board displays
    for(int x=0;x<10;x++)    
    {
        cout << "   " << letters[x] << "  ";
                
        for(int z=0;z<10;z++)
            cout << "| " << player2_board[x][z]<< " ";
        
        cout << "|" << endl 
             << "      -   -   -   -   -   -   -   -   -   -   -"<< endl;
    }
    
    //Formatting
    cout << endl;
}

}; 

int Board::ship_coors1[20][20] = {}; 
int Board::ship_coors2[20][20] = {}; 
char Board::player1_board[10][10] = {};
char Board::enemy2_board[10][10] = {};
char Board::player2_board[10][10] = {};
char Board::enemy1_board[10][10] = {};

#endif /* BOARD_H */

