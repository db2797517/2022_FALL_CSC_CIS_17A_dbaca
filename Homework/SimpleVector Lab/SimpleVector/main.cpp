/* 
 * File:   main.cpp   
 * Author: Dr. Mark E. Lehr (modified by Daniel Baca)
 * Created on June 1st, 2021, 7:50 AM
 * Purpose:  To Test and Modify the Simple Vector
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "SimpleVector.h"

//Global Constants

//Function prototypes
void fillVec(SimpleVector<unsigned char> &);
void prntVec(SimpleVector<unsigned char> &,char);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    unsigned char size=100;
    SimpleVector<unsigned char> sv(size);
    char choice; //Char variable to choose to pop or push
      
    //Fill the Vector
    fillVec(sv);
    
    //Prchar the Vector
    cout<<"Original Random Dynamic Array derived Simple Vector";
    prntVec(sv,10);
    
    //Loop for push and pop
    do
    { 
        //Prompt user to input value for push, pop, or end program
        cout << endl << "   1 -> To push" << endl << "   2 -> To pop" << endl 
             << "   3 -> To End Program" << endl << endl << "Choice: ";
         cin >> choice;
        cout << endl;
        
        if(choice == '1' )
        {
            //Push the last element in the array
            sv.push();

            //Copy the Vector
            SimpleVector<unsigned char> copysv(sv);

            //Print the Vector
            cout<<"Copied Random Dynamic Array derived Simple Vector"<<endl;
            prntVec(copysv,10);
        }
        else if(choice == '2' )
        {
            //Pop the last element in the array
            sv.pop();

            //Copy the Vector
            SimpleVector<unsigned char> copysv(sv);

            //Print the Vector
            cout<<"Copied Random Dynamic Array derived Simple Vector"<<endl;
            prntVec(copysv,10);
        }
    }while(choice != '3');

    //Exit stage right
    return 0;
}

void prntVec(SimpleVector<unsigned char> &sv,char perLine){
    cout<<endl;
    for(unsigned char i=0;i<sv.size();i++){
        cout<<sv[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void fillVec(SimpleVector<unsigned char> &sv){
    for(unsigned char i=0;i<sv.size();i++){
        sv[i]=rand()%26+65;
    }
}

