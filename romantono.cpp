#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s)
{
    map<char, int> m1;
    for (auto &i : s)
    {
        m1[i]++;
    }
    int count = 0;
    for (auto &i : m1)
    {
        switch (i.first)
        {
        case 'I':
            count += 1*i.second;
            break;
        case 'V':
            count += 5*i.second;
            break;
        case 'X':
            count += 10*i.second;
            break;
        case 'C':
            count += 100*i.second;
            break;
        case 'D':
            count += 500*i.second;
            break;
        case 'M':
            count += 1000*i.second;
            break;
        case 'L':
            count += 50;
            break;
        default:
            break;
        }
    }
    return count;
}
int main()
{
    string s;
    getline(cin, s);
    cout << romanToInt(s);
    return 0;
}