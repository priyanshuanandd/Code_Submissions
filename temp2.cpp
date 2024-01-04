#include <bits/stdc++.h>
using namespace std;
void printvecofvec(vector<vector<int>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (auto &i : v[i])
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v;
    for (int i = 0; i < n; ++i)
    {
        int vecl;
        cin >> vecl;
        vector<int> v2;
        while (vecl--)
        {
            int x;
            cin >> x;
            v2.push_back(x);
            
        }
        v.push_back(v2);
    }
    printvecofvec(v);
    return 0;
}