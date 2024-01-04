#include <bits/stdc++.h>
using namespace std;
void isprime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return ;
        }
    }
    cout << n << endl;
    return;
}
int main()
{
    int l, r;
    cin >> l >> r;

    for (int i = l; i <= r; i++)
    {
        isprime(i);
    }
    return 0;
}