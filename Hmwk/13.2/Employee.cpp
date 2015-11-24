
#include <cstdlib>
#include <iostream>
#include "Employee.h"

using namespace std;

Employee::Employee()
{
    name="";
    idNumber=0;
    department="";
    position="";
}

void Employee::setName(string n)
{
    name=n;
}

void Employee::setNum(int id)
{
    idNumber= id;
}

void Employee::setDep(string dep)
{
    department=dep;
}

void Employee::setPos(string pos)
{
    position=pos;
}

string Employee::getName(){
    return name;
}

int Employee::getNum(){
    return idNumber;
}
string Employee::getDep()
{
    return department;
}
string Employee::getPos(){
    return position;
}