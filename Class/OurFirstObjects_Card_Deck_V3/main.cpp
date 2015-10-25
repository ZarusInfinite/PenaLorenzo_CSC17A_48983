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
    Card **card=new Card*[nCards];
    char *indx=new char[nCards];

    //Loop on all potential 52 cards
    cout<<endl<<"Class Check"<<endl;
    for(int i=0;i<nCards;i++){
        card[i]=new Card(i+1);
        indx[i]=i;
        cout<<"Card Number = "<<static_cast<int>(card[i]->getNum());
        cout<<" Suit = "<<card[i]->suit();
        cout<<" Numerical Value = "<<static_cast<int>(card[i]->numVal());
        cout<<" Face Value = "<<card[i]->faceVal()<<endl;
    }
    cout<<endl<<endl;
    
    //How to shuffle the deck
    srand(static_cast<unsigned int>(time(0)));
    for(int nShuffles=1;nShuffles<=7;nShuffles++){
        for(int i=0;i<nCards;i++){
            int rnd=rand()%nCards;
            int temp=indx[i];
            indx[i]=indx[rnd];
            indx[rnd]=temp;
        }
    }
    
    //Output the array
    cout<<endl<<"After Shuffle"<<endl;
    for(int i=0;i<nCards;i++){
        cout<<"Card Number = "<<static_cast<int>(card[indx[i]]->getNum());
        cout<<" Suit = "<<card[indx[i]]->suit();
        cout<<" Numerical Value = "<<static_cast<int>(card[indx[i]]->numVal());
        cout<<" Face Value = "<<card[indx[i]]->faceVal()<<endl;
    }
    
    //Exit stage right
    for(int i=0;i<nCards;i++){
        delete card[i];
    }
    delete []card;
    delete []indx;
    return 0;
}