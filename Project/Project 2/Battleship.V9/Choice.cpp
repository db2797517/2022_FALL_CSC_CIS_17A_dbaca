/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Shots_Fired.h"
 
    //Overloaded << operator function
    ostream& operator<<(ostream& os, Shts_Frd & same)
    {
        os << "        ----------- Battleship -----------" << endl
         << "        The classic strategy board game!!!" << endl;
         os << "          ----- Somethings to know -----" << endl
         << "           Carrier Size (5 spaces)" << endl
         << "        Battleship Size (4 spaces)" << endl       
         << "           Cruiser Size (3 spaces)" << endl
         << "         Submarine Size (3 spaces)" << endl         
         << "         Destroyer Size (2 spaces)" << endl << endl
         << "  --- Keep this in mind for when you place your ships!!! ---"
         << endl << "  --- Once the game starts and each player can shoot ---" 
         << endl << "  --- you can input Q to Quit the Game whenever.     ---"
         << endl << endl;
    
        return os;
    }

