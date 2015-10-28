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
#include "player.h"

//Function Prototypes
void info();
void createDeck(const int, card*);
int prep(player,int);
int nextStep(player,card*,float,bool);
int getCards(player,card*,bool);
void sortAI(int *,int);
int shuffleCards();
int getAICrd(card*);
int getDealCrd(card*);
float placeBet(float);
bool blackjack(int*,int,int);
bool compare(player,int*,int,int);
card *fillDeck(int);

using namespace std;

int main(int argc, char** argv) {
    
    //Pre-game preparations
    srand(static_cast<unsigned int>(time(0)));
    const int numCards=52;//Number of cards in our deck
    bool win,bust,push,ace;
    int numPlyr;//Holds the number of player
    int deal;//Used for when someone wants a hit.
    float money=100;//Your money to bet.

    //Establishing parties
    player YOU;//The player controlled by the user
    int Dealer;//Memory allocated for the dealer's hand
    int *AI= nullptr;//Memory allocated for the AIs' hand
    
    int numAI=prep(YOU,numPlyr);//Get the number of AIs
    
    //Allocate memory for our deck
    card *Deck=fillDeck(numCards);//Fill the deck of cards
 
    //Start the game!
    //Place bets
    YOU.bet=placeBet(money);
    
    //Get YOUR cards 
    YOU.hand=getCards(YOU,Deck,ace);
    
    //Get Dealer cards
    Dealer=getDealCrd(Deck);
    
    //Get AI cards
    AI=new int[numAI];
    for(int i=0;i<numAI;i++)
    {
        AI[i]=getAICrd(Deck);
    }
    //Adjust AI Cards
        for(int l=0;l<numAI;l++)
        {
            if(AI[l] > 21)
            {
                AI[l]=0;
            }
        }
    //sort
    sortAI(AI,numAI);
    
    //Next step: hit or stand?
    YOU.hand+=nextStep(YOU,Deck,money,win);
    
   
    //BLACKJACK!!!
    if(YOU.hand==21)
    {
        push=blackjack(AI,Dealer,numAI);
    }   

    //Compare with other players
    win=compare(YOU,AI,Dealer,numAI);

    //If you lose
    if(win==false)
    {
        if(YOU.hand>21)//If you bust
        {
            cout<<"Looks like you bust!"<<endl;
            cout<<endl;
        }
        cout<<"You lost. You now have $"<<money-YOU.bet<<"."<<endl;
    }
    else if(win==true)//If you win
    {
        cout<<"Congrats! You won!"<<endl;
        money+=YOU.hand/2;
        cout<<"You now have $"<<money<<"."<<endl;
    }
    else//If push
    {
        cout<<"Looks like it's a push. You keep your money"<<endl;
    }
            
        
           
        
 //DISPLAY COMPETITION'S CARDS  
    cout<<"Your hand: "<<YOU.hand<<endl;
    cout<<"Dealer's hand: "<<Dealer<<endl;
        for(int i=0;i<numAI;i++)
        {
            if(AI[i]!=0)
            {
                cout<<"Player "<<i+2<<"'s hand rank: "<<AI[i]<<endl; 
            }
            else
            {
                cout<<"Player "<<i+2<<" bust!"<<endl;
            }
        }    
    
    
    delete Deck;
    delete [] AI;
    return 0;
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
int getAICrd(card* Deck)
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
    if(total<17)
       {
         int index=shuffleCards();
         total+=Deck->numval[index];
        }       
   }        
    return total;   
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
    cout<<"Press any other key than H to move on."<<endl;
    cout<<endl;
}

