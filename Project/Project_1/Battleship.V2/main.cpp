/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on October 15th, 2022, 9:34 PM
 * Purpose:  Version 2 - Battleship
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
#include <iostream>  //I/O Librplayers.ship_coors
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <cstring>
using namespace std;
 
//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Structure for all player information
struct Playerinfo 
{
    string player_name; //String Array holding the name of the player
    string ships[5];        //String Array holding the ships coordinates input 
                            //by the player
    
    //String array holding the names of each ship
    string ship_name[5] = {"Carrier", "Battleship", "Cruiser", 
                           "Submarine", "Destroyer"};
    int ship_coors[20][20]; //Number Array with the number coordinates converted
                            //from user input
    string shts_frd[100]; //String Array holding the shots fired by the 
                          //player
    char player_board[10][10]; //C-string array holding the players board moves
    char enemy_board[10][10];  //C-string array holding the players board moves
    
};

//Function Prototypes
Playerinfo game_start(int num); //Get both player's names and ship coordinates
// int *coin_flip(int *coin);   //Get the results of the coin flip

//Display Player 1's two game boards
void disp_board1(struct Playerinfo players[], int SIZE, ofstream &plyr_1file);

//Display Player 2's two game boards
void disp_board2(struct Playerinfo players[], int SIZE, ofstream &plyr_2file);

//Convert string input to usable coordinates
void coorTonum(struct Playerinfo players[],int SIZE,int count);

//Input converted coordinate to match player boards
void numToboard(struct Playerinfo players[],int SIZE,int count);

//Have Player 1 shoot at the enemy's board, show what was hit or missed and 
//endgame if necessary
bool shooting1(struct Playerinfo players[],int SIZE,int count);

//Have Player 2 shoot at the enemy's board, show what was hit or missed and 
//endgame if necessary
bool shooting2(struct Playerinfo players[],int SIZE,int count);

//Print each players move to their file
void prntTofile(struct Playerinfo players[],int SIZE,ofstream &plyr_1file);

//Print each players move to their file
void prntTofile(struct Playerinfo players[],int SIZE,ofstream &plyr_2file);

