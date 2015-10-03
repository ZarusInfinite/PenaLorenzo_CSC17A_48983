/* 
 * File:   main.cpp
 * Author: Lorenzo Pena
 *
 * Created on September 27, 2015, 3:41 PM
 */

#include <cstdlib>
#include <iostream>

void fillArray(int[],int);//Fills the array with elements inputed by user
void displayArray(int[],int);//Function to output our array
void sortArray(int[],int);
float mean(int [],int);
float median(int [],int);
int mode(int [],int);

using namespace std;

int main(int argc, char** argv) {
    
    int SIZE, Mode;//Hold size of array, holds mode.
    float average, mid;
    cout<<"The array contains a repeated set of elements. Goes from 0 to 9 and repeats."<<endl;
    cout<<"You choose how many elements the array holds."<<endl;//User determines size of array
    cin>>SIZE;
    int A[SIZE];//Our array
    fillArray(A,SIZE);
    sortArray(A,SIZE);
    displayArray(A,SIZE);
    average=mean(A,SIZE);
    mid=median(A,SIZE);
    mode(A,SIZE);
    cout<<"The mean is: "<<average<<endl;
    cout<<"The median is: "<<mid<<endl;
    return 0;
}

void fillArray(int A[], int SIZE)
{
    int element=0;//Starting value of array element. Array goes from 0 to 9. By moding 10 by 10 we reset the element to zero and start over again.
        for(int i=0; i<SIZE; i++)
        {
            A[i]=element++;
            if(element%10==0)
            {
                element=0;
            }
        }
}

void displayArray(int A[],int SIZE)
{
    cout<<"This is the array sorted:"<<endl;
    for(int i =0; i<SIZE; i++)
    {
        if(i%10==0)
        {
            cout<<endl;
        }
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

void sortArray(int A[],int SIZE)
{
    int index, min;
    for (int i = 0; i <SIZE; i++)
    {
       index = i;
       min= A[i];
       for(int count = i + 1; count < SIZE; count++)
       {
          if (A[count] < min)
          {
             min = A[count];
             index= count;
          }
       }
       A[index] = A[i];
       A[i] = min;
    }
 }

float mean(int A[],int SIZE)
{
    float total=0;
    for(int i=0; i<SIZE; i++)
    {
        total+= A[i];
    }
    float mean=total/SIZE;
    return mean;
}

float median(int A[], int SIZE)
{
    float tempMedian, median;
    int *Aptr=A;
    if(SIZE%2==0)//If there are an even number of elements
    {
        tempMedian= *(Aptr+SIZE/2-1)+ *(Aptr+SIZE/2);
        median=tempMedian/2;
    }
    else//If there are an odd number of elements
    {
        median= *(Aptr+(1+SIZE)/2-1);
    }
       return median; 
}

int mode(int A[], int SIZE)
{
        int max=1,freq=1,mode=A[0];
        for(int i=0; i<SIZE; i++)
        {
            if(A[i]==A[i+1])
            {
                freq++;
                if(freq>max)
                {
                    max=freq;
                    mode=A[i];
                }
            }
        else freq=1;
        }
    cout<<"The mode is: "<<mode<<endl;   
    cout<<"The frequency is: "<<max<<endl;
   
}
  
