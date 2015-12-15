/* 
 * File:   Memory.h
 * Author: Louli
 *
 * Created on December 14, 2015, 11:14 PM
 */

#ifndef MEMORY_H
#define	MEMORY_H
#include <string>

using namespace std;

//Memory class
       class Memory
       {
       private:
           string brand;
           string model;
           string type;
           int speed;
           int capacity;
           float price;
       public:
           Memory();//Constructor
           //Mutators
           void setBrand(string);
           void setModel(string);
           void setSpeed(int);
           void setCap(int);
           void setPrice(float);
           //Accessors
           string getBrand();
           string getModel();
           string getType();
           int getSpeed();
           int getCap();
           float getPrice();
       };


#endif	/* MEMORY_H */

