/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on October 14th, 2022, 3:22 PM
 * Purpose:  Version 1 - Battleship
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
 *    you won't call this shot again.
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
using namespace std;

//User Libraries
 
//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Structure for all player information
struct Playerinfo 
{ 
    string player_name; //String Array holding the name of the player
    string ships[5];    //String Array holding the ships coordinates input 
                        //by the player
    //String array holding the names of each ship
    string ship_name[5] = {"Carrier", "Battleship", "Cruiser", 
                           "Submarine", "Destroyer"};
    
    int player_board[10][10]; //Array holding the players board moves
    int enemy_board[10][10];  //Array holding the enemy board moves
    
};

//Function Prototypes
Playerinfo game_start(int num); //Get both player's names and ship coordinates
// int *coin_flip(int *coin);   //Get the result of the coin flip
void disp_board(struct Playerinfo players[], int SIZE, int count); //Display 
                                            //both players game boards
Playerinfo coorTonum(); //Convert string input to usable coordinates
    
//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all variables for this function
    const int SIZE = 2;     //Size of the array
    struct Playerinfo players[SIZE];  //Dynamically create array of structures
    int count=0; //Counter
    int *coin;   //Coin pointer variables
    
    //Get both players sets of starting information
    for(int j=0;j<2;j++)
    players[j]=game_start(j);
    
    /* Test some info out about the ships array
    int x =0, y=0;

    x = players[0].ships[0][3] - 64;
    y = players[0].ships[0][4] -48;
    
    cout << x << " " << y;
    */
    
    //Initialize 2D int array
    int ary[20][20];
      
    //Try to convert string input into usable number coordinates
    for(int i=0;i<5;i++)
    {
        cout << "hi" << endl;
        for(int j=0;j<10;j++)
        {   
            // Determine if the portion of the string is a letter and convert to
            // an int
            if(isalpha(players[0].ships[i][j]))
            {
                ary[i][j] = players[0].ships[i][j] - 64;
            cout << ary[i][j] << " ";
            }

            // Determine if the portion of the string is a number and convert to 
            // an int
            if(isdigit(players[0].ships[i][j]) && players[0].ships[i][j+1] == '0')
            {
                ary[i][j] = 10;
                        cout << ary[i][j] << " ";
            }
            else if(isdigit(players[0].ships[i][j]))
            {
                ary[i][j] = players[0].ships[i][j] - 48;
                        cout << ary[i][j] << " ";
            } 
        }
    }
    
    //Output the number coordinates
    for(int i=0;i<5;i++)
        for(int j=0;j<10;j++)
            cout << ary[i][j] << " " ;
    
    // coin=coin_flip(coin);
    // cout << coin;
    
    //Call the function to find out who has won the coin flip
    // cout << players[*coin].player_name << " has won the Coin Flip and will go First!!!!";
    
    //Function to display the players boards
    //disp_board(players,SIZE,count);
    
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
Playerinfo game_start(int num)
{
    //Declare variables
    struct Playerinfo players; //Temporary Structure
    
    //Prompt the player to input their name
    cout << "Name for Player #" << (num+1) << ": ";
    getline(cin, players.player_name);
    
    //Output prompt to player to input ship coordinates
    cout << "  --- " << players.player_name 
         << " choose you Ship Locations ---" << endl;
      
    //Prompt the player to input their ship coordinates
    for(int j=0;j<5;j++)
        {
            cout << "Coordinates for your " << players.ship_name[j] << ": ";
            getline(cin,players.ships[j]);
        }
    
    //Return the temporary structure created
    return players;
}

/* Potentially work on a coin flip function to determine which Player is going 
 * first
int *coin_flip(int *coin)
{
    
    *coin = rand()%(2-1 + 1) + 1;
    return coin;
}
 */

//Function used to convert players string input to usable int number coordinates
//for the rest of the program 
Playerinfo coorTonum()
{
    //Declare Variables
    struct Playerinfo players; //Temporary structure 
    int ary[100];              //Array used to store number input coordinates 
    
    //Char array holding each letter for board output
    char letters[10] = {'A','B','C','D','E','F','G','H','I','J'};
    
    /* Code trying to convert players string input to usable number coordinates
    for(int i=0;i<5;i++)
        for(int j=0;j<sizeof(players.ships[i]);j++)
        {
            if(isalpha(players.ships[i][j])
            {
                int ary[]
            }
            else if(isdigit(players.ships[i][j]))
            {
                
            }
                
                        
        }
    */
    
    //Return the structure created
    return players;
}

// Function used to display the boards for each player on their turns
void disp_board(struct Playerinfo players[],int SIZE,int count)
{
    //Initialize the player board array but only once
    if(!(count == 1));
        for(int k=0;k<2;k++)
        {
            count++;
            
            for(int i=0;i<10;i++)
                for(int j=0;j<10;j++)
                    players[k].player_board[i][j] = 0;
        }
          
    //Char array holding each letter for board output
    char letters[10] = {'A','B','C','D','E','F','G','H','I','J'};
    
    //Begin board format output
    cout << "        1   2   3   4   5   6   7   8   9   10" << endl
         << "        _   _   _   _   _   _   _   _   _   _ " << endl << endl;
    
    //Output the rest of board output
    for(int x=0;x<10;x++)    
    {
        cout << "   " << letters[x] << "  ";
                
        for(int z=0;z<10;z++)
            cout << "| " << players[0].player_board[x][z]<< " ";
        
        cout << "|" << endl 
             << "      -   -   -   -   -   -   -   -   -   -   -"<< endl;
    }    
}