#include <iostream>
using namespace std;

int main()
{
   signed int u ;
   int c;
    cin>> u;
 if (u>=1)
 {
   int  c = 0;
 }
 if (u>=100)
 {
    if (u > 200)
    {
        c= 500;
    }
    else{
        c= (u-100)*5;
    }
 }
if (u>=200)
 {
     if (u > 300)
    {
        c= c + 1000 ;
    }
    else{
        c= c+ (u-200)*10;
    }
 }
if (u>=300)
 {
    c= c+ (u-300)*12;
 }
    cout<< "ELECTRICITY BILL: "<< c<<endl;
    return 0;

}