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
  

int main(int argc, char** argv) 

{
    cout<<"Hello. This is a program for people who want to step into the realm of PC gaming."<<endl;
    cout<<"By giving the program an estimate of your budget, it will be able to develop a system"<<endl;
    cout<<"the best possible performance in 3D applications while still fitting within the given budget."<<endl;
    cout<<"It is important to remember that prices fluctuate. The final amount for these may vary from the real time"<<endl;
    cout<<"prices. However, they will be very close."<<endl;
    
    int budget;
    
    /***********************************************************************************************************************************/
    //Create hardware database
    
    //GPU
    //sub $200
    
    GPU *midAMD,*midNV,*sweet,*high;
    midAMD= new [4] GPU;
    midNV= new [3] GPU;
    sweet=new [2] GPU;
    high=new [3] GPU;
    
    CPU *cpuAMD,*cpuINT;
    cpuAMD=new [4];
    cpuINT=new [3];
    
    for(int i=0;i<2;i++)
    {
        if(i=0)
        {
            midAMD[i].setBrand("XFX");
        }
        else {midAMD[i].setBrand("ASUS");}
    
        midAMD[i].setManu("AMD");
        if(i=0)
        {
            midAMD[i].setSeries("Radeon R7");
        }
        else { midAMD[i].setSeries("Radeon R9");}
        
        midAMD[i].setChip(370+(i*10));
        midAMD[i].setCClock(985-(i*5));
        midAMD[i].setBoost(1010);
        midAMD[i].setVRAM(2+(i*2));
        midAMD[i].setMClock(5600+(i*100));
        midAMD[i].setMaxPow(150+(i*75));
        midAMD[i].setRecPow(500+(i*100));
        midAMD[i].setLength(6.7+(i*3.97));
        midAMD[i].setHeight(4.6+(i*.87));
        midAMD[i].setPrice(150+(i*70));        
    }
    
    for (int i=0;i<3;i++)
    {
        midNV[i].setManu("NVIDIA");
        midNV[i].setSeries("Geforce GTX");
        if(i=0)
        {   
        midNV[i].setBrand("EVGA");   
        midNV[i].setChip(750);
        midNV[i].setCClock(1020);
        midNV[i].setBoost(1085);
        midNV[i].setVRAM(2);
        midNV[i].setMClock(5400);
        midNV[i].setMaxPow(60);
        midNV[i].setRecPow(300);
        midNV[i].setLength(6.7);
        midNV[i].setHeight(4.4);
        midNV[i].setPrice(130);
        }
        else if(i=1)
        {
        midNV[i].setBrand("EVGA");   
        midNV[i].setChip(950);
        midNV[i].setCClock(1152);
        midNV[i].setBoost(1342);
        midNV[i].setVRAM(2);
        midNV[i].setMClock(6610);
        midNV[i].setMaxPow(110);
        midNV[i].setRecPow(350);
        midNV[i].setLength(6.8);
        midNV[i].setHeight(4.4);
        midNV[i].setPrice(160);  
        }
        else  
        midNV[i].setBrand("EVGA");   
        midNV[i].setChip(960);
        midNV[i].setCClock(1279);
        midNV[i].setBoost(1342);
        midNV[i].setVRAM(2);
        midNV[i].setMClock(7010);
        midNV[i].setMaxPow(160);
        midNV[i].setRecPow(400);
        midNV[i].setLength(10.1);
        midNV[i].setHeight(4.4);
        midNV[i].setPrice(210);  
    }
    
    for(int i=0;i<2;i++)
    {
        if(i=0)
        {   
        sweet[i].setManu("NVIDIA");
        sweet[i].setSeries("Geforce GTX");
        sweet[i].setBrand("EVGA");   
        sweet[i].setChip(970);
        sweet[i].setCClock(1190);
        sweet[i].setBoost(1342);
        sweet[i].setVRAM(4);
        sweet[i].setMClock(7010);
        sweet[i].setMaxPow(200);
        sweet[i].setRecPow(500);
        sweet[i].setLength(10.1);
        sweet[i].setHeight(4.4);
        sweet[i].setPrice(325);
        }
        else if(i=1)
        {
        sweet[i].setManu("AMD");
        sweet[i].setSeries("R9");
        sweet[i].setBrand("GIGABYTE");   
        sweet[i].setChip(390);
        sweet[i].setCClock(1025);
        sweet[i].setBoost(0);
        sweet[i].setVRAM(8);
        sweet[i].setMClock(6000);
        sweet[i].setMaxPow(225);
        sweet[i].setRecPow(600);
        sweet[i].setLength(9.2);
        sweet[i].setHeight(5.1);
        sweet[i].setPrice(310);
        }
    }
    
    for( int i=0;i<3;i++)
    {
        if(i=0)
        {   
        high[i].setManu("NVIDIA");
        high[i].setSeries("Geforce GTX");
        high[i].setBrand("GIGABYTE");   
        high[i].setChip(980);
        high[i].setCClock(1203);
        high[i].setBoost(1304);
        high[i].setVRAM(4);
        high[i].setMClock(7010);
        high[i].setMaxPow(200);
        high[i].setRecPow(600);
        high[i].setLength(12.3);
        high[i].setHeight(5.1);
        high[i].setPrice(500);
        }
        else if(i=1)
        {
        high[i].setManu("NVIDIA");
        high[i].setSeries("Geforce GTX");
        high[i].setBrand("GIGABYTE");   
        high[i].setChip(980);//add ti
        high[i].setCClock(1102);
        high[i].setBoost(1190);
        high[i].setVRAM(6);
        high[i].setMClock(7010);
        high[i].setMaxPow(225);
        high[i].setRecPow(600);
        high[i].setLength(11);
        high[i].setHeight(4.6);
        high[i].setPrice(630);   
        }
        else
        {
        high[i].setManu("AMD");
        high[i].setSeries("R9");
        high[i].setBrand("SAPPHIRE");   
        high[i].setChip(static_cast<int>(Fury));
        high[i].setCClock(1000);
        high[i].setBoost(0);
        high[i].setVRAM(4);
        //high[i].setMClock(7010);
        //high[i].setMaxPow(225);
        //high[i].setRecPow(600);
        high[i].setLength(15);
        high[i].setHeight(9.8);
        high[i].setPrice(610);
        }
    }
    //CPU
    for(int i=0;i<4;i++)
    {
        
        cpuAMD[i].setBrand("AMD");
        if(i=0)
        {
        cpuAMD[i].setSeries("FX series");
        cpuAMD[i].setSock("AM3+");
        cpuAMD[i].setModel("4350");
        cpuAMD[i].setCores(4);
        cpuAMD[i].setClock(4.2);
        cpuAMD[i].setTDP(125);
        cpuAMD[i].setPrice(90);
        }
        else if(i=1)
        {
        cpuAMD[i].setSeries("FX series");
        cpuAMD[i].setSock("AM3+");
        cpuAMD[i].setModel("6300");
        cpuAMD[i].setCores(4);
        cpuAMD[i].setClock(4.1);
        cpuAMD[i].setTDP(95);
        cpuAMD[i].setPrice(100); 
        }
        else if(i=2)
        {
        cpuAMD[i].setSeries("FX series");
        cpuAMD[i].setSock("AM3+");
        cpuAMD[i].setModel("8350");
        cpuAMD[i].setCores(8);
        cpuAMD[i].setClock(4.2);
        cpuAMD[i].setTDP(125);
        cpuAMD[i].setPrice(150); 
        }
        else
        {
        cpuAMD[i].setSeries("Athlon");
        cpuAMD[i].setSock("FM2+");
        cpuAMD[i].setModel("x4 860k");
        cpuAMD[i].setCores(4);
        cpuAMD[i].setClock(3.8);
        cpuAMD[i].setTDP(95);
        cpuAMD[i].setPrice(70); 
        }
             
    }
    
    for (int i=0;i<3;i++)
    {
        cpuINT[i].setBrand("INTEL");
        if(i=0)
        {
        cpuINT[i].setSeries("i3");
        cpuINT[i].setSock("LGA 1150");
        cpuINT[i].setModel("4170");
        cpuINT[i].setCores(4);
        cpuINT[i].setThreads(4);
        cpuINT[i].setClock(3.7);
        cpuINT[i].setTDP(54);
        cpuINT[i].setPrice(100);
        }
        else if(i=1)
        {
        cpuINT[i].setSeries("i5");
        cpuINT[i].setSock("LGA 1150");
        cpuINT[i].setModel("4690k");
        cpuINT[i].setCores(4);
        cpuINT[i].setThreads(4);
        cpuINT[i].setClock(3.9);
        cpuINT[i].setTDP(88);
        cpuINT[i].setPrice(215);
        }
        else if(i=2)
        {
        cpuINT[i].setSeries("i5");
        cpuINT[i].setSock("LGA 1150");
        cpuINT[i].setModel("4790k");
        cpuINT[i].setCores(4);
        cpuINT[i].setThreads(8);
        cpuINT[i].setClock(4.4);
        cpuINT[i].setTDP(95);
        cpuINT[i].setPrice(310);
        }
        
    }
    
    //MOBO
    
    
        
    
    
    
    
    
    //delete al obj
    delete [] midAMD;
    delete [] midNV;
    delete [] sweet;
    delete [] cpuAMD;
    delete [] cpuINT;

    
   return 0; 
}
      