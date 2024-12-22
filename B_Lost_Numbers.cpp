#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
int query(int a, int b)
{
    cout << "? " << a << " " << b << endl;
    int ans;
    cin >> ans;
    return ans;
}
int main()
{
    vector<int> v = {4, 8, 15, 16, 23, 42};
    int a = query(1, 2);
    int b = query(2, 3);
    int c = query(3, 4);
    int d = query(4, 5);
    do
    {
        if (v[0] * v[1] == a and v[1] * v[2] == b and v[2] * v[3] == c and v[3] * v[4] == d)
        {
            cout << "! ";
            for (auto i : v)
            {
                cout << i << " ";
            }
            fflush(stdout);
        }
    } while (next_permutation(all(v)));
}