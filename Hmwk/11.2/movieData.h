/* 
 * File:   movieData.h
 * Author: rcc
 *
 * Created on October 12, 2015, 1:36 PM
 */

#ifndef MOVIEDATA_H
#define	MOVIEDATA_H
#include <string>

using namespace std;

struct movieData{
    string Title;
    string Director;
    unsigned int Year;
    unsigned int Runtime;
    unsigned int cost;
    unsigned int revenue;
};

#endif	/* MOVIEDATA_H */