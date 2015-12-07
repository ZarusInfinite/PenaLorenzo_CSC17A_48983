#include <cstdlib>
#include <string>
#include "Car.h"

using namespace std;

Car::Car(int y, string m)
{
    speed=0;
    make=m;
    yearModel=y;
}

string Car::getMake()
{
    return make;
}

int Car::getYear()
{
    return yearModel;
}

int Car::getSpeed()
{
    return speed;
}

void Car::accel()
{
    speed+=5;
}

void Car::brake()
{
    speed-=5;
}