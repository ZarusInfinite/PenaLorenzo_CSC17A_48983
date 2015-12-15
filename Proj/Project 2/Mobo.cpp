#include <cstdlib>
#include <string>
#include "Mobo.h"

using namespace std;

//Mobo class

Mobo::Mobo()
{
    brand="";
    series="";
    model="";
    socket="";
    cpuType="";
    chipset="";
    //memType="";
    numMem=0;
    maxMem=0;
    numPCI=0;
    numSata=0;
    formFact=0;
    length=0;
    height=0;
    HDMI=false;
    VGA=false;
    DVI=false;
    price=0; 
}
//Mutators
void Mobo::setBrand(string b)
{
    brand=b;
}

void Mobo::setSeries(string s)
{
    series=s;
}

void Mobo::setModel(string m)
{
    model=m;
}

void Mobo::setSock(string sck)
{
    socket=sck;
}

void Mobo::setCpuType(string ct)
{
    cpuType=ct;
}

void Mobo::setChip(string c)
{
    chipset=c;
}

void Mobo::setMem(string mem)
{
    memType=mem;
}

void Mobo::setNumMem(int nm)
{
    numMem=nm;
}

void Mobo::setMaxMem(int mm)
{
    maxMem=mm;
}

void Mobo::setNumSata(int ns)
{
    numSata=ns;
}

void Mobo::setNumUSB(int u)
{
    numUSB=u;
}

void Mobo::setFormFac(int f)
{
    formFact=f;
}

void Mobo::setLength(int l)
{
    length=l;
}

void Mobo::setHeight(int h)
{
    height=h;
}

void Mobo::setHDMI()
{
    HDMI=true;
}

void Mobo::setVGA()
{
    VGA=true;
}

void Mobo::setDVI()
{
    DVI=true;
}

void Mobo::setPrice(float p)
{
    price=p;
}
//Accessors
string Mobo::getBrand()
{
    return brand;
}

string Mobo::getSeries()
{
    return series;
}

string Mobo::getModel()
{
    return model;
}

string Mobo::getSocket()
{
    return socket;
}

string Mobo::getCpuType()
{
    return cpuType;
}

string Mobo::getChip()
{
    return chipset;
}

string Mobo::getMem()
{
    return memType;
}

int Mobo::getNumMem()
{
    return numMem;
}

int Mobo::getMaxMem()
{
    return maxMem;
}

int Mobo::getNumSata()
{
    return numSata;
}

int Mobo::getNumUSB()
{
    return numUSB;
}

int Mobo::getFormFac()
{
    return formFact;
}

int Mobo::getLength()
{
    return length;
}

int Mobo::getHeight()
{
    return height;
}

float Mobo::getPrice()
{
    return price;
}
