/* 
 * File:   main.cpp
 * Author: Louli
 *
 * Created on November 23, 2015, 8:46 PM
 */

#include <cstdlib>
#include <iostream>
#include "Date.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    int m,d,y;
    Date date;
    cout<<"Enter the month."<<endl;
    cin>>m;
    cout<<"Enter the day."<<endl;
    cin>>d;
    cout<<"Enter the year."<<endl;
    cin>>y;
    date.setDay(d);
    date.setMonth(m);
    date.setYear(y);
    cout<<endl;
    date.getDate1();
    date.getDate2();
    date.getDate3();
    
    return 0;
}

