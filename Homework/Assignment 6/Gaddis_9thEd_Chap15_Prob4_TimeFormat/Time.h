/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Time.h
 * Author: Daniel Baca
 *
 * Created on November 20, 2022, 3:30 PM
 */

#ifndef TIME_H
#define TIME_H

//Time Class
class Time
{ 
protected:
    int hour;
    int min;
    int sec;
public:
    //Default Constructor
    Time()
        { hour = 0; min = 0; sec = 0; }
    
    //Constructor
    Time(int h, int m, int s)
        { hour = h; min = m; sec = s; }
    
    //Accessor Functions
    int getHour() const
        { return hour; }
     
    int getmin() const
        { return min; } 
    
    int getsec() const
        { return sec; }       
};

#endif /* TIME_H */