//Execution of Code Begins Here
int main(int argc, char** argv) 
{
    //Set the random number seed here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all variables for this function
    const int SIZE = 2; //Size of the array
    struct Playerinfo players[SIZE]; //Dynamic Array of Structures
    int count =0; //Counter
    int count1=0; //Second counter
    int count2=0; //Third counter
    int *coin;    //Coin Pointer
    bool gme_ovr; //Bool value for ending the game
     
    //Declare the two files
    ofstream plyr_1file;
    ofstream plyr_2file;
    
    //Open the two files
    plyr_1file.open("Player_1");
    plyr_2file.open("Player_2");
     
    //Display the beginning of the board game
    cout << " ----------- Battleship -----------" << endl
         << " The classic strategy board game!!!" << endl;
    
    cout << "----- Somethings to know -----" << endl
         << "    Carrier Size (5 spaces)" << endl
         << " Battleship Size (4 spaces)" << endl       
         << "    Cruiser Size (3 spaces)" << endl
         << "  Submarine Size (3 spaces)" << endl         
         << "  Destroyer Size (2 spaces)" << endl << endl
         << " --- Keep this in mind for when you place your ships!!! ---"
         << endl << endl;
     
    //Receive both player's information
    for(int j=0;j<2;j++)
        players[j]=game_start(j);
    
    //for(int j=0;j<2;j++)
    coorTonum(players, SIZE, count);
     
    //coin=coin_flip(coin);
    
    // cout << coin;
    
    // cout << players[*coin].player_name << " has won the Coin Flip and will go First!!!!";
    
    //Initialize the boards with 0's
    for(int z=0;z<2;z++)
        for(int i=0;i<10;i++)
            for(int j=0;j<10;j++)
            {
            players[z].player_board[i][j] = '0';
            players[z].enemy_board[i][j] = '0';
            }      
    
    //Setup the player boards to match their inputs
    numToboard(players, SIZE, count);
    
    //Loop for each player's turn, shooting their shots until someone wins
    while(!gme_ovr)
    {
        //Start Player 1's turn
        cout << "    " <<players[0].player_name << " it's your turn!!!" << endl;
        disp_board1(players,SIZE,plyr_1file);  
        gme_ovr = shooting1(players,SIZE, count1);
        
        //Start Player 2's turn
        cout << players[1].player_name << "it's your turn!!!" << endl;
        disp_board2(players,SIZE,plyr_2file);  
        gme_ovr = shooting2(players,SIZE, count2);
    }
    
    //Close the two files
    plyr_1file.close();
    plyr_2file.close();

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
  
// Function for receiving all player information including name and ship 
// coordinates
Playerinfo game_start(int num)
{
    struct Playerinfo players; // Temporary structure for function
            
    // Get Name of Player
    cout << endl << "Name for Player #" << (num+1) << ": ";
    getline(cin, players.player_name);
    cout << endl;
    
    // Prompt user to input ship coordinates
    cout << "            --- " << players.player_name 
         << " choose you Ship Locations ---" << endl;
    
    cout << "Select the coordinates for each ship "
         << "(ex. input A1 A5, for the carrier)" << endl << endl;
        
    //Loop for ship coordinates input
    for(int j=0;j<5;j++)
        {
            cout << setw(20) << players.ship_name[j] << ": ";
            getline(cin,players.ships[j]);  
        }
    
    //Return the temporary structure
    return players;
}

/* Function for getting coin flip result
int *coin_flip(int *coin)
{
    
    *coin = rand()%(2-1 + 1) + 1;
    return coin;
}
 */

// Function for converting user ship coordinates input to usable coordinates for 
// the game
void coorTonum(struct Playerinfo players[],int SIZE,int count)
{
    // Loop for each player and each subsequent string input for their ship 
    // coordinates
for(int x=0;x<2;x++)
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {   
            // Determine if the portion of the string is a letter and convert to
            // an int
            if(isalpha(players[x].ships[i][j]))
                players[x].ship_coors[i][j] = players[x].ships[i][j] - 64;

            // Determine if the portion of the string is a number and convert to 
            // an int
            if(isdigit(players[x].ships[i][j]) && players[x].ships[i][j+1] == '0')
            {
                players[x].ship_coors[i][j] = 10;
                break;
            }
            else if(isdigit(players[x].ships[i][j]))
            {
                players[x].ship_coors[i][j] = players[x].ships[i][j] - 48;
            }
            // Determine if the portion of the string is a space
            if(isspace(players[x].ships[i][j]))
                players[x].ship_coors[i][j] = 0;
        }
    }
} 
}

// Use the converted coordinates to format the player boards with each ship of 
// their ships
void numToboard(struct Playerinfo players[],int SIZE,int count)
{
    // Place X's that represent ships on the player's boards
    for(int z=0;z<2;z++)
    {
    for(int i=0;i<5;i++)
    {
    if(players[z].ship_coors[i][0] == players[z].ship_coors[i][3])
    {
        for(int k=(players[z].ship_coors[i][1]-1);k<players[z].ship_coors[i][4];k++)
            players[z].player_board[(players[z].ship_coors[i][0]-1)][k] = 'X';
    }
    else
    {
        for(int a=(players[z].ship_coors[i][0]-1);a<players[z].ship_coors[i][3];a++)
                    players[z].player_board[a][(players[z].ship_coors[i][1]-1)] = 'X';
    }
    }
    }     
}

