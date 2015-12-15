/* 
 * File:   CPU.h
 * Author: Louli
 *
 * Created on December 14, 2015, 11:11 PM
 */

#ifndef CPU_H
#define	CPU_H
#include <string>

using namespace std;

//CPU class
    class CPU
    {
    private:
        string brand;
        string series;
        string model;
        string socket;//Socket type, i.e. LGA 1150 or AM3+
        string coreName;
        bool hyperThread;//Whether cpu support hyperthreading (intel only)
        bool intGraphics;//Integrated graphics yes or no
        int numCores;
        int numThreads;
        int clock;
        int TDP;
        float price;
    public:
        CPU();//Constructors
        //Mutators
        void setBrand(string);
        void setSeries(string);
        void setModel(string);
        void setSock(string);
        void setName(string);
        void setHype();//call if true
        void setIG();//call if true
        void setCores(int);
        void setThreads(int);
        void setClock(int);
        void setTDP(int);
        void setPrice(float);
        //Accessors
        string getBrand();
        string getSeries();
        string getModel();
        string getSocket();
        string getName();
        int getCores();
        int getThreads();
        int getClock();
        int getTDP();
        float getPrice();
    };


#endif	/* CPU_H */

