/* 
 * File:   main.cpp
 * Author: Louli
 *
 * Created on October 5, 2015, 6:36 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>


using namespace std;

//Function Prototypes
void menu();
int numVOW(char *);
int numCON(char*);

int main(int argc, char** argv) {
    
    int const SIZE=100;
    int vowl,cons;
    char sentence[SIZE], choice;
    do{
    cout<<"Enter a string less than 100 charactes."<<endl;
    cin.getline(sentence, SIZE);
    menu();
    cin>>choice;
    choice=toupper(choice);
    vowl=numVOW(sentence);
    cons=numCON(sentence);
    switch(choice)
        {
        case 'A':cout<<"There are a total of "<<vowl<<" vowels in the sentence.";break;
        case 'B':cout<<"There are a total of "<<cons<<" consonants in the sentence.";break;
        case 'C':cout<<"There are a total of "<<vowl<<" vowels and "<<cons<<" consonants in the sentence.";break;
        case 'D':choice='D';break;
        case 'E':return 0; break;
        default:cout<<"Your choice is invalid, please try again."<<endl;
        menu();
        cin>>choice;
        choice=toupper(choice);
        break;
        }
    cin.ignore();
    }while(choice=='D');
    

    return 0;
}

void menu(){
    cout<<' '<<endl<<setw(7)<<"A) Count the number of vowels in the string"<<endl
                   <<setw(7)<<"B) Count the number of consonants in the string"<<endl
                   <<setw(7)<<"C) Count both the vowels and consonants in the string"<<endl
                   <<setw(7)<<"D) Enter another string"<<endl
                   <<setw(7)<<"E) Exit the program"<<endl;           
}

int numVOW(char * sentence){
    
    int vow=0,con=0;
    for( int i=0; i<strlen(sentence); i++)
    {
        char temp=toupper(*(sentence+i));
        switch(temp)
        {
            case'A':
            case'E':
            case'I':
            case'O':
            case'U':
            vow++;
            break;
            
        }
    }
  return vow; 
}

int numCON(char *sentence)
{
      int vow=0,con=0;
    for( int i=0; i<strlen(sentence); i++)
    {
        char temp=toupper(*(sentence+i));
        switch(temp)
        {
            case'A':
            case'E':
            case'I':
            case'O':
            case'U':
            vow++;
            break;
            case' ':
            case'.':
            case'?':
            case'!':
            break;
            default:
            con++;
        }
    }
      return con;
}