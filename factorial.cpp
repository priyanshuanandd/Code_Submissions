#include <bits/stdc++.h>
using namespace std;
int factorial(int n)
{
    int ans = 1;
    if (n == 0)
    {
        return 1;
    }
    ans = n*factorial(n-1);
    return ans;
}
int main()
{
    int n;
    cin >> n;
    cout << factorial(n)<<endl;
    return 0;
}