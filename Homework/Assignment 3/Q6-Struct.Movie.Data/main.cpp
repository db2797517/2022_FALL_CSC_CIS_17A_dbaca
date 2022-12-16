/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on September 14th, 2022, 9:35 AM
 * Purpose: 
 
Write a program that uses a structure named MovieData to store the following information about a movie:
Title
Director
Year Released
Running Time (in minutes)
The program should read the number of movies, then create MovieData structure 
variables, store values in their members, and pass each one, in turn, to a 
function that displays the information about the movie in a clearly formatted 
manner. 
 */
 
//System Libraries
#include <iostream>
using namespace std;

//User Libraries-none

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions
  
//Function Prototypes
float getData(struct movie_data movies[], int);
void prntData(struct movie_data movies[], int);

//Structure for the movies data
struct movie_data
{
  string title;
  string director;
  int year_re;
  int run_time;
};

//Execution Begins Here
int main(int argc, char** argv)
{
    //Declare variables
    int SIZE;   //Size is equal to the number of movies to hold data for
    
    cin >> SIZE;  // Get the size or the number of movies
    
    struct movie_data movies[SIZE]; //Array Structure of movies
    
    // Use function to get data
    getData(movies,SIZE);
    
    // Use function to print output
    prntData(movies,SIZE);
    
    //Exit stage right!
    return 0;
}

// Recieve Input function
float getData(struct movie_data movies[], int SIZE)
{
    
    //Display prompt for the user
    cout << "This program reviews structures" << endl;
    cout << "Input how many movies, the Title of the Movie, Director, Year Released, and the Running Time in (minutes)." << endl;
    cout << endl;
    
    //Get the input for each movie
    for(int i=0; i<SIZE; i++)
    {
        cin.ignore();
        getline(cin,movies[i].title);

        cin.ignore(0);
        getline(cin,movies[i].director);
        
        cin >> movies[i].year_re;
        cin >> movies[i].run_time;
    } 
    return 0;
}

//Display Output Function
void prntData(struct movie_data movies[], int SIZE)
{
    //Output all the information for each movie
    for(int i=0; i<SIZE; i++)
    {
        cout << "Title:     " << movies[i].title << endl;
        cout << "Director:  " << movies[i].director << endl;
        cout << "Year:      " << movies[i].year_re << endl;
        cout << "Length:    " << movies[i].run_time << endl;
        
        if(i <SIZE-1)
        cout << endl;
    }
}



