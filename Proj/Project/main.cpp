/* 
 * File:   main.cpp
 * Author: Louli
 *Purpose: Blackjack
 * Created on October 18, 2015, 1:47 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
// User Libraries
#include "card.h"
#include "dealer.h"
#include "player.h"
//Function Prototypes
void createDeck(int, card*);
void dealCards(card*);


using namespace std;

int main(int argc, char** argv) {
    
    srand(static_cast<unsigned int>(time(0)));
    const int numCards=52;
    int numPlyr;
    char response;
    //Establish parties
    player YOU;//The player you control
    dealer Dealer;//Our dealer
    card *Deck= new card[numCards];//Create our deck of cards.
    player *AI=new player[numPlyr-1];//Other players besides you.
    createDeck(numCards,Deck);
    //Prepare for the game
    cout<<"You're playing BlackJack!"<<endl;
    cout<<"What's your name?"<<endl;
    getline(cin,YOU.name);
    cout<<"Alright "<<YOU.name<<", how many people are playing tonight?"<<endl;
    cin>>numPlyr;
    //Start the game!
    
    //Place bets
    cout<<"It's time for the players to place their bets!"<<endl;
    cout<<"Place your bet.(Minimum of $5, Maximum of $100."<<endl;
    cin>>YOU.bet;
    //Other players place their bets
   
    for(int i;i<(numPlyr-1);i++)
    {
        int maxbet=100;
        int minbet=5;
        *(AI+i)->bet=(rand()%maxbet-minbet+1)+minbet;
        cout<<static_cast<int>(*(AI+i)->bet);
    }
     */
    dealCards(Deck);//Deal cards
   
    delete [] Deck;
    delete [] AI;
   
    return 0;
}

void createDeck(int numCards, card *Deck)
{
    //Get Facevalue
    for(int i=0; i<numCards; i++)
    { 
       char crdvalues[13]={'A','2','3','4','5','6',
                     '7','8','9','T','J','Q','K'};
        Deck[i].faceval=crdvalues[i%13];
    }
    //Get suits
    for(int i= 0; i<numCards; i++)
    {
        char suit[4]={'S','H','D','C'};
        Deck[i].suit=suit[i%4];
    }
    //Get numbers
    for(int i=0; i<numCards; i++)
    {
        int number=1+(i%13);
        int altnum=0;
        if(number==1)altnum=11;
        if(number>10)number=10;
        Deck[i].numval=number;
        Deck[i].altnumval=altnum;
    }
   
    /*Display Cards
    for(int i=0; i<numCards; i++)
    {
        cout<<"Card "<<i+1<<" Facevalue: "<<Deck[i].faceval<< " Suit: "<<Deck[i].suit;
        cout<<" Numbervalue: "<<Deck[i].numval<<" Alt Numbervalue: "<<Deck[i].altnumval<<endl;   
           
    }
    */
}

void dealCards(card *Deck)
{
//Deal cards
    for(int i=0;i<2;i++)//For initial deal
    {
        int index;
        int minCrd=0;
        int maxCrd=51;
        index=(rand()%maxCrd-minCrd+1)+minCrd;
        cout<<Deck[index].faceval<<" "<<Deck[index].suit<<endl;
    }
}