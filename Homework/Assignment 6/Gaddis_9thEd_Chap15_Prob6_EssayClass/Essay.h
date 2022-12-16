/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Essay.h
 * Author: User
 *
 * Created on November 20, 2022, 5:56 PM
 */

#ifndef ESSAY_H
#define ESSAY_H
#include "GradedActivity.h"

//Essay Class 
class Essay : public GradedActivity
{
     
private:  
    float gram;     //Float for the number of points scored in Grammar
    float spell;    //Float for the number of points scored in Spelling
    float corlen;   //Float for the number of points scored for Correct length
    float cont;     //Float for the number of points scored in Content
public:  
    
    //Default constructor
    Essay()
    { 
        gram = 0.0;
        spell = 0.0;
        corlen = 0.0;
        cont = 0.0;
    }
    
    //Constructor
    Essay(float g, float s, float cl, float c)
    {   
        gram = g;
        spell = s;
        corlen = cl;
        cont = c;
    } 
     
    //Mutator functions
    void setgram(float g)
        {   gram = g;   }
    
    void setspell(float s)
        {   spell = s;   }
        
    void setcorlen(float cl)
        {   corlen = cl;   }
            
    void setcont(float c)
        {   cont = c;   }

    //Accessor Functions
    float getgram()
        {   return gram;  }
    
    float getspell()
        {   return spell;  }
        
    float getcorlen()
        {   return corlen;  }
            
    float getscont()
        {   return cont;  } 
    
    //Function to receive letter grade
    char getlettergrade()
    {
        float num = corlen + spell + cont + gram;
        
        setscore(num);
        
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

#endif /* ESSAY_H */

