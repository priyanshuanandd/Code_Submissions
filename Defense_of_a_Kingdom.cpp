#include <bits/stdc++.h>
using namespace std;

int minTaps(int n, vector<int> v)
{
    vector<pair<int, int>> range;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] != 0)
        {
            range.push_back(make_pair(i - v[i], i + v[i]));
        }
    }
    n = v.size();
    sort(range.begin(), range.end());
    int x,y;
    x = y = 0;
    int count = 0;
    for (auto i : range)
    {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << minTaps(10, v) << endl;
}