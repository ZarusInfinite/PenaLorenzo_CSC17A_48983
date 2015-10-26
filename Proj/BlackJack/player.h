/* 
 * File:   player.h
 * Author: Louli
 *
 * Created on October 18, 2015, 5:34 PM
 */

#ifndef PLAYER_H
#define	PLAYER_H
#include <string>

using namespace std; 
struct player{
    
    string name;
    float bet;//Initial bet
    int hand;//Holds the rank in a player's current hand
    
};

#endif	/* PLAYER_H */

