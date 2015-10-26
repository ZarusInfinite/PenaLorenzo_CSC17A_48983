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
#include <cstring>
// User Libraries
#include "card.h"
#include "dealer.h"
#include "player.h"
#include "ai.h"
//Function Prototypes
void info();
void createDeck(const int, card*);
int prep(player,int);
void getCards(player,card*);
void nextStep(player,card*,float,bool);
void getCards(player,card*);
void nextStep(player,card*,float,bool);
void sortAI(ai*,int);
int shuffleCards();
int getAICrd(ai*,card*);
int getDealCrd(dealer,card*);
float placeBet(float);
bool blackjack(ai*,dealer,int);
bool compare(player,ai*,dealer,int);
card *fillDeck(int);
ai *getAIs(int);

using namespace std;

int main(int argc, char** argv) {
    
    //Pre-game preparations
    srand(static_cast<unsigned int>(time(0)));
    int numCards=52;//Number of cards in our deck
    bool win;
    int numPlyr;//Holds the number of player
    int deal;//Used for when someone wants a hit.
    float money;//Your money to bet.

    //Establishing parties
    player YOU;//The player controlled by the user
    dealer Dealer;//The dealer, controlled by the computer of course.
    
     //Prepare for the game
    int numAI=prep(YOU,numPlyr);
    
    //Allocate memory for structures
    card *Deck=fillDeck(numCards);//Create variable for our deck of cards.
    ai *AI=new ai[numAI];//Other players besides you.
 
    //Start the game!
    //Place bets
    YOU.bet=placeBet(money);
    
    //Get YOUR cards 
    getCards(YOU,Deck);
  
    //Next step: hit or stand?
    nextStep(YOU,Deck,money,win);
    if(YOU.hand>21)
    {
        cout<<"Looks like you bust.Better luck next time"<<endl;
        cout<<endl;
        win=false;
    }
    
    //Get AI cards
    for(int i=0; i<numAI;i++)
    {
        AI->hand[i]=getAICrd(AI,Deck);
    }
      
    //Get Dealer cards
    Dealer.hand=getDealCrd(Dealer,Deck);
    
    //Calculate card value of ais
    sortAI(AI,numAI);
    
    //Compare Cards
    for(int l=0;l<numAI;l++)
    {
        if(AI->hand[l] > 21)
        {
            AI->hand[l]=0;
        }
    }
    
    //BLACKJACK!!!
    if(YOU.hand==21)
    {
        win=blackjack(AI,Dealer,numAI);
    }
    //Compare with other players
    win=compare(YOU,AI,Dealer,numAI);
    //If you lost
    if(win=false)
    {
        cout<<"You lost. You now have $"<<money-YOU.bet<<"."<<endl;
        //Deallocate memory
        delete Deck;
        delete AI;
        return 0;
    }
    else//if you win
    {
        //Deallocate memory
        delete Deck;
        delete AI;
        return 0;
    }
}
/********************************************************************************************************************************************************/
/*FUNCTION DEFINITIONS
/********************************************************************************************************************************************************/
card *fillDeck(int n)
{
    //Allocate memory
    card *str= new card;
    str->altnumval=new int[n];
    str->faceval=new char[n];
    str->numval=new int[n];
    str->suit=new char[n];
    //Fill facevalue
    for(int i=0; i<n; i++)
    { 
       char crdvalues[13]={'A','2','3','4','5','6',
                     '7','8','9','T','J','Q','K'};
        str->faceval[i]=crdvalues[i%13];
    }
    //Fill suits
    for(int i=0; i<n; i++)
    {
        char suits[4]={'S','H','D','C'};
        str->suit[i]=suits[i%4];
    }
    //Fill number value
    for(int i=0; i<n; i++)
    {
        int number=1+(i%13);
        int altnum=0;
        if(number==1)altnum=11;
        if(number>10)number=10;
        str->numval[i]=number;
        str->altnumval[i]=altnum;
    }
    return str;
}
/********************************************************************************************************************************************************/
ai *getAIs(int n)
{
    ai *plyr=new ai;
    plyr->hand=new int[n];
    return plyr;
}
/********************************************************************************************************************************************************/
void info()
{
    cout<<endl;
    cout<<"Blackjack is pretty simple. There are players, such as you, ad a dealer"<<endl;
    cout<<"The goal is to rack up as many points without going of 21."<<endl;
    cout<<"Going over 21 would be considered a bust, which means you lose."<<endl;
    cout<<"However, if you happen to get exactly 21, that would be BLACKJACK, meaning you"<<endl;
    cout<<" automatically win unless the dealer also has BLACKJACK. Your main opponent"<<endl;
    cout<<" is the dealer. If you beat him, you when the game. You start with 2 cards, and"<<endl;
    cout<<" and can add on more if you choose to. Just be careful. You place your bet at the beginning"<<endl;
    cout<<" of the game. If you win you get get back your money plus an addition %50."<<endl;
    cout<<"If you're tied with the dealer, it's a push, meaning you keep your money."<<endl;
    cout<<"Also, remember an ace can either be 1 or 11."<<endl;
    cout<<endl;
    cout<<"ICONS:"<<endl;
    cout<<endl;
    cout<<"FACEVALUE:     A: Ace   T: 10   J: Jack   Q: Queen   K: King"<<endl;
    cout<<"SUITS:     H: Hearts  D: Diamonds  S: Spades  C: Clubs"<<endl;
    cout<<endl;
    cout<<"Have fun!"<<endl;
    cout<<endl;
}

