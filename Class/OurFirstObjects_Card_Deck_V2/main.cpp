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
    const int nCards=52;
    Card card[nCards];

    //Loop on all potential 52 cards
    cout<<endl<<"Class Check"<<endl;
    for(int i=0;i<nCards;i++){
        card[i].setNum(i+1);
        cout<<"Card Number = "<<static_cast<int>(card[i].getNum());
        cout<<" Suit = "<<card[i].suit();
        cout<<" Numerical Value = "<<static_cast<int>(card[i].numVal());
        cout<<" Face Value = "<<card[i].faceVal()<<endl;
    }

    return 0;
}