#include <cstdlib>
#include <string>
#include "Memory.h"


using namespace std;

//Memory class

Memory::Memory()
{
    brand="";
    model="";
    type="";
    speed=0;
    capacity=0;
    price=0;
}

void Memory::setBrand(string b)
{
    brand=b;
}

void Memory::setModel(string m)
{
    model=m;
}

void Memory::setSpeed(int s)
{
    speed=s;
}

void Memory::setCap(int c)
{
    capacity=c;
}

void Memory::setPrice(float p)
{
    price=p;
}

string Memory::getBrand()
{
    return brand;
}

string Memory::getModel()
{
    return model;
}

string Memory::getType()
{
    return type;
}

int Memory::getSpeed()
{
    return speed;
}

int Memory::getCap()
{
    return capacity;
}

float Memory::getPrice()
{
    return price;
}
