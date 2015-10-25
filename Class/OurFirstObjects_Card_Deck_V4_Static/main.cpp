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
#include "Card.h"
#include "Deck.h"

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare some variables
    srand(static_cast<unsigned int>(time(0)));
    Deck deck;//Static Declaration

    //Loop on all potential 52 cards
    cout<<endl<<"Class Check"<<endl;
    for(int i=0;i<2*deck.getNCrd();i++){
        int num=deck.deal()+1;
        Card *card=new Card(num);
        cout<<"Card Number = "<<static_cast<int>(card->getNum());
        cout<<" "<<num<<" ";
        cout<<" Suit = "<<card->suit();
        cout<<" Numerical Value = "<<static_cast<int>(card->numVal());
        cout<<" Face Value = "<<card->faceVal()<<endl;
        delete card;
    }
    
    //Exit stage right
    return 0;
}