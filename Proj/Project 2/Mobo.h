/* 
 * File:   Mobo.h
 * Author: Louli
 *
 * Created on December 14, 2015, 11:13 PM
 */

#ifndef MOBO_H
#define	MOBO_H
#include <string>

using namespace std;

//MotherBoard class
    class Mobo
    {
    private:
        string brand;
        string series;
        string model;
        string socket;
        string cpuType;
        string chipset;
        string memType;
        int numMem;
        int maxMem;
        int numPCI;
        int numSata;
        int numUSB;
        int formFact;
        int length;
        int height;
        bool HDMI;
        bool VGA;
        bool DVI;
        float price;
    public:
        Mobo();//constructor
        //Mutators
        void setBrand(string);
        void setSeries(string);
        void setModel(string);
        void setSock(string);
        void setCpuType(string);
        void setChip(string);
        void setMem(string);
        void setNumMem(int);
        void setMaxMem(int);
        void setNumSata(int);
        void setNumUSB(int);
        void setFormFac(int);
        void setLength(int);
        void setHeight(int);
        void setHDMI();
        void setVGA();
        void setDVI();
        void setPrice(float);
        //Accessors
        string getBrand();
        string getSeries();
        string getModel();
        string getSocket();
        string getCpuType();
        string getChip();
        string getMem();
        int getNumMem();
        int getMaxMem();
        int getNumSata();
        int getNumUSB();
        int getFormFac();
        int getLength();
        int getHeight();
        bool getHDMI();
        bool getVGA();
        bool getDVI();
        float getPrice();
        
    };


#endif	/* MOBO_H */

