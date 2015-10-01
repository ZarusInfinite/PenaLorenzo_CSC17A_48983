/* 
 * File:   main.cpp
 * Author: Louli
 *
 * Created on September 27, 2015, 3:41 PM
 */

#include <cstdlib>
#include <iostream>

void inputArray(int[],int);//Fills the array with elements inputed by user
void sortArray(int[],int);//Function to sort our array
void displayArray(int[],int);//Function to output our array
void modesrchArray(int[], int);//Function that determines mode within the array

using namespace std;

int main(int argc, char** argv) {
    
    int SIZE;//Hold size of array
    cout<<"Enter size of array"<<endl;//User determines size of array
    cin>>SIZE;
    int A[SIZE];//Our array with SIZE
    inputArray(A,SIZE);
    cout<<"This is the array:"<<endl;
    displayArray(A,SIZE);
    sortArray(A,SIZE);
    cout<<"This is the array sorted:"<<endl;
    displayArray(A,SIZE);
    modesrchArray(A,SIZE);
    return 0;
}

void inputArray(int A[], int SIZE)
{
    cout<<"Enter array elements"<<endl;
        for(int count=0; count<SIZE; count++)
        {
            cin>>A[count];
        }
}

void sortArray(int A[],int SIZE)
{
    int count, index, min;
    for (count = 0; count <SIZE; count++)
    {
       index = count;
       min= A[count];
       for(int i = count + 1; i < SIZE; i++)
       {
          if (A[i] < min)
          {
             min = A[i];
             index= i;
          }
       }
       A[index] = A[count];
       A[count] = min;
    }
 }

void displayArray(int A[],int SIZE)
{
    int count;
    for(count =0; count<SIZE; count++)
    {
        cout<<A[count]<<endl;
    }
}

void modesrchArray(int A[], int size)
{
    int max=0;//
    int mdCount = 1;//Counts the amount of times an element is repeated
    int mode=A[0];//The value of the mode
    for(int count= 0; count<size; count++)
    {
        if(A[count]=A[count+1])
        {
            mdCount++;
            if(mdCount > max)
            {
                max= mdCount;
                mode=A[count];
            }
        }
    else mdCount=1;
    }
cout << "mode : " << mode << endl;
}