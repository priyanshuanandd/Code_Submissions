#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<char, int> m;

    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {

        m[s[i]] = m[s[i]] + 1;
    }
    for (auto i : m)
    {
        cout << i.first << " " << i.second  << endl;
    }

    return 0;
}