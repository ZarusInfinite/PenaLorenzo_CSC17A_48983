/* 
 * File:   main.cpp
 * Author: Louli
 *
 * Project: PC building and benchmarking program. Takes in user's budget and
 * for custom PC. This program will choose from a database of hardware and create 
 * a hardware list that will best satisfy the user's budget and need.
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    /********************************************************************************************************************************/
    //Class Definitions
    /********************************************************************************************************************************/
    
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
        void setMType(string);
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
    /********************************************************************************************************************************/
    //CPU class
    class CPU
    {
    private:
        string brand;
        string series;
        string model;
        string socket;//Socket type, i.e. LGA 1150 or AM3+
        string coreName;
        bool hyperThread;//Whether cpu support hyperthreading (intel only)
        bool intGraphics;//Integrated graphics yes or no
        int numCores;
        int numThreads;
        int clock;
        int TDP;
        float price;
    public:
        CPU();//Constructors
        //Mutators
        void setBrand(string);
        void setSeries(string);
        void setModel(string);
        void setSock(string);
        void setName(string);
        void setHype(bool);
        void setIG(bool);
        void setCores(int);
        void setThreads(int);
        void setClock(int);
        void setTDP(int);
        void setPrice(float);
        //Accessors
        string getBrand();
        string getSeries();
        string getModel();
        string getSocket();
        string getName();
        bool getHype();
        bool getIG();
        int getCores();
        int getThreads();
        int getClock();
        int getTDP();
        float getPrice();
    };
   /********************************************************************************************************************************/
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
        int numSataEXP;
        int numM2;
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
        void setNumPCI(int);
        void setNumSata(int);
        void setNumSataEXP(int);
        void setNumM2(int);
        void setNumUSB(int);
        void setFormFac(int);
        void setLength(int);
        void setHeight(int);
        void setHDMI(bool);
        void setVGA(bool);
        void setDVI(bool);
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
        int getNumPCI();
        int getNumSata();
        int getNumSataEXP();
        int getNumM2();
        int getNumUSB();
        int getFormFac();
        int getLength();
        int getHeight();
        bool getHDMI();
        bool getVGA();
        bool getDVI();
        float getPrice();
/********************************************************************************************************************************/
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
/********************************************************************************************************************************/
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
           void setSSD(bool);
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
/********************************************************************************************************************************/
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
/********************************************************************************************************************************/
//Case class
        class Case
        {
        private:
            string Brand;
            string Series;
            string Model;
            int moboType;
            bool wPSU;
            bool frntPorts;
            int numEXP;
            int numFans;
            int fanSize;
            int height;
            int width;
            int length;
            float maxGPU;
            float maxCooler;
            float maxPSU;
            float radCom;
            float price;
        public:
            Case();//Constructor
            //Mutators
            void setBrand(string);
            void setSeries(string);
            void setModel(string);
            void setMobo(int);
            void setWPSU(bool);
            void setPort(bool);
            void setNumEXP(int);
            void setNumFans(int);
            void setFSize(int);
            void setHeight(int);
            void setWidth(int);
            void setLength(int);
            void setMaxGPU(float);
            void setMaxCooler(float);
            void setMaxPSU(float);
            void setRadCom(float);
            void setPrice(float);
            //Accessors
            string getBrand();
            string getSeries();
            string getModel();
            int getMobo();
            bool getWPSU();
            bool getPort();
            int getNumEXP();
            int getNumFans();
            int getFSize();
            int getHeight();
            int getWidth();
            int getLength();
            float getMaxGPU();
            float getMaxCooler();
            float getMaxPSU();
            float getRadCom();
            float getPrice();
        
        };
/********************************************************************************************************************************/
        
        
        
           
        
        
        
        
        
        
        
        
    };
    return 0;
}

