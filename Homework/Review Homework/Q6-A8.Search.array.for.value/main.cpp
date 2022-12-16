/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * 9/4/2022 19:27pm
 * Purpose:  Searching for multiple occurrence of patterns
 * Note:  cout proceeds to null terminator, cin reads to end of line
 *        for character arrays
 */
 
//System Libraries Here
#include <iostream>//cin,cout,getline()
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//PI, e, Gravity, or conversions

//Function Prototypes Begins Here
//srch1 utility function Input->start position, Output->position found or not
//srch1 is a simple linear search function, repeat in srchAll till all found
//srch1 Input->sentence, pattern, start position Output-> position found
//Remember arrays start at index/position 0
//srchAll Input->sentence, pattern Output->position array
int  srch1(const char [],const char [],int);//Search for 1 occurrence
void srchAll(const char [],const char [],int []);//Search for all occurrences
void print(const char []);//Print the character arrays
void print(const int []); //Print the array of indexes where the pattern found

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int LINE=81;               //Size of sentence or pattern to find
    char sntnce[LINE],pattern[LINE]; //80 + null terminator
    int match[LINE];                 //Index array where pattern was found
    
    //Input a sentence and a pattern to match
    cout<<"Match a pattern in a sentence."<<endl;
    cout<<"Input a sentence"<<endl;
    cin.getline(sntnce,LINE);
    cout<<"Input a pattern."<<endl;
    cin.getline(pattern,LINE);

    //Search for the pattern
    //Input the sentence and pattern, Output the matching positions
    //Remember, indexing starts at 0 for arrays.
    srchAll(sntnce,pattern,match);
    
    //Display the inputs and the Outputs
    cout<<endl<<"The sentence and the pattern"<<endl;
    print(sntnce);
    print(pattern);
    cout<<"The positions where the pattern matched"<<endl;
    print(match);
    
    //Exit
    return 0;
}


// Search the sentence for the pattern by using the search once function muliple times
void srchAll (const char sntnce[], const char pattern[], int match[])
{
    int num =0; // Variable for readjusting loop in search
    
    // Use the search once function multiple times 
    for(int i =0; i <5;i++)
    {
        match[i] = srch1(sntnce,pattern,num);
        num = match[i];
    }
        
}

// Search the sentence for one instance of the pattern
int srch1(const char sntnce[], const char pattern[], int num)
{
    int count = strlen(sntnce); // Set the count equal to the length of the sentence
    int count2 = 0; // Counter for the characters in the pattern array
    int count3 = 0; // Counter keeping track of the length of the pattern found
    int count4 =0;  // Counter indicating the space in the array that the pattern was initially found
    int i=0;        // Loop counter
    
    // If there has already been one instance of the pattern, adjust the search loop
    if(num!=0)
        i = num + 1;
    
    // Find the pattern in the sentence and relay its location
    for(i; i < count;i++)
    {
        if (sntnce[i] == pattern[count2])
        {
            if(count3 == 0)
                count4=i;
                
            count3++;
            count2++;
            
            if(count3 == strlen(pattern))
                break;
        }
        else   
        {
            count2 = 0;
            count3 = 0;
        }
    }
    
    // Return the position the pattern was found at
    return count4;
}

// Print the array
void print(const char array[])
{
    cout << array << endl;
}

// Print the final results
void print(const int match[])
{
    // Check to see if the first spot in the array is empty.
    if(match[0] == 0)
        cout << "None" << endl;
    
    // Output the results
    for(int j =0; j <5;j++)
    {
        if(match[j] > 0)
            cout << match[j] << endl;
        else
            break;
    }
}

