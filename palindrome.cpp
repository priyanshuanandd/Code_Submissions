#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    int len = s.length();
    for (int i = 0; i * i < len; i++)
        {
            if (s[i] != s[len - 1 - i])
            {
                return false;
            }
        }
        return true;
}
int main()
{
    string s, t;
    getline(cin, s);
    cout << isPalindrome(s);
    return 0;
}