/********************************************************************************************************************************************************/
int prep(player YOU,int numPlyr)
{
    cout<<"Welcome to BlackJack!"<<endl;
    cout<<"What's your name?"<<endl;
    getline(cin,YOU.name);
    cout<<"Alright "<<YOU.name<<", here's some info"<<endl;
    info();
    int AIs;
    //Players
    cout<<"How many people are playing tonight? A maximum of 10 people can play."<<endl;
    cin>>numPlyr;
    AIs=numPlyr-1;//Number of computer controlled players. Basically everyone else besides the dealer and player character.
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
    cout<<numPlyr<<" players? Okay! Let's play."<<endl;
    cout<<endl;
    return AIs;
}
/********************************************************************************************************************************************************/
void getCards(player YOU, card *Deck)
{
    cout<<"The cards have been dealt. Here's your hand: "<<endl;
    cout<<endl;
    for(int i=0; i<2;i++)
    {
        int index=shuffleCards();
        cout<<"Card "<<i+1<<" : Suit: "<<Deck->suit[index]<<" Face Value: ";
        cout<<Deck->faceval[index]<<" Number Value: "<<Deck->numval[index];
        if(Deck->altnumval[index]>1)
        {
            cout<<endl;
            cout<<"You have an Ace! Remember you can change it's to 1 or 11.";
            cout<<"choose wisely."<<endl;
        }
        cout<<endl;
        YOU.hand+=Deck->numval[index];
    }
    cout<<"You have a total of "<<YOU.hand<<" points"<<endl;
}
/********************************************************************************************************************************************************/
void nextStep(player YOU, card *Deck,float money,bool win)
{
    char choice;
    cout<<"Now do you want to take your chances and take a hit, or stick with what you got and stand?"<<endl;
    cout<<"Press h for hit or s for stand."<<endl;
    cin>>choice;
    while((choice != 'h') || (choice != 's'))
    {
        cout<<"Sorry but that's not a correct response"<<endl;
        cout<<"Please press h for hit or s for stand."<<endl;
        cin>>choice;
    }
    while(choice=='h')
    {
        int more=shuffleCards();
        YOU.hand+=Deck->numval[more];
        cout<<"Alright Adding this card to your hand..."<<endl;
        cout<<"New Card:  Suit: "<<Deck[more].suit<< " Face Value: ";
        cout<<Deck[more].faceval<<" Number Value: "<<Deck[more].numval;
        if(Deck->numval[more]==1)
        {
        cout<<"You have an Ace! Remember you can change it's to 1 or 11.";
        cout<<"choose wisely"<<endl;
        }
        cout<<endl;
        cout<<"Are you done, or do you want to go for another hit?"<<endl;
        cin>>choice;
    }     
    if(YOU.hand>21)
    {
        cout<<"Looks like you bust.Better luck next time"<<endl;
        money-=YOU.bet;
        cout<<"You now have $"<<money<<endl;
        cout<<endl;
        win=false;
    }
}
/********************************************************************************************************************************************************/
void sortAI(ai* AI,int numAI)
{
 int z, min;
    for (int i = 0; i <numAI; i++)
    {
       z = i;
       min= AI->hand[i];
       for(int j = i + 1; j < numAI; j++)
       {
          if (AI->hand[j] < min)
          {
             min = AI->hand[j];
             z= j;
          }
       }
      AI->hand[z] = AI->hand[i];
       AI->hand[i] = min;
    }
    for(int i=0;i<numAI;i++)
    {
        cout<<"AI cards:"<<endl;
        cout<<AI->hand[i]<<endl;
    }
}
/********************************************************************************************************************************************************/
int shuffleCards()
{
        int index;
        int minCrd=0;
        int maxCrd=51;
        index=(rand()%maxCrd-minCrd+1)+minCrd;
        return index;
}
/********************************************************************************************************************************************************/
int getAICrd(ai* AI,card* Deck)
{
    int total=0;
            
            for(int z=0; z<2;z++)
            {
                int index=shuffleCards();
                total+=Deck->numval[index];
                if(Deck->altnumval[index]>1)
                {
                    if(total <= 10)
                    {
                        total+=10;
                    }
                }
            }   
            if(total<17)
            {
                int index=shuffleCards();
                total+=Deck->numval[index];
            }
    return total;   
} 
/********************************************************************************************************************************************************/
int getDealCrd(dealer Dealer,card* Deck)
{
    int total=0;
    for(int a=0;a<2;a++)
    {
        int index=shuffleCards();
        total+=Deck->numval[index];
        if(Deck->altnumval[index]>1)
        {
            if(total <= 10)
            {
                total+=10;
            }
        }    
    }
 return total;   
}   
/********************************************************************************************************************************************************/
float placeBet(float money)
{
    float bet;
    cout<<"It's time to place your bet! How much money did you bring?"<<endl;
    cin>>money;
    cout<<"Place your bet (Minimum of $5, Maximum of $100)"<<endl;
    cin>>bet;//Place your bet
    while(bet>money)
    {
        cout<<"You don't have enough money"<<endl;
        cin>>bet;
    }
    while(isalpha(bet))
    {
        cout<<"That's not even a number! Try again.?"<<endl;
        cin.ignore();
        cin>>bet;
    }
    while((bet < 5) || (bet > 100))//Input Validation 
    { 
        cout<<"Sorry but you cannot place that bet as it is beyond the established bounds."<<endl;
        cout<<"Please place a bet of a lower or higher amount"<<endl;
        cin>>bet;
    }
    return bet;
}
/********************************************************************************************************************************************************/
bool blackjack(ai* AI, dealer Dealer, int numAI)
{
        cout<<"Blackjack! But hold on now, let's if anybody else has blackjack."<<endl;
        for(int i =0; i<numAI;i++)
        {
            if(AI->hand[i]==21)
            {
                cout<<"Player"<<i+1<<"Also seems to have blackjack"<<endl;
                if(Dealer.hand==21)
                {
                    cout<<"And so does the dealer. Looks like it's a push. You keep your money"<<endl;
                    return false;
                }
            }
        }
        if(Dealer.hand==21)
        {
            cout<<"And so does the dealer. Looks like it's a push. You keep your money"<<endl;
            return false;
        }   
}
/********************************************************************************************************************************************************/
bool compare(player YOU, ai* AI, dealer Dealer, int numAI)
{
    if(YOU.hand>AI->hand[numAI])
    {
        cout<<"You did better than the other players! But what about against the dealer?"<<endl;
        if(YOU.hand<Dealer.hand)
        {
            cout<<"The dealer has "<<Dealer.hand<<" points, which is more than you."<<endl;
            cout<<"Seems like you lost."<<endl;
            return false;
        }
        else
        {
            cout<<"The dealer has "<<Dealer.hand<<" points."<<endl;
            cout<<"You won!"<<endl;
            return true;
        }
    }
    else//If you lost
    {
        cout<<"Looks you didn't fair as well as other players. You lost"<<endl;
        return false;
    }
}
/********************************************************************************************************************************************************/