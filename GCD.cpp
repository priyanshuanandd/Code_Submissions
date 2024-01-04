#include <iostream>
using namespace std;
int greatestCommonDivisor(int x, int y)
{
    int GCD = 1;
    if (x > y)
    {
        for (int i = 2; i <= x; i++)
        {
            if (x % i == 0 && y % i == 0)
            {
                GCD = i;
            }
        }
    }
    else{
        for (int i = 2; i <= y; i++)
        {
            if (x % i == 0 && y % i == 0)
            {
                GCD = i;
            }
        }
        
    }
    cout << GCD;
}
int main()
{   int x,y;
    cin >> x>> y;
    greatestCommonDivisor(x,y);

    return 0;
}