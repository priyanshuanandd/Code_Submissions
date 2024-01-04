#include <bits/stdc++.h>
using namespace std;
int getbit(int n, int i)
{
    int k = (1 << i);
    cout << ((n & k) > 0 ? 1 : 0) << endl;
}
int setbit(int n, int i)
{
    int k = (1 << i);
    n = (n | k);
    cout << n << endl;
}
int clearbitsinrange(int &n, int i, int j)
{
    int a = (-1 << j + 1);
    int b = ((1 << i ) - 1);
    int mask = (a | b);
    n = (n & mask);

    cout << n << endl;
}
int replacebits(int &n, int &m, int i, int j)
{
    clearbitsinrange(n, i, j);
    m = (m << i);

    cout << (n|m) << endl;
}
int main()
{
    int x;
    cin >> x;
    if ((x & 1) == 0)
    {
        cout << "Even" << endl;
    }
    else if ((x & 1) == 1)
    {
        cout << "Odd" << endl;
    }
    int i;
    cin >> i;
    int j;
    cin >> j;
    int m = 2;
   // clearbitsinrange(x, i, j);
    replacebits(x, m , i, j);
    return 0;
}