/* 
 * File:   card.cpp
 * Author: Dr. Mark E. Lehr
 * Created on October 15, 2015, 11:20 AM
 * Purpose: Implementation for the Card Class
 */

//User Library for the Specification
#include "card.h"

Card::Card(char n){
    setNum(n);
}

void Card::setNum(char n){
    if(n<1||n>52)number=1;
    else number=n;
}
        
char Card::faceVal(){
     char fValue[13]={'A','2','3','4','5','6',
                     '7','8','9','T','J','Q','K'};
     return fValue[(number-1)%13];
}

char Card::numVal(){
    char numVal=(number-1)%13+1;
    if(numVal>10)numVal=10;
    return numVal;
}

char Card::suit(){
    //Declare suit array
    char aSuit[4]={'S','H','C','D'};
    return aSuit[(number-1)/13];
}