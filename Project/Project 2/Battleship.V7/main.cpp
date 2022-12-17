/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on November 23rd, 2022, 8:39 PM
 * Purpose:  Version 7 - Battleship
 *   
 * Create a functional game of BattleShip, implementing many of the programming 
 * concepts from Chapter 9 to 12, while following the rules of the original 
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
#include "Player.h"
#include "AbsPlayer.h"
using namespace std;
 
/*
struct Playerinfo 
{
    char player_name[100];  //C-string Array holding the name of the player
    string ships[5];        //String Array holding the ship coordinates input 
                            //by the player
    int ship_coors[20][20]; //Number Array with the number coordinates converted
                            //from user input
    //string * shts_frd = new string[100]; //Dynamic String Array holding the 
                                         //shots fired by the player
    char player_board[10][10]; //C-string array holding the players board moves
    char enemy_board[10][10];  //C-string array holding the enemy board moves
      
    //String array holding the names of each ship
    string ship_name[5] = {"Carrier", "Battleship", "Cruiser", 
                           "Submarine", "Destroyer"};
};
 

//Structure holding information needed for the array of structures
struct Players
{
    const int SIZE = 2;    //Size of the array of structures
    const int numshps = 5; //Variable for number of ships
    //Playerinfo * info;     //Pointer holding the array of structures
}; 
*/

//Enum format for player boards output loop
//enum grid {A,B,C,D,E,F,G,H,I,J,K};
    
//Function Prototypes
void game_start(Board []);      //Get both player's names and ship coordinates

//Execution of Code Begins Here
int main(int argc, char** argv) 
{ 
    //Declare all variables
    //struct Players * plyrs = new Players; //Dynamic Structure for Players
    
    //int count1=0;   //A counter for the number of times players 1 has shot at 
                    //Player 2
    //int count2=0;   //A counter for the number of times players 2 has shot at 
                    //Player 1
    bool gme_ovr;   //The bool variable gotten from the shooting functions 
                    //telling whether or not the game has ended or not
    //char choice;    //The character input for whether or not to have endgame 
                    //review
    
    Board play[2];  
      
    //Declare the two text files
    ofstream plyr_1file;
    ofstream plyr_2file;
     
    //Open the binary file
    fstream file;
    file.open("Players Info", ios:: in | ios::out | ios:: binary);
     
    //Open the two text files
    plyr_1file.open("Player_1");
    plyr_2file.open("Player_2");
     
    //Display the beginning of the board game
    cout << "        ----------- Battleship -----------" << endl
         << "        The classic strategy board game!!!" << endl;
    cout << "          ----- Somethings to know -----" << endl
         << "           Carrier Size (5 spaces)" << endl
         << "        Battleship Size (4 spaces)" << endl       
         << "           Cruiser Size (3 spaces)" << endl
         << "         Submarine Size (3 spaces)" << endl         
         << "         Destroyer Size (2 spaces)" << endl << endl
         << "  --- Keep this in mind for when you place your ships!!! ---"
         << endl << "  --- Once the game starts and each player can shoot ---" 
         << endl << "  --- you can input Q to Quit the Game whenever.     ---"
         << endl << endl;
      
    //Receive both player's starting information
    
    game_start(play);
    
    play[0].coorsTonum1();
    play[1].coorsTonum2();
    
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
    
    return 0;
}
  
// Function for receiving all player information including name and ship 
// coordinates
void game_start(Board play[])
{ 
    //Declare Variables
    //struct Players * plyrs = new Players;      //Dynamic array structure  
    //plyrs->info = new Playerinfo[plyrs->SIZE]; //for function
    char choice;
    int numshps = 5;
    string player_name;  //C-string Array holding the name of the player
    string ships[5];        //String Array holding the ship coordinates input 
                            //by the player
    string ship_name[5] = {"Carrier", "Battleship", "Cruiser", 
                           "Submarine", "Destroyer"};
    bool tryagain = true;
    
    //Ask player if they would like to see example input
    cout << "Would you like to see some example player input? (Y/N) ";
     cin >> choice;
     
    //Use choice input to determine what to input for end of program
    if(choice == 'Y' || choice == 'y')
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
        
    //Formatting
    cin.ignore(1); 
      
    //Loop to get input for each player
    for(int i=0; i<2;i++)
    {
        // Get Name of Player
        cout << endl << "Name for Player #" << (i+1) << ": ";
        getline(cin, player_name);
        cout << endl;
         
        play[i].setplyrnm(player_name);
        
        //if(i != 1)
        //play[i] = play[i+1];
 
        // Prompt user to input ship coordinates
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
        
        tryagain = true;
        
        while(tryagain)
        {
            try
            {
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
 