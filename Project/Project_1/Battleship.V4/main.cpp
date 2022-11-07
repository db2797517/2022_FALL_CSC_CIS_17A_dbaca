/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on October 24th, 2022, 6:30 PM
 * Purpose:  Version 4 - Battleship
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
    char player_name[100]; // C-string holding the name of the player
    string ships[5];       //String Array holding the ships coordinates input 
                           //by the player
    int ship_coors[20][20]; //Number Array with the number coordinates converted
                            //from user input
    string * shts_frd = new string[100]; //Dynamic String Array holding the 
                                         //shots fired by the player
    char player_board[10][10]; //C-string array holding the players board moves
    char enemy_board[10][10];  //C-string array holding the enemy board moves
    
    //String array holding the names of each ship
    string ship_name[5] = {"Carrier", "Battleship", "Cruiser", 
                           "Submarine", "Destroyer"};
};
   
//Enum format for player boards output loop
enum grid {A,B,C,D,E,F,G,H,I,J,K};
  
//Function Prototypes
int *coin_flip(string []); //Get the result of the coin flip
Playerinfo *game_start();  //Get both player's names and ship coordinates
void coorTonum(Playerinfo *,int);  //Convert string input to usable coordinates
void numToboard(Playerinfo *,int); //Input converted coordinate to match player 
                                   //boards
void disp_board1(Playerinfo *, int, ofstream &); //Display Player 1's two game 
                                                 //boards
void disp_board2(Playerinfo *, int, ofstream &); //Display Player 2's two game 
                                                 //boards
bool shooting1(Playerinfo *,int &); //Have Player 1 shoot at the enemy's board,
                                    //show what was hit or missed and end game 
                                    //if necessary
bool shooting2(Playerinfo *,int &); //Have Player 2 shoot at the enemy's board,
                                    //show what was hit or missed and end game 
                                    //if necessary
void prntTofile(Playerinfo *,int,ofstream &); //Print each players move to their 
                                              //file
void prntToBinFile(Playerinfo *,ofstream &);  //Print the overall players 
                                              //information to the Binary file
void BinFileToprnt(Playerinfo *); //Read from the binary file and output the 
                                  //player's information
 
//Execution of Code Begins Here
int main(int argc, char** argv) 
{
    //Set the random number seed here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all variables
    const int SIZE = 2; //Size of the array
    struct Playerinfo * players; //Dynamic struct array
    players = new Playerinfo[SIZE];
    
    int count =0; //Counter variable
    int count1=0; //A counter for the number of times players 1 has shot at 
                  //Player 2
    int count2=0; //A counter for the number of times players 2 has shot at 
                  //Player 1
    int coin = 0; //Coin Variables
    string Coin_sde[2] = {"Heads", "Tails"}; //Coins sides string array
    string * ptr2 = Coin_sde; // Pointer to the Coin sides array
    int * ptr = &coin; //Pointer to the coin variable
    bool gme_ovr; //The bool variable gotten from the shooting functions 
                  //telling whether or not the game has ended or not
    char choice; //The character input for whether or not to have endgame review
    
    //ptr = coin_flip(Coin_sde);
    
    //Declare the two files
    ofstream plyr_1file;
    ofstream plyr_2file;
    
    //Open the file again
    ofstream file;
    file.open("Players Info", ios::out | ios:: binary);
    
    //Open the two files
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
         << endl << endl;
     
    // Receive both player's starting information
    players = game_start();
    
    // Convert the user input to usable coordinates using the function
    coorTonum(players, SIZE);
     
    //coin=coin_flip(coin);
    
    // cout << coin;
    
    // cout << players[*coin].player_name << " has won the Coin Flip and will go First!!!!";    
    
    // Go to function to setup coordinates to board
    numToboard(players, SIZE);
    
    // Loop for each player's turn, shooting their shots until someone wins
    while(!gme_ovr)
    {
        cout << endl << "    " <<players[0].player_name << " it's your turn!!!"
             << endl << endl;
        disp_board1(players,SIZE,plyr_1file);  
        gme_ovr = shooting1(players, count1);
        
        if(gme_ovr)
            break;
         
        cout << endl << "    " <<players[1].player_name << " it's your turn!!!" 
             << endl << endl;
        disp_board2(players,SIZE,plyr_2file);  
        gme_ovr = shooting2(players, count2);
    } 
     
    // Call function to write records to binary file
    prntToBinFile(players,file);
    
    //Prompt players to input choice for Players Info
    cout << "     Would you like to view the overall Players Recap? (Y/N) ";
         cin >> choice;
 
    //Use choice input to determine what to input for end of program
    if(choice == 'Y' || choice == 'y')
    {
        // Call function to print records from binary file
        BinFileToprnt(players);
        cout << endl << "    Thank you for Playing!!! " << endl;
    } 
    else if(choice == 'N' || choice == 'n')
        cout << endl << "     Thank you for Playing!!! " << endl;

    //Close the two text files
    plyr_1file.close();
    plyr_2file.close();
     
    //Deallocate memory
    delete[] players;
    delete[] players->shts_frd;

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}
 
