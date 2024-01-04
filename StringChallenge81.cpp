#include <bits/stdc++.h>
using namespace std;

int canBeFormedOrNot(string s1, string s2)
{
    map<char, int> mainmap;
    map<char, int> sub;
    for (auto &i : s1)
    {
        mainmap[i]++;
    }
    for (auto &i : s2)
    {
        sub[i]++;
    }
    for (auto i : sub)
    {
        if (mainmap[i.first] < i.second)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    string s, t;
    getline(cin, s);
    getline(cin, t);
    cout << canBeFormedOrNot(s, t);
    return 0;
}