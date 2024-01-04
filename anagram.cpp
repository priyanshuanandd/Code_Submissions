#include <bits/stdc++.h>
#include <map>
using namespace std;

bool isAnagram(string s, string t)
{
    map<char, int> m1;
    map<char, int> m2;
    for (auto &i : s)
    {
        m1[i]++;
    }
    for (auto &i : t)
    {
        m2[i]++;
    }
    if (m1 == m2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    string s, t;
    getline(cin, s);
    getline(cin, t);
    cout << isAnagram(s, t);
}