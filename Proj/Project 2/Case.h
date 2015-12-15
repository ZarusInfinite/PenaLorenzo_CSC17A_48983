/* 
 * File:   Case.h
 * Author: Louli
 *
 * Created on December 14, 2015, 11:17 PM
 */

#ifndef CASE_H
#define	CASE_H
#include <string>

using namespace std;

//Case class
        class Case
        {
        private:
            string brand;
            string series;
            string model;
            int moboType;
            bool wPSU;
            bool frntPorts;
            int numEXP;
            int numFans;
            int fanSize;
            int height;
            int width;
            int length;
            float maxGPU;
            float maxCooler;
            float maxPSU;
            float radCom;
            float price;
        public:
            Case();//Constructor
            //Mutators
            void setBrand(string);
            void setSeries(string);
            void setModel(string);
            void setMobo(int);
            void setWPSU();
            void setPort();
            void setNumEXP(int);
            void setNumFans(int);
            void setFSize(int);
            void setHeight(int);
            void setWidth(int);
            void setLength(int);
            void setMaxGPU(float);
            void setMaxCooler(float);
            void setMaxPSU(float);
            void setRadCom(float);
            void setPrice(float);
            //Accessors
            string getBrand();
            string getSeries();
            string getModel();
            int getMobo();
            bool getWPSU();
            bool getPort();
            int getNumEXP();
            int getNumFans();
            int getFSize();
            int getHeight();
            int getWidth();
            int getLength();
            float getMaxGPU();
            float getMaxCooler();
            float getMaxPSU();
            float getRadCom();
            float getPrice();
        
        };


#endif	/* CASE_H */

