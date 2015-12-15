#include <cstdlib>
#include <string>
#include "CPU.h"

using namespace std;

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

void CPU::setClock(float clk)
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

float CPU::getClock()
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
