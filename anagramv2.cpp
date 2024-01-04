#include <bits/stdc++.h>
#include<string.h>
using namespace std;
bool isAnagram(string  s, string t)
{
    int l1 = s.length();
    int l2 = t.length();
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if (s == t)
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
    return 0;
}