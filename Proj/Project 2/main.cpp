/* 
 * File:   main.cpp
 * Author: Louli
 *
 * Project: PC building and benchmarking program. Takes in user's budget and
 * for custom PC. This program will choose from a database of hardware and create 
 * a hardware list that will best satisfy the user's budget and need.
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "GPU.h"
#include "CPU.h"
#include "Mobo.h"
#include "Memory.h"
#include "Storage.h"
#include "PSU.h"
#include "Case.h"
using namespace std;
//
void gpuInfo(GPU);
  

int main(int argc, char** argv) 

{
    cout<<"This program takes a PC's specs and gives it a grade relative to it's performance."<<endl;
    
    //Take build
    GPU gpu;
    CPU cpu;
    Mobo motherbrd;
    Memory mem;
    Storage strg;
   
   return 0; 
}
  
void gpuInfo(GPU g)
{
    string b,s,m;
    int chp,clk,bst,vrm,mClk,mTp,mP,rP,l,h,p
    cout<<"Brand?"<<endl;
    getline(cin,b);
    cout<<"Series"<<endl;
    getline(cin,s);
    cout<<"Model?"<<endl;
    getline(cin,m);
    cout<<"Chip(i.e. Nvidia or AMD)?";
    getline(cin,chp);
    cout<<"Clockspeed?"<<endl;
    cin>>clk;
    cout<<"Overclocked?(If so put by how much, if not type 0)"<<endl;
    cin>>bst;
    cout<<"VRAM?(In GBs)?"<<endl;
    cin>>vrm;
    cout<<"Max Power draw?"<<endl;
    cin>>mP;
    
    g.setBrand(b);
    g.setM
    
}
    
    
}