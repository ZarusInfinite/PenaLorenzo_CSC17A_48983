/* 
 * File:   Storage.h
 * Author: Louli
 *
 * Created on December 14, 2015, 11:15 PM
 */

#ifndef STORAGE_H
#define	STORAGE_H
#include <string>

using namespace std;

//Storage class
       class Storage
       {
       private:
           string brand;
           string series;
           string model;
           bool SSD;
           int capacity;
           int RPM;
           float price;
       public:
           Storage();//Constructor
           //Mutators
           void setBrand(string);
           void setSeries(string);
           void setModel(string);
           void setSSD();
           void setCapacity(int);
           void setRPM(int);
           void setPrice(float);
           //Accessors
           string getBrand();
           string getSeries();
           string getModel();
           bool getSSD();
           int getCap();
           int getRPM();
           float getPrice();

       };


#endif	/* STORAGE_H */

