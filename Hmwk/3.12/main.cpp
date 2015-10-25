/* 
 * File:   main.cpp
 * Author: Louli
 *Purpose: Convert Celsius temperatures to Fahrenheit temperatures.
 * 
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    float F,C;//F for Fahrenheit, C for Celsius
    cout<<"Input Celsius temperature you'd like to convert. "<<endl;
    cin>>C;
    F=(9*C)/5+32;//Conversion formula
    cout<<F<<" degrees Fahrenheit equals "<<C<<" degrees Celsius."<<endl;

    return 0;
}