//Function Implementations

//Get the result of the coin flip
int *coin_flip(string Coin_sde[])
{
    int * num = nullptr;
    
    *num = 6;
    
    cout << num;
    
    return num;
    
}
  
// Function for receiving all player information including name and ship 
// coordinates
Playerinfo *game_start()
{
    //Declare Variables
    struct Playerinfo * players; // Temporary dynamic array structure for 
    players = new Playerinfo[2]; // function
      
    //Loop to get input for each player
    for(int i=0; i<2;i++)
    {
    // Get Name of Player
    cout << endl << "Name for Player #" << (i+1) << ": ";
    cin.getline(players[i].player_name, 100);
    cout << endl;
    
    // Prompt user to input ship coordinates
    cout << "            --- " << players[i].player_name 
         << " choose you Ship Locations ---" << endl;
    
    cout << "Select the coordinates for each ship "
         << "(ex. input A1 A5, for the carrier)" << endl << endl;
        
    //Loop for ship coordinates input
    for(int j=0;j<5;j++)
        {
            cout << setw(20) << players[i].ship_name[j] << ": ";
            getline(cin,players[i].ships[j]); 
            
            while(players[i].ships[j].length() > 7 || !isalpha(players[i].ships[j][0]))
            {
                cout << endl << " Please follow the input format for the ship "
                    << "coordinates. (ex. B3 B7)" << endl << endl;
               
                cout << setw(20) << players[i].ship_name[j] << ": ";
                getline(cin,players[i].ships[j]); 
                       
            }
        }
    }
      
    //Return the players array of structures
    return players;
}

// Function for converting user ship coordinates input to usable coordinates for 
// the game
void coorTonum(struct Playerinfo * players,int SIZE)
{
    
// Loop for each player and each subsequent string input for their ship 
// coordinates
for(int x=0;x<SIZE;x++)
{
    for(int i=0;i<5;i++)
    {
        if(players[x].ships[i].length() == 5 || players[x].ships[i].length() == 6)
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
        else
        {
            players[x].ship_coors[i][0] = players[x].ships[i][0] - 64;
            players[x].ship_coors[i][3] = players[x].ships[i][4] - 64;
            players[x].ship_coors[i][2] = 0;
            players[x].ship_coors[i][1] = 10;
            players[x].ship_coors[i][4] = 10;
        }
    }
} 
}
 
