#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<string> v;
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {

        cin >> s;

        v.push_back(s);
    }

    for (auto &i : v)
    {
        cout << i << endl;
    }
    



    return 0;
}