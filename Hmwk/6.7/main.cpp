/* 
 * File:   main.cpp
 * Author: Louli
 *
 * Created on September 13, 2015, 9:18 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

//Function Prototypes
float cel(float);//Multiplies a number by 10 and outputs results

/*
 * 
 */
int main(int argc, char** argv) {
    
    float F,C;
    for(int i=1; i < 21; i++){
        F=i;
        cel(F);
        }

    return 0;
}

float cel(float F){
    
    float C;
    C= ((F-32)*5)/9;
    cout<<F<<" degrees Fahrenheit "<< C <<" degrees Celsius."<<endl;
}
       
