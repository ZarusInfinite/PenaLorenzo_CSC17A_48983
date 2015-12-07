/* 
 * File:   Car.h
 * Author: rcc
 *
 * Created on December 1, 2015, 12:49 PM
 */

#ifndef CAR_H
#define	CAR_H

#include <string>

using namespace std;

class Car
{
private:
    int yearModel;
    string make;
    int speed; 
public:
    Car(int,string);//constructor
    int getYear();
    string getMake();
    int getSpeed();
    void accel();//acceleration function
    void brake();//brake
    
    
};


#endif	/* CAR_H */

