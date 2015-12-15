/* 
 * File:   GPU.h
 * Author: Louli
 *
 * Created on December 14, 2015, 11:10 PM
 */

#ifndef GPU_H
#define	GPU_H
#include <string>

using namespace std;


//GPU class
    class GPU
    {
    private:
            string brand;
            string series;
            string model;
            char chip;//Chip manufacturer, i.e. Nvidia or AMD
            int coreClock;//gpu clockspeed
            int boost;//after market overclock
            int VRAM;
            int memClock;//memory clockspeed
            string memType;
            int maxPow;//max Power output 
            int recPow;//recommend PSU wattage
            int length;
            int height;
            float price;
    public:
        GPU();//Constructor
        //Mutators
        void setBrand(string);
        void setSeries(string);
        void setModel(string);
        void setChip(char);
        void setCClock(int);
        void setBoost(int);
        void setVRAM(int);
        void setMClock(int);
        //void setMType(string);
        void setMaxPow(int);
        void setRecPow(int);
        void setLength(int);
        void setHeight(int);
        void setPrice(float);
        //Accessors
        string getBrand();
        string getSeries();
        string getModel();
        char getChip();
        int getCClock();
        int getBoost();
        int getVRAM();
        int getMClock();
        string getMType();
        int getMaxPow();
        int getRecPow();
        int getLength();
        int getHeight();
        float getPrice();     
    };

#endif	/* GPU_H */

