/* 
 * File:   card.h
 * Author: Dr. Mark E. Lehr
 * Created on October 15, 2015, 11:20 AM
 * Purpose: Specification for the Deck Class
 */

#ifndef DECK_H
#define	DECK_H

#include "Card.h"

class Deck{
   private:
       int nCards;
       Card **card;
       char *indx;
       char dltCard;
   public:
       Deck();
       ~Deck();
       void shuffle(void);
       char deal(void);
       int getNCrd(void){return nCards;}
};

#endif	/* DECK_H */

