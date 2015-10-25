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
void createDeck(const int, card*);
int shuffleCards();
int dealCards(card*);
float AIbet(int);


using namespace std;

int main(int argc, char** argv) {
    //Pre-game preparations
    srand(static_cast<unsigned int>(time(0)));
    const int numCards=52;
    int numPlyr;//Holds the number of player
    bool areAI;//Whether there are computer controlled players.
    int numAI=numPlyr-1;//Number of computer controlled players. Basically everyone else besides the dealer and player character.
    
    //Establishing parties
    player YOU;//The player controlled by the user
    dealer Dealer;//The dealer, controlled by the computer of course.
    card *Deck= new card[numCards];//Create variable for our deck of cards.
    player *AI=new player[numPlyr-1];//Other players besides you.
    //Create game assets
    createDeck(numCards,Deck);//Create 52 cards using the card structure.
    
    //Prepare for the game
    cout<<"Welcome to BlackJack!"<<endl;
    cout<<"What's your name?"<<endl;
    getline(cin,YOU.name);
    cout<<"Alright "<<YOU.name<<", how many people are playing tonight?"<<endl;
    cin>>numPlyr;
    while(numPlyr<1)
    {
        cout<<"Little jokester huh? Seriously how many people are playing?"<<endl;
        cin>>numPlyr;
    }
    if(numPlyr>1)areAI=true;
    
    //Start the game!
    //Place bets
    cout<<"It's time for the players to place their bets!"<<endl;
    cout<<"Place your bet.(Minimum of $5, Maximum of $100)"<<endl;
    cin>>YOU.bet;//Place your bet
    while(YOU.bet < 5 || YOU.bet > 100)//Input Validation 
    { 
        cout<<"Sorry but you cannot place that bet as it is beyond the established bounds."<<endl;
        cout<<"Please place a bet of a lower or higher amount"<<endl;
        cin>>YOU.bet;
    }
    //Other players place their bets
    if(areAI=true)
    {
        for(int i=0;i<(numPlyr-1);i++)
        {
        AI[i].bet==AIbet(numAI);
        }
    }
    //Get YOUR cards 
    cout<<"The cards have been dealt. Here's your hand: "<<endl;
    cout<<endl;
    YOU.hand=dealCards(Deck);
    cout<<endl;
    cout<<"You have a total of "<<YOU.hand<<" points"<<endl;
   
    //Deallocate memory
    delete [] Deck;
    delete [] AI;
   
    return 0;
}

void createDeck(const int numCards, card *Deck)
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
   
}

int shuffleCards()
{
//Shuffle cards
    for(int i=0;i<2;i++)//For initial deal
    {
        int index[i];
        int minCrd=0;
        int maxCrd=51;
        index[i]=(rand()%maxCrd-minCrd+1)+minCrd;
        if(index[i]==index[i+1])i--;//In case we get duplicates
        return index[i];
        //cout<<Deck[index].faceval<<" "<<Deck[index].suit<<endl;
    }
}

float AIbet(int numAI)
{
    for(int i=0; i<numAI; i++)
    {
        float bet;//
        int minBet=5;
        int maxBet=100;
        bet=(rand()%maxBet-minBet+1)+ minBet;
        return bet;
    }
}
int dealCards(card* Deck)
{
   int total=0;
   for(int i=0; i<2;i++)
    {
        int index=shuffleCards();
        cout<<"Card "<<i+1<<" : Suit: "<<Deck[index].suit<<" Face Value: ";
        cout<<Deck[index].faceval<<" Number Value: "<<Deck[index].numval;
        if(Deck[index].numval==1)
        cout<<" Alternative Number Value: "<<Deck[index].altnumval<<endl;
        cout<<endl;
        total+=Deck[index].numval;
    }
 return total;
}    