/* 
 * File:   main.cpp
 * Author: Daniel Baca, originally Dr. Lehr's work
 * Created on October 10th, 2022, 10:39 PM
 * Purpose:  Compare 1 and 2 Dimensional Dynamic Arrays - Convert the 1D and 2D
 * Arrays to 1D and 2D Vectors.
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions and Array Dimension
     
//Function Prototypes Here
void prntVec(vector<int> &,int,int);
void prntVec(vector<vector<int>> &,int,int);
void fillVec(vector<int> &,int,int,int);
void fillVec(vector<vector<int>> &, int,int);
void fillVec(vector<vector<int>> &,vector<int> &,int,int); 
// void destroy(int **,int);
void fillVec(int &,vector<int> &,int,int,int);
void swap(int &,int &);
void smlLst(vector<int> &,int,int);
void mrkSort(vector<int> &,int);
 
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
     
    //Declare all Variables Here
    int rowsize=4;//Row size for both 1 and 2 D arrays
    int colsize=3;//The column size for a 2 dimensional Array
    int lowRng=100,highRng=999;
    int perLine=4;
    
    /* Old array elements
    int *array;
    int *brray;
    int *crray;
    int **table;
    */
    
    //Vectors used in place of 1D and 2D dynamic arrays
    vector<int> vec_a(rowsize);
    vector<int> vec_b(rowsize);
    vector<int> vec_c(rowsize);
    vector<vector<int>> vec_d(rowsize, vector<int> (colsize));
        
    //Fill each parallel array
    fillVec(vec_a,rowsize,highRng,lowRng);
    fillVec(vec_b,rowsize,highRng/10,lowRng/10);
    fillVec(vec_c,rowsize,highRng/100,lowRng/100);
    
    //Sort the array the for all positions
    mrkSort(vec_a,rowsize);
    mrkSort(vec_b,rowsize);
    mrkSort(vec_c,rowsize);
    
    //Fill the 2-D array
    fillVec(vec_d,rowsize,colsize);
    fillVec(vec_d,vec_a,rowsize,0);
    fillVec(vec_d,vec_b,rowsize,1);
    fillVec(vec_d,vec_c,rowsize,2);
    
    //Print the values in the vectors
    prntVec(vec_a,rowsize,perLine);
    prntVec(vec_b,rowsize,perLine);
    prntVec(vec_c,rowsize,perLine);
    prntVec(vec_d,rowsize,colsize);
    
    /* Cleanup for the original arrays
    delete []array;
    delete []brray;
    delete []crray;
    destroy(table,rowsize);
    */

    //Exit
    return 0;
}

/* Not necessary for vectors
void destroy(int **a,int rows){
    for(int row=0;row<rows;row++){
        delete []a[row];
    }
    delete []a;
}
*/

void fillVec(vector<vector<int>> &vec_a,vector<int> &vec_c,int rowSize,int wchCol){
    for(int row=0;row<rowSize;row++){
        vec_a[row][wchCol]=vec_c[row];
    }
}

void fillVec(vector<int> &vec_a,int n,int hr,int lr)
{
    for(int indx=0;indx<vec_a.size();indx++){
        vec_a[indx]=rand()%(hr-lr+1)+lr;
    }
}

void fillVec(vector<vector<int>> &vec_a,int rows,int cols){
    //Allocate Memory for 2-D Vector
    rows=rows<2?2:rows;
    cols=cols<2?2:cols;

    //Fill it with 0's
    for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
            vec_a[row][col]=0;
        }
    }
}

void prntVec(vector<vector<int>> &vec_a,int rowsize,int colsize){
     cout<<endl<<"The Vector Values"<<endl;
    for(int row=0;row<rowsize;row++){
        for(int col=0;col<colsize;col++){
            cout<<setw(4)<<vec_a[row][col];
        }
        cout<<endl;
    }
}

void prntVec(vector<int> &vec_a,int n,int perLine){
    //Print the values in the array
    cout<<endl<<"The Vector Values"<<endl;
    for(int indx=0;indx<vec_a.size();indx++){
        cout<<vec_a[indx]<<" ";
        if(indx%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void mrkSort(vector<int> &vec_a,int n){
    for(int pos=0;pos<vec_a.size();pos++){
        smlLst(vec_a,n,pos);
    }
}

void smlLst(vector<int> &vec_a,int n,int pos){
    for(int i=pos+1;i<vec_a.size();i++){
        if(vec_a[pos]>vec_a[i]){
            swap(vec_a[pos],vec_a[i]);
        }
    }
}

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

