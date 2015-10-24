/* 
 * File:   main.cpp
 * Author: Louli
 *Purpose: Blackjack
 * Created on October 18, 2015, 1:47 PM
 */

#include <cstdlib>
#include <iostream>
// User Libraries
#include "card.h"
#include "dealer.h"
#include "player.h"

//Function Prototypes
void createCards(int, card*);


using namespace std;
/*
 * 
 */
int main(int argc, char** argv) {
    
    const int numCards=52;
    int numPlyr=1;
    char response;
    
    player YOU;
    dealer Dealer;
    card *Cards= new card[numCards];
    cout<<"You're playing BlackJack!"<<endl;
    createCards(numCards,Cards);
    //create deck
    
    
    return 0;
}

void createCards(int numCards, card *Cards){
    //Get Facevalue
    for(int j=0; j<numCards; j++){
        
       char crdvalues[13]={'A','2','3','4','5','6',
                     '7','8','9','T','J','Q','K'};
        
        Cards[j].faceval=crdvalues[j%13];
    }
    //Get suits
    for(int i= 0; i<numCards; i++)
    {
        char suit[4]={'S','H','D','C'};
        Cards[i].suit=suit[i%4];
    }
    /*Get numbers
    for(int z; z<numCards; z++)
    {
        int n, number;
     if(n<1||n>52)number=1;
    else number=n;
     char numVal=(number-1)%13+1;
    if(numVal>10)numVal=10;
    Cards[z].numval=static_cast<char>(numVal);
        
        //Cards[z].numval=Cards[z].faceval;
        //if(Cards[z].faceval=='A')Cards[z].numval==(1||11);
        //if(Cards[z].faceval==('T'||'J'||'Q'||'K'))static_cast<int>(Cards[z].numval==10);
    }
    */
    //Display Cards
    for(int x=0; x<numCards; x++)
    {
        cout<<"Card "<<x+1<<" facevalue: "<<Cards[x].faceval<</*" numval: "<<Cards[x].numval<< */" suit: "<<Cards[x].suit<<endl;    
           
    }
}