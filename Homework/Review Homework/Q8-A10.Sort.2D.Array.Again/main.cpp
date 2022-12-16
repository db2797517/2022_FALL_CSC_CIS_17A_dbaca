/* 
 * Note:  This time you create the strcmp() function that takes into
 * account the new sort order.
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char [][COLMAX],int &);//Outputs row and columns detected from input
void sort(char [][COLMAX],int,int,const char[],const char[]);//Sort by row using strcmp();
void print(const char [][COLMAX],int,int);//Print the sorted 2-D array
//int strcmp(char a[],char b[],char replace[],char with[]){
//int strcmp(char [],char [],const char [],const char []);//Replace sort order

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    char replace[COLMAX],with[COLMAX];//New sort order
    
    //Input the new sort order then sort
    cout<<"Modify the sort order by swapping these characters."<<endl;
    cin>>replace;
    cout<<"With the following characters"<<endl;
    cin>>with;
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,rowDet);
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    if(rowDet==rowIn&&colDet==colIn)
    {
        sort(array,rowIn,colIn,replace,with);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    }
    
    //Exit
    return 0;
}

// Read the input and determine the number of columns of input
int read(char array[][COLMAX], int &rowDet)
{
    //Establish counter
    int count=0;
    
    // Gather user input and determine number of actual rows
    for(int i= 0;i<20;i++)
    {
        if(cin >> array[i])
            count++;
    }
    
    // Set numbers of rows counted
    rowDet = count;
        
    // 
    int length;       // Legnth of the row
    char* swap_char;  // Char to use for switching out the input chars
    int cols[rowDet]; // Array for columns numbers determined

    // Determine the number of columns in the array
    for(int i= 0;i<rowDet;i++)
    {
        swap_char = array[i];
        length = strlen(swap_char);
        cols[i] = length;
    }
    
    // Initialize value for the determined number of columns
    int max = cols[0];

    // Find the true value
    for (int j = 0; j < rowDet; ++j) 
    {
        if (cols[j] > max) 
            max = cols[j];
    }
    
    // Return the true number of columns 
    return max;
}


// Sort the array 
void sort(char array[][COLMAX],int rowIn,int colIn, const char replace[], const char with[])
{
    
    char temp[rowIn];
    
    for(int i = 0; i < (rowIn-1);i++)
    {     
        for(int j = i+1; j < rowIn;j++)
        {
            if(strcmp(array[i],array[j]) < 0)
            {
                strcpy(temp,array[i]);
                strcpy(array[i], array[j]);
                strcpy(array[j], temp);
            }
        }
    }
}

// Print the output
void print(const char array[][COLMAX],int rowIn,int colIn)
{

    for(int i = 0; i < rowIn;i++)
    {     
        cout << array[i] << endl;
    }
    
}
