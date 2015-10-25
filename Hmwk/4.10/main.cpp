/* 
 * File:   main.cpp
 * Author: Louli
 *
 * Created on September 13, 2015, 8:42 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    
    int size=12;
    int month[size];
    int year;
    bool leap;
  
    cout<<"Enter a month from 1 to 12."<<endl;
    cin>>size;
    cout<<"Enter a year."<<endl;
    cin>>year;
    
    for(int i=0; i<size;i++)
    {
        if((i+1)%2==0)
        {
            month[i]=31;
        }
        else month[i]=30;
    }
   
    if(year%4==0)
    {
        leap=true;
        month[1]=29;
    }
    else
    { 
        leap=false;
    }
    
    cout<<month[size-1]<<" days."<<endl;
        return 0;
}

