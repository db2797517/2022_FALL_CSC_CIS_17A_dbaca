/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on September 26th, 2022, 10:02 PM
 * Purpose:  
 * 
 * Write a program that keeps track of a speaker's bureau. The program should 
 * use a structure to store the following data about a speaker.
 *
 * Name
 * Telephone Number
 * Speaking Topic
 * Fee required
 *   
 * The program should use an array of at least 10 structures. It should let the 
 * user enter data into the array, change the contents of any element, and 
 * display all the data stored in the array. The program should have a 
 * menu-driven user interface.
 * 
 * Input Validation: When the data for a new speaker is entered, be sure the 
 * user enters data for all the fields. No negative amounts should be entered 
 * for a speaker's fee.
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>
#include <cstring>
#include <string>
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

// Structure holding variables for each Speaker
struct Speaker_Info
{
    string name;    // Name of the speaker
    string telnum;  // Telephone Number of the speaker
    string topic;   // Speaker's speech topic
    float fee = 0;  // Speaker's numeric Fee value
};

//Function Prototypes
bool menu(struct Speaker_Info speaker[], int&, int&);     // Menu for program
void getData(struct Speaker_Info speaker[],int);   // Place to receive all info 
void chngData(struct Speaker_Info speaker[], int); // Place to change any info
void prntData(struct Speaker_Info speaker[],int);  // Print all data
 
//Execution of Code Begins Here
int main(int argc, char** argv) 
{
    //Declare all variables for this function
    int SIZE = 10; // Size of the speaker structure array
    int value;     // Variable for the while loop menu functionality
    int num;       // Number of speakers
    struct Speaker_Info speaker[SIZE]; // Structure Array variable for speakers
    
    do
    {
    // Prompt user to enter number of speakers
    cout << "Enter the number of speakers: ";
    cin >> num;
    cout << endl;
    
    } while(num<1);
    
    if(num > 0)
        while(value) value = menu(speaker,SIZE,num);  // Start menu function

    // Exit stage right
    return 0;
}
 
// Function Implementations
bool menu(struct Speaker_Info speaker[], int &SIZE, int & val)
{
    int num; // Number used for menu input
    
    // Set user input to array size
    SIZE = val;
     
    // Output for menu input
    cout << "--------------------- Menu ----------------------" << endl
         << "  1 - Get Info for all the speakers." << endl
         << "  2 - Change the info for any one speaker." << endl
         << "  3 - Show the current info for each speaker." << endl
         << "  4 - Quit the program." << endl << endl;
     
    // Prompt use to enter menu input
    cout << "Enter a Number: ";
    cin >> num;
    cout << endl;
      
    // Provide menu functionality
    switch(num)
    { 
        case 1:
            getData(speaker,SIZE);
            break;
        case 2:
            chngData(speaker,SIZE);
            break;
        case 3: 
            prntData(speaker,SIZE); 
            break;
        case 4: 
            cout << " - Program End - " << endl;
            return false; // End loop and program 
        default:
            cout << "Please enter a menu option (0-4)." << endl << endl;

    }
    
    // Return menu loop feedback
    return true;
}

void getData(struct Speaker_Info speaker[], int SIZE)
{
    // Clarify user input
    cout << " - Please enter the following information for each speaker - " 
         << endl;
    
    // Formatting
    cin.ignore(1);
    
    // Prompt user input for all speakers and format appropriately
    for(int i=0;i<SIZE;i++)
    { 
        cout << "       - Speaker #" << (i+1) << " -" << endl;
        
        cout << setw(18) << "Name: ";
        getline(cin,speaker[i].name);
        if(speaker[i].name.empty())
        {
            cout << " - Please enter a name for the speaker. Try again. - " 
                 << endl;
            break;
        } 
        cin.ignore(0);
                
        cout << setw(15) << "Telephone Number: ";
        getline(cin,speaker[i].telnum);
        if(speaker[i].telnum.empty())
        {
            cout << " - Please enter a telphone number for the speaker." 
                 << " Try again. - " << endl;
            break;
        }
        cin.ignore(0);
        
        cout << setw(18) << "Speaker's Topic: ";
        getline(cin,speaker[i].topic);
        if(speaker[i].topic.empty())
        {
            cout << " - Please enter a topic for the speaker." 
                 << " Try again. - " << endl;
            break;
        }
        cin.ignore(0);
        
        cout << setw(19) << "Fee: $";
        cin >> speaker[i].fee;
        if(speaker[i].fee < 0)
        {
            cout << " - Please enter a valid fee for the speaker." 
                 << " Try again. - " << endl;
            break;
        }  
        cout << endl;
        
        // Formatting
        cin.ignore(1);
    }
}

void chngData(struct Speaker_Info speaker[], int SIZE)
{
    int spenum; // Number of speaker to change info for
    
    do
    {
        // Prompt user input and change info
        cout << "Which speakers' info would you like to change? (0 - 100) - ";
        cin >> spenum;
        cout << endl; 
        
    }while(spenum<1);
    
    cout << "       - Speaker #" << (spenum) << " -" << endl;
        
    cin.ignore(1);
        
    cout << setw(18) << "Name: ";
    getline(cin,speaker[spenum-1].name);
    if(speaker[spenum-1].name.empty())
    {
        cout << " - Please enter a name for the speaker. Try again. - " 
             << endl;
        return;
    } 
    cin.ignore(0);

    cout << setw(15) << "Telephone Number: ";
    getline(cin,speaker[spenum-1].telnum);
    if(speaker[spenum-1].telnum.empty())
    {
        cout << " - Please enter a telphone number for the speaker." 
             << " Try again. - " << endl;
    }
    cin.ignore(0);

    cout << setw(18) << "Speaker's Topic: ";
    getline(cin,speaker[spenum-1].topic);
    if(speaker[spenum-1].topic.empty())
    {
        cout << " - Please enter a topic for the speaker." 
             << " Try again. - " << endl;
    }
    cin.ignore(0);

    cout << setw(19) << "Fee: $";
    cin >> speaker[spenum-1].fee;
    if(speaker[spenum-1].fee < 0)
    {
        cout << " - Please enter a valid fee for the speaker." 
             << " Try again. - " << endl;
    }
    cout << endl;
    
}

void prntData(struct Speaker_Info speaker[], int SIZE)
{
    // Output clarification
    cout << "All Speakers' Information:" << endl
         << "-------------------------" << endl;
    
    // Print all the current Speakers' Information
    for(int i=0;i<SIZE;i++)
        cout << "       - Speaker #" << (i+1) << " -" << endl
             << setw(18) << "Name: "
             << speaker[i].name << endl  
             << setw(15) << "Telephone Number: "
             << speaker[i].telnum << endl
             << setw(18) << "Speaker's Topic: "
             << speaker[i].topic << endl
             << setw(19) << "Fee: $" << fixed << showpoint << setprecision(2) 
             << speaker[i].fee << endl << endl;
} 