/* 
 * File:   main.cpp
 * Author: Louli
 *
 * Created on October 2, 2015, 3:05 PM
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

//Function Prototypes
void fillArray(float *, float);//Take in grades into array.
void sortArray(float *, float);//Sort the grades in ascending order.
float avrgTests(float *, float);//Calculates the average test score.
void displayTests(float*, float, float);//Displays results/

/*
 * 
 */
int main(int argc, char** argv) {
    
    int numTests;//Holds number of tests.
    float average;//Holds average/
    float *tests= new float[numTests];
    cout<<"How many test scores are we observing today?"<<endl;//Ask user for amount of tests.
    cin>>numTests;
    fillArray(tests, numTests);
    sortArray(tests, numTests);
    average=avrgTests(tests, numTests);
    displayTests(tests,average, numTests);
    delete [] tests;
    
    return 0;
}

void fillArray(float *tests, float numTests)
{
    cout<<"Enter the grades."<<endl;
    for(int i=0; i<numTests; i++)
    {
        cin>> *(tests+i);
    }    
}
void sortArray(float *tests,float numTests)
{
    int index, min;
    for (int i = 0; i <numTests; i++)
    {
       index = i;
       min= *(tests+i);
       for(int count = i + 1; count < numTests; count++)
       {
          if (*(tests+count) < min)
          {
             min = *(tests+count);
             index= count;
          }
       }
       *(tests+index)  = *(tests+i) ;
       *(tests+i)  = min;
    }
 }

float avrgTests(float *tests, float numTests)
{
    float average, total= 0.0; 
    for( int i=0; i<numTests; i++)
    {
        total+= *(tests+i);
    }
    average=total/numTests;
    return average;
}
void displayTests(float *tests,float average,float numTests)
{
    cout<<"TESTS:"<<endl;
    for(int i=0; i<numTests; i++)
    {
        cout<<*(tests+i)<<endl;
    }
    cout<<"AVERAGE: "<<average;
    
}