 /* File:   card.h
 * Author: Dr. Mark E. Lehr
 * Created on October 15, 2015, 11:20 AM
 * Purpose: Implementation for the Deck Class
 */

#include <cstdlib>
#include "Deck.h"
       
Deck::Deck(){
    //Start constructing the Deck by initializing the properties
    dltCard=0;
    nCards=52;
    card=new Card*[nCards];
    indx=new char[nCards];
    //Loop and create the cards and index
    for(int i=0;i<nCards;i++){
        card[i]=new Card(i+1);
        indx[i]=i;
    }
}

Deck::~Deck(){
    //Deallocate Memory
    for(int i=0;i<nCards;i++){
        delete card[i];
    }
    delete []card;
    delete []indx;
}
       
void Deck::shuffle(void){
    int rnd,temp;
    for(int nShuffles=1;nShuffles<=7;nShuffles++){
        for(int i=0;i<nCards;i++){
            rnd=rand()%nCards;
            temp=indx[i];
            indx[i]=indx[rnd];
            indx[rnd]=temp;
        }
    }
}
       
char Deck::deal(void){
    if(dltCard > .9*nCards){
        shuffle();
        dltCard=0;
    }
    return indx[dltCard++];
}