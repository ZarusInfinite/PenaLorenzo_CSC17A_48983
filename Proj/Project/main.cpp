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
// User Libraries
#include "card.h"
#include "dealer.h"
#include "player.h"

//Function Prototypes
void createDeck(int, card*);


using namespace std;

int main(int argc, char** argv) {
    
    srand(static_cast<unsigned int>(time(0)));
    const int numCards=52;
    int numPlyr;
    char response;
    
    player YOU;//The player you control
    dealer Dealer;//Our dealer
    card *Cards= new card[numCards];
    player *AI=new player[numPlyr-1];//Other players besides you.
    cout<<"You're playing BlackJack!"<<endl;
    cout<<"What's your name?"<<endl;
    getline(cin,YOU.name);
    cout<<"Alright "<<YOU.name<<", how many people are playing tonight?"<<endl;
    cin>>numPlyr;
    //Place bets
    cout<<"It's time for the players to place their bets!"<<endl;
    cout<<"Place your bet.(Minimum of $5, Maximum of $100."<<endl;
    cin>>YOU.bet;
    //Other players place their bets
   
    for(int i;i<(numPlyr-1);i++)
    {
        int maxbet=100;
        int minbet=5;
       /* *(AI+i)->bet=(rand()%maxbet-minbet+1)+minbet;
        cout<<*(AI+i)->bet;*/
    }
    //Deal cards
    
    
            
    
    createDeck(numCards,Cards);
    
    
 
    
    
    return 0;
}

void createDeck(int numCards, card *Cards){
    //Get Facevalue
    for(int i=0; i<numCards; i++){
        
       char crdvalues[13]={'A','2','3','4','5','6',
                     '7','8','9','T','J','Q','K'};
        
        Cards[i].faceval=crdvalues[i%13];
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
        cout<<"Card "<<x+1<<" facevalue: "<<Cards[x].faceval<< " suit: "<<Cards[x].suit<<endl;    
           
    }

}