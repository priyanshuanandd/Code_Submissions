#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;

    if (t >= 1 && t <= 1000)
    {
        int n, m, k, H;

        while (t--)
        {
            cin >> n >> m >> k >> H;
            if (n >= 1 && m <= 50 && k >= 1 && H <= 1000000)
            {
                int h[n]{};
                int f = 0;
                for (int i = 0; i < n; i++)
                {
                    cin >> h[i];
                    for (int j = 1; j <= m; j++)
                    {
                        if ((h[i] - H) == (k * j))
                        {
                            f = f + 1;
                        }
                    }
                }
                cout << f << endl;
            }
        }
    }
    return 0;
}