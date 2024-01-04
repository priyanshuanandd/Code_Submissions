#include <iostream>
using namespace std;

int main()
{
    int dec,num1=0,p = 1;
    cin>> dec;
    for (;dec!=0;)
    {
        num1 += (dec%2)*p;
        p*= 10;
        dec/=2;
    }
    cout<< num1;
    return 0;
}