/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on December 3, 2015, 9:48 AM
 */
#include <iostream>
#include <cstdlib>
#include <string>

#include "Info.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    Info *ID=nullptr;
    ID= new Info[3];
    int tempNum;
    string name,address;
    
    cout<<"Let's start with your info first. What's your name?"<<endl;
    //cin.ignore();
    getline(cin,name);
    ID[0].setName(name);
    cout<<"What's your address?"<<endl;
    //cin.ignore();
    getline(cin,address);
    ID[0].setAddress(address);
    cout<<"Finally, what's your number?"<<endl;
    cin>>tempNum;
    while(tempNum<100000000 || tempNum>9999999999)
    {
        cout<<"That's not a valid number. Try again"<<endl;
        cin>>tempNum;
    }
    ID[0].setNum(tempNum);

    //Display Info
    cout<<"Name: "<<ID[0].getName()<<endl;
    cout<<"Address: "<<ID[0].getAddress()<<endl;
    cout<<"Number: "<<ID[0].getNum()<<endl;
    
    delete [] ID;
    
    return 0;
}

