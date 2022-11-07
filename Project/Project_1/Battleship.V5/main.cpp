/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on October 27th, 2022, 6:14 PM
 * Purpose:  Version 5 - Battleship
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
using namespace std;
 
//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants
 
//Structure for all player information
struct Playerinfo 
{
    char player_name[100];  //C-string Array holding the name of the player
    string ships[5];        //String Array holding the ship coordinates input 
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
 
//Structure holding information needed for the array of structures
struct Players
{
    const int SIZE = 2;    //Size of the array of structures
    const int numshps = 5; //Variable for number of ships
    Playerinfo * info;     //Pointer holding the array of structures
}; 

//Enum format for player boards output loop
enum grid {A,B,C,D,E,F,G,H,I,J,K};
    
//Function Prototypes
Players *game_start();      //Get both player's names and ship coordinates
void coorTonum(Players *);  //Convert string input to usable coordinates
void numToboard(Players *); //Input converted coordinates to match player 
                            //boards
void disp_board1(Players *,ofstream &); //Display Player 1's two game 
                                        //boards
void disp_board2(Players *,ofstream &); //Display Player 2's two game 
                                        //boards
bool shooting1(Players *,int &);    //Have Player 1 shoot at the enemy's board,
                                    //show what was hit or missed and end game 
                                    //if necessary
bool shooting2(Players *,int &);    //Have Player 2 shoot at the enemy's board,
                                    //show what was hit or missed and end game 
                                    //if necessary
void prntTofile(Players*,int,ofstream &); //Print each player's move to their 
                                          //file
void prntToBinFile(Players *,fstream &); //Print the overall players 
                                         //information to the Binary file 
void BinFileToprnt(Players *,fstream &); //Read from the binary file and output 
                                         //the player's information 
    
//Execution of Code Begins Here
int main(int argc, char** argv) 
{ 
    //Declare all variables
    struct Players * plyrs = new Players; //Dynamic Structure for Players
    
    int count1=0;   //A counter for the number of times players 1 has shot at 
                    //Player 2
    int count2=0;   //A counter for the number of times players 2 has shot at 
                    //Player 1
    bool gme_ovr;   //The bool variable gotten from the shooting functions 
                    //telling whether or not the game has ended or not
    char choice;    //The character input for whether or not to have endgame 
                    //review
      
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
    plyrs = game_start();
    
    //Convert the user input to usable coordinates using the function
    coorTonum(plyrs);  
    
    //Go to function to setup coordinates to board
    numToboard(plyrs);
    
    //Loop for each player's turn, shooting their shots until someone wins
    while(!gme_ovr)
    {  
        //Start Player 1's turn
        cout << endl << "    " <<plyrs->info[0].player_name << " it's your turn!!!"
             << endl << endl;
        disp_board1(plyrs,plyr_1file);  
        gme_ovr = shooting1(plyrs, count1);
        
        //End game if necessary
        if(gme_ovr)
            break;
         
        //Start Player 2's turn
        cout << endl << "    " <<plyrs->info[1].player_name << " it's your turn!!!" 
             << endl << endl;
        disp_board2(plyrs,plyr_2file);  
        gme_ovr = shooting2(plyrs, count2);
    } 
     
    // Call function to write records to binary file
    prntToBinFile(plyrs,file);
    
    //Prompt players to input choice for Players Info
    cout << "     Would you like to view the overall Players Recap? (Y/N) ";
         cin >> choice;
 
    //Use choice input to determine what to input for end of program
    if(choice == 'Y' || choice == 'y')
    {
        // Call function to print records from binary file
        BinFileToprnt(plyrs, file);
        cout << endl << "    Thank you for Playing!!! " << endl;
    } 
    else if(choice == 'N' || choice == 'n')
        cout << endl << "     Thank you for Playing!!! " << endl;

    //Close the two text files
    plyr_1file.close();
    plyr_2file.close();
        
    //Close the binary file
    file.close(); 
     
    //Deallocate memory
    delete[] plyrs;
    delete[] plyrs->info->shts_frd;
 
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}
  
// Function for receiving all player information including name and ship 
// coordinates
Players *game_start()
{ 
    //Declare Variables
    struct Players * plyrs = new Players;      //Dynamic array structure  
    plyrs->info = new Playerinfo[plyrs->SIZE]; //for function
    char choice;
    
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
    for(int i=0; i<plyrs->SIZE;i++)
    {
        // Get Name of Player
        cout << endl << "Name for Player #" << (i+1) << ": ";
        cin.getline(plyrs->info[i].player_name, 100);
        cout << endl;

        // Prompt user to input ship coordinates
        cout << "            --- " << plyrs->info[i].player_name 
             << " choose you Ship Locations ---" << endl;
        cout << "Select the coordinates for each ship "
             << "(ex. input A1 A5, for the carrier)" << endl << endl;
        
        //Loop for ship coordinates input
        for(int j=0;j<plyrs->numshps;j++)
        {
            //Input the ship coordinates
            cout << setw(20) << plyrs->info[i].ship_name[j] << ": ";
            getline(cin,plyrs->info[i].ships[j]); 
             
            //Input Validation for Ship Coordinates
            while(plyrs->info[i].ships[j].length() > 7 || !isalpha(plyrs->info[i].ships[j][0]))
            {
                //Prompt the user to enter valid input
                cout << endl << " Please follow the input format for the ship "
                    << "coordinates. (ex. B3 B7)" << endl << endl;
               
                //Get the input again
                cout << setw(20) << plyrs->info[i].ship_name[j] << ": ";
                getline(cin,plyrs->info[i].ships[j]);        
            }
        }
    }
      
    //Return the plyrs pointer and the array of structures
    return plyrs;
}
 
//Function used to convert players string input to usable int number coordinates
//for the rest of the program  
void coorTonum(struct Players * plyrs)
{
    
// Loop for each player and each subsequent string input for their ship 
// coordinates
for(int x=0;x<plyrs->SIZE;x++)
{
    for(int i=0;i<plyrs->numshps;i++)
    {
        //See if the string is a certain length and choose option based on it
        if(plyrs->info[x].ships[i].length() == 5 || plyrs->info[x].ships[i].length() == 6)
        {
        for(int j=0;j<plyrs->numshps;j++)
        {   
            // Determine if the portion of the string is a letter and convert to
            // an int
            if(isalpha(plyrs->info[x].ships[i][j]))
                plyrs->info[x].ship_coors[i][j] = plyrs->info[x].ships[i][j] - 64;

            // Determine if the portion of the string is a number and convert to 
            // an int
            if(isdigit(plyrs->info[x].ships[i][j]) && plyrs->info[x].ships[i][j+1] == '0')
            {
                plyrs->info[x].ship_coors[i][j] = 10;
                break;
            } 
            else if(isdigit(plyrs->info[x].ships[i][j]))
            {
                plyrs->info[x].ship_coors[i][j] = plyrs->info[x].ships[i][j] - 48;
            }
            // Determine if the portion of the string is a space
            if(isspace(plyrs->info[x].ships[i][j]))
                plyrs->info[x].ship_coors[i][j] = 0;
        }
        }
        else
        {
            //Convert string of chars to usable number coordinates
            plyrs->info[x].ship_coors[i][0] = plyrs->info[x].ships[i][0] - 64;
            plyrs->info[x].ship_coors[i][3] = plyrs->info[x].ships[i][4] - 64;
            plyrs->info[x].ship_coors[i][2] = 0;
            plyrs->info[x].ship_coors[i][1] = 10;
            plyrs->info[x].ship_coors[i][4] = 10;
        }
    }
} 
}
 
//Function used to have the converted coordinates format the player boards with
//each of their ships
void numToboard(struct Players * plyrs)
{ 
    // Initialize empty board layout
    for(int z=0;z<plyrs->SIZE;z++)
        for(int i=A;i<K;i++)
            for(int j=A;j<K;j++)
            {
            plyrs->info[z].player_board[i][j] = '0';
            plyrs->info[z].enemy_board[i][j] = '0';
            }  
    
    // Place X's that represent ships on the player's boards
    for(int z=0;z<plyrs->SIZE;z++)
    {
    for(int i=0;i<plyrs->numshps;i++)
    {
    if(plyrs->info[z].ship_coors[i][0] == plyrs->info[z].ship_coors[i][3])
        for(int k=(plyrs->info[z].ship_coors[i][1]-1);k<plyrs->info[z].ship_coors[i][4];k++)
            plyrs->info[z].player_board[(plyrs->info[z].ship_coors[i][0]-1)][k] = 'X';
    else
        for(int a=(plyrs->info[z].ship_coors[i][0]-1);a<plyrs->info[z].ship_coors[i][3];a++)
                    plyrs->info[z].player_board[a][(plyrs->info[z].ship_coors[i][1]-1)] = 'X';
    }
    }     
}
   
//Function used to have player 1 shoot at player 2, output hits and ships hit or
//missed, and decide if the game is over yet
bool shooting1(struct Players * plyrs,int &count1)
{
    //Declare Variables
    int num[2];    //Array holding converted user number coordinates
    int hits = 0;  //Number of ship coordinates not yet shot
    int count = 0; //Counter used to determine what kind of ship was hit
    
    // Initial shot user input
    cout << endl << "    " << plyrs->info[0].player_name << ", where to shoot? ";
    getline(cin,plyrs->info[0].shts_frd[count1]);
    cout << endl;
    
    //Check to see if player wants to quit the game
    if(plyrs->info[0].shts_frd[count1][0] == 'Q' || plyrs->info[0].shts_frd[count1][0] == 'q')
    {
        cout << "    Game over!" << endl << endl;
        return true;
    }
        
    // Input Validation for user shot input
    while(!isalpha(plyrs->info[0].shts_frd[count1][0]) 
          && !isupper(plyrs->info[0].shts_frd[count1][0])  
          || !isdigit(plyrs->info[0].shts_frd[count1][1]))
    {
        cout << "Please input a correct coordinate. (ex. A10, B7, I3)" << endl;
        cout << endl << "    " << plyrs->info[0].player_name << ", where to shoot? ";
        getline(cin,plyrs->info[0].shts_frd[count1]);
        cout << endl;
    } 
     
    // Convert the input coordinates into usable number coordinates
    for(int j=0;j<plyrs->SIZE;j++)
    {   
        if(isalpha(plyrs->info[0].shts_frd[count1][j]))
            num[j] = plyrs->info[0].shts_frd[count1][j] - 64;
 
        if(isdigit(plyrs->info[0].shts_frd[count1][j]) && plyrs->info[0].shts_frd[count1][j+1] == '0')
        { 
            num[j] = 10;
            break;
        }
        else if(isdigit(plyrs->info[0].shts_frd[count1][j]))
        {
            num[j] = plyrs->info[0].shts_frd[count1][j] - 48;
        }
    }  
      
    // Change the game board to show missed and hit shots and output it
    for(int m=0;m<11;m++)
    {   
        for(int l=0;l<11;l++)
        {
            if(l == num[1] && m == num[0])
            {
                if(plyrs->info[1].player_board[m-1][l-1]== 'X')
                {
                    //Output that a ship has been hit
                    cout << "    !!!!! It was a Hit! !!!!!" << endl;
                    plyrs->info[0].enemy_board[m-1][l-1] = 'H';
                    plyrs->info[1].player_board[m-1][l-1] = 'H';
                    
                    //Determine what ship has been shot at
                    for(int x=0;x<plyrs->numshps;x++)
                    {
                        if(m >= plyrs->info[1].ship_coors[x][0] && m <= plyrs->info[1].ship_coors[x][3] 
                           && l == plyrs->info[1].ship_coors[x][1] &&  l == plyrs->info[1].ship_coors[x][4])
                        {
                            //Length of the ship shot used for output
                            count = (plyrs->info[1].ship_coors[x][3]+1) - plyrs->info[1].ship_coors[x][0];
                            
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
                        else if(l >= plyrs->info[1].ship_coors[x][1] && l <= plyrs->info[1].ship_coors[x][4] 
                           && m == plyrs->info[1].ship_coors[x][0] &&  m == plyrs->info[1].ship_coors[x][3])
                        {
                            //Length of the ship shot used for output
                            count = (plyrs->info[1].ship_coors[x][4]+1) - plyrs->info[1].ship_coors[x][1];
                            
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
                    plyrs->info[0].enemy_board[m-1][l-1] = 'M';
                    plyrs->info[1].player_board[m-1][l-1] = 'M';
                }
            }
        }  
    }
       
    // Detect to see if there are any ships coordinates not shot yet
    for(int z=0;z<11;z++)
        for(int y=0;y<11;y++)
            if(plyrs->info[1].player_board[z][y] == 'X')
                hits++;
     
    // Condition to see if the game has ended yet   
    if(hits == 0)
    {
            cout << endl << "    " << plyrs->info[0].player_name
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
bool shooting2(struct Players * plyrs,int &count2)
{
    //Declare Variables
    int num[2];    //Array holding converted user number coordinates
    int hits = 0;  //Number of ship coordinates not yet shot
    int count = 0; //Counter used to determine what kind of ship was hit
       
    // Initial shot user input
    cout << endl << "    " << plyrs->info[1].player_name << ", where to shoot? ";
    getline(cin,plyrs->info[1].shts_frd[count2]);
    cout << endl;
       
    //Check to see if user wants to quit the game
    if(plyrs->info[1].shts_frd[count2][0] == 'Q' || plyrs->info[1].shts_frd[count2][0] == 'q')
    {
        cout << "    Game over!" << endl << endl;
        return true;
    }
    
    // Input Validation for user shot input
    while(!isalpha(plyrs->info[1].shts_frd[count2][0]) 
          && !isupper(plyrs->info[1].shts_frd[count2][0])  
          || !isdigit(plyrs->info[1].shts_frd[count2][1]))
    {
        cout << "Please input a correct coordinate. (ex. A10, B7, I3)" << endl;
        cout << endl << "    " << plyrs->info[1].player_name << ", where to shoot? ";
        getline(cin,plyrs->info[1].shts_frd[count2]);
        cout << endl;
    }
    
    // Convert the input coordinates into usable number coordinates
    for(int j=0;j<plyrs->SIZE;j++)
    {   
        if(isalpha(plyrs->info[1].shts_frd[count2][j]))
            num[j] = plyrs->info[1].shts_frd[count2][j] - 64;

        if(isdigit(plyrs->info[1].shts_frd[count2][j]) && plyrs->info[1].shts_frd[count2][j+1] == '0')
        {
            num[j] = 10;
            break;
        }
        else if(isdigit(plyrs->info[1].shts_frd[count2][j]))
            num[j] = plyrs->info[1].shts_frd[count2][j] - 48;
    }
     
    // Change the game board to show missed and hit shots and output it
    for(int m=0;m<11;m++)
    {   
        for(int l=0;l<11;l++)
        {
            if(l == num[1] && m == num[0])
            {
                if(plyrs->info[0].player_board[m-1][l-1]== 'X')
                {
                    //Output that a ship has been hit
                    cout << "    !!!!! It was a Hit! !!!!!" << endl;
                    plyrs->info[1].enemy_board[m-1][l-1] = 'H';
                    plyrs->info[0].player_board[m-1][l-1] = 'H';
                    
                    //Determine what ship has been shot at
                    for(int x=0;x<plyrs->numshps;x++)
                    {
                        if(m >= plyrs->info[0].ship_coors[x][0] && m <= plyrs->info[0].ship_coors[x][3] 
                           && l == plyrs->info[0].ship_coors[x][1] &&  l == plyrs->info[0].ship_coors[x][4])
                        {
                            //Length of the ship shot used for output
                            count = (plyrs->info[0].ship_coors[x][3]+1) - plyrs->info[0].ship_coors[x][0];
                            
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
                        else if(l >= plyrs->info[0].ship_coors[x][1] && l <= plyrs->info[0].ship_coors[x][4] 
                           && m == plyrs->info[0].ship_coors[x][0] &&  m == plyrs->info[0].ship_coors[x][3])
                        {
                            //Length of the ship shot used for output
                            count = (plyrs->info[0].ship_coors[x][4]+1) - plyrs->info[0].ship_coors[x][1];
                            
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
                    plyrs->info[1].enemy_board[m-1][l-1] = 'M';
                    plyrs->info[0].player_board[m-1][l-1] = 'M';
                }
            }
        }  
    } 
    
    // Detect to see if there are any ships coordinates not shot yet
    for(int z=0;z<11;z++)
        for(int y=0;y<11;y++)
            if(plyrs->info[0].player_board[z][y] == 'X')
                hits++;
     
    // Condition to see if the game has ended yet
    if(hits == 0) 
    {
        cout << endl << "    " << plyrs->info[1].player_name
             << " has won the game!" << endl << endl;
        return true;
    }

    // Increase count for recording shots
    count2++;
    
    // Return false if the game hasn't ended
    return false;
}
 
// Function used to display the boards for each player on their turns
void disp_board1(struct Players * plyrs, ofstream &plyr_1file)
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
            cout << "| " << plyrs->info[0].enemy_board[x][z]<< " ";
        
        cout << "|" << endl 
             << "      -   -   -   -   -   -   -   -   -   -   -"<< endl;
    }
    
    //Formatting
    cout << endl;
     
    // Use the print to file function to record players moves
    prntTofile(plyrs,0,plyr_1file);
    
    // Format the output and general layout of the game boards
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
            cout << "| " << plyrs->info[0].player_board[x][z]<< " ";
        
        cout << "|" << endl 
             << "      -   -   -   -   -   -   -   -   -   -   -"<< endl;
    }
    
    //Formatting
    cout << endl;
}

// Function used to display the boards for each player on their turns
void disp_board2(struct Players * plyrs, ofstream &plyr_2file)
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
            cout << "| " << plyrs->info[1].enemy_board[x][z]<< " ";
        
        cout << "|" << endl 
             << "      -   -   -   -   -   -   -   -   -   -   -"<< endl;
    }
    
    //Formatting
    cout << endl;
      
    // Use the print to file function to record players moves
    prntTofile(plyrs,1,plyr_2file);
     
    // Format the output and general layout of the game boards
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
            cout << "| " << plyrs->info[1].player_board[x][z]<< " ";
        
        cout << "|" << endl 
             << "      -   -   -   -   -   -   -   -   -   -   -"<< endl;
    }
    
    // Formatting
    cout << endl;    
} 

// Function to print the players moves to the text files
void prntTofile(struct Players * plyrs, int play_num, ofstream &plyr_file)
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
    for(int x=A;x<K;x++)    
    {
        plyr_file << "   " << letters[x] << "  ";
                 
        for(int z=A;z<K;z++)
            plyr_file << "| " << plyrs->info[play_num].enemy_board[x][z]<< " ";
        
        plyr_file << "|" << endl 
             << "      -   -   -   -   -   -   -   -   -   -   -"<< endl;
    }
    
    //More game board input to the file
    plyr_file << endl << endl;
    plyr_file << "        1   2   3   4   5   6   7   8   9   10" << endl
         << "        _   _   _   _   _   _   _   _   _   _ " << endl << endl;
    
    // Loop for more accurate board displays
    for(int x=A;x<K;x++)    
    {
        plyr_file << "   " << letters[x] << "  ";
                
        for(int z=A;z<K;z++)
            plyr_file << "| " << plyrs->info[play_num].player_board[x][z]<< " ";
        
        plyr_file << "|" << endl 
             << "      -   -   -   -   -   -   -   -   -   -   -"<< endl;
    }  
}  
  
// Function to write the records to the binary files
void prntToBinFile(struct Players * plyrs, fstream &file)
{
    // Check to see if the file is open and available
    if(!file)
        cout << endl << "error" << endl;
    
    // Write both structure records to the binary file
    for(int z=0;z<plyrs->SIZE;z++)
        file.write(reinterpret_cast<char *>(&plyrs->info[z]), sizeof(plyrs->info[z]));
    
    //Close the Binary File
    file.close();
}
 
// Function to print the records from the binary file
void BinFileToprnt(struct Players * plyrs, fstream &file)
{     
    //Reopen the Binary file
    file.open("Players Info", ios:: in | ios:: binary);
    
    //Temporary struct array used for output
    struct Playerinfo temp[2];
     
    // Check to make sure the file is open and available
    if(!file)
        cout << endl << "error" << endl;
     
    //Read the records from the Binary file
    file.read(reinterpret_cast<char *>(&temp), sizeof(temp));
       
    // Output all of the records
    for(int count=0;count<plyrs->SIZE;count++)
    {
        cout << endl <<"  --- Player #" << (count+1) << " Information ---"
             << endl << endl << " Name: " << temp[count].player_name << endl;
         
        cout << endl << " Coordinates of ships:" << endl << endl;
        
        for(int z=0;z<plyrs->numshps;z++)
            cout <<  "      " << temp[count].ships[z] << endl;
       
        cout << endl << " Shots Fired: " << endl << endl;
                
        for(int z=0;z<100;z++)
            cout << " " << temp[count].shts_frd[z];
        
        cout << endl << " Final Player Board:" << endl;

        for(int z=0;z<10;z++)
        {
            for(int f=0;f<10;f++)
               cout << " " << temp[count].player_board[z][f];
            
            cout << endl;
        }    
    } 
}        