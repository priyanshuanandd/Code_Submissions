#include <bits/stdc++.h>
using namespace std;

char largestFrequencyCharacter(string s)
{   map<char,int> m1;
    for (auto &i : s)
    {
        m1[i]++;
    }
    int pata = 0;
    char fre = ' ';
    for (auto i : m1)
    {
        if (i.second > pata)
        {
            pata = i.second;
            fre = i.first;
        }
        
    }
    return fre;
}   
int main()
{
    string s;
    getline(cin, s);
   cout << largestFrequencyCharacter(s);
    return 0;
}