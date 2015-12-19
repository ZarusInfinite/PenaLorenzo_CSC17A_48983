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
using namespace std;
//
void gpuInfo(GPU);
  

int main(int argc, char** argv) 

{
    
    
        int budget, cpuBud,gpuBud,moboBud,cpuIND,gpuIND,moboIND;
        char cpuChoice;
        char gpuChoice;
        
        
    cout<<"This program takes a budget and displays the recommend GPU, CPU, and Motherboard for the best value and performance possible."<<endl;
    cout<<"Insert your budget."<<endl;
    cin>>budget;
    cout<<"AMD or Intel CPU? Press 'a' for AMD and 'i' for Intel."<<endl;
    cin>>cpuChoice;
 
    cout<<"AMD or Nvidia GPU? Press 'a' for AMD and 'n' for Nvidia."<<endl;
    cin>>gpuChoice;
    
    
        
        gpuBud=budget*.30;
        cpuBud=budget*.2;
        moboBud=budget*.15;
        
        
        
     
   /***********************************************************************************************************************************/
   //Create hardware database    
    //GPU
    //sub $200
    
    GPU *gpuAMD,*gpuNV;
    gpuAMD= new GPU[4];
    gpuNV= new GPU[5];
   
    CPU *cpuAMD,*cpuINT;
    cpuAMD=new CPU[4];
    cpuINT=new CPU[3];
    
    Mobo *amdMobo, *intMobo;
    amdMobo= new Mobo[4];
    intMobo= new Mobo[5];
    
    
    for(int i=0;i<4;i++)
    {
        if(i=0)
        {
         gpuAMD[i].setBrand("XFX");   
         gpuAMD[i].setManu("AMD");
         gpuAMD[i].setSeries("AMD Radeon R7 300 Series");
         gpuAMD[i].setChip("R7 370");
         gpuAMD[i].setCClock(985);
         gpuAMD[i].setBoost(1010);
         gpuAMD[i].setVRAM(2);
         gpuAMD[i].setMClock(5600);
         gpuAMD[i].setMaxPow(150);
         gpuAMD[i].setRecPow(500);
         gpuAMD[i].setLength(6.7);
         gpuAMD[i].setHeight(4.6);
         gpuAMD[i].setPrice(150);
        }
        else if(i=1)
        {
         gpuAMD[i].setBrand("GIGABYTE");   
         gpuAMD[i].setManu("AMD");
         gpuAMD[i].setSeries("AMD Radeon R9 300 Series");
         gpuAMD[i].setChip("R9 380");
         gpuAMD[i].setCClock(990);
         gpuAMD[i].setBoost(1010);
         gpuAMD[i].setVRAM(4);
         gpuAMD[i].setMClock(5700);
         gpuAMD[i].setMaxPow(150);
         gpuAMD[i].setRecPow(500);
         gpuAMD[i].setLength(9.2);
         gpuAMD[i].setHeight(5.1);
         gpuAMD[i].setPrice(210);
        }
        else if(i=2)
        {
         gpuAMD[i].setBrand("MSI");   
         gpuAMD[i].setManu("AMD");
         gpuAMD[i].setSeries("AMD Radeon R9 300 Series");
         gpuAMD[i].setChip("Radeon R9 390");
         gpuAMD[i].setCClock(1010);
         gpuAMD[i].setBoost(1060);
         gpuAMD[i].setVRAM(8);
         gpuAMD[i].setMClock(6100);
         gpuAMD[i].setMaxPow(275);
         gpuAMD[i].setRecPow(600);
         gpuAMD[i].setLength(10.9);
         gpuAMD[i].setHeight(5.1);
         gpuAMD[i].setPrice(320); 
        }
        else
        {
         gpuAMD[i].setBrand("SAPPHIRE");   
         gpuAMD[i].setManu("AMD");
         gpuAMD[i].setSeries("AMD Radeon R9 300 Series");
         gpuAMD[i].setChip("Radeon R9 Fury (Includes HBM VRAM)");
         gpuAMD[i].setCClock(1050);
         gpuAMD[i].setBoost(1060);
         gpuAMD[i].setVRAM(4);
         gpuAMD[i].setMClock(6100);
         gpuAMD[i].setMaxPow(275);
         gpuAMD[i].setRecPow(750);
         gpuAMD[i].setLength(12.1);
         gpuAMD[i].setHeight(4.9);
         gpuAMD[i].setPrice(500); 
        }
    }
    
    for (int i=0;i<3;i++)
    {
        if (i=0)
        {
            gpuNV[i].setManu("NVIDIA");
            gpuNV[i].setSeries("Geforce GTX 700 Series");
            gpuNV[i].setBrand("EVGA");   
            gpuNV[i].setChip("GTX 750ti");
            gpuNV[i].setCClock(1020);
            gpuNV[i].setBoost(1085);
            gpuNV[i].setVRAM(2);
            gpuNV[i].setMClock(5400);
            gpuNV[i].setMaxPow(60);
            gpuNV[i].setRecPow(300);
            gpuNV[i].setLength(6.7);
            gpuNV[i].setHeight(4.4);
            gpuNV[i].setPrice(130);
        }
        else if(i=1)
        {
           gpuNV[i].setManu("NVIDIA");
           gpuNV[i].setSeries("Geforce GTX 900 Series");     
           gpuNV[i].setBrand("EVGA");   
           gpuNV[i].setChip("GTX 950");
           gpuNV[i].setCClock(1152);
           gpuNV[i].setBoost(1342);
           gpuNV[i].setVRAM(2);
           gpuNV[i].setMClock(6610);
           gpuNV[i].setMaxPow(110);
           gpuNV[i].setRecPow(350);
           gpuNV[i].setLength(6.8);
           gpuNV[i].setHeight(4.4);
           gpuNV[i].setPrice(160);  
       }
        else if (i=2)
        {
            gpuNV[i].setManu("NVIDIA");
            gpuNV[i].setSeries("Geforce GTX 900 Series");   
            gpuNV[i].setBrand("EVGA");   
            gpuNV[i].setChip("GTX 960");
            gpuNV[i].setCClock(1279);
            gpuNV[i].setBoost(1342);
            gpuNV[i].setVRAM(2);
            gpuNV[i].setMClock(7010);
            gpuNV[i].setMaxPow(160);
            gpuNV[i].setRecPow(400);
            gpuNV[i].setLength(10.1);
            gpuNV[i].setHeight(5.1);
            gpuNV[i].setPrice(180);
        }
        else if (i=3)
        {
            gpuNV[i].setManu("NVIDIA");
            gpuNV[i].setSeries("Geforce GTX 900 Series");   
            gpuNV[i].setBrand("GIGABYTE");   
            gpuNV[i].setChip("GTX 970");
            gpuNV[i].setCClock(1178);
            gpuNV[i].setBoost(1329);
            gpuNV[i].setVRAM(4);
            gpuNV[i].setMClock(7010);
            gpuNV[i].setMaxPow(160);
            gpuNV[i].setRecPow(500);
            gpuNV[i].setLength(12.3);
            gpuNV[i].setHeight(5.1);
            gpuNV[i].setPrice(350); 
        }
        else
        {
            gpuNV[i].setManu("NVIDIA");
            gpuNV[i].setSeries("Geforce GTX 900 Series");   
            gpuNV[i].setBrand("GIGABYTE");   
            gpuNV[i].setChip("GTX 980");
            gpuNV[i].setCClock(1203 );
            gpuNV[i].setBoost(1304 );
            gpuNV[i].setVRAM(4);
            gpuNV[i].setMClock(7010);
            gpuNV[i].setMaxPow(200);
            gpuNV[i].setRecPow(600);
            gpuNV[i].setLength(12.3);
            gpuNV[i].setHeight(5.1);
            gpuNV[i].setPrice(510); 
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
        else
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
    //AMD
    for (int i=0;i<4;i++)
    {
        if(i=0)
        {
            amdMobo[i].setBrand("GIGABYTE");
            amdMobo[i].setModel("GA-78LMT-USB3 (rev. 6.0)");
            amdMobo[i].setSock("AM3+");
            amdMobo[i].setCpuType("AMD AM3+/ AMD AM3 Phenom II/ AMD Athlon II processor");
            amdMobo[i].setChip("AMD 760G + SB710");
            amdMobo[i].setMem("DDR3 1600(O.C.)/ 1333/ 1066");
            amdMobo[i].setNumMem(4);
            amdMobo[i].setNumSata(6);
            amdMobo[i].setMaxMem(32);
            amdMobo[i].setNumUSB(6);
            amdMobo[i].setFormFac(1);
            amdMobo[i].setDVI();
            amdMobo[i].setHDMI();
            amdMobo[i].setLength(9.6);
            amdMobo[i].setWidth(9.6);
            amdMobo[i].setPrice(50);
        }
        else if(i=1)
        {
            amdMobo[i].setBrand("GIGABYTE");
            amdMobo[i].setModel("GA-F2A78M-D3H");
            amdMobo[i].setSock("FM2+");
            amdMobo[i].setCpuType("Athlon/A- Series");
            amdMobo[i].setChip("AMD A78 (Bolton D3)");
            amdMobo[i].setMem("DDR3 2400(OC)/2133/1866/1600/1333");
            amdMobo[i].setNumMem(4);
            amdMobo[i].setNumSata(6);
            amdMobo[i].setMaxMem(64);
            amdMobo[i].setNumUSB(6);
            amdMobo[i].setFormFac(1);
            amdMobo[i].setDVI();
            amdMobo[i].setHDMI();
            amdMobo[i].setLength(9.6);
            amdMobo[i].setWidth(9.6);
            amdMobo[i].setPrice(60);
        }
        else if(i=2)
        {
            amdMobo[i].setBrand("MSI");
            amdMobo[i].setModel("970 Gaming");
            amdMobo[i].setSock("AM3+");
            amdMobo[i].setCpuType("AMD FXTM/ Phenom II/ Athlon II and Sempron");
            amdMobo[i].setChip("AMD 970");
            amdMobo[i].setMem("DDR3 2133(OC)/ 1866/ 1600/ 1333/ 1066");
            amdMobo[i].setNumMem(4);
            amdMobo[i].setNumSata(6);
            amdMobo[i].setMaxMem(32);
            amdMobo[i].setNumUSB(10);
            amdMobo[i].setFormFac(2);
            amdMobo[i].setLength(9.6);
            amdMobo[i].setWidth(12);
            amdMobo[i].setPrice(100);
        }
        else
        {
            amdMobo[i].setBrand("MSI");
            amdMobo[i].setModel("990FXA-GAMING");
            amdMobo[i].setSock("AM3+");
            amdMobo[i].setCpuType("AMD FXTM/ Phenom II/ Athlon II and Sempron");
            amdMobo[i].setChip("AMD 990FX & SB950");
            amdMobo[i].setMem("DDR3 2133(OC)/ 1866/ 1600/ 1333/ 1066");
            amdMobo[i].setNumMem(4);
            amdMobo[i].setNumSata(6);
            amdMobo[i].setMaxMem(32);
            amdMobo[i].setNumUSB(10);
            amdMobo[i].setFormFac(2);
            amdMobo[i].setLength(9.6);
            amdMobo[i].setWidth(12);
            amdMobo[i].setPrice(150);
        }
        
    }
    //INTEL
    for(int i=0;i<5;i++)
    {
        if(i=0)
        {
            intMobo[i].setBrand("MSI");
            intMobo[i].setModel("H81M-E33");
            intMobo[i].setSock("LGA 1150");
            intMobo[i].setCpuType("4th Generation Intel Corei7/Corei5/Corei3/Pentium/Celeron (LGA 1150)");
            intMobo[i].setChip("Intel H81");
            intMobo[i].setMem("DDR3 1600/1333/1066");
            intMobo[i].setNumMem(2);
            intMobo[i].setNumSata(4);
            intMobo[i].setMaxMem(16);
            intMobo[i].setNumUSB(6);
            intMobo[i].setFormFac(1);
            intMobo[i].setLength(6.8);
            intMobo[i].setWidth(8.9);
            intMobo[i].setHDMI();
            intMobo[i].setPrice(52);
        }
        else if(i=1)
        {
            intMobo[i].setBrand("GIGABYTE");
            intMobo[i].setModel("GA-H97M-HD3");
            intMobo[i].setSock("LGA 1150");
            intMobo[i].setCpuType("Core i7 / i5 / i3 / Pentium / Celeron (LGA1150)");
            intMobo[i].setChip("Intel H97");
            intMobo[i].setMem("DDR3 1600/1333");
            intMobo[i].setNumMem(2);
            intMobo[i].setNumSata(6);
            intMobo[i].setMaxMem(16);
            intMobo[i].setNumUSB(6);
            intMobo[i].setFormFac(1);
            intMobo[i].setLength(6.9);
            intMobo[i].setWidth(9.6);
            intMobo[i].setHDMI();
            intMobo[i].setDVI();
            intMobo[i].setPrice(75);
        }
        else 
        {
            intMobo[i].setBrand("GIGABYTE");
            intMobo[i].setModel("GA-Z97X-Gaming 7");
            intMobo[i].setSock("LGA 1150");
            intMobo[i].setCpuType("Core i7 / i5 / i3 / Pentium / Celeron (LGA1150)");
            intMobo[i].setChip("Intel H97");
            intMobo[i].setMem("DDR3 3200(OC)/3100(OC)/3000(OC)/2933(OC)/2800(OC)/2666(OC)/2600(OC)/2500(OC)/2400(OC)/2200(OC)/2133(OC)/2000(OC)/1866(OC)/1800(OC)/1600/");
            intMobo[i].setNumMem(4);
            intMobo[i].setNumSata(8);
            intMobo[i].setMaxMem(32);
            intMobo[i].setNumUSB(8);
            intMobo[i].setFormFac(2);
            intMobo[i].setLength(9.6);
            intMobo[i].setWidth(12);
            intMobo[i].setHDMI();
            intMobo[i].setDVI();
            intMobo[i].setVGA();
            intMobo[i].setPrice(150);   
        }
        
    }
    
    // Take budget and choose parts
    
    //CPU
    //AMD
    if(cpuChoice=='a')
    {
        for(int i=0;i<4;i++)
        {
            int index;
            index=i;
            if(cpuAMD[i].getPrice()<cpuBud)
            {
                cpuIND=index;
            }
        }
    }
    //INTEL
    if(cpuChoice=='i')
    {
        for(int i=0;i<3;i++)
        {
            int index;
            index=i;
            if(cpuINT[i].getPrice()<cpuBud)
            {
                cpuIND=index;
            }
        }
    }
    //GPU
    //AMD
    if(gpuChoice=='a')
    {
        for(int i=0;i<4;i++)
        {
            int index;
            index=i;
            if(gpuAMD[i].getPrice()<gpuBud)
            {
                gpuIND=index;
            }
        }
    }
    //NVIDIA
    else
    {
        for(int i=0;i<5;i++)
        {
            int index;
            index=i;
            if(gpuNV[i].getPrice()<gpuBud)
            {
                gpuIND=index;
            }
        }
    }
    //MOBO
    //AMD
    if(cpuChoice=='a')
    {
        for(int i=0;i<5;i++)
        {
            int index;
            index=i;
            if(amdMobo[i].getPrice()<moboBud)
            {
                moboIND=index;
            }
        }
    }
    //INT
    else
    {
        for(int i=0;i<5;i++)
        {
            int index;
            index=i;
            if(intMobo[i].getPrice()<moboBud)
            {
                moboIND=index;
            }
        }
    }
    
    //Display Info
    cout<<"Here's what we've got:"<<endl;
    cout<<endl;
    //CPU
    if(cpuChoice=='a')
    {
        cout<<"Brand: "<<cpuAMD[cpuIND].getBrand()<<endl;
        cout<<"Model: "<<cpuAMD[cpuIND].getModel()<<endl;
        cout<<"Socket: "<<cpuAMD[cpuIND].getSocket()<<endl;
        cout<<"Series: "<<cpuAMD[cpuIND].getSeries()<<endl;
        cout<<"Clock Speed: "<<cpuAMD[cpuIND].getClock()<<endl;
        cout<<"Number of Cores: "<<cpuAMD[cpuIND].getCores()<<endl;
        cout<<"Number of Threads: "<<cpuAMD[cpuIND].getThreads()<<endl;
        cout<<"TDP: "<<cpuAMD[cpuIND].getTDP()<<endl;
        cout<<"Price: $"<<cpuAMD[cpuIND].getPrice()<<endl;
    }
    else
    {
        cout<<"Brand: "<<cpuINT[cpuIND].getBrand()<<endl;
        cout<<"Model: "<<cpuINT[cpuIND].getModel()<<endl;
        cout<<"Socket: "<<cpuINT[cpuIND].getSocket()<<endl;
        cout<<"Series: "<<cpuINT[cpuIND].getSeries()<<endl;
        cout<<"Clock Speed: "<<cpuINT[cpuIND].getClock()<<endl;
        cout<<"Number of Cores: "<<cpuINT[cpuIND].getCores()<<endl;
        cout<<"Number of Threads: "<<cpuINT[cpuIND].getThreads()<<endl;
        cout<<"TDP: "<<cpuINT[cpuIND].getTDP()<<endl;
        cout<<"Price: $"<<cpuINT[cpuIND].getPrice()<<endl;
    }
    cout<<endl;
    //GPU
    if(gpuChoice=='a')
    {
        cout<<"Brand: "<<gpuAMD[gpuIND].getBrand()<<endl;
        cout<<"manufacturer: "<<gpuAMD[gpuIND].getManu()<<endl;
        cout<<"Series: "<<gpuAMD[gpuIND].getSeries()<<endl;
        cout<<"Core Name: "<<gpuAMD[gpuIND].getChip()<<endl;
        cout<<"Clock Speed: "<<gpuAMD[gpuIND].getCClock()<<endl;
        cout<<"Boost Speed: "<<gpuAMD[gpuIND].getBoost()<<endl;
        cout<<"VRAM: "<<gpuAMD[gpuIND].getVRAM()<<endl;
        cout<<"Memory Speed: "<<gpuAMD[gpuIND].getMClock()<<endl;
        cout<<"Max Power consumption: "<<gpuAMD[gpuIND].getMaxPow()<<"w"<<endl;
        cout<<"Recommended PSU: "<<gpuAMD[gpuIND].getRecPow()<<"w"<<endl;
        cout<<"Length: "<<gpuAMD[gpuIND].getLength()<<" inches"<<endl;
        cout<<"Height: "<<gpuAMD[gpuIND].getHeight()<<" inches"<<endl;
        cout<<"Price: $"<<gpuAMD[gpuIND].getPrice()<<endl;
    }
    else
    {
        cout<<"Brand: "<<gpuNV[gpuIND].getBrand()<<endl;
        cout<<"manufacturer: "<<gpuNV[gpuIND].getManu()<<endl;
        cout<<"Series: "<<gpuNV[gpuIND].getSeries()<<endl;
        cout<<"Core Name: "<<gpuNV[gpuIND].getChip()<<endl;
        cout<<"Clock Speed: "<<gpuNV[gpuIND].getCClock()<<endl;
        cout<<"Boost Speed: "<<gpuNV[gpuIND].getBoost()<<endl;
        cout<<"VRAM: "<<gpuNV[gpuIND].getVRAM()<<endl;
        cout<<"Memory Speed: "<<gpuNV[gpuIND].getMClock()<<endl;
        cout<<"Max Power consumption: "<<gpuNV[gpuIND].getMaxPow()<<"w"<<endl;
        cout<<"Recommended PSU: "<<gpuNV[gpuIND].getRecPow()<<"w"<<endl;
        cout<<"Length: "<<gpuNV[gpuIND].getLength()<<" inches"<<endl;
        cout<<"Height: "<<gpuNV[gpuIND].getHeight()<<" inches"<<endl;
        cout<<"Price: $"<<gpuNV[gpuIND].getPrice()<<endl;
    }
    //Mobo
    if(cpuChoice=='a')
    {
        cout<<"Brand: "<<amdMobo[moboIND].getBrand()<<endl;
        cout<<"Model: "<<amdMobo[moboIND].getModel()<<endl;
        cout<<"Socket: "<<amdMobo[moboIND].getSocket()<<endl;
        cout<<"Series: "<<amdMobo[moboIND].getSeries()<<endl;
        cout<<"CPU Type: "<<amdMobo[moboIND].getCpuType()<<endl;
        cout<<"Chipset: "<<amdMobo[moboIND].getChip()<<endl;
        cout<<"Number of memory slots: "<<amdMobo[moboIND].getNumMem()<<endl;
        cout<<"Supported Memory: "<<amdMobo[moboIND].getMem()<<endl;
        cout<<"Max Memory: "<<amdMobo[moboIND].getMaxMem()<<" GB"<<endl;
        cout<<"Number of SATA ports: "<<amdMobo[moboIND].getNumSata()<<endl;
        cout<<"Number of USB ports: "<<amdMobo[moboIND].getNumUSB()<<endl;
        cout<<"Length: "<<amdMobo[moboIND].getLength()<<" inches"<<endl;
        cout<<"Width: "<<amdMobo[moboIND].getWidth()<<" inches"<<endl;
        cout<<"Price: $"<<amdMobo[moboIND].getPrice()<<endl;
    }
    else
    {
        cout<<"Brand: "<<intMobo[moboIND].getBrand()<<endl;
        cout<<"Model: "<<intMobo[moboIND].getModel()<<endl;
        cout<<"Socket: "<<intMobo[moboIND].getSocket()<<endl;
        cout<<"Series: "<<intMobo[moboIND].getSeries()<<endl;
        cout<<"CPU Type: "<<intMobo[moboIND].getCpuType()<<endl;
        cout<<"Chipset: "<<intMobo[moboIND].getChip()<<endl;
        cout<<"Number of memory slots: "<<intMobo[moboIND].getNumMem()<<endl;
        cout<<"Supported Memory: "<<intMobo[moboIND].getMem()<<endl;
        cout<<"Max Memory: "<<intMobo[moboIND].getMaxMem()<<" GB"<<endl;
        cout<<"Number of SATA ports: "<<intMobo[moboIND].getNumSata()<<endl;
        cout<<"Number of USB ports: "<<intMobo[moboIND].getNumUSB()<<endl;
        cout<<"Length: "<<intMobo[moboIND].getLength()<<" inches"<<endl;
        cout<<"Width: "<<intMobo[moboIND].getWidth()<<" inches"<<endl;
        cout<<"Price: $"<<intMobo[moboIND].getPrice()<<endl;
    }

    
    
    
   
    
    //delete al obj
    delete [] gpuAMD;
    delete [] gpuNV;
    delete [] cpuAMD;
    delete [] cpuINT;
    delete [] amdMobo;
    delete [] intMobo;
}