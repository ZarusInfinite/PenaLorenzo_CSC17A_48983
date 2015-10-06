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
    
    int const SIZE=100;//Limit length of string.
    int vowl,cons;//For vowels and consonant.
    char sentence[SIZE], choice;//Our character array, and our input variable for the menu.
    do{
    cout<<"Enter a string less than 100 charactes."<<endl;
    cin.getline(sentence, SIZE);//Get the cstring.
    menu();//Call our menu
    cin>>choice;//User makes a choice in the menu.
    choice=toupper(choice);//Change input to upper case for the switch statment.
    vowl=numVOW(sentence);//Get the number of vowels.
    cons=numCON(sentence);//Get the number of consonants.
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
    
    int vow=0,con=0;//Counters
    for( int i=0; i<strlen(sentence); i++)
    {
        char temp=toupper(*(sentence+i));//Change letters to uppercase for switch
        switch(temp)
        {
            case'A':
            case'E':
            case'I':
            case'O':
            case'U':
            vow++;//count up vowels
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
            vow++;//count up vowels, although they wont be returned in this function
            break;
            case' '://we don't want anything but letters.
            case'.':
            case'?':
            case'!':
            break;
            default:
            con++;//count up consonants.
        }
    }
      return con;
}