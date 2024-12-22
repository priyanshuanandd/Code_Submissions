#include <iostream>
using namespace std;

void binary(int b){
    int mul=1,add = 0,remainder = 0;
    for (int i = 0; b !=0 ;i++ )
    {
        remainder = b%10;
        add+= remainder*mul;
        b/=10;
        mul*=2;
           }
    cout << add;
}

int main()
{
    int inte;
    cin>> inte;
    binary(inte);
    return 0;
}