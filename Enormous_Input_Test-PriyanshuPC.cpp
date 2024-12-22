#include <iostream>
using namespace std;

int main()
{
    int n, k, a, i = 1, mul = 0;
    cin >> n >> k;
    while (i <= n)
    {
        cin >> a;
        if (a % k == 0)
        {
            mul++;
            i++;
        }
        else
        {
            i++;
        }
    }
    cout << mul << endl;
    return 0;
}