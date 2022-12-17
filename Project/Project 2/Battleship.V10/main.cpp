/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on December 4th, 2022, 7:49 PM
 * Purpose:  Version 10 (Final Version) - Battleship
 *   
 * Create a functional game of BattleShip, implementing many of the programming 
 * concepts from Chapter 13 to 16, while following the rules of the original 
 * board game which are:
 *      
 * 1. Players place their 5 ships on their player board, the rules here are:
 * 
 *  - Place each ship in any horizontal or vertical position, but not 
 *    diagonally.
 *  - Do not place a ship so that it overlaps the edge of the board or another
 *    ship.
 *  - Do not change the position of any ship once the game has begun.
 * 
 * 2. Decide who will go first, each player will alternate turns, calling out 
 *    one shot per turn to try and hit each other's ships.
 * 
 * 3. On your turn, pick a target hole on your enemy board and call out its 
 *    location by the letter and number. Each target hole has a letter-number 
 *    coordinate that corresponds with the same coordinate on your
 *    enemy's board. To determine each coordinate, find its 
 *    corresponding letter on the left side of the target board and its number 
 *    on the top of the board. For example, when you call a shot, your opponent 
 *    must tell you whether your shot is a hit or a miss.
 *   
 * 4. It's a Hit - If you call out a shot location that is occupied by a ship on
 *    your enemy's board, your shot is a hit! Your opponent tells you which ship
 *    you have hit (cruiser, submarine, etc.). Your shots will be recorded for 
 *    you on each of the boards. Your opponent's board will be updated in the 
 *    corresponding hole of the ship you have hit on his or her board.
 *
 * 5. It's a Miss - If you call out a shot location not occupied by a ship on 
 *    your opponent's board, it's a miss. The board will record this move, so 
 *    you cannot call this shot again.
 *    
 *    Play continues in this manner, with you and your opponent calling one shot
 *    per turn.
 * 
 * 6. Once all the holes in any one ship are hit then the ship is considered
 *    sunk. The owner of the ship must announce which ship was sunk.
 * 
 * 7. If you're the first player to sink your opponents entire fleet of 5 ships,
 *    you win the game!  
 *  
 */ 
      
//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <cstring>
#include "Board.h"
using namespace std;
    
//Function Prototype
void game_start(Board []);      //Get both player's names and ship coordinates

//Execution of Code Begins Here
int main(int argc, char** argv) 
{ 
    //Declare all variables
    bool gme_ovr;   //The bool variable gotten from the shooting functions 
                    //telling whether or not the game has ended or not
    char choice;    //Char variable for the choice
    Board play[2];  //Array of object variables used for the game
    
    //Receive both player's starting information
    game_start(play);
    
    //Check to see if each player has unique names and coordinates
    if(play[0] == play[1])
    {
        cout << endl << " You cannot have the same names and ship "
             << "coordinates. Please Try Again." << endl;
    }
    else if(play[0] != play[1])
    {
        
    cout << endl << "   Name and Coordinates look good to go..." << endl;
     
    //Set the player coordinates
    play[0].coorsTonum1();
    play[1].coorsTonum2();
    
    //Set the players board up
    play[0].numToboard1();
    play[1].numToboard2();
    
    //Loop for each player's turn, shooting their shots until someone wins
    while(!gme_ovr)
    {   
        //Start Player 1's turn
        cout << endl << "    " << play[0].getplyrnm() << " it's your turn!!!"
             << endl << endl;
        play[0].disp_board1();  
        gme_ovr = play[0].shooting1();
        
        //End game if necessary
        if(gme_ovr)
            break;
           
        //Start Player 2's turn
        cout << endl << "    " << play[1].getplyrnm() << " it's your turn!!!" 
             << endl << endl;
        play[1].disp_board2();  
        gme_ovr = play[1].shooting2();
    } 
    
    //Prompt players to input choice for Players Info
    cout << "     Would you like to view the overall Players Recap? (Y/N) ";
     cin >> choice;
         
    //Use choice input to determine what to input for end of program
    if(choice == 'Y' || choice == 'y')
    {
        play[0].results1();
        play[1].results2();
        cout << endl << "    Thank you for Playing!!! " << endl;
    } 
    else if(choice == 'N' || choice == 'n')
        cout << endl << "     Thank you for Playing!!! " << endl;
    
    }
    
    //Exit Stage Right
    return 0;
}
 
//Function for receiving all player information including name and ship 
//coordinates
void game_start(Board play[])
{ 
    //Declare Variables
    char choice;         //Char variable holding player choice
    int numshps = 5;     //Number of ships per player
    string player_name;  //String Array holding the name of the player
    string ships[5];        //String Array holding the ship coordinates input 
                            //by the player
    //String array holding the ship names
    string ship_name[5] = {"Carrier", "Battleship", "Cruiser", 
                           "Submarine", "Destroyer"};
    bool tryagain = true;   //Bool variable for exception loop
    
    //Ask player if they would like to see example input
    cout << endl << " Would you like to see some example player input? (Y/N) ";
     cin >> choice;
    cout << endl;
     
    //Output player choice response
    play[0].setchoice(choice);
        
    //Formatting
    cin.ignore(1); 
      
    //Loop to get input for each player
    for(int i=0; i<2;i++)
    {
        // Get Name of Player
        cout << endl << "Name for Player #" << (i+1) << ": ";
        getline(cin, player_name);
        cout << endl;
         
        //Set player name to corresponding player object
        play[i].setplyrnm(player_name);
 
        //Prompt user to input ship coordinates
        cout << "            --- " << play[i].getplyrnm()
             << " choose you Ship Locations ---" << endl;
        cout << "Select the coordinates for each ship "
             << "(ex. input A1 A5, for the carrier)" << endl << endl;
        
        //Loop for ship coordinates input
        for(int j=0;j<numshps;j++)
        {
            //Input the ship coordinates
            cout << setw(20) << ship_name[j] << ": ";
            getline(cin,ships[j]);
        } 
         
        //Reset the bool variable for loop
        tryagain = true;
         
        //Catch exceptions and mistakes in ship coordinate input
        while(tryagain)
        { 
            try
            {
                //Set the ships coordinates into corresponding player object
                play[i].setships(ships);
                tryagain = false;
            }
            catch(Player::BadShips)
            {
                //Prompt the user to enter valid input
                cout << endl << " Please follow the input format for the ship "
                    << "coordinates. (ex. B3 B7)" << endl << endl;

                //Loop for ship coordinates input
                for(int j=0;j<numshps;j++)
                {
                    //Input the ship coordinates
                    cout << setw(20) << ship_name[j] << ": ";
                    getline(cin,ships[j]);
                } 
            }
        }
    }
}
 