#include <iostream>
using namespace std;


int dtb(int a)
{
    int num1 = 0;
    for (; a != 0;)
    {
        num1 = num1 * 10 + a % 2;
        a /= 2;
    }
    int num2 = 0;
    for (; num1!= 0; num1 /= 10)
    {
        num2 = num2 * 10 + (num1% 10);
    }
    cout<< num2;
}
int main()
{
    int dec;
    cin>> dec;
   dtb(dec);
    return 0;
}
