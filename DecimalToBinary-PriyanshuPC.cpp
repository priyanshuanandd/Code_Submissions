#include <iostream>
using namespace std;

int reversethenumber(int a)
{
    int num1 = 0;
    for (; a != 0; a /= 10)
    {
        num1 = num1 * 10 + (a % 10);
        return num1;
    }
}
int dtb(int a)
{
    int num1 = 0;
    for (; a != 0;)
    {
        num1 = num1 * 10 + a % 2;
        a /= 2;
    }
    cout << reversethenumber(num1);
}
int main()
{
   cout<<( reversethenumber(53));
    return 0;
}