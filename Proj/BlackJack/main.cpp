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
void info();
void createDeck(const int, card*);
void prep(player,int,int);
void getCards(player,card*);
void nextStep(player,card*,float,bool);
void getCards(player,card*);
void nextStep(player,card*,float,bool);
int shuffleCards();
float placeBet(float);
bool blackjack(player*,dealer,int);
bool compare(player,player*,dealer,int);

int getAICrd(player*,card*);
int getDealCrd(dealer,card*);

using namespace std;

int main(int argc, char** argv) {
    
    //Pre-game preparations
    srand(static_cast<unsigned int>(time(0)));
    const int numCards=52;
    bool win;
    int numPlyr,numAI;//Holds the number of player
    int deal;//Used for when someone wants a hit.
    float money;//Your money to bet.

    //Establishing parties
    player YOU;//The player controlled by the user
    dealer Dealer;//The dealer, controlled by the computer of course.
    card *Deck= new card[numCards];//Create variable for our deck of cards.
    player *AI=new player[numPlyr-1];//Other players besides you.
  
    //Create game assets
    createDeck(numCards,Deck);//Create deck.
    
    //Prepare for the game
    prep(YOU,numPlyr,numAI);
    
    //Start the game!
    //Place bets
    YOU.bet=placeBet(money);
    
    //Get YOUR cards 
    getCards(YOU,Deck);
  
    //Next step: hit or stand?
    nextStep(YOU,Deck,money,win);
    
    //Get AI cards
    for(int i=0; i<numAI;i++)
    {
        AI[i].hand=getAICrd(AI,Deck);
    }
      
    //Get Dealer cards
    Dealer.hand=getDealCrd(Dealer,Deck);
    
    //Calculate card value of ais
    sortAI(AI,numAI);
    
    //Compare Cards
    for(int l=0;l<numAI;l++)
    {
        if(AI[l].hand > 21)
        {
            AI[l].hand=0;
        }
    }
    
    //BLACKJACK!!!
    if(YOU.hand==21)
    {
        win=blackjack(AI,Dealer,numAI);
    }
    else//Compare with other players
    {
        win=compare(YOU,AI,Dealer,numAI);
    }
    
    //If you lost
    if(win=false)
    {
        //Deallocate memory
        delete Deck;
        delete AI;
        return 0;
    }
    
    //Deallocate memory
    delete Deck;
    delete AI;
   
    return 0;
}
/********************************************************************************************************************************************************/
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
void getCards(player* YOU, card *Deck)
{
    cout<<"The cards have been dealt. Here's your hand: "<<endl;
    cout<<endl;
    for(int i=0; i<2;i++)
    {
        int index=shuffleCards();
        cout<<"Card "<<i+1<<" : Suit: "<<Deck[index].suit<<" Face Value: ";
        cout<<Deck[index].faceval<<" Number Value: "<<Deck[index].numval;
        if(Deck[index].altnumval>1)
        {
            cout<<endl;
            cout<<"You have an Ace! Remember you can change it's to 1 or 11.";
            cout<<"choose wisely."<<endl;
        }
        cout<<endl;
        YOU->hand+=Deck[index].numval;
    }
    cout<<"You have a total of "<<YOU->hand<<" points"<<endl;
}
/********************************************************************************************************************************************************/
void nextStep(player* YOU, card *Deck,float money,bool win)
{
 int choice;
    cout<<"Now do you want to take your chances and take a hit, or stick with what you got and stand?"<<endl;
    cout<<"Press 1 for hit or 0 for stand."<<endl;
    cin>>choice;
    while((choice < 1) || (choice > 2))
    {
        cout<<"Sorry but that's not a correct response"<<endl;
        cout<<"Please press 1 for hit or 0 for stand."<<endl;
        cin>>choice;
    }
    while(choice==1)
    {
        int n=3;
        int more=shuffleCards();
        YOU->hand+=Deck[more].numval;
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
    if(YOU->hand>21)
    {
        cout<<"Looks like you bust.Better luck next time"<<endl;
        money-=YOU->bet;
        cout<<"You now have $"<<money<<endl;
        cout<<endl;
        win=false;
    }
}
/********************************************************************************************************************************************************/
int getAICrd(player* AI,card* Deck)
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
            if(total<17)
            {
                int index=shuffleCards();
                total+=Deck[index].numval;
            }
    return total;   
} 
/********************************************************************************************************************************************************/
int getDealCrd(dealer* Dealer,card* Deck)
{
    int total=0;
    for(int a=0;a<2;a++)
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
 return total;   
}   
/********************************************************************************************************************************************************/
void prep(player YOU,int numPlyr,int numAI)
{
    cout<<"Welcome to BlackJack!"<<endl;
    cout<<"What's your name?"<<endl;
    getline(cin,YOU.name);
    cout<<"Alright "<<YOU.name<<", here's some info"<<endl;
    info();
    
    //Players
    cout<<"How many people are playing tonight? A maximum of 10 people can play."<<endl;
    cin>>numPlyr;
    numAI=numPlyr-1;//Number of computer controlled players. Basically everyone else besides the dealer and player character.
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
}
/********************************************************************************************************************************************************/
float placeBet(float money)
{
    float bet;
    cout<<"It's time to place your bet! How much money did you bring?"<<endl;
    cin>>money;
    cout<<"Place your bet (Minimum of $5, Maximum of $100)"<<endl;
    cin>>bet;//Place your bet
    
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
void sortAI(player* AI,int numAI)
{
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
}
/********************************************************************************************************************************************************/
bool blackjack(player* AI, dealer Dealer, int numAI)
{
        cout<<"Blackjack! But hold on now, let's if anybody else has blackjack."<<endl;
        for(int i =0; i<numAI;i++)
        {
            if(AI[i].hand==21)
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
bool compare(player YOU, player* AI, dealer Dealer, int numAI)
{
    if(YOU.hand>AI[numAI].hand)
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