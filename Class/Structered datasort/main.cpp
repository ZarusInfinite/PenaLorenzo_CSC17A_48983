/* 
 * File:   main.cpp
 * Author: rcc
 * Created on October 6, 2015, 11:18 AM
 *  Show utility of a structure referenced to a database sort.
 *  Indexed column in a database
 */

//HW: Convert this to dot notation for the dereferencing. 
//      Then pointer notation for the arrays.

#include <cstdlib>
#include <iostream>
#include <ctime>
#include "indexedcolumn.h"
using namespace std;

indexcolumn *fill(int);
void printStructure(indexcolumn *,int);
void printArray(int *,int,int);
void sort(indexcolumn *);

int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    //Allocate memory for structure
    int n=100,col=10;
    indexcolumn *structure=fill(n);
    cout<<"The original index array"<<endl;
    //Print structure/index
    printArray((*structure).index,(*structure).size,col);
    //Print data in array
    cout<<"The original data array"<<endl;
    printArray((*structure).array,(*structure).size,col);
    cout<<"The original data array using the indexed array"<<endl;
    printStructure(structure,col);
    //sort data using index, hence database sort
    sort(structure);
    cout<<"Sorted index array"<<endl;
    //Print structure/index
    printArray((*structure).index,(*structure).size,col);
    //Print data in array
    cout<<"Sorted data array"<<endl;
    printArray((*structure).array,(*structure).size,col);
    cout<<"Sorted data array using the indexed array"<<endl;
    printStructure(structure,col);
    return 0;
}

indexcolumn *fill(int n){
    //Allocate memory
    indexcolumn *col=new indexcolumn;
    if(n<=1)n=2;
    (*col).size=n;
    //Allocate pointers for array
    (*col).array=new int[n];
    (*col).index=new int[n];
    //Fill array
    for(int i=0;i<n;i++){
        //*((*col).array+i).
        *((*col).index+i)=i;
        *((*col).array+i)=rand()%90+10;
    }
    //return the allocated and filled structure
    return col;
}

void printStructure(indexcolumn *a,int perLine){ //prints using indexes
    cout<<endl;
    for(int i=0;i<(*a).size;i++){
        cout<<(*a).array[*((*a).index+i)]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void printArray(int *a,int size,int perLine){ //prints elements in array one at a time
    cout<<endl;
    for(int i=0;i<size;i++){
        cout<<*(a+i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void sort(indexcolumn *a){
    //Pick position to sort
    for(int i=0;i<(*a).size-1;i++){             //THIS IS DOT OPERATOR
        //sort list by position
        for(int j=i+1;j<(*a).size;j++){
            if((*a).array[*((*a).index+i)]>(*a).array[*((*a).index+j)]){
                int temp=*((*a).index+i);
                *((*a).index+i)=*((*a).index+j);
                *((*a).index+j)=temp;
            }
        }
    }
}