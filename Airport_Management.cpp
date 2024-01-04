#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<int, int> m;
        int x;
        for (int i = 0; i < 2 * n; i++)
        {
            cin >> x;
            m[x]++;
        }
        int freq = INT_MIN;
        for (auto i : m)
        {
            cout << "Number " << i.first << " is repeated " << i.second << " times" << endl;
            if (i.second > freq)
            {
                freq = i.second;
            }
            cout << "Freq is " << freq << endl;
        }
        cout << freq << endl;
    }

    return 0;
}