// Use the converted coordinates to format the player boards with each ship of 
// their ships
void numToboard(struct Playerinfo * players,int SIZE)
{ 
    // Initialize empty board layout
    for(int z=0;z<SIZE;z++)
        for(int i=A;i<K;i++)
            for(int j=A;j<K;j++)
            {
            players[z].player_board[i][j] = '0';
            players[z].enemy_board[i][j] = '0';
            }  
    
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
bool shooting1(struct Playerinfo * players,int &count1)
{
    // Variables
    int num[2];   // Array holding converted user number coordinates
    int hits = 0; // Number of ship coordinates not yet shot
    
    // Initial shot user input
    cout << endl << "    " << players[0].player_name << ", where to shoot? ";
    getline(cin,players[0].shts_frd[count1]);
    cout << endl;
    
    // Input Validation for user shot input
    while(!isalpha(players[0].shts_frd[count1][0]) || !isdigit(players[0].shts_frd[count1][1]))
    {
        cout << "Please input a correct coordinate. (ex. A10, B7, I3)" << endl;
        cout << endl << "    " << players[0].player_name << ", where to shoot? ";
        getline(cin,players[0].shts_frd[count1]);
        cout << endl;
    } 
    
    // Convert the input coordinates into usable number coordinates
    for(int j=0;j<2;j++)
    {   
        if(isalpha(players[0].shts_frd[count1][j]))
            num[j] = players[0].shts_frd[0][j] - 64;

        if(isdigit(players[0].shts_frd[count1][j]) && players[0].shts_frd[count1][j+1] == '0')
        {
            num[j] = 10;
            break;
        }
        else if(isdigit(players[0].shts_frd[count1][j]))
        {
            num[j] = players[0].shts_frd[count1][j] - 48;
        }
    }  
    
    // Change the game board to show missed and hit shots
    for(int m=0;m<11;m++)
    {   
        for(int l=0;l<11;l++)
        {
            if(l == num[1] && m == num[0])
            {
                if(players[1].player_board[m-1][l-1]== 'X')
                {
                    cout << "    !!!!! It was a Hit! !!!!!" << endl;
                    players[0].enemy_board[m-1][l-1] = 'H';
                    players[1].player_board[m-1][l-1] = 'H';
                }
                else
                {
                    cout << "    !!!!! It was a Miss! !!!!!" << endl;
                    players[0].enemy_board[m-1][l-1] = 'M';
                    players[1].player_board[m-1][l-1] = 'M';
                }
            }
        }  
    }
     
    // Detect to see if there are any ships coordinates not shot yet
    for(int z=0;z<11;z++)
        for(int y=0;y<11;y++)
            if(players[1].player_board[z][y] == 'X')
                hits++;
     
    // Condition to see if the game has ended yet   
    if(hits == 0)
    {
            cout << endl << "    " << players[0].player_name
                 << " has won the game!" << endl << endl;
            return true;
    }
    
    // Increase count for recording shots
    count1++;
        
    // Return false if the game hasn't ended
    return false;
}

//Function used to have player 2 shoot at player 1, output hits and ships hit or
//missed, and decide if the game is over yet
bool shooting2(struct Playerinfo * players,int &count2)
{
    // Variables
    int num[2];   // Array holding converted user number coordinates
    int hits = 0; // Number of ship coordinates not yet shot
    
    // Initial shot user input
    cout << endl << "    " << players[1].player_name << ", where to shoot? ";
    getline(cin,players[1].shts_frd[count2]);
    cout << endl;
    
    // Input Validation for user shot input
    while(!isalpha(players[1].shts_frd[count2][0]) || !isdigit(players[1].shts_frd[count2][1]))
    {
        cout << "Please input a correct coordinate. (ex. A10, B7, I3)" << endl;
        cout << endl << "    " << players[1].player_name << ", where to shoot? ";
        getline(cin,players[1].shts_frd[count2]);
        cout << endl;
    }
    
    // Convert the input coordinates into usable number coordinates
    for(int j=0;j<2;j++)
        {   
            if(isalpha(players[1].shts_frd[count2][j]))
                num[j] = players[1].shts_frd[count2][j] - 64;

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
     
    // Change the game board to show missed and hit shots
    for(int m=0;m<11;m++)
    {   
        for(int l=0;l<11;l++)
        {
            if(l == num[1] && m == num[0])
            {
                if(players[0].player_board[m-1][l-1]== 'X')
                {
                    cout << "    !!!!! It was a Hit! !!!!!" << endl;
                    players[1].enemy_board[m-1][l-1] = 'H';
                    players[0].player_board[m-1][l-1] = 'H';
                }
                else
                {   
                    cout << "    !!!!! It was a Miss! !!!!!" << endl;
                    players[1].enemy_board[m-1][l-1] = 'M';
                    players[0].player_board[m-1][l-1] = 'M';
                }
            }
        }  
    } 
    
    // Detect to see if there are any ships coordinates not shot yet
    for(int z=0;z<11;z++)
        for(int y=0;y<11;y++)
            if(players[0].player_board[z][y] == 'X')
                hits++;
     
    // Condition to see if the game has ended yet
    if(hits == 0) 
    {
        cout << endl << "    " << players[1].player_name
             << " has won the game!" << endl << endl;
        return true;
    }

    // Increase count for recording shots
    count2++;
    
    // Return false if the game hasn't ended
    return false;
}
 
// Function used to display the boards for each player on their turns
void disp_board1(struct Playerinfo * players,int SIZE, ofstream &plyr_1file)
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
    for(int x=A;x<K;x++)    
    {
        cout << "   " << letters[x] << "  ";
                
        for(int z=A;z<K;z++)
            cout << "| " << players[0].enemy_board[x][z]<< " ";
        
        cout << "|" << endl 
             << "      -   -   -   -   -   -   -   -   -   -   -"<< endl;
    }
    
    //Formatting
    cout << endl;
     
    // Use the print to file function to record players moves
    prntTofile(players,0,plyr_1file);
    
    cout << "           -------- Player Board -----------       "
         << "X = Your ships" << endl
         << "        1   2   3   4   5   6   7   8   9   10"
         << "     H = Your ship has been hit" << endl
         << "        _   _   _   _   _   _   _   _   _   _ "
         << "     M = The enemy has missed your ships" << endl << endl;
    
    // Loop for more accurate board displays
    for(int x=A;x<K;x++)    
    {
        cout << "   " << letters[x] << "  ";
                
        for(int z=A;z<K;z++)
            cout << "| " << players[0].player_board[x][z]<< " ";
        
        cout << "|" << endl 
             << "      -   -   -   -   -   -   -   -   -   -   -"<< endl;
    }
    
    //Formatting
    cout << endl;
}

// Function used to display the boards for each player on their turns
void disp_board2(struct Playerinfo * players,int SIZE, ofstream &plyr_2file)
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
    for(int x=A;x<K;x++)    
    {
        cout << "   " << letters[x] << "  ";
                
        for(int z=A;z<K;z++)
            cout << "| " << players[1].enemy_board[x][z]<< " ";
        
        cout << "|" << endl 
             << "      -   -   -   -   -   -   -   -   -   -   -"<< endl;
    }
    
    //Formatting
    cout << endl;
     
    // Use the print to file function to record players moves
    prntTofile(players,1,plyr_2file);
    
    cout << "           -------- Player Board -----------       "
         << "X = Your ships" << endl
         << "        1   2   3   4   5   6   7   8   9   10"
         << "     H = Your ship has been hit" << endl
         << "        _   _   _   _   _   _   _   _   _   _ "
         << "     M = The enemy has missed your ships" << endl << endl;
    
    // Loop for more accurate board displays
    for(int x=A;x<K;x++)    
    {
        cout << "   " << letters[x] << "  ";
                
        for(int z=A;z<K;z++)
            cout << "| " << players[1].player_board[x][z]<< " ";
        
        cout << "|" << endl 
             << "      -   -   -   -   -   -   -   -   -   -   -"<< endl;
    }
    
    // Formatting
    cout << endl;    
} 

