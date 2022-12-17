/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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

    virtual void setplyrnm() = 0;
     
    virtual void setships() = 0;
    
    virtual string getplyrnm() = 0;
};

#endif /* ABSPLAYER_H */

