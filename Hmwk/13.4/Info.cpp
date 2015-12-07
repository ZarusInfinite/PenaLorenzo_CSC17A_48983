#include <string>
#include "Info.h"

using namespace std;

Info::Info(){
    name="";
    address="";
    number=0;
}

void Info::setName(string n){
    name=n;
}

void Info::setAddress(string a){
    address=a;
}

void Info::setNum(int num){
 
   number=num;
}

string Info::getName(){
    return name;
}

string Info::getAddress(){
    return address;
}

int Info::getNum(){
    return number;
}