// Function to print the players moves to the text files
void prntTofile(struct Playerinfo * players, int play_num,ofstream &plyr_file)
{
    plyr_file << endl
              << "   ----- All Plays Made during the Game by this player  -----"
              << endl << endl;
    
    // Format the output and general layout of the game boards
    char letters[10] = {'A','B','C','D','E','F','G','H','I','J'};
    
    plyr_file << "        1   2   3   4   5   6   7   8   9   10" << endl
         << "        _   _   _   _   _   _   _   _   _   _ " << endl << endl;
    
    // Loop for more accurate board displays
    for(int x=A;x<K;x++)    
    {
        plyr_file << "   " << letters[x] << "  ";
                 
        for(int z=A;z<K;z++)
            plyr_file << "| " << players[play_num].enemy_board[x][z]<< " ";
        
        plyr_file << "|" << endl 
             << "      -   -   -   -   -   -   -   -   -   -   -"<< endl;
    }
    
    plyr_file << endl << endl;
    plyr_file << "        1   2   3   4   5   6   7   8   9   10" << endl
         << "        _   _   _   _   _   _   _   _   _   _ " << endl << endl;
    
    // Loop for more accurate board displays
    for(int x=A;x<K;x++)    
    {
        plyr_file << "   " << letters[x] << "  ";
                
        for(int z=A;z<K;z++)
            plyr_file << "| " << players[play_num].player_board[x][z]<< " ";
        
        plyr_file << "|" << endl 
             << "      -   -   -   -   -   -   -   -   -   -   -"<< endl;
    }  
}  
 
// Function to write the records to the binary files
void prntToBinFile(struct Playerinfo * players, ofstream &file)
{
    // Check to see if the file is open and available
    if(!file)
        cout << endl << "error" << endl;
    
    // Write both structure records to the binary file
    for(int z=0;z<2;z++)
        file.write(reinterpret_cast<char *>(&players[z]), sizeof(players[z]));
    
    // Close the binary file
    file.close();
}

// Function to print the records from the binary file
void BinFileToprnt(struct Playerinfo * players)
{   
    //Open the file again
    fstream file;
    file.open("Players Info", ios::in | ios:: binary);
    
    // Check to make sure the file is open and available
    if(!file)
        cout << endl << "error" << endl;
 
    // Output all of the records
    for(int count=0;count<2;count++)
    {
        cout << endl <<"  --- Player #" << (count+1) << " Information ---"
             << endl << endl << " Name: " << players[count].player_name << endl;
        
        cout << endl << " Coordinates of ships:" << endl << endl;
        
        for(int z=0;z<5;z++)
            cout <<  "      " << players[count].ships[z] << endl;
       
        cout << endl << " Shots Fired: " << endl << endl;
                
        for(int z=0;z<100;z++)
            cout << " " << players[count].shts_frd[z];
        
        cout << endl << " Final Player Board:" << endl;

        for(int z=0;z<10;z++)
        {
            for(int f=0;f<10;f++)
               cout << " " << players[count].player_board[z][f];
            
            cout << endl;
        }   
    
        file.read(reinterpret_cast<char *>(&players[count]), sizeof(players[count]));  
    }
         
    //Close the binary file
    file.close();   
} 