/********************************************************************************************************************************************************/
int prep(player YOU,int numPlyr)
{
    char choice;
    cout<<"Welcome to BlackJack!"<<endl;
    cout<<"What's your name?"<<endl;
    getline(cin,YOU.name);
    cout<<"Alright "<<YOU.name<<", have you played Blackjack before?"<<endl;
    cout<<"If not, press H for some help. But if you're ready to go, press any other letter."<<endl;
    cin>>choice;
    while(!isalpha(choice))
    {
        cout<<"Sorry but that's not a correct response. Please try again."<<endl;
        cin>>choice;
    }
    while(toupper(choice)=='H')
    {
        info();
        cin>>choice;
    }
    int AIs;
    //Players
    cout<<"How many people are playing tonight? A maximum of 10 people can play."<<endl;
    cin>>numPlyr;
    AIs=numPlyr-1;//Number of computer controlled players. Basically everyone else besides the dealer and player character.
    while(numPlyr < 1 || numPlyr >10)
    {
        cout<<"Sorry but that's an incorrect response. Please try again."<<endl;
        cin>>numPlyr;
    }
    cout<<numPlyr<<" players? Okay! Let's play."<<endl;
    cout<<endl;
    return AIs;
        
}
/********************************************************************************************************************************************************/
int getCards(player YOU, card *Deck,bool ace)
{
    cout<<"The cards have been dealt. Here's your hand: "<<endl;
    cout<<endl;
    int total=0;
    for(int i=0; i<2;i++)
    {
        int index=shuffleCards();
        cout<<"Card "<<i+1<<" : Suit: "<<Deck->suit[index]<<" Face Value: ";
        cout<<Deck->faceval[index]<<" Number Value: "<<Deck->numval[index]<<endl;
        if(Deck->numval[index]==1)
        {
            cout<<"You have an Ace! Remember you can change it's to 1 or 11.";
            cout<<" Choose wisely."<<endl;
            int add=0;
            cout<<"You have an ace. Would you like to convert it to 11, or leave it as 1?"<<endl;
            cout<<"Press 1 to keep it as 1 or 11 to turn it into 11"<<endl;
            cin>>add;
            total+add;
        }
        total+=Deck->numval[index];
    }
    cout<<endl;
    return total;
}
/********************************************************************************************************************************************************/
int nextStep(player YOU, card *Deck,float money,bool win)
{
    int total=0;
    char choice;
    cout<<"Now do you want to take your chances and take a hit, or stick with what you got and stand?"<<endl;
    cout<<"Press H for hit or S for stand."<<endl;
    cin>>choice;
    while(!isalpha(choice))
    {
        cout<<"Sorry but that's not even a letter. Please try again."<<endl;
        cin>>choice;
    }
    while(toupper(choice) != 'H' && toupper(choice)!='S')
    {
        cout<<"Please press H or S."<<endl;
        cin>>choice;
    }
    while(toupper(choice)=='H')
    {
        int more=shuffleCards();
        total+=Deck->numval[more];
        cout<<endl;
        cout<<"Alright Adding this card to your hand..."<<endl;
        cout<<"New Card:  Suit: "<<Deck->suit[more]<< " Face Value: ";
        cout<<Deck->faceval[more]<<" Number Value: "<<Deck->numval[more];
        if(Deck->numval[more]==1)
        {
        cout<<"You have an Ace! Remember you can change it's to 1 or 11.";
        cout<<"choose wisely"<<endl;
        }
        cout<<endl;
        
        cout<<"Are you done, or do you want to go for another hit?"<<endl;
        cout<<"Press H for hit or S for stand."<<endl;
        cin>>choice;
    }  
    return total;
}
/********************************************************************************************************************************************************/
void sortAI(int *AI,int numAI)
{
 int z, min;
    for (int i = 0; i <numAI; i++)
    {
       z = i;
       min= AI[i];
       for(int j = i + 1; j < numAI; j++)
       {
          if (AI[j] < min)
          {
             min = AI[j];
             z= j;
          }
       }
      AI[z] = AI[i];
       AI[i] = min;
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
int getDealCrd(card* Deck)
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
    cout<<"It's time to place your bet! You have $100 with you. Don't bet it all in one go."<<endl;
    cout<<"Place your bet (Minimum of $5, Maximum of $100)"<<endl;
    cin>>bet;//Place your bet
    while(bet>money)
    {
        cout<<"You don't have enough money"<<endl;
        cin>>bet;
    }   
    while(bet < 5 || bet > 100)//Input Validation 
    { 
        cout<<"Sorry but you cannot place that bet as it is beyond the established bounds."<<endl;
        cout<<"Please place a bet of a lower or higher amount"<<endl;
        cin>>bet;
    }
    cout<<"$"<<bet<<" ? Ok!"<<endl;
    cout<<endl;
    return bet;
}
/********************************************************************************************************************************************************/
bool blackjack(int *AI, int Dealer, int numAI)
{
        cout<<"Blackjack! But hold on now, let's if anybody else has blackjack."<<endl;
        for(int i =0; i<numAI;i++)
        {
            if(AI[i]==21)
            {
                cout<<"Player"<<i+1<<"Also seems to have blackjack."<<endl;
                if(Dealer==21)
                {
                    cout<<"And so does the dealer."<<endl;
                    return true;
                }
                return true;
            }
        }
        if(Dealer==21)
        {
            cout<<"And so does the dealer."<<endl;
            return true;
        }
        //If nobody else has blackjack
        return false;
}
/********************************************************************************************************************************************************/
bool compare(player YOU, int* AI, int Dealer, int numAI)
{
    cout<<endl;
    if(YOU.hand>=AI[numAI-1])
    {
        cout<<"You did better than the other players! But what about against the dealer?"<<endl;
        if(YOU.hand<Dealer)
        {
            cout<<"The dealer has "<<Dealer<<" points."<<endl;
            return false;
        }
        else if(YOU.hand==Dealer)
        {
            cout<<"The dealer has "<<Dealer<<" points."<<endl;
            return false;
        }
        else
        {
            cout<<"The dealer has "<<Dealer<<" points."<<endl; 
            return true;
        }
    }
    
    else //if(YOU.hand<AI[numAI])//If you lost
    {
        cout<<"Looks like you didn't fair as well as other players."<<endl;
        return false;
    }
}
/********************************************************************************************************************************************************/
