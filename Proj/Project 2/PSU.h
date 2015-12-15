/* 
 * File:   PSU.h
 * Author: Louli
 *
 * Created on December 14, 2015, 11:16 PM
 */

#ifndef PSU_H
#define	PSU_H
#include <string>

using namespace std;
//Power supply class
       class PSU
       {
       private:
           string brand;
           string model;
           int maxPow;
           int num8pin;
           int numPeri;
           float price;
       public:
           PSU();//Constructor
           //Mutators
           void setBrand(string);
           void setModel(string);
           void setMaxPow(int);
           void setNum8(int);
           void setNumPeri(int);
           void setPrice(float);
           //Accessors
           string getBrand();
           string getModel();
           int getMaxPow();
           int getNum8();
           int getNumPeri();
           float getPrice();
        
        };


#endif	/* PSU_H */

