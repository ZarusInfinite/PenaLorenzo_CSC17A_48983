/* 
 * File:   main.cpp
 * Author: Louli
 *
 * Created on September 27, 2015, 3:41 PM
 */

#include <cstdlib>
#include <iostream>

void sortArray(int[],int);
void displayArray(int[],int);
void searchArray(int[], int);

using namespace std;


int main(int argc, char** argv) {
    
    int SIZE;
    int A[SIZE];
    cout<<"Enter size of array"<<endl;
    cin>>SIZE;
    cout<<"Enter array elements"<<endl;
        for(int count=0; count<SIZE; count++)
        {
            cin>>A[count];
        }
    sortArray(A,SIZE);
    displayArray(A,SIZE);
    searchArray(A,SIZE);
    return 0;
}

void sortArray(int A[],int SIZE)
{
    int startScan, minIndex, minValue;
    for (startScan = 0; startScan < (SIZE - 1); startScan++)
    {
       minIndex = startScan;
       minValue = A[startScan];
       for(int index = startScan + 1; index < SIZE; index++)
       {
          if (A[index] < minValue)
          {
             minValue = A[index];
             minIndex = index;
          }
       }
       A[minIndex] = A[startScan];
       A[startScan] = minValue;
    }
 }

void displayArray(int A[],int SIZE)
{
    int count;
    cout<<"This the array:"<<endl;
    for(count =0; count<SIZE; count++)
    {
        
        cout<<A[count]<<endl;
    }
}

void searchArray(int A[], int size)
{
    int max=0;
    int mdCount = 1;
    int mode;
    int element = A[0]; 
    
    for(int count= 0; count<size; count++)
    {
        if(A[count]=A[count+1])
        {
            mdCount++;
        }
        else
        {
            if(mdCount > max)
            {
                max= mdCount;
                mode=element;
            }
        }
    }
cout << "mode : " << mode << endl;
}