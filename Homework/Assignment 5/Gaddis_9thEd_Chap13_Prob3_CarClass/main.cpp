/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on November 13th, 2022, 4:30 PM
 * 
 * Purpose: 
 * 
 * Write a class named Car that has the following member variables:
 * yearModel - An int that hold's the car's year model
 * make - A string that holds the make of the car
 * speed - An int that holds the car's current speed
 * 
 * In addition the class should have the following constructor and other member 
 * functions:
 * 
 * Constructor-- The constructor should accept the car's year model and make as 
 *               arguments. These values should be assigned to the object's 
 *               yearModel and make member variables. The constructor should 
 *               also assign 0 to the speed member variables.
 * Accessor-- appropriate accessor functions to get the values stored in an 
 *            object's yearmodel, make, and speed member variables.
 * Accelerate. --The accelerate function should add 5 to the speed member 
 *               variable each time it is called
 * Brake- The brake function should subtract 5 from the speed member variable 
 *        each time it is called.
 *  
 * Demonstrate the class in a program that creates a Car object, then calls the 
 * accelerate function five times. After each call to the accelerate function,
 * get the current speed of the car and display it. Then, call the brake 
 * function five times. After each call to the brake fuction, get the current 
 * speed of the car and display it.
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

//RetailItem Class 
class Car
{
    
private:  
    
    //Class variables
    int yearm;    //an int that holds the car's year model
    string make;  //a string that holds the make of the car
    int speed;    //an int that holds the car's current speed
    
public:  
    
    //Initialization constructor
    Car(int y, string m)
    {
        //Set everything equal to input
        yearm = y;
        make = m;
        speed = 0;
    } 
    
    //Mutator functions
    void accelerate()
        {   speed += 5; }
    
    void brake()
        {   speed -= 5; }
    
    //Accessor Functions
    int getyearm()
        {   return yearm;  }
    
    string getmake()
        {   return make;   }
        
    int getspeed()
        {   return speed;   }    
};

//Execution of Code Begins Here
int main(int argc, char** argv) 
{  
    //Declare Variables
    int yearm;    //an int that holds the car's year model
    string make;  //a string that holds the make of the car
    int speed;    //an int that holds the car's current speed
    
    //Formatting
    cout << endl;
    
    //Prompt the user for year model   
    cout << "  Year Model: ";
     cin >> yearm;
     
    //Input validation for year model   
    while(yearm < 0)
    {
       cout << endl << "  Please enter a non-negative value." << endl << endl;
       cout << "  Year Model: ";
        cin >> yearm;
    }
     
    //Formatting
    cin.ignore();

    //Prompt the user for make of the car    
    cout << "        Make: ";
    getline(cin, make);
     
    Car car(yearm,make); //Object for the car class
    
    //Output that the car is now accelerating
    cout << "   !!!Now accelerating!!!" << endl;
     
    //Repeat the accelerating loop output five times
    for(int i=0; i<5;i++)
    {
        car.accelerate();
        cout << "   Speed is now... " << car.getspeed() << endl;
    }
    
    //Output that the car is now braking
    cout << endl << "   !!!Hitting the brakes!!!" << endl;
    
    //Repeat the braking loop output five times
    for(int i=0; i<5;i++)
    {
        car.brake();
        cout << "   Speed is now... " << car.getspeed() << endl;
    }
     
    //Output car information  
    cout << endl << " -- Car Information --" << endl << "  Year Model: " 
        << car.getyearm() << endl << "        Make: " << car.getmake() << endl;
         
    //Exit stage right
    return 0;  
}    