
#include <iostream>
#include <map>
using namespace std;
int binomialCoefficients(int n, int k)
{
    if (k == 0 || k == n)
        return 1;
    return binomialCoefficients(n - 1, k - 1) + binomialCoefficients(n - 1, k);
}
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        int tt = 0;
        map<int, int> inner;
        int count;
        int arr[count];
        cin >> count;
        for (int i = 0; i < count; i++)
        {

            cin >> arr[i];
            inner[arr[i]]++;
        }
        for (auto &t : inner)
        {
            if (t.second >= 2)
            {
                tt += binomialCoefficients(t.second, 2);
            }
        }
        cout << tt << endl;
        return 0;
    }
}