/* 
 * File:   Info.h
 * Author: rcc
 *
 * Created on December 3, 2015, 9:49 AM
 */

#ifndef INFO_H
#define	INFO_H
#include <string>

using namespace std;

class Info{
    
private:
    string name;
    string address;
    int number;
public:
    Info();
    void setName(string);
    void setAddress(string);
    void setNum(int);
    string getName();
    string getAddress();
    int getNum();
};
#endif	/* INFO_H */

