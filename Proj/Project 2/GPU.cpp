#include <cstdlib>
#include <string>
#include "GPU.h"


using namespace std;

// GPU class 
GPU::GPU()
{
    brand="";
    series="";
    manu="";
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

void GPU::setManu(string m)
{
    model=m;
}

void GPU::setChip(int c)
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

void GPU::setLength(float l)
{
    length=l;
}

void GPU::setHeight(float h)
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

string GPU::getManu()
{
    return manu;
}

int GPU::getChip()
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

float GPU::getLength()
{
    return length;
}

float GPU::getHeight()
{
    return height;
}

float GPU::getPrice()
{
    return price;
}