//Function used to have player 1 shoot at player 2, output hits and ships hit or
//missed, and decide if the game is over yet
bool shooting1(struct Playerinfo players[],int SIZE,int count1)
{
    //Declare Variables
    int num[2]; //Array holding converted user number coordinates
    
    // Initial shot user input    
    cout << endl << players[0].player_name << ", where to shoot? ";
    getline(cin,players[0].shts_frd[count1]);
    cout << endl;
    
    // Convert the input coordinates into usable number coordinates    
    for(int j=0;j<2;j++)
        {   
            if(isalpha(players[0].shts_frd[count1][j]))
            {
                num[j] = players[0].shts_frd[count1][j] - 64;
            }

            if(isdigit(players[0].shts_frd[0][j]) && players[0].shts_frd[count1][j+1] == '0')
            {
                num[j] = 10;
                        break;
            }
            else if(isdigit(players[0].shts_frd[count1][j]))
            {
                num[j] = players[0].shts_frd[count1][j] - 48;
            }
        }  
 
    // Change the game board to show missed and hit shots and output it
    for(int m=0;m<10;m++)
    {   
    for(int l=0;l<10;l++)
    {
        if(l == num[1] && m == num[0])
        {
            if(players[1].player_board[m-1][l-1]== 'X')
            {
                cout << "Hit!" << endl;
                players[0].enemy_board[m-1][l-1] = 'H';
                players[1].player_board[m-1][l-1] = 'H';
                count1++;
                
                if(count1 == 17)
                    return true;
            }
            else
            {
                cout << "Miss!" << endl;
                players[0].enemy_board[m-1][l-1] = 'M';
                players[1].player_board[m-1][l-1] = 'M';
            }  
        }
    }  
    }
      
    // Return false if the game hasn't ended   
    return false;
}

//Function used to have player 2 shoot at player 1, output hits and ships hit or
//missed, and decide if the game is over yet
bool shooting2(struct Playerinfo players[],int SIZE,int count2)
{
    //Declare Variables
    int num[2];   //Array holding converted user number coordinates 
    
    // Initial shot user input
    cout << players[1].player_name << "where to shoot? ";
    getline(cin,players[1].shts_frd[count2]);
    cout << endl;
    
    // Convert the input coordinates into usable number coordinates
    for(int j=0;j<2;j++)
        {   
            if(isalpha(players[1].shts_frd[count2][j]))
            {
                num[j] = players[1].shts_frd[count2][j] - 64;
            }

            if(isdigit(players[1].shts_frd[count2][j]) && players[1].shts_frd[count2][j+1] == '0')
            {
                num[j] = 10;
                        break;
            }
            else if(isdigit(players[1].shts_frd[count2][j]))
            {
                num[j] = players[1].shts_frd[count2][j] - 48;
            }
        }
            
    // Change the game board to show missed and hit shots and output it        
    for(int m=0;m<10;m++)
    {   
        for(int l=0;l<10;l++)
        {
            if(l == num[1] && m == num[0])
            {
                if(players[0].player_board[m-1][l-1]== 'X')
                {
                    cout << "Hit!" << endl;
                    players[1].enemy_board[m-1][l-1] = 'H';
                    players[0].player_board[m-1][l-1] = 'H';

                }
                else
                {   
                    cout << "Miss!" << endl;
                    players[1].enemy_board[m-1][l-1] = 'M';
                    players[0].player_board[m-1][l-1] = 'M';
                }
            }
        }  
    }  
    
    // Return false if the game hasn't ended
    return false;
}

