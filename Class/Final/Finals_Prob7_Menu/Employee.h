/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Employee.h
 * Author: Daniel Baca
 *
 * Created on December 10, 2022, 8:50 PM
 */
 
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
  
//Employee Class
class Employee
{
private:
    double Tax(float);  //Utility Procedure
    char MyName[20];   //MyName Char Array Property
    char JobTitle[20]; //JobTitle Char Array Property
    float HourlyRate;  //HourlyRate Property
    int HoursWorked;   //HoursWorked Property
    float GrossPay;    //GrossPay Property
    float NetPay;      //NetPay Property
      
public:
    Employee(const char[], const char[],float); //Constructor
    float CalculatePay(float,int); //Procedure
    float getGrossPay(float,int);  //Procedure
    float getNetPay(float);        //Procedure
    void toString();               //Procedure
    int setHoursWorked(int);       //Procedure
    float setHourlyRate(float);    //Procedure
};

#endif /* EMPLOYEE_H */

