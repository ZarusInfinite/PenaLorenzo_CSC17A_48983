/* 
 * File:   main.cpp
 * Author: Louli
 *
 * Created on September 13, 2015, 9:00 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    /* Variable factor5 is used as a counter for the for loop and outputs 
     * factors of 5 all the way to 100.
    */
    float startSize;
    float avgGrowth;
    float percent;
    int days;
    float currentSize;
    
    cout<<"What's the starting size of the population?"<<endl;
    cin>> startSize;
        
        while(startSize < 2){
            cout<<"Please input a number above 2."<<endl;
            cin>>startSize;
        }
        
    cout<<"What's the daily growth rate? Give a percentage."<<endl;
    cin>>percent;
    
    avgGrowth=percent/100;
    
    cout<<"How many days are we examining?"<<endl;
    cin>>days;
    
        while(days < 1){
            cout<<"Please do not input a number below 1"<<endl;
            cin>>days;
        }
         
    for(int i=1; i <= days; i++){
        
       currentSize= startSize + (startSize * avgGrowth * i);
       cout<<"Day "<<i<<":"<<currentSize<<endl;
    }
        return 0;
}

