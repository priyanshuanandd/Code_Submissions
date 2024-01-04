#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for (int test = 0; test < testcases; test++)
    {
        int l, k;
        cin >> l >> k;
        if (l % k == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << 1 <<endl;
        }
    }
    return 0;
}