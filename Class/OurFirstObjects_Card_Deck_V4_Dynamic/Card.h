/* 
 * File:   card.h
 * Author: Dr. Mark E. Lehr
 * Created on October 15, 2015, 11:20 AM
 * Purpose: Specification for the Card Class
 */

#ifndef CARD_H
#define	CARD_H

class Card{
    private:
        char number;
        void setNum(char);                //Mutator / Utility
    public:
        Card(char);                       //Constructor
        char getNum(){return number;}     //Accessor (in-line)
        char suit();                      //Suit property
        char numVal();                    //Numerical Value property
        char faceVal();                   //Face value property
};

#endif	/* CARD_H */

