/* 
 * File:   main.cpp
 * Author: Daniel Baca
 * 9/5/2022 9:37am
 * Purpose:  Sum Rows, Sum Columns, Grand Sum of an integer array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <iomanip> //setw(10)
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;  //Max Columns much larger than needed.

//Function Prototypes Here
void read(int [][COLMAX],int &,int &);//Prompt for size then table
void sum(const int [][COLMAX],int,int,int[][COLMAX]);//Sum rows,col,grand total
void print(const int [][COLMAX],int,int,int);//Either table can be printed

//Program Execution Begins Here
int main(int argc, char** argv) 
{
    //Declare all Variables Here
    const int ROW=80;           //Max Rows much larger than needed
    int array[ROW][COLMAX]={};  //Declare original array
    int augAry[ROW][COLMAX]={}; //Actual augmented table row+1, col+1
    int row,col;                
    
    //Input the original table
    read(array,row,col);
    
    //Augment the original table by the sums
    sum(array,row,col,augAry);
    
    //Output the original array
    cout<<endl<<"The Original Array"<<endl;
    print(array,row,col,10);//setw(10)
    
    //Output the augmented array
    cout<<endl<<"The Augmented Array"<<endl;
    print(augAry,row+1,col+1,10);//setw(10)
    
    //Exit
    return 0;
}

// read the input
void read(int array[][COLMAX],int &row,int &col)
{
    cout << "Input a table and output the Augment row,col and total sums." << endl 
         << "First input the number of rows and cols. <20 for each" << endl 
         << "Now input the table." << endl;
    
    cin >> row;
    cin >> col;

    for (int i = 0; i < row; i++ )
    {
        for (int z = 0; z < col; z++ )
            cin >> array[i][z];
    }
}

// get the sums of the rows and columns
void sum(const int array[][COLMAX],int row,int col,int augAry[][COLMAX])
{
    int totalsum = 0;
    int Rowsum [row];
    int rowsum = 0;
    int colsum [col];
    for (int i = 0; i < row; i++ )
    {
        for (int z = 0; z < col; z++ )
             augAry[i][z] = array[i][z];
    }
    
    for (int i = 0; i < row; i++ )
    {
        for (int z = 0; z < col; z++ )
        {
             augAry[i][col] += augAry[i][z];
             augAry[row][col] += augAry[i][z];
             augAry[row][z] += augAry[i][z];
        }
    }  
    
}

// print the results
void print(const int array[][COLMAX], int row, int col, int ten)
{
    for (int i = 0; i < row; i++ )
    {
        for (int z = 0; z < col; z++ )
            cout <<setw(ten) << array[i][z] << setw(ten);
        cout << endl;
    }
}
