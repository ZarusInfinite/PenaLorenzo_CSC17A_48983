/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on December 1, 2015, 12:44 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include "Car.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    //get all the important info
    int year;
    string make;
    cout<<"What year was the car released?"<<endl;
    cin>>year;
    cin.ignore();
    cout<<"What's the make?"<<endl;
    getline(cin,make);
    Car whip(year,make);
    
    //Display info
    cout<<"Car Info: "<<endl;
    cout<<"Model: "<<whip.getMake()<<" Year: "<<whip.getYear()<<endl;
    cout<<"Accelerating your car over 5 intervals"<<endl;
    for(int i=0;i<5;i++)
    {
        whip.accel();
        cout<<"Current Speed: "<<whip.getSpeed()<<endl;
    }
    cout<<"Decelerating your car over 5 intervals"<<endl;
    for(int i=0;i<5;i++)
    {
        whip.brake();
        cout<<"Current Speed: "<<whip.getSpeed()<<endl;
    }
    
    
    
    
    return 0;
}

