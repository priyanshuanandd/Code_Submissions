#include <iostream>
using namespace std;

void binary(int b){
    int sum =0,add = 0,remainder = 0;
    for (int i = 0; b !=0 ;i++)
    {
        remainder = b%10;
        for (size_t mul = 1; mul <= i ; mul++)
        {
            remainder *= 2;
        }
        b/=10;
        add += remainder;
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

