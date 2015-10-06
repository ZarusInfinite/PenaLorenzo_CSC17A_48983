/* Author: Lorenzo Pena
 * Purpose:Takes in a sentence and displays the number of words
 *  and average number of letters.
 * Created on October 5, 2015, 1:12 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

//int numWords(string);
int numWords(char *, int const);


int main(int argc, char** argv) {
    
    int numWord;//Holds the number of wordsin our sentence.
    int const SIZE=100;
    char charptr[SIZE];
    cout<<"Enter a sentence with less than 100 characters."<<endl;
    cin.getline(charptr, SIZE);
    numWord=numWords(charptr, SIZE);
    cout<<"There are "<<numWord<<" words."<<endl;
    float avgltr=(static_cast<float>(strlen(charptr)-(numWord-1))/numWord);//Calculates average number of letters.
    cout<<"There are an average of "<<avgltr<<" letters."<<endl;
    //cout<<strlen(charptr);
    return 0;
}
int numWords(char *charptr, int const SIZE)
{
    int count=0;
    for(int i=0; i<SIZE; i++)
    {
        if(*(charptr+i)!='\0')//Makes sure it's not the end of a sentence
        {
            if(*(charptr+i)==' ')//Space indicates the end of a word.
                count++;
        }
    }
    return count;
}