// Function used to display the boards for each player on their turns
void disp_board1(struct Playerinfo players[],int SIZE, ofstream &plyr_1file)
{
    // Format the output and general layout of the game boards
    char letters[10] = {'A','B','C','D','E','F','G','H','I','J'};
    
    cout << "        1   2   3   4   5   6   7   8   9   10" << endl
         << "        _   _   _   _   _   _   _   _   _   _ " << endl << endl;
    
    // Loop for more accurate board displays
    for(int x=0;x<10;x++)    
    {
        cout << "   " << letters[x] << "  ";
                
        for(int z=0;z<10;z++)
            cout << "| " << players[0].enemy_board[x][z]<< " ";
        
        cout << "|" << endl 
             << "      -   -   -   -   -   -   -   -   -   -   -"<< endl;
    }
    
    // Use the print to file function to record players moves
    prntTofile(players,SIZE,plyr_1file);
    
    // Format the output and general layout of the game boards
    cout << endl << endl;
    cout << "        1   2   3   4   5   6   7   8   9   10" << endl
         << "        _   _   _   _   _   _   _   _   _   _ " << endl << endl;
    
    // Loop for more accurate board displays
    for(int x=0;x<10;x++)    
    {
        cout << "   " << letters[x] << "  ";
                
        for(int z=0;z<10;z++)
            cout << "| " << players[0].player_board[x][z]<< " ";
        
        cout << "|" << endl 
             << "      -   -   -   -   -   -   -   -   -   -   -"<< endl;
    }    
}

// Function used to display the boards for each player on their turns
void disp_board2(struct Playerinfo players[],int SIZE, ofstream &plyr_2file)
{
    // Format the output and general layout of the game boards
    char letters[10] = {'A','B','C','D','E','F','G','H','I','J'};
    
    cout << "        1   2   3   4   5   6   7   8   9   10" << endl
         << "        _   _   _   _   _   _   _   _   _   _ " << endl << endl;
     
    // Loop for more accurate board displays
    for(int x=0;x<10;x++)    
    {
        cout << "   " << letters[x] << "  ";
                
        for(int z=0;z<10;z++)
            cout << "| " << players[1].enemy_board[x][z]<< " ";
        
        cout << "|" << endl 
             << "      -   -   -   -   -   -   -   -   -   -   -"<< endl;
    }
    
    // Use the print to file function to record players moves
    prntTofile(players,SIZE,plyr_2file);
    
    // Format the output and general layout of the game boards
    cout << endl << endl;
    cout << "        1   2   3   4   5   6   7   8   9   10" << endl
         << "        _   _   _   _   _   _   _   _   _   _ " << endl << endl;
    
    // Loop for more accurate board displays
    for(int x=0;x<10;x++)    
    {
        cout << "   " << letters[x] << "  ";
                
        for(int z=0;z<10;z++)
            cout << "| " << players[1].player_board[x][z]<< " ";
        
        cout << "|" << endl 
             << "      -   -   -   -   -   -   -   -   -   -   -"<< endl;
    }  
} 

//Function used to print the players boards to the text file
void prntTofile(struct Playerinfo players[],int SIZE,ofstream &plyr_file)
{
    //File Setup text 
    plyr_file << endl
              << "   ----- All Plays Made during the Game by this player  -----"
              << endl << endl;
    
    // Format the output and general layout of the game boards
    char letters[10] = {'A','B','C','D','E','F','G','H','I','J'};
    
    plyr_file << "        1   2   3   4   5   6   7   8   9   10" << endl
         << "        _   _   _   _   _   _   _   _   _   _ " << endl << endl;
    
    // Loop for more accurate board displays
    for(int x=0;x<10;x++)    
    {
        plyr_file << "   " << letters[x] << "  ";
                 
        for(int z=0;z<10;z++)
            plyr_file << "| " << players[1].enemy_board[x][z]<< " ";
        
        plyr_file << "|" << endl 
             << "      -   -   -   -   -   -   -   -   -   -   -"<< endl;
    }
    
    //More game board input to the file
    plyr_file << endl << endl;
    plyr_file << "        1   2   3   4   5   6   7   8   9   10" << endl
         << "        _   _   _   _   _   _   _   _   _   _ " << endl << endl;
    
    // Loop for more accurate board displays
    for(int x=0;x<10;x++)    
    {
        plyr_file << "   " << letters[x] << "  ";
                
        for(int z=0;z<10;z++)
            plyr_file << "| " << players[1].player_board[x][z]<< " ";
        
        plyr_file << "|" << endl 
             << "      -   -   -   -   -   -   -   -   -   -   -"<< endl;
    }  
}