#include <cstdlib>
#include <string>
#include "Case.h"

using namespace std;
//Case class

Case::Case()
{
    brand="";
    series="";
    model="";
    moboType=0;
    wPSU=false;
    frntPorts=false;
    numEXP=0;
    numFans=0;
    fanSize=0;
    height=0;
    width=0;
    length=0;
    maxGPU=0;
    maxCooler=0;
    maxPSU=0;
    radCom=0;
    price=0;
}

void Case::setBrand(string b)
{
    brand=b;
}

void Case::setSeries(string s)
{
    series=s;
}

void Case::setModel(string m)
{
    model=m;
}

void Case::setMobo(int m)
{
    moboType=m;
}

void Case::setWPSU()
{
    wPSU=true;
}

void Case::setPort()
{
    frntPorts=true;
}

void Case::setNumEXP(int nxp)
{
    numEXP=nxp;
}

void Case::setNumFans(int nf)
{
    numFans=nf;
}

void Case::setFSize(int fs)
{
    fanSize=fs;
}

void Case::setHeight(int h)
{
    height=h;
}

void Case::setWidth(int w)
{
    width=w;
}

void Case::setLength(int l)
{
    length=l;
}

void Case::setMaxCooler(float mc)
{
    maxCooler=0;
}

void Case::setMaxPSU(float mp)
{
    maxPSU=mp;
}

void Case::setRadCom(float rd)
{
    radCom=rd;
}

void Case::setPrice(float p)
{
    price=p;
}
//Accessors

string Case::getBrand()
{
    return brand;
}

string Case::getSeries()
{
    return series;
}

string Case::getModel()
{
    return model;
}

int Case::getMobo()
{
    return moboType;
}

int Case::getNumEXP()
{
    return numEXP;
}

int Case::getNumFans()
{
    return numFans;
}

int Case::getFSize()
{
    return fanSize;
}

int Case::getHeight()
{
    return height;
}

int Case::getWidth()
{
    return width;
}

int Case::getLength()
{
    return length;
}

float Case::getMaxGPU()
{
    return maxGPU;
}

float Case::getMaxCooler()
{
    return maxCooler;
}

float Case::getMaxPSU()
{
    return maxPSU;
}

float Case::getRadCom()
{
    return radCom;
}

float Case::getPrice()
{
    return price;
}