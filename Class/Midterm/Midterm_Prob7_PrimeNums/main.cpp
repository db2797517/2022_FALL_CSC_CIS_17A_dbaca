/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on October 22nd, 2022, 1:38 PM
 * 
 * Purpose: Factor an input integer into it’s prime numbers. Create a structure 
 * to hold the array of prime numbers. Any number between [2,65000] will be a 
 * valid number to check for prime factors.
 * struct Prime{
 * unsigned short prime;
 * unsigned char power;
 * };
 * struct Primes
 * {
 * unsigned char nPrimes;
 * Prime *prime;
 * };
 * Output the number and it’s primes i.e. 120 = 2^3 ∗ 3^1 ∗ 5^1
 * So create a function 
 * Primes *factor(int); Input an integer, return all prime factors
 * void prntPrm(Primes *); Output all prime factors
 * 
 */
 
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>

struct Prime  // Prime numbers storage structure
{
    unsigned short prime;
    unsigned char power;
};  

struct Primes // Prime numbers structure holding the prime number info arrays
{
    unsigned char nPrimes;

    Prime *prime;
};

//Function Prototypes
Primes *factor(int);        //Function to find factored data and return it
void prntPrm(Primes * prm); //Function to output factored output

using namespace std;

int main(int argc, char** argv) 
{
    struct Primes * prm = new Primes; //Dynamic Prime Number structure
    int input =0;                     //User number input to factor
    
    //Prompt the user for a number to factor
    cout << endl << " Enter a number to factor: ";
    cin >> input;
    
    //Input Validation Loop
    while(input < 2 || input > 65000)
    {
        //Prompt User to input valid number
        cout << endl
             << " Please enter a number in the range (2 - 65000). Try Again."
             << endl;
          
        //Prompt the user for a new number to factor
        cout << endl << " Enter a number to factor: ";
        cin >> input;
    }
    
    //Find factored data and enter it into the structure
    prm = factor(input);
    
    //Output the format for the number input
    cout << endl << "    " << input << " = ";
    
    //Print the factored output
    prntPrm(prm);
    
    //Formatting
    cout << endl;
    
    //Delete the dynamic structure
    delete[] prm;
    
    //Exit Stage Right
    return 0;
}

//Function used to factorize the input number and store the output
Primes *factor(int input)
{
    struct Primes * prm = new Primes;   //Dynamically allocated structure
    prm->prime = new Prime[50];         //Dynamically allocated array of 
                                        //structures
    unsigned char power =0; //Temporary value holding the power of each prime #
    int count =0;    //Counter for size of the array           
    int c = 2;       //Prime number value counter
    int i = 0;       //Array element counter
    
    //Check to see if number is entirely factored
    while(input>1)
    {
        //Check to see if input is modable by the prime number counter
        if(input%c==0)
        {
        prm->prime[i].prime = c;
        input/=c;
        power++;
        
            if(input == 1)
            {
                prm->prime[i].power = power;
                i++;
                count++;
                power =0;
            }
        }
        else 
        {
            //Raise the prime number counter by 1
            c++;
            
            //Check to see if the input is modable by the counter
            if(input%c==0 )
            {
            prm->prime[i].power = power;
            i++;
            count++;
            power =0;
            }
        }
    }
    
    //Set the number of primes value
    prm->nPrimes = count;

    //Return the prm structure
    return prm;
}
 
//Function for the final factored results
void prntPrm(Primes * prm)
{
    //Output the final factored results
    if(prm->prime[0].prime > 1000)
    {
        for(int i=1;i<prm->nPrimes;i++)
        {
            if(i == (prm->nPrimes-1))
            cout << prm->prime[i].prime << "^" 
                 << static_cast<int>(prm->prime[i].power) << " ";
            else
                cout << prm->prime[i].prime << "^" 
                 << static_cast<int>(prm->prime[i].power) << " * ";
        }
    }
    else  
    {  
        for(int i=0;i<prm->nPrimes;i++)
        {
            if(i == (prm->nPrimes-1))
            cout << prm->prime[i].prime << "^" 
                 << static_cast<int>(prm->prime[i].power) << " ";
            else
                cout << prm->prime[i].prime << "^" 
                 << static_cast<int>(prm->prime[i].power) << " * ";
        }
    }
}

