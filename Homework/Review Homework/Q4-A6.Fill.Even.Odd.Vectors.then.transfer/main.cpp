/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * 9/5/2022 17:56pm
 * Purpose:  Even, Odd Vectors and Array Columns Even, Odd
 * Note:  Check out content of Sample conditions in Hacker Rank
 * Input size of integer array, then array, output columns of Even, Odd
 * Vectors then Even, Odd 2-D Array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <vector>  //vectors<>
#include <iomanip> //Format setw(),right
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=2;//Only 2 columns needed, even and odd

//Function Prototypes Here
void read(vector<int> &, vector<int> &);
void copy(vector<int> &, vector<int> &,int [][COLMAX]);
void prntVec(vector<int> &, vector<int> &);//int n is the format setw(n)
void prntAry(const int [][COLMAX],vector<int> &, vector<int> &);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //No more than 80 rows
    int array[ROW][COLMAX];     //Really, just an 80x2 array, even vs. odd
    vector<int> even(0),odd(0); //Declare even,odd vectors
    
    //Input data and place even in one vector odd in the other
   read(even,odd);
    
    //Now output the content of the vectors
    //          setw(10)
    
    prntVec(even,odd);//Input even, odd vectors with setw(10);
    
    //Copy the vectors into the 2 dimensional array
    copy(even,odd,array);
    
    //Now output the content of the array
    //                              setw(10)
    prntAry(array,even,odd);//Same format as even/odd vectors
    
    //Exit
    return 0;
}

// read the input into the vectors
void read(vector<int> &even, vector<int> &odd)
{
    int numonum;
    int j = 0;
    int k =0;
    
    cout << "Input the number of integers to input." << endl;
     cin >>  numonum;
     
    int nums[numonum];
     
    cout << "Input each number." << endl;
    
    for(int i =0; i < numonum; i++)
        cin >> nums[i];

    for(int i =0; i < numonum; i++)
    {
        if (nums[i] % 2 == 0)
        {
            even.push_back(nums[i]);
            j++;
        }
        else
        {
        odd.push_back(nums[i]);
           k++;
        }
    }
}

// print the vectors
void prntVec(vector<int> &even, vector<int> &odd)
{
    cout << setw(10) << "Vector" << setw(10) << "Even" << setw(10) << "Odd" << endl;
    
    if(odd.size() > even.size())
    {
        for (int i = 0; i < odd.size();i++)
    {
        if(i < even.size())
        {
        cout << setw(20) << even[i] << setw(10) << odd[i] << endl;
        }
        else
        {
        cout << setw(30) << odd[i] << endl;
        }
    }
    }
        else if(even.size() > odd.size())
    {
        for (int i = 0; i < even.size();i++)
    {
        if(i < odd.size())
        {
        cout << setw(20) << even[i] << setw(10) << odd[i] << endl;
        }
        else
        {
        cout << setw(20) << even[i] << endl;
        }
    }
    }
    else if(even.size() == odd.size())
    {
        for (int i = 0; i < even.size();i++)
        cout << setw(20) << even[i] << setw(10) << odd[i] << endl;
    }
  
// copy the vectors elements into the array  
}

void copy(vector<int> &even, vector<int> &odd, int array[][COLMAX])
{
    
    for(int i = 0; i < even.size(); i++)
    {
        array[i][0] = even[i];
    }
    for(int i =0; i < odd.size(); i++)
    {
        array[i][1] = odd[i];
    }
}

// print the results
void prntAry(const int array[][COLMAX], vector<int> &even, vector<int> &odd)
{
    
   cout << setw(10) << "Array" << setw(10) << "Even" << setw(10) << "Odd" << endl;
    
    if (odd.size() > even.size())
    {
    for(int i =0; i < odd.size(); i++)
    {
        if(i < even.size())
        {
        cout << setw(20) << array[i][0] << setw(10) << array[i][1] << endl;
        }
        else
        {
            cout << setw(30) << array[i][1] << endl;
        }
    }
    }
    else if(even.size() > odd.size())
    {
        for (int i = 0; i < even.size();i++)
    {
        if(i < odd.size())
        {
        cout << setw(20) << array[i][0] << setw(10) << array[i][1] << endl;
        }
        else
        {
        cout << setw(20) << array[i][0] << endl;
        }
    }
    }
    else if(even.size() == odd.size())
    {
        for (int i = 0; i < even.size();i++)
        cout << setw(20) << array[i][0] << setw(10) << array[i][1] << endl;
    }
}





















