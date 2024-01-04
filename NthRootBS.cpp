#include <bits/stdc++.h>
using namespace std;
auto eps = 1e-15;

double multiply(double n, double k)
{
    double ans = 1;
    for (int i = 0; i < k; i++)
    {
        ans = ans * n;
    }
    return ans;
}
int main()
{
    double n;
    cin >> n;

    double p;
    cin >> p;
    double lo = 0;
    double hi = n;

    while (hi - lo > eps)
    {
        double mid = (hi + lo) / 2;
        if (multiply(mid, p) < n)
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }

    cout << setprecision(10) << hi << " " << lo << endl;

    return 0;
}