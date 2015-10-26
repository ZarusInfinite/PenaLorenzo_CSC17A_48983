/* 
 * File:   main.cpp
 * Author: Louli
 *Purpose: Blackjack
 * Created on October 18, 2015, 1:47 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cctype>
#include <string>
// User Libraries
#include "card.h"
#include "dealer.h"
#include "player.h"
//Function Prototypes
void nameAI(player*);
void createDeck(const int, card*);
int shuffleCards();
int dealCards(int, card*);
int aiCards(int, int, card*);//Same as dealCards, but for dealer and ais, as it doesn't output their hand to the user.
int nextStep(card*);
int sortAI(int, card*);//Sort out which ai has rank of cards below 21
//float AIbet(int);

using namespace std;

int main(int argc, char** argv) {
    //Pre-game preparations
    srand(static_cast<unsigned int>(time(0)));
    const int numCards=52;
    bool won,lost;
    int numPlyr;//Holds the number of player
    int deal;//Used for when someone wants a hit.

    //Establishing parties
    player YOU;//The player controlled by the user
    dealer Dealer;//The dealer, controlled by the computer of course.
    card *Deck= nullptr;
    player *AI= nullptr;
    Deck= new card[numCards];//Create variable for our deck of cards.
    AI=new player[numPlyr-1];//Other players besides you.
    //bool ace;
    
    //Create game assets
    createDeck(numCards,Deck);//Create deck.
    
    //Prepare for the game
    cout<<"Welcome to BlackJack!"<<endl;
    cout<<"What's your name?"<<endl;
    getline(cin,YOU.name);
    cout<<"Alright "<<YOU.name<<", how many people are playing tonight? Pick from between 1 to 10."<<endl;
    cin>>numPlyr;
    int numAI=numPlyr-1;//Number of computer controlled players. Basically everyone else besides the dealer and player character.
    while(numPlyr<1)
    {
        cout<<"Little jokester huh? Seriously how many people are playing?"<<endl;
        cin>>numPlyr;
    }
    while(numPlyr>10)
    {
        cout<<"That's too many players! Might want to get a smaller group."<<endl; 
        cin>>numPlyr;
    }
    //if(numPlyr>1)areAI=true;//Establishes ai players
    cout<<numPlyr<<" players? Okay! Let's play."<<endl;
    cout<<endl;
    //Start the game!
    //Place bets
    cout<<"It's time to place your bet!"<<endl;
    cout<<"(Minimum of $5, Maximum of $100)"<<endl;
    cin>>YOU.bet;//Place your bet
    while(isalpha(YOU.bet))
    {
        cout<<"That's not even a number! Try again.?"<<endl;
        cin>>YOU.bet;
    }
    while(YOU.bet < 5 || YOU.bet > 100)//Input Validation 
    { 
        cout<<"Sorry but you cannot place that bet as it is beyond the established bounds."<<endl;
        cout<<"Please place a bet of a lower or higher amount"<<endl;
        cin>>YOU.bet;
    }
    
    //Get YOUR cards 
    cout<<"The cards have been dealt. Here's your hand: "<<endl;
    cout<<endl;
    for(int i=0; i<2;i++)
    {
        int index=shuffleCards();
        cout<<"Card "<<i+1<<" : Suit: "<<Deck[index].suit<<" Face Value: ";
        cout<<Deck[index].faceval<<" Number Value: "<<Deck[index].numval;
        if(Deck[index].numval==1)
        {
        cout<<"You have an Ace! Remember you can change it's to 1 or 11.";
        cout<<"choose wisely"<<endl;
        }
        cout<<endl;
        YOU.hand+=Deck[index].numval;
        cout<<endl;
    }
    cout<<"You have a total of "<<YOU.hand<<" points"<<endl;
  
    //Next step: hit or stand?
    int choice;
    cout<<"Now do you want to take your chances and take a hit, or stick with what you got and stand?"<<endl;
    cout<<"Press 1 for hit or 0 for stand."<<endl;
    cin>>choice;
    while((choice < 1) || (choice > 2))
    {
        cout<<"Sorry but that's not a correct response"<<endl;
        cout<<"Please press 1 for hit or 2 for stand."<<endl;
        cin>>choice;
    }
    while(choice==1)
    {
        int n=3;
        int more=shuffleCards();
        YOU.hand+=Deck[more].numval;
        cout<<"Alright Adding this card to your hand..."<<endl;
        cout<<"Card "<<n<<":  Suit: "<<Deck[more].suit<< " Face Value: ";
        cout<<Deck[more].faceval<<" Number Value: "<<Deck[more].numval;
        if(Deck[more].numval==1)
        {
        cout<<"You have an Ace! Remember you can change it's to 1 or 11.";
        cout<<"choose wisely"<<endl;
        }
        cout<<endl;
        cout<<"Are you done, or do you want to go for another hit?"<<endl;
        cin>>choice;
    }      
    //Get AI cards
  
        for(int x=0;x<(numAI);x++)
        {
            int total=0;
            for(int z=0; z<2;z++)
            {
                int index=shuffleCards();
                total+=Deck[index].numval;
                if(Deck[index].altnumval>1)
                {
                    if(total <= 10)
                    {
                        total+=10;
                    }
                }
            }   
            AI[x].hand=total;
        }

    //Get Dealer cards
    for(int a=0;a<2;a++)
    {
        int index=shuffleCards();
        Dealer.hand+=Deck[index].numval;
        if(Deck[index].altnumval>1)
        {
            if(Dealer.hand <= 10)
            {
                Dealer.hand+=10;
            }
        }    
    }
    
    //Calculate card value of ais
    int z, min;
    for (int i = 0; i <numAI; i++)
    {
       z = i;
       min= AI[i].hand;
       for(int j = i + 1; j < numAI; j++)
       {
          if (AI[j].hand < min)
          {
             min = AI[j].hand;
             z= j;
          }
       }
       AI[z].hand = AI[i].hand;
       AI[i].hand = min;
    }
    for(int i=0;i<numAI;i++)
    {
        cout<<"AI cards:"<<endl;
        cout<<AI[i].hand<<endl;
    }
    //Compare Cards
    cout<<"Seems like ";
    for(int l=0;l<numPlyr;l++)
    {
        //int maxplr=0;
        if(YOU.hand < AI[l].hand)
        {
            cout<<" you lost. "<<endl;
        }
    }
    if(YOU.hand>AI[numAI].hand)
    {
        cout<<"You did better than the other players! But what about against the dealer?"<<endl;
        if(YOU.hand<Dealer.hand)
        {
            cout<<"The dealer has "<<Dealer.hand<<" points, which is more than you."<<endl;
            cout<<"Seems like you lost."<<endl;
        }
        else{
            cout<<"The dealer has "<<Dealer.hand<<" points."<<endl;
            cout<<"You won!"<<endl;
        }
    }
    
    //Deallocate memory
    delete Deck;
    delete AI;
   
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
        int index;
        int minCrd=0;
        int maxCrd=51;
        index=(rand()%maxCrd-minCrd+1)+minCrd;
        return index;
}

