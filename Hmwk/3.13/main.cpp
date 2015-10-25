/* Author: Pena, Lorenzo
 * Date: 9/13/2015
 * Purpose: (3.13) Converts dollars to yen and euros.
 */
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

const float YEN_PER_DOLLAR= 120.39;
const float EUROS_PER_DOLLAR= 0.88;

int main()
{
    float dollars,yen,euros;
    cout<<"Please enter a dollar value you'd like to convert."<<endl;
    cin>>dollars;
    
    yen= dollars * YEN_PER_DOLLAR;
    euros= dollars * EUROS_PER_DOLLAR;
    cout<< setprecision(2)<< fixed;
    cout<<"That will translate into "<<yen<<" yen and "<<euros<<" euros."<<endl;
           
    return 0;
}
