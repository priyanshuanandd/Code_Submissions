#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<string> v;
void generate(string &s, ll o, ll c)
{
    if (o == 0 and c == 0)
    {
        v.push_back(s);
        return;
    }

    if (o > 0)
    {
        s.push_back('(');
        generate(s, o - 1, c);
        s.pop_back();
    }

    if (c > 0)
    {
        if (o < c)
        {
            s.push_back(')');
            generate(s, o, c - 1);
            s.pop_back();
        }
    }


}
