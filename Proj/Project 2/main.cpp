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
        void setHype();//call if true
        void setIG();//call if true
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
        //bool getHype();
        //bool getIG();
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
        
    };
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
//Class Implementation 
/********************************************************************************************************************************/

/********************************************************************************************************************************/        
// GPU class 
GPU::GPU()
{
    brand="";
    series="";
    model="";
    chip =' ';
    coreClock=0;
    boost=0;
    VRAM=0;
    memClock=0;
    memType="GDDR5";
    maxPow=0;
    recPow=0;
    length=0;
    height=0;
    price=0; 
}

void GPU::setBrand(string b)
{
    brand=b;
}

void GPU::setSeries(string s)
{
    series=s;
}

void GPU::setModel(string m)
{
    model=m;
}

void GPU::setChip(char c)
{
    chip=c;
}

void GPU::setCClock(int clk)
{
    coreClock=clk;
}

void GPU::setBoost(int bst)
{
    boost=bst;
}
    
void GPU::setVRAM(int v)
{
    VRAM=v;
}

void GPU::setMClock(int mc)
{
    memClock=mc;
}

void GPU::setMaxPow(int mxp)
{
    maxPow=mxp;
}

void GPU::setRecPow(int rcp)
{
    recPow=rcp;
}

void GPU::setLength(int l)
{
    length=l;
}

void GPU::setHeight(int h)
{
    height=h;
}

void GPU::setPrice(float)
{
    price=0;
}

string GPU::getBrand()
{
    return brand;
}

string GPU::getSeries()
{
    return series;
}

string GPU::getModel()
{
    return model;
}

char GPU::getChip()
{
    return chip;
}

int GPU::getCClock()
{
    return coreClock;
}

int GPU::getBoost()
{
    return boost;
}

int GPU::getVRAM()
{
    return VRAM;
}

int GPU::getMClock()
{
    return memClock;
}

int GPU::getMaxPow()
{
    return maxPow;
}

int GPU::getRecPow()
{
    return recPow;
}

int GPU::getLength()
{
    return length;
}

int GPU::getHeight()
{
    return height;
}

float GPU::getPrice()
{
    return price;
}

/********************************************************************************************************************************/        

//CPU class

CPU::CPU()
{
    brand="";
    series="";
    model="";
    socket="";
    coreName="";
    hyperThread=false;
    intGraphics=false;
    numCores=0;
    numThreads=0;
    clock=0;
    TDP=0;
    price=0;
}

void CPU::setBrand(string b)
{
    brand=b;
}

void CPU::setSeries(string s)
{
    series=s;
}

void CPU::setModel(string m)
{
    model=m;
}

void CPU::setSock(string sck)
{
    socket=sck;
}

void CPU::setName(string n)
{
    coreName=n;
}

void CPU::setHype()
{
    hyperThread=true;
}

void CPU::setIG()
{
    intGraphics=true;
}

void CPU::setCores(int cr)
{
    numCores=cr;
}

void CPU::setThreads(int tr)
{
    numThreads=tr;
}

void CPU::setClock(int clk)
{
    clock=clk;
}

void CPU::setTDP(int tdp)
{
    TDP=tdp;
}

void CPU::setPrice(float p)
{
    price=p;
}

//Accessors

string CPU::getBrand()
{
    return brand;
}

string CPU::getSeries()
{
    return series;
}

string CPU::getModel()
{
    return model;
}

string CPU::getSocket()
{
    return socket;
}

string CPU::getName()
{
    return coreName;
}

int CPU::getCores()
{
    return numCores;
}

int CPU::getThreads()
{
    return numThreads;
}

int CPU::getClock()
{
    return clock;
}

int CPU::getTDP()
{
    return TDP;
}

float CPU::getPrice()
{
    return price;
}














int main(int argc, char** argv) 

{
    
   return 0; 
}
      