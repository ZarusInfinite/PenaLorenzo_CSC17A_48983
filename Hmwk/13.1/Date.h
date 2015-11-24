/* 
 * File:   Date.h
 * Author: Louli
 *
 * Created on November 23, 2015, 8:48 PM
 */

#ifndef DATE_H
#define	DATE_H

class Date{

private:
    int month;
    int day;
    int year;
public:
    Date();
    void setMonth(int);
    void setDay(int);
    void setYear(int);
    void getDate1();
    void getDate2();
    void getDate3();
    
};

#endif	/* DATE_H */

