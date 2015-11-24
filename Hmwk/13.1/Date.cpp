#include <cstdlib>
#include <iostream>
#include "Date.h"

using namespace std;

Date::Date(){
    
    month=0;
    day=0;
    year=0;
}

void Date::setDay(int d){
    if(d>0){
    day=d;
    }
}
void Date::setMonth(int m){
    if(m>0){
    month=m;
    }
}
    
void Date::setYear(int y){
    if(y>0){
    year=y;
    }
}
void Date::getDate1(){
    cout<<month<<"/"<<day<<"/"<<year<<endl;
}
void Date::getDate2(){
    switch (month){
        case 1:cout<<"January";break;
        case 2:cout<<"Febuary";break;
        case 3:cout<<"March";break;
        case 4:cout<<"April";break;
        case 5:cout<<"May";break;
        case 6:cout<<"June";break;
        case 7:cout<<"July";break;
        case 8:cout<<"August";break;
        case 9:cout<<"September";break;
        case 10:cout<<"October";break;
        case 11:cout<<"November";break;
        case 12:cout<<"Decemeber";break;
        default:cout<<"No date"<<endl;
        break;
    }
    cout<<" "<<day<<","<<year<<endl;
}
void Date::getDate3(){
    cout<<day<<" ";
    switch (month){
        case 1:cout<<"January";break;
        case 2:cout<<"Febuary";break;
        case 3:cout<<"March";break;
        case 4:cout<<"April";break;
        case 5:cout<<"May";break;
        case 6:cout<<"June";break;
        case 7:cout<<"July";break;
        case 8:cout<<"August";break;
        case 9:cout<<"September";break;
        case 10:cout<<"October";break;
        case 11:cout<<"November";break;
        case 12:cout<<"Decemeber";break;
        default:cout<<"No date"<<endl;
        break;
    }
    cout<<" "<<year<<endl;
}