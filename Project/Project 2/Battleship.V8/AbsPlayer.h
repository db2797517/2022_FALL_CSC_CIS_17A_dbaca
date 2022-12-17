
/* 
 * File:   AbsPlayer.h
 * Author: User
 *
 * Created on November 26, 2022, 9:28 PM
 */

#ifndef ABSPLAYER_H
#define ABSPLAYER_H
 
#include <string>
#include <cstring>
using namespace std;

class AbsPlayer
{
public:  

    virtual void setplyrnm(string) = 0;
    
    virtual string getplyrnm() = 0;
};

#endif /* ABSPLAYER_H */

