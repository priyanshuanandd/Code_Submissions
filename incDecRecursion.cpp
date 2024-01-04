#include <iostream>
using namespace std;

int dec(int n)
{
    if (n == 0)
    {
        return 0;
    }
    cout << n << " ";
    dec(n - 1);
}

int inc(int n)
{
    if (n == 0)
    {
        return 0;
    }
    inc(n - 1);
    cout << n << " ";
}

int main()
{
    int n;
    cin >> n;
    inc(n);
    cout << endl;
    dec(n);
    cout << endl;
    return 0;
}