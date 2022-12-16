/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MilTime.h
 * Author: Daniel Baca
 *
 * Created on November 20, 2022, 3:35 PM
 */

#ifndef MILTIME_H
#define MILTIME_H
  
//MilTime Class
class MilTime : public Time
{
protected:
    int milh; //Contains the hours in 24-hour format
    int mils; //Contains the seconds in standard format
public:
    //Default Constructor
    MilTime()
        { milh = 0; mils = 0; }
       
    //Constructor
    MilTime(int mh, int ms)
    {   settime(mh,ms);   }
    
    //Exception Class #1
    class BadHour
    {   };
    
    //Exception Class #2
    class BadSeconds
    {   };
    
    //Function to convert the time from military to standard time
    void settime(int mh, int ms)
    { 
        if(mh >= 0 && mh < 2360)
            milh = mh; 
        else 
            throw BadHour(); 
        
        if(ms >= 0 && ms < 60)
            mils = ms; 
        else 
            throw BadSeconds(); 
      
        int num1000 = 0,
            num10 = 0,
            num1 = 0;
         
        num1000 = mh/100;
        num10 = mh%100/10;
        num1 = mh%10;
        
        if(num1000 > 12)
            num1000 -= 12;
        
        if(num1000 == 0)
            num1000=12;
        
        if(num10 !=0 && num1 == 0)
            num10 *= 10;
        else if(num10 !=0 && num1 != 0)
        {
            num10 *= 10;
            num10 += num1;
        }
        else 
        { 
            num10 = num1;
        }
        
        hour = num1000;
        min = num10;
        sec = ms; 
    } 
    
    //Accessor Functions
    int gethour()
        { return milh; } 
    
    int getstandhr() 
        { return hour; } 
};

#endif /* MILTIME_H */

