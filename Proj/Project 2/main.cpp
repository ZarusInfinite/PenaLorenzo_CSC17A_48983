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
    
    
    
   return 0; 
}
      