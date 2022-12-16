/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GradedActivity.h
 * Author: User
 *
 * Created on November 20, 2022, 5:43 PM
 */

#ifndef GRADEDACTIVITY_H
#define GRADEDACTIVITY_H
 
//GradedActivity Class 
class GradedActivity
{
    
protected:  
    float score; //To hold the numeric score
public:  
    
    //Default constructor
    GradedActivity()
    {   score = 0.0;    }
    
    //Constructor
    GradedActivity(float s)
    {   score = s;  } 
    
    //Mutator functions
    void setscore(float s)
        {   score = s; }
 
    //Accessor Functions
    float getscore()
        {   return score; }
    
    char getlettergrade() const
    {
        char lettergrade; //To hold the letter grade

        if(score > 89)
            lettergrade = 'A';
        else if(score > 79)
            lettergrade = 'B';
        else if(score > 69)
            lettergrade = 'C';    
        else if(score > 59)
            lettergrade = 'D';    
        else
            lettergrade = 'F'; 

        return lettergrade;
    }
};

#endif /* GRADEDACTIVITY_H */

