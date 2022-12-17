
/* 
 * File:   AbsPlayer.h
 * Author: Daniel Baca
 * 
 * Created on November 26, 2022, 9:28 PM
 */
  
#ifndef ABSPLAYER_H
#define ABSPLAYER_H
  
#include <string>
#include <cstring>
using namespace std;

//Abstract class for all player objects created and then inherited
class AbsPlayer
{
public:  
  
    //Virtual function for setplyrnm function
    virtual void setplyrnm(string) = 0;
      
    //Virtual function for getplyrnm function
    virtual string getplyrnm() = 0;
}; 

#endif /* ABSPLAYER_H */

