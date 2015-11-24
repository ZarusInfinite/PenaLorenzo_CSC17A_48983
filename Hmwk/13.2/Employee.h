/* 
 * File:   Employee.h
 * Author: Louli
 *
 * Created on November 23, 2015, 6:32 PM
 */

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H
#include <string>

using namespace std;

class Employee{
private:
    string name;
    int idNumber;
    string department;
    string position;
public:
    Employee();
    void setNum(int);
    void setName(string);
    void setDep(string);
    void setPos(string);
    string getName();
    int getNum();
    string getDep();
    string getPos();
};


#endif	/* EMPLOYEE_H */

