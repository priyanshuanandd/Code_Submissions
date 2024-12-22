#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    vector<int> v(6);

    for (int i = 0; i < 6; i++)
    {
        v[i] = i + 1;
    }

    // dp array to store the number of ways to get sum j with dice results up to i
    vector<int> dp(n + 1, 0);

        dp[0] = 1;
    

    // Fill the dp table
    for (int i = 1; i < 7; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i - j >= 0)
            {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }

    cout << dp[n] << endl;

    return 0;
}
