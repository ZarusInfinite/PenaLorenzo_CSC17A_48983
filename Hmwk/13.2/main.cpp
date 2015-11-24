/* 
 * File:   main.cpp
 * Author: Louli
 *
 * Created on November 23, 2015, 6:32 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;

//Function
void prntInfo(Employee);
int main(int argc, char** argv) {

    Employee *emp= nullptr;
    emp=new Employee[3];
    string name[]={"Susan Meyers","Mark Jones","Joy Rogers"};
    int id[]={47899,39119,81774};
    string dep[]={"Accounting","IT","Manufacturing"};
    string pos[]={"Vice President","Programmer","Engineer"};
    //Get info for emp
    for(int i=0;i<3;i++){
        emp[i].setName(name[i]);
        emp[i].setNum(id[i]);
        emp[i].setDep(dep[i]);
        emp[i].setPos(pos[i]);
    }
   //Print info
    for(int i=0;i<3;i++){
        cout<<"Employee "<<i+1<<":"<<endl;
        cout<<endl;
        cout<<"Name: "<<emp[i].getName()<<endl;
        cout<<"ID Number: "<<emp[i].getNum()<<endl;
        cout<<"Department: "<<emp[i].getDep()<<endl;
        cout<<"Position: "<<emp[i].getPos()<<endl;
        cout<<endl;
    }
    //Delete dynamic memory
    delete [] emp;
    //Done
    return 0;
}

