#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int len, c = 0;
        cin >> len;        
        string str;
        cin>> str;
         for (int i = 0; i < len - 1; i++)
        {
            if (str[i] == str[i + 1])
            {
                c++;
            }

        }
        cout << c<<endl;
    }

    return 0;
}