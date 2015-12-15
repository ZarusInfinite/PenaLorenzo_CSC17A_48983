#include <cstdlib>
#include <string>
#include "Storage.h"

using namespace std;
//Storage class

Storage::Storage()
{
    brand="";
    series="";
    model="";
    SSD=false;
    capacity=0;
    RPM=0;
    price=0;
}

void Storage::setBrand(string b)
{
    brand=b;
}

void Storage::setSeries(string s)
{
    series=s;
}

void Storage::setModel(string m)
{
    model=m;
}

void Storage::setSSD()
{
    SSD=true;
}

void Storage::setCapacity(int cap)
{
    capacity=cap;
}

void Storage::setRPM(int r)
{
    RPM=r;
}

void Storage::setPrice(float p)
{
    price=p;
}

string Storage::getBrand()
{
    return brand;
}

string Storage::getSeries()
{
    return series;
}

string Storage::getModel()
{
    return model;
}

int Storage::getCap()
{
    return capacity;
}

int Storage::getRPM()
{
    return RPM;
}

float Storage::getPrice()
{
    return price;
}

