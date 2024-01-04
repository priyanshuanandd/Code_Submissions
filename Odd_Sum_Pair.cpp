#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int odd_counter = 0;
        int even_counter = 0;
        int x;

        for (int i = 0; i < 3; i++)
        {
            cin >> x;
            if (x % 2 == 0)
            {
                even_counter++;
            }
            else
            {
                odd_counter++;
            }
        }
        if (odd_counter != 0 and even_counter != 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

        return 0;
    }
}
