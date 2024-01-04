#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int m;
    cin >> n >> m;
    vector<int> v1(n), v2(m), ans;

    for (int i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> v2[i];
    }

    int i, j;
    i = j = 0;
    while (i < v1.size() or j < v2.size())
    {
        if (j == m || (i < n && v1[i] < v2[j]))
        {
            ans.push_back(v1[i]);
            i++;
        }
        else
        {
            ans.push_back(v2[j]);
            j++;
        }
    }
    for (auto i : ans)
    {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}