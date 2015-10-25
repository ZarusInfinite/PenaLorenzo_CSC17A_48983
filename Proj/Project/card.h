/* 
 * File:   card.h
 * Author: Louli
 *
 * Created on October 18, 2015, 5:34 PM
 */

#ifndef CARD_H
#define	CARD_H
#include <string>

using namespace std;

struct card{
    
    char suit;
    int numval;
    int altnumval;//Used for an Ace since it's rank can be 1 or 11;
    char faceval;
  
};



#endif	/* CARD_H */
