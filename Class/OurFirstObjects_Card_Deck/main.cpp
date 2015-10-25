/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on October 15, 2015, 11:20 AM
 * Purpose: Creation of first Object Oriented Program
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries
#include "card.h"

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare some variables

    //Loop on all potential 52 cards
    cout<<endl<<"Class Check"<<endl;
    for(int i=0;i<=53;i++){
        Card card(0);
        card.setNum(i);
        cout<<"Card Number = "<<static_cast<int>(card.getNum());
        cout<<" Suit = "<<card.suit();
        cout<<" Numerical Value = "<<static_cast<int>(card.numVal());
        cout<<" Face Value = "<<card.faceVal()<<endl;
    }

    return 0;
}