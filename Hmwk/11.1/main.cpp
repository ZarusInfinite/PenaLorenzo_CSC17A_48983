/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on October 12, 2015, 1:35 PM
 */

#include <cstdlib>
#include <iostream>
#include "movieData.h"

using namespace std;

//Function Prototypes

void displayInfo(movieData*);
movieData *fillMovie();

int main(int argc, char** argv) {
    
    movieData *Movie1, *Movie2;
    cout<<"MOVIE #1:"<<endl;
    Movie1= fillMovie();//Fill in first Movie
    displayInfo(Movie1);//Display first movie's info
    delete Movie1;
    cout<<"MOVIE #2:"<<endl;
    Movie2= fillMovie();//Fillin second Movie
    displayInfo(Movie2);//Display second movie's info
    delete Movie2;
    return 0;
}

movieData *fillMovie(){
    movieData *Movie= new movieData;
    
    cout<<"Enter the title of the movie"<<endl;
    getline(cin,Movie->Title);
    cout<<"Now the name of the Director."<<endl;
    getline(cin,Movie->Director);
    cout<<"The year it was released."<<endl;
    cin>>Movie->Year;
    cout<<"And finally the movie's runtime in minutes."<<endl;
    cin>>Movie->Runtime;
    return Movie;
}
void displayInfo(movieData* Movie){
    cout<<endl;
    cout<<"TITLE: "<<Movie->Title<<endl;
    cout<<"DIRECTOR: "<<Movie->Director<<endl;
    cout<<"YEAR: "<<Movie->Year<<endl;
    cout<<"RUNTIME: "<<Movie->Runtime<<endl;
    cout<<endl;
}