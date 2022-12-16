/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * Created on October 17th, 2022, 6:32 PM
 * Purpose: 
 * A company wants to transmit data over the telephone, but they are concerned 
 * that their phones may be tapped. All of their data is transmitted as 
 * four-digit integers. However, they utilize the digits 0,1,2,3,4,5,6,7 only. 
 * They have asked you to write a program that will encrypt their data so that 
 * it may be transmitted more securely.Your application should read a four-digit
 * integer with the numbers 0 to 7 entered by the user in an input dialog and 
 * encrypt it as follows: Replace each digit by the sum of that digit plus 6 
 * modulus 8. Then swap the first digit with the third, and swap the second 
 * digit with the fourth. Then print the encrypted integer. Write a separate 
 * application that inputs an encrypted four-digit integer and decrypts. If you 
 * encrypt a number, you should be able to get the same number decrypted back 
 * when the user does this. Note: sometimes errors occur and the digits 8, and 
 * 9 might appear. Detect this condition and flag the error. Can’t read in 
 * numbers individually. All the digits must be read with one cin statement.
 */
       
//Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;

//No Global Constants - none

//Function Prototypes - none

//Execution Begins Here
int main(int argc, char** argv) 
{ 
    //Declare Variables
    int SIZE = 4;   //Size of the arrays
    int arr[SIZE];  //Array holding converted string values
    int input;     //Number input for menu
    string nums;    //String holding four digit number
    int temp;       //Temporary value used for holding and switching values
    int temp1=0;    //Second temporary value same purpose as the other one
    int tempary[SIZE]; //Temporary array holding possible configurations             
    int count[SIZE];   //Array used in combination loop
    int temps[0];      //Second array used in combination loop
    bool result = 1;   //Input validation result 
    
    //Display Menu
    cout << "Select an option:" << endl
         << " - 1 - > Encrypt Four digit integer" << endl
         << " - 2 - > Decrypt Four digit integer" << endl
         << endl
         << "--> Input: ";

    //Receive input for menu
    cin >> input;
    cout << endl;
    
    //Formatting
    cin.ignore();
    
    //Menu input validation
    while(input != 1 && input != 2)
    {
        cout << "Please enter enter a valid option (ex. 1 or 2)" << endl;
        cout << endl << "--> Input: ";
        cin >> input; 
        cout << endl;
        
        //Formatting
        cin.ignore(1);
    }
    
    //Chose which operation to do based on menu input
    switch(input)
    {
        case 1:
                //Loop for input validation
                do
                { 
                   
                //Reset bool value in case of loop
                result = 1;
                   
                //Prompt user for number to encrypt
                cout << endl << "Encryption Number: ";
                 cin >> nums;
                
                //Check to make sure input is only four digits long
                int i = 0;
                while (nums[i])
                i++;
                     
                //Input validation for the user number input
                for(int i = 0; i < nums.length(); i++)
                    if(nums[i] == '9' || nums[i] == '8' || isalpha(nums[i]))
                        result = 0; 
                
                //If string is too long or too short then retry
                if(i > 4 || i < 4)
                result = 0;
                
                //Output the input validation prompt
                if(result == 0)
                cout << endl << "Only enter digits from (0-7) and exactly four"
                     << " digits" << endl;
                
                }while(result != 1);
                //As long as the input is invalid keep looping

                //Change string values to usable int values
                for(int i = 0; i < SIZE; i++)
                {
                    arr[i] = nums[i] - 48;
                }
                 
                //Perform the encryption
                for(int i = 0; i < SIZE; i++)
                {
                    temp = arr[i];
                    temp += 6;
                    temp = temp % 8;
                    arr[i] = temp; 
                }
      
                temp = 0;
 
                //Swap the values around
                temp = arr[3];
                temp1 = arr[1];
                arr[3] = temp1;
                arr[1] = temp;

                temp = arr[2];
                temp1 = arr[0];
                arr[2] = temp1;
                arr[0] = temp;
 
                //Output the final encrypted number
                cout << endl << " Encrypted Number: ";               
                for(int i = 0; i < SIZE; i++)
                {
                    cout << arr[i];
                }
                cout << endl;

                break;
        case 2:
                //Loop for input validation
                do
                { 
                   
                //Reset bool value in case of loop
                result = 1;
                   
                //Prompt user for number to encrypt
                cout << endl << "Decryption Number: ";
                 cin >> nums;
                
                //Check to make sure input is only four digits long
                int i = 0;
                while (nums[i])
                i++;
                     
                //Input validation for the user number input
                for(int i = 0; i < nums.length(); i++)
                    if(nums[i] == '9' || nums[i] == '8' || isalpha(nums[i]))
                        result = 0;
                
                //If string is too long or too short then retry
                if(i > 4 || i < 4)
                result = 0;
                
                //Output the input validation prompt
                if(result == 0)
                cout << endl << "Only enter digits from (0-7) and exactly four"
                     << " digits" << endl;
                
                }while(result != 1);
                //As long as the input is invalid keep looping
                
                //Convert string input to int array values
                for(int i = 0; i < SIZE; i++)
                    arr[i] = nums[i] - 48;

                //Initialize all elements withing the arrays
                for(int i = 0; i < 4; i++)
                {
                    tempary[i] = 0;
                    count[i]=0;
                    temps[i]=0;
                }

                //Encrypt all possible combinations and find matching decrypted
                //and encrypted combinations
                for(int a = 0; a < 8; a++)
                {
                    if(count[0]==8)
                    {
                        tempary[1]=0; 
                        tempary[2]=0;
                        tempary[3]=0; 
                        count[0]=0;
                    }       
                    for(int b = 0; b < 8; b++)
                    {
                        if(count[1]==8)
                        {
                            tempary[1]=0; 
                            tempary[2]=0;
                            tempary[3]=0;
                            count[1]=0;
                        }
                        for(int c = 0; c < 8; c++)
                        {
                            if(count[2]==8)
                            {
                                tempary[2]=0;
                                tempary[3]=0; 
                                count[2]=0;
                            }
                            for(int d = 0; d < 8; d++)
                            { 
                                if(count[3]==8)
                                {
                                    tempary[3]=0;
                                    count[3]=0;
                                }

                                 temps[0]=tempary[0];
                                 temps[1]=tempary[1];
                                 temps[2]=tempary[2];
                                 temps[3]=tempary[3];

                            for(int i = 0; i < SIZE; i++)
                            {
                                temp = tempary[i];
                                temp += 6;
                                temp = temp % 8;
                                tempary[i] = temp; 
                            }
  
                            temp = tempary[3];
                            temp1 = tempary[1];
                            tempary[3] = temp1;
                            tempary[1] = temp;

                            temp = tempary[2];
                            temp1 = tempary[0];
                            tempary[2] = temp1;
                            tempary[0] = temp;                  

                            //Display the decrypted number
                            if(!memcmp(arr, tempary, sizeof(arr)))
                            {           
                                cout << endl << " Decrypted Number: ";
                                cout << temps[0] << temps[1] 
                                     << temps[2] << temps[3];
                            }

                            tempary[0]=temps[0];
                            tempary[1]=temps[1];
                            tempary[2]=temps[2];
                            tempary[3]=temps[3];

                                count[3]++;
                                tempary[3]++;
                            }
                            count[2]++;
                            tempary[2]++; 
                        }
                        count[1]++;
                        tempary[1]++;
                    }
                    count[0]++;
                    tempary[0]++;
                }

                //Formatting
                cout << endl;
                break; 
    }
    
    //Exit Stage Right
    return 0;